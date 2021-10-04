//
// Created by Dell on 2021/10/4.
//

#ifndef CPP_SHAPE_H
#define CPP_SHAPE_H

#endif //CPP_SHAPE_H

#include <iostream>
using namespace std;
class Shape{
public:
    Shape(){}
    ~Shape(){}
    virtual double GetArea()=0;
    virtual double GetPerimeter()=0;
    static Shape* createRectangle(double length,double width);
    static Shape* createCircle(double radius);
};
