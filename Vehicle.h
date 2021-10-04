//
// Created by Dell on 2021/10/4.
//

#ifndef CPP_VEHICLE_H
#define CPP_VEHICLE_H

#endif //CPP_VEHICLE_H

#include <iostream>
using namespace std;
class Vehicle{
public:
    Vehicle(){
        cout<<"Vehicle constructor..."<<endl;
    }
    ~Vehicle(){
        cout<<"Vehicle destructor..."<<endl;
    }
    virtual void display() const =0;
    static Vehicle * createCar();
    static Vehicle * createTruck();
    static Vehicle * createBoat();
};