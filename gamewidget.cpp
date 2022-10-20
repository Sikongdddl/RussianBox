#include "gamewidget.h"
#include "item.h"

int timeStamp = 1;

void gamewidget::init()
{
    this->resize(BLOCK_SIZE*(WIDTH+2),BLOCK_SIZE*HEIGHT);
    this->setWindowTitle("俄罗斯方块儿真好玩儿！");
    srand((int)time (NULL));

    this->score = 0;

    map=new box* [HEIGHT];
    for(int i=0;i<HEIGHT;i++) map[i]=new box [WIDTH];

    timer = new QTimer(this);

    this->fall = new QPushButton(this);
    fall->move(-50,-50);
    fall->setShortcut(tr("S"));

    this->moveLeft = new QPushButton(this);
    moveLeft->move(-50,-50);
    moveLeft->setShortcut(tr("A"));

    this->moveRight = new QPushButton(this);
    moveRight->move(-50,-50);
    moveRight->setShortcut(tr("D"));

    this->traverse = new QPushButton(this);
    traverse->move(-50,-50);
    traverse->setShortcut(Qt::Key_Space);

    this->hell = new QPushButton(this);
    hell->move(-50,-50);
    hell->setShortcut(Qt::Key_Enter);
}
void gamewidget::nextOne()
{
    this->timer->start(300);
    int tryX = rand()%(WIDTH);
    while(tryX == 0 || tryX == WIDTH-1)
    {
        tryX = rand()%(WIDTH);
    }

    int tryT = rand()%8;
    while(tryT == 0)
    {
        tryT = rand()%8;
    }

    this->curOne.stamp=timeStamp;
    ++timeStamp;

    this->curOne.center.x=tryX;
    this->curOne.center.y=1;

    this->curOne.group.clear();
    this->curOne.type=tryT;

    this->curOne.towards = Item::UP;
    //this->curOne.type = 2;
    this->curOne.shuffle();
    for(int i = 0; i < 4; ++i)
    {
        int row = curOne.group[i].y;
        int col = curOne.group[i].x;
        map[row][col].type = curOne.type;
    }

}

void gamewidget::copy(int des, int tar)
{
    for(int j = 0; j < WIDTH; ++j)
    {
        map[des][j].type = map[tar][j].type;
        map[des][j].stamp = map[tar][j].stamp;
        map[tar][j].type=0;
        map[tar][j].stamp=0;
    }
}
void gamewidget::checkDel()
{
    bool isFull = 1;
    std::vector<int> delLine;
    delLine.clear();
    for(int i = 0; i < HEIGHT; ++i)//del
    {
        isFull = 1;
        for(int j = 0; j < WIDTH; ++j)
        {
            if(map[i][j].type==0) isFull = 0;
        }
        if(isFull == 0)
        {
            continue;
        }
        else if(isFull == 1)
        {
            delLine.push_back(i);
            ++score;
            for(int j = 0; j < WIDTH; ++j)
            {
                map[i][j].stamp = 0;
                map[i][j].type = 0;
            }
        }
    }
    int length = (int)delLine.size();
    for(int k = 0; k < length; ++k)
    {
        maintainDel(delLine[k]);
    }
}
void gamewidget::maintainDel(int lineDel)
{
    for(int k = lineDel; k >= 1; --k)
    {
        copy(k,k-1);
    }
}

void gamewidget::lambdaConnection()
{
    connect(timer,&QTimer::timeout,this,[=]()
    {
        int downMax = 0;
        nextPos.clear();
        for(int i = 0; i < 4; ++i)
        {
            if(curOne.group[i].y > downMax)
            {
                downMax = curOne.group[i].y;
            }
        }
        if(downMax == HEIGHT-1)
        {
            nextOne();
            checkDel();
            update();
            return;
        }
        else
        {
            for(int i = 0; i < 4; ++i)//calculate nextPos
            {
                int nextX = curOne.group[i].x;
                int nextY = curOne.group[i].y+1;
                Item::locat tmp;
                tmp.x = nextX;
                tmp.y = nextY;
                nextPos.push_back(tmp);
            }
            for(int i = 0; i < 4; ++i)//check if crash
            {
                int rowTmp = nextPos[i].y;
                int colTmp = nextPos[i].x;
                if(map[rowTmp][colTmp].type != 0 && map[rowTmp][colTmp].stamp != curOne.stamp&&map[rowTmp][colTmp].stamp!=0)//crash
                {
                    nextOne();
                    checkDel();
                    return;
                }
            }
            curOne.center.y+=1;
            for(int i = 0; i < 4; ++i)//clear curPos
            {
                int row = curOne.group[i].y;
                int col = curOne.group[i].x;
                map[row][col].type = 0;
                map[row][col].stamp = 0;
            }
            for(int i = 0; i < 4; ++i)//gain nextPos
            {
                curOne.group[i].y = nextPos[i].y;
            }
            for(int i = 0; i < 4; ++i)//prepare to draw nextPos
            {
                int row = curOne.group[i].y;
                int col = curOne.group[i].x;
                map[row][col].type = curOne.type;
                map[row][col].stamp = curOne.stamp;
            }
            update();
        }
    });

    connect(hell,&QPushButton::clicked,this,[=]()
    {
        this->timer->start(30);
    });
    connect(fall,&QPushButton::clicked,this,[=]()
    {
        timer->start(300);
        /*int downMax = 0;
        for(int i = 0; i < 4; ++i)
        {
            if(curOne.group[i].y > downMax)
            {
                downMax = curOne.group[i].y;
            }
        }
        if(downMax == HEIGHT-1)
        {
            nextOne();
            return;
        }
        else
        {
            curOne.center.y+=1;
            for(int i = 0; i < 4; ++i)
            {
                int row = curOne.group[i].y;
                int col = curOne.group[i].x;
                map[row][col].type = 0;
            }
            for(int i = 0; i < 4; ++i)
            {
                curOne.group[i].y += 1;
            }
            for(int i = 0; i < 4; ++i)
            {
                int row = curOne.group[i].y;
                int col = curOne.group[i].x;
                map[row][col].type = curOne.type;
            }
            update();
        }*/
    });
    connect(moveLeft,&QPushButton::clicked,this,[=]()
    {
        int leftMin = 10;
        nextPos.clear();
        for(int i = 0; i < 4; ++i)
        {
            if(curOne.group[i].x < leftMin)
            {
                leftMin = curOne.group[i].x;
            }
        }

        if(leftMin == 0)
        {
            return;
        }
        else
        {
            for(int i = 0; i < 4; ++i)//calculate nextPos
            {
                int nextX = curOne.group[i].x-1;
                int nextY = curOne.group[i].y;
                Item::locat tmp;
                tmp.x = nextX;
                tmp.y = nextY;
                nextPos.push_back(tmp);
            }
            for(int i = 0; i < 4; ++i)//check if crash
            {
                int rowTmp = nextPos[i].y;
                int colTmp = nextPos[i].x;
                if(map[rowTmp][colTmp].type != 0 && map[rowTmp][colTmp].stamp != curOne.stamp&&map[rowTmp][colTmp].stamp!=0)//crash
                {
                    return;
                }
            }
            curOne.center.x-=1;
            for(int i = 0; i < 4; ++i)//clear curPos
            {
                int row = curOne.group[i].y;
                int col = curOne.group[i].x;
                map[row][col].type = 0;
                map[row][col].stamp = 0;
            }
            for(int i = 0; i < 4; ++i)//gain nextPos
            {
                curOne.group[i].x = nextPos[i].x;
            }
            for(int i = 0; i < 4; ++i)//prepare to draw nextPos
            {
                int row = curOne.group[i].y;
                int col = curOne.group[i].x;
                map[row][col].type = curOne.type;
                map[row][col].stamp = curOne.stamp;
            }
        }
            update();
    });
    connect(moveRight,&QPushButton::clicked,this,[=]()
    {
        int rightMin = 0;
        nextPos.clear();
        for(int i = 0; i < 4; ++i)
        {
            if(curOne.group[i].x > rightMin)
            {
                rightMin = curOne.group[i].x;
            }
        }
        if(rightMin == WIDTH -1)
        {
            return;
        }
        else
        {
            for(int i = 0; i < 4; ++i)//calculate nextPos
            {
                int nextX = curOne.group[i].x+1;
                int nextY = curOne.group[i].y;
                Item::locat tmp;
                tmp.x = nextX;
                tmp.y = nextY;
                nextPos.push_back(tmp);
            }
            for(int i = 0; i < 4; ++i)//check if crash
            {
                int rowTmp = nextPos[i].y;
                int colTmp = nextPos[i].x;
                if(map[rowTmp][colTmp].type != 0 && map[rowTmp][colTmp].stamp != curOne.stamp&&map[rowTmp][colTmp].stamp!=0)//crash
                {
                    return;
                }
            }
            curOne.center.x+=1;
            for(int i = 0; i < 4; ++i)//clear curPos
            {
                int row = curOne.group[i].y;
                int col = curOne.group[i].x;
                map[row][col].type = 0;
                map[row][col].stamp = 0;
            }
            for(int i = 0; i < 4; ++i)//gain nextPos
            {
                curOne.group[i].x = nextPos[i].x;
            }
            for(int i = 0; i < 4; ++i)//prepare to draw nextPos
            {
                int row = curOne.group[i].y;
                int col = curOne.group[i].x;
                map[row][col].type = curOne.type;
                map[row][col].stamp = curOne.stamp;
            }
        }
            update();
    });
    connect(traverse, &QPushButton::clicked,this,[=]()
    {
        formerPos.clear();
        for(int i = 0; i < 4; ++i)//storage former position
        {
            int nextX = curOne.group[i].x;
            int nextY = curOne.group[i].y;
            Item::locat tmp;
            tmp.x = nextX;
            tmp.y = nextY;
            formerPos.push_back(tmp);
        }

        int curTowards = this->curOne.towards;
        curTowards = (curTowards+1) % 4;
        this->curOne.towards = (Item::toward)curTowards;
        this->curOne.shuffle();

        for(int i = 0; i < 4; ++i)//clear formerPos
        {
            int row = formerPos[i].y;
            int col = formerPos[i].x;
            map[row][col].type = 0;
            map[row][col].stamp = 0;
        }
        for(int i = 0; i < 4; ++i)//prepare to draw nextPos
        {
            int row = curOne.group[i].y;
            int col = curOne.group[i].x;
            map[row][col].type = curOne.type;
            map[row][col].stamp = curOne.stamp;
        }
        update();

    });
}

gamewidget::gamewidget()
{
    this->nextPos.clear();
    this->init();
    this->lambdaConnection();
    this->nextOne();
}

gamewidget::~gamewidget()
{

}
void gamewidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QString tmp = QString::number(score);
    painter.drawText(BLOCK_SIZE*WIDTH + BLOCK_SIZE*0.5,0,BLOCK_SIZE,BLOCK_SIZE,Qt::AlignCenter,tmp);
    for(int i = 0; i < HEIGHT; ++i)
        for(int j = 0; j < WIDTH; ++j)
        {
            char t[3];
            t[0]=map[i][j].stamp/10+'0';
            t[1]=map[i][j].stamp%10+'0';
            t[2]='\0';
            QString tt(t);
            painter.drawRect(BLOCK_SIZE*j,BLOCK_SIZE*i,BLOCK_SIZE, BLOCK_SIZE);
            //painter.drawText(BLOCK_SIZE*j,BLOCK_SIZE*i,BLOCK_SIZE, BLOCK_SIZE,Qt::AlignCenter,tt);
            if(map[i][j].type==0)
            {
                QColor colorGray(192,192,192,127);
                painter.fillRect(BLOCK_SIZE*j,BLOCK_SIZE*i,BLOCK_SIZE, BLOCK_SIZE,colorGray);
            }
            else if(map[i][j].type==1)
            {
                QColor colorPurple(128,0,128,127);
                painter.fillRect(BLOCK_SIZE*j,BLOCK_SIZE*i,BLOCK_SIZE, BLOCK_SIZE,colorPurple);
            }
            else if(map[i][j].type==2)
            {
                QColor colorYellow(255,255,0,127);
                painter.fillRect(BLOCK_SIZE*j,BLOCK_SIZE*i,BLOCK_SIZE, BLOCK_SIZE,colorYellow);
            }
            else if(map[i][j].type==3)
            {
                QColor colorOrange(255,128,0,127);
                painter.fillRect(BLOCK_SIZE*j,BLOCK_SIZE*i,BLOCK_SIZE, BLOCK_SIZE,colorOrange);
            }
            else if(map[i][j].type==4)
            {
                QColor colorBlue(0,0,255,127);
                painter.fillRect(BLOCK_SIZE*j,BLOCK_SIZE*i,BLOCK_SIZE, BLOCK_SIZE,colorBlue);
            }
            else if(map[i][j].type==5)
            {
                QColor colorLightBlue(0,191,255,127);
                painter.fillRect(BLOCK_SIZE*j,BLOCK_SIZE*i,BLOCK_SIZE, BLOCK_SIZE,colorLightBlue);
            }
            else if(map[i][j].type==6)
            {
                QColor colorRed(255,0,0,127);
                painter.fillRect(BLOCK_SIZE*j,BLOCK_SIZE*i,BLOCK_SIZE, BLOCK_SIZE,colorRed);
            }
            else if(map[i][j].type==7)
            {
                QColor colorGreen(0,255,0,127);
                painter.fillRect(BLOCK_SIZE*j,BLOCK_SIZE*i,BLOCK_SIZE, BLOCK_SIZE,colorGreen);
            }
        }


}
