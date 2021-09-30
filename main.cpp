#include <iostream>
#include "ShapeFactory.h"
#include <vector>
class Triangle:public ShapeFactory{
    float a;
    float b;
    float c;

public:
    Triangle(float a,float b,float c){
        this->a=a;
        this->b=b;
        this->c=c;
    }
    virtual float Circumstance() override{
        return (a+b+c);
    }
};
class Circle:public ShapeFactory{
    float r;
public:
    Circle(float r){
        this->r=r;
    }
    virtual float Circumstance() override{
        double pi=3.14;
        return 2*pi*r;
    }
};
class Quadrangle:public ShapeFactory{
    float a;
    float b;
    float c;
    float d;
public:
    Quadrangle(float a,float b,float c,float d) {
        this->a=a;
        this->b=b;
        this->c=c;
        this->d=d;
    }
    virtual float Circumstance() override{
        return a+b+c+d;
    }
};
ShapeFactory * ShapeFactory::Create(float a,float b,float c)
{
    ShapeFactory *p=new Triangle(a,b,c);
    return p;
}
ShapeFactory * ShapeFactory::Create(float r) {
    ShapeFactory *p=new Circle(r);
    return p;
}
ShapeFactory * ShapeFactory::Create(float a,float b,float c,float d) {
    ShapeFactory *p=new Quadrangle(a,b,c,d);
    return p;
}