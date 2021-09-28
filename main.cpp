#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
class Ctriangle {
    double a,b,c;
    public:
    Ctriangle(double a,double b,double c){
        this->a=a;
        this->b=b;
        this->c=c;
    }
    void display(void){
        cout<<"Ctriangle:a="<<a<<",b="<<b<<",c="<<c<<endl;
    }
    double GetPerimeter(void){
        return(a+b+c);
    }
    double GetArea(void){
        double s=(a+b+c)/2;
        double area=sqrt(s*(s-a)*(s-b)*(s-c));
        return area;
    }
};
int main(){
    double a,b,c;
    cin>>a>>b>>c;
    Ctriangle T(a,b,c);
    T.display();
    cout<<"Perimeter:"<<T.GetPerimeter()<<endl;
    cout<<"Area:"<<T.GetArea()<<endl;
    return 0;
}