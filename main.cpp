#include"Shape.h"

class Rectangle :public Shape{
    double a;
    double b;
public:
    Rectangle(double l,double w){
        a=l;
        b=w;
    }
    double GetArea()override{
        return a*b;
    }
    double GetPerimeter()override{
        return (a+b)*2;
    }
};


class Circle :public Shape{
    double r;
public:
    Circle(double r){
        this->r=r;
    }
    double GetArea() override{
        return(r*r*3.14);
    }
    double GetPerimeter() override{
        return (2*r*3.14);
    }
};
Shape * Shape::createRectangle(double l,double w){return new Rectangle(l,w);}
Shape * Shape::createCircle(double r){return new Circle(r);}

