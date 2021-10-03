//
// Created by Dell on 2021/10/3.
//

#ifndef CPP_CLOCKANDDATE_H
#define CPP_CLOCKANDDATE_H

#endif //CPP_CLOCKANDDATE_H

#include <iostream>
using namespace std;
class Clock{
public:
    Clock(int h,int m,int s){
        hour =(h>23? 0:h);
        minute = (m>59?0:m);
        second = (s>59?0:m);
    }
    virtual void run(){
        second = second+1;
        if (second>59)
        {
            second =0;
            minute+=1;
        }
        if (minute>59)
        {
            minute =0;
            hour+=1;
        }
        if (hour>23)
        {
            hour =0;
        }
    }
    virtual void showTime(){
        cout<<"Now:"<<hour<<":"<<minute<<":"<<second<<endl;
    }
    int getHour(){return hour;}
    int getMinute(){return minute;}
    int getSecond(){return second;}

    Clock * createClockWithDate(int h,int m,int s,int year,int month,int day);
protected:
    int hour;
    int minute;
    int second;
};

class Date{
public:
    Date(int y=1996,int m=1,int d=1){
        day =d;
        year =y;
        month =m;
        if (m>12||m<1)
        {
            m=1;
        }
        if(d>days(y,m)){
            day = 1;
        }
    };
    int days(int year,int month);
    void NewDay();
    void display(){
        cout<<year<<"-"<<month<<"-"<<day<<endl;
    }
protected:
    int year;
    int month;
    int day;
};