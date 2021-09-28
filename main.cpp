#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class Student{
    string name;
    string num;
    int grade[3];
public:
    Student(string name,string num,int n1,int n2,int n3){
        this->name=name;
        this->num=num;
        this->grade[0]=n1;
        this->grade[1]=n2;
        this->grade[2]=n3;
    }
    void display(void){
        cout<<num<<" "<<name<<" "<<grade[0]<<" "<<grade[1]<<" "<<grade[2]<<" ";
    }
};
int main(){
    Student *stu1,*stu2,*stu3;
    char name1[10],name2[10],name3[10];
    char num1[12],num2[12],num3[12];
    int grade1[3],grade2[3],grade3[3];
    cin>>name1>>num1>>grade1[0]>>grade1[1]>>grade1[2];
    cin>>name2>>num2>>grade2[0]>>grade2[1]>>grade2[2];
    cin>>name3>>num3>>grade3[0]>>grade3[1]>>grade3[2];
    stu1 = new Student(name1,num1,grade1[0],grade1[1],grade1[2]);
    stu2 = new Student(name2,num2,grade2[0],grade2[1],grade2[2]);
    stu3 = new Student(name3,num3,grade3[0],grade3[1],grade3[2]);

    stu1->display();
    stu2->display();
    stu3->display();

    cout<<"The average grade of course1:"<<(grade1[0]+grade2[0]+grade3[0])/3.0<<endl;
    cout<<"The average grade of course2:"<<(grade1[1]+grade2[1]+grade3[1])/3.0<<endl;
    cout<<"The average grade of course3:"<<(grade1[2]+grade2[2]+grade3[2])/3.0<<endl;
    return 0;
}