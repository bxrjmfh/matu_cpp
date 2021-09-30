#include "Building.h"
class TeachBuilding :public Building{
    char function[20];
public:
    virtual void display(){
        cout<<"Name:"<<name<<endl;
        cout<<"Floor:"<<floor<<endl;
        cout<<"Room:"<<room<<endl;
        cout<<"Area:"<<area<<endl;
        cout<<"Function:"<<function<<endl;
    }
    TeachBuilding(char *name,int floor,int room,int area,char *function):
                Building(name,floor,room,area){
        strcpy(this->function,function);
    }
};
class DormBuilding :public Building{
    int peoples;
public:
    virtual void display(){
        cout<<"Name:"<<name<<endl;
        cout<<"Floor:"<<floor<<endl;
        cout<<"Room:"<<room<<endl;
        cout<<"Area:"<<area<<endl;
        cout<<"Peoples:"<<peoples<<endl;
    }
    DormBuilding(char *name,int floor,int room,int area,int peoples):
    Building(name,floor,room,area){
        this->peoples=peoples;
    }
};
Building* Building::createTeachBuilding(char *name,int floor,int room,int area,char *function){
    return  new TeachBuilding(name,floor,room,area,function);
}
Building * Building::creatDormBuilding(char *name,int floor,int room,int area,int peoples){
    return new DormBuilding(name,floor,room,area,peoples);
}