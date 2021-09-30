#include <iostream>
#include <cstring>
#include "Clock.h"
using namespace std;

class NewClock:public Clock{
public:
    NewClock(int h,int m,int s):Clock(h,m,s){

    }
    virtual void showTime(void) override{
        int h=getHour();
        int m=getMinute();
        int s=getSecond();

        if(h<12){
            cout<<"Now:"<<h<<":"<<m<<":"<<s<<"AM"<<endl;
        }else if(h==12){
            cout<<"Now:"<<h<<":"<<m<<":"<<s<<"PM"<<endl;
        }else{
            cout<<"Now:"<<h-12<<":"<<m<<":"<<s<<"PM"<<endl;
        }

    }
};
Clock* Clock::createNewClock(int h,int m,int s){
    return new NewClock(h,m,s);
}