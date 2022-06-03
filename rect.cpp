#include "rect.h"
#include "math.h"
Rect::Rect()
{

}

Rect::Rect(int x, int y, int x1, int y1)
{
    if (y < y1) {
        originY = y;
    }
    else {
        originY = y1;
    }
   if (x < x1) {
       originX = x;
   }
   else {
       originX = x1;
   }
   height = abs(y - y1);
   weidth = abs(x - x1);
}

int Rect::getOriginX() const
{
    return originX;
}

int Rect::getOriginY() const
{
    return originY;
}
int Rect::getHeight() const
{
    return height;
}
int Rect::getWeidth() const
{
    return weidth;
}


