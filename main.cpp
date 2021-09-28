
#include "Clock.h"

Clock::Clock(int h,int m, int s){
    if(h>=0&&h<=23){
        this->hour=h;
    }else{
        this->hour=0;
    }
    if(m>=0&&m<=59){
        this->minute=m;
    }else{
        this->minute=0;
    }
    if(s>=0&&s<=59){
        this->second=s;
    }else{
        this->second=0;
    }
}
void Clock::SetAlarm(int h,int m, int s){
    if(h<=23){
        this->Ahour=h;
    }else{
        this->Ahour=0;
    }
    if(m<=59){
        this->Aminute=m;
    }else{
        this->Aminute=0;
    }
    if(s<=59){
        this->Asecond=s;
    }else{
        this->Asecond=0;
    }
}

void Clock::run(){
    this->second+=1;
    if(this->second==60){
        this->second=0;
        if(this->minute==59){
            this->minute=0;
            if(this->hour==23){
                this->hour=0;
            }else{
                this->hour+=1;
            }
        }else{
            this->minute+=1;
        }
    }

    if(this->hour==this->Ahour&&
    this->minute==this->Aminute&&
    this->second==this->Asecond){
        cout<<"Plink!plink!plink!..."<<endl;
    }
}