#include "CNumberFactory.h"
class CNumber :public CNumberFactory{
private:
    int num;
public:
    CNumber(){
        this->num=0;
    }
    void SetValue(int number){
        this->num=number;
    }
    int GetValue(void){
       return this->num;
    }
    virtual void Add(int number) override{
        this->num+=number;
    }
    virtual void Sub(int number) override{
        this->num-=number;
    }
};
CNumberFactory *CNumberFactory::Create()
{
    return new CNumber();
}