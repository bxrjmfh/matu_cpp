#include <iostream>
#include <cstring>

using namespace std;

class Table{
    float high;
public:
    Table(float high=0){
        this->high=high;
    }
    float GetHigh(void){
        return high;
    }
};

class Circle{
    float radius;
public:
    Circle(float radius){
        this->radius=radius;
    }
    float GetArea(void){
        double pi=3.14;
        return this->radius*this->radius*pi;
    }
};
class RoundTable:public Circle,public Table{
    char color[100];
public:
    RoundTable(float a,float b,char *c): Table(b), Circle(a){
        strcpy(this->color,c);
    }
    char *GetColor(){
        return this->color;
    }
};
int main(){
    float radius,high;
    char color[20];
    cin>>radius>>high>>color;

    RoundTable RT(radius,high,color);
    cout<<"Area:"<<RT.GetArea()<<endl;
    cout<<"High:"<<RT.GetHigh()<<endl;
    cout<<"Color:"<<RT.GetColor()<<endl;
    return 0;
}