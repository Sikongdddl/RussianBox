#ifndef ITEM_H
#define ITEM_H

#include <vector>

class Item
{
private:

public:
    Item();
    int stamp;
    enum toward{UP=0,RIGHT,DOWN,LEFT};
    toward towards;

    void shuffle()
    {
        this->group.clear();
        locat lcTmp;
        switch(this->type)
        {
        case 1:
            if(this->towards==UP)
            {
                // X
                //XOX
                group.push_back(this->center);
                lcTmp.x = this->center.x-1;
                lcTmp.y = this->center.y;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x+1;
                lcTmp.y = this->center.y;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x;
                lcTmp.y = this->center.y-1;
                this->group.push_back(lcTmp);
            }
            else if(this->towards==RIGHT)
            {
                // X
                // OX
                // X
                group.push_back(this->center);
                lcTmp.x = this->center.x;
                lcTmp.y = this->center.y+1;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x+1;
                lcTmp.y = this->center.y;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x;
                lcTmp.y = this->center.y-1;
                this->group.push_back(lcTmp);
            }
            else if(this->towards==DOWN)
            {
                //XOX
                // X
                group.push_back(this->center);
                lcTmp.x = this->center.x-1;
                lcTmp.y = this->center.y;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x+1;
                lcTmp.y = this->center.y;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x;
                lcTmp.y = this->center.y+1;
                this->group.push_back(lcTmp);
            }
            else if(this->towards==LEFT)
            {
                //  X
                // XO
                //  X
                group.push_back(this->center);
                lcTmp.x = this->center.x;
                lcTmp.y = this->center.y-1;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x-1;
                lcTmp.y = this->center.y;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x;
                lcTmp.y = this->center.y+1;
                this->group.push_back(lcTmp);
            }
            break;
        case 2:
            // XX
            // OX
            group.push_back(this->center);
            lcTmp.x = this->center.x;
            lcTmp.y = this->center.y-1;
            this->group.push_back(lcTmp);
            lcTmp.x = this->center.x+1;
            lcTmp.y = this->center.y-1;
            this->group.push_back(lcTmp);
            lcTmp.x = this->center.x+1;
            lcTmp.y = this->center.y;
            this->group.push_back(lcTmp);
            break;
        case 3:
            if(this->towards==UP)
            {
                // X
                // O
                // XX
                group.push_back(this->center);
                lcTmp.x = this->center.x;
                lcTmp.y = this->center.y-1;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x;
                lcTmp.y = this->center.y+1;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x+1;
                lcTmp.y = this->center.y+1;
                this->group.push_back(lcTmp);
            }
            else if(this->towards==RIGHT)
            {
                //XOX
                //X
                group.push_back(this->center);
                lcTmp.x = this->center.x-1;
                lcTmp.y = this->center.y;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x-1;
                lcTmp.y = this->center.y+1;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x+1;
                lcTmp.y = this->center.y;
                this->group.push_back(lcTmp);
            }
            else if(this->towards==DOWN)
            {
                //XX
                // O
                // X
                group.push_back(this->center);
                lcTmp.x = this->center.x;
                lcTmp.y = this->center.y-1;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x-1;
                lcTmp.y = this->center.y-1;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x;
                lcTmp.y = this->center.y+1;
                this->group.push_back(lcTmp);
            }
            else if(this->towards==LEFT)
            {
                //  X
                //XOX
                group.push_back(this->center);
                lcTmp.x = this->center.x-1;
                lcTmp.y = this->center.y;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x+1;
                lcTmp.y = this->center.y;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x+1;
                lcTmp.y = this->center.y-1;
                this->group.push_back(lcTmp);
            }
            break;
        case 4:
            if(this->towards==UP)
            {
                //  X
                //  O
                // XX
                group.push_back(this->center);
                lcTmp.x = this->center.x;
                lcTmp.y = this->center.y-1;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x;
                lcTmp.y = this->center.y+1;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x-1;
                lcTmp.y = this->center.y+1;
                this->group.push_back(lcTmp);
            }
            else if(this->towards==RIGHT)
            {
                // X
                // XOX
                group.push_back(this->center);
                lcTmp.x = this->center.x-1;
                lcTmp.y = this->center.y-1;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x-1;
                lcTmp.y = this->center.y;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x+1;
                lcTmp.y = this->center.y;
                this->group.push_back(lcTmp);
            }
            else if(this->towards==DOWN)
            {
                //  XX
                //  O
                //  X
                group.push_back(this->center);
                lcTmp.x = this->center.x;
                lcTmp.y = this->center.y-1;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x;
                lcTmp.y = this->center.y+1;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x+1;
                lcTmp.y = this->center.y-1;
                this->group.push_back(lcTmp);
            }
            else if(this->towards==LEFT)
            {
                //  XOX
                //    X
                group.push_back(this->center);
                lcTmp.x = this->center.x-1;
                lcTmp.y = this->center.y;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x+1;
                lcTmp.y = this->center.y;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x+1;
                lcTmp.y = this->center.y+1;
                this->group.push_back(lcTmp);
            }
            break;
        case 5:
            if(this->towards==UP || this->towards==DOWN)
            {
                //  X
                //  O
                //  X
                //  X
                group.push_back(this->center);
                lcTmp.x = this->center.x;
                lcTmp.y = this->center.y-1;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x;
                lcTmp.y = this->center.y+1;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x;
                lcTmp.y = this->center.y+2;
                this->group.push_back(lcTmp);
            }
            else if(this->towards==LEFT || this->towards==RIGHT)
            {
                //  XOXX
                group.push_back(this->center);
                lcTmp.x = this->center.x-1;
                lcTmp.y = this->center.y;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x+1;
                lcTmp.y = this->center.y;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x+2;
                lcTmp.y = this->center.y;
                this->group.push_back(lcTmp);
            }
            break;
        case 6:
            if(this->towards==UP||this->towards==DOWN)
            {
                // XX
                //  OX
                group.push_back(this->center);
                lcTmp.x = this->center.x-1;
                lcTmp.y = this->center.y-1;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x;
                lcTmp.y = this->center.y-1;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x+1;
                lcTmp.y = this->center.y;
                this->group.push_back(lcTmp);
            }
            else if(this->towards==LEFT || this->towards==RIGHT)
            {
                //  X
                // XO
                // X
                group.push_back(this->center);
                lcTmp.x = this->center.x-1;
                lcTmp.y = this->center.y;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x;
                lcTmp.y = this->center.y-1;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x-1;
                lcTmp.y = this->center.y+1;
                this->group.push_back(lcTmp);
            }
            break;
        case 7:
            if(this->towards==UP||this->towards==DOWN)
            {
                //  XX
                // XO
                group.push_back(this->center);
                lcTmp.x = this->center.x-1;
                lcTmp.y = this->center.y;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x;
                lcTmp.y = this->center.y-1;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x+1;
                lcTmp.y = this->center.y-1;
                this->group.push_back(lcTmp);
                break;
            }
            else if(this->towards==LEFT||this->towards==RIGHT)
            {
                //  X
                //  XO
                //   X
                group.push_back(this->center);
                lcTmp.x = this->center.x-1;
                lcTmp.y = this->center.y;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x-1;
                lcTmp.y = this->center.y-1;
                this->group.push_back(lcTmp);
                lcTmp.x = this->center.x;
                lcTmp.y = this->center.y+1;
                this->group.push_back(lcTmp);
                break;
            }

        }
    }

    struct locat
    {
        int x;
        int y;
        locat()
        {

        }
        locat(int xx, int yy)
        {
            this->x = xx;
            this->y = yy;
        }
    };
    int type;
    locat center;
    std::vector<locat>group;
    locat getPosition()
    {
        locat tmp;
        tmp.x = this->center.x;
        tmp.y = this->center.y;
        return tmp;
    }

};

#endif // ITEM_H
