#include"Vehicle.h"

class Car:public Vehicle{
    ~Car(){
        cout<<"Car destructor..."<<endl;
    }
    void display() const override{
        cout<<"This is a car!"<<endl;
    }

public:
    Car(){
        cout<<"Car constructor..."<<endl;
    }
};

class Truck:public Vehicle{
    ~Truck(){
        cout<<"Truck destructor..."<<endl;
    }
    void display() const override{
        cout<<"This is a truck!"<<endl;
    }

public:
    Truck(){
        cout<<"Truck constructor..."<<endl;
    }
};

class Boat:public Vehicle{
    ~Boat(){
        cout<<"Boat destructor..."<<endl;
    }
    void display() const override{
        cout<<"This is a boat!"<<endl;
    }

public:
    Boat(){
        cout<<"Boat constructor..."<<endl;
    }
};
Vehicle * Vehicle::createCar(){return new Car();}
Vehicle * Vehicle::createTruck(){return new Truck();}
Vehicle * Vehicle::createBoat(){return new Boat();}