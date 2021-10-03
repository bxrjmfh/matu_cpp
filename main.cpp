#include <iostream>
#include <cstring>
#include "ClockAndDate.h"

using namespace std;

int Date::days(int year, int month) {
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
            break;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                return 29;
            } else {
                return 28;
            }
            break;
        default:
            break;
    }
}

void Date::NewDay() {
    int month_flag = 0;
    int year_flag = 0;

    switch (this->month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (this->day == 31) {
                this->day = 1;
                month_flag++;
            } else {
                this->day += 1;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (this->day == 30) {
                this->day = 1;
                month_flag++;
            } else {
                this->day += 1;
            }
            break;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                if (this->day == 29) {
                    this->day = 1;
                    month_flag++;
                } else {
                    this->day += 1;
                }
            } else {
                if (this->day == 28) {
                    this->day = 1;
                    month_flag++;
                } else {
                    this->day += 1;
                }
            }
            break;
        default:
            break;
    }

    if (this->month < 12) {
        this->month += month_flag;
    } else {
        this->month = 1;
        year_flag++;
    }

    this->year += year_flag;
}

class ClockWithDate:public Clock,public Date{
public:
    void showTime() override{
        cout<<"Now:"<<hour<<":"<<minute<<":"<<second<<endl;
        cout<<year<<"-"<<month<<"-"<<day<<endl;
    }
    void run() override{
        int now_h=getHour();
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
        if(now_h>getHour()){
            NewDay();
        }
    }
    ClockWithDate(int h,int m,int s,int year,int month,int day): Clock(h,m,s), Date(year,month,day){

    }
};
Clock* Clock::createClockWithDate(int h,int m,int s,int year,int month,int day){
    return new ClockWithDate(h,m,s,year,month,day);
}