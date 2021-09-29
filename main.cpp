#include <iostream>
#include <math.h>
#include "CPoint.h"

Rectangle ::Rectangle(float xx, float yy, float w, float h) : Point(xx, yy) {
    width=w;
    high=h;
}
float Rectangle::Area() {
    return width*high;
}

Circle ::Circle(float xx, float yy, float r) : Point(xx,yy){
    radius=r;
}
float Circle::Area() {
    return(radius*radius*3.14);
}