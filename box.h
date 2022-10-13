#ifndef BOX_H
#define BOX_H
#include <vector>
#include "item.h"

class box
{
public:
    int type;
    int stamp;
    /**
     * type0:
     * background,grey
     * type1:
     *  X
     * XXX
     * purple
     * type2:
     * XX
     * XX
     * yellow
     * type3:
     * X
     * X
     * XX
     * orange
     * type4:
     *  X
     *  X
     * XX
     * blue
     * type5:
     * XXXX
     * light blue
     * type6:
     * XX
     *  XX
     * red
     * type7:
     *  XX
     * XX
     * green
     **/
    box();
};

#endif // BOX_H
