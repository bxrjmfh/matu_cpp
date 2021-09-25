#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>


using namespace std;
int find_step(double precision){
    int i=1;
    while((double)1/i>precision){
        i=2*i-1;
    }
    return i;
}
double find_pi(int step){
    if(step==1){
        return 4.0;
    }
    else{
        return ((step%2)*2-1)*(1/step)+ find_pi(step-1);
    }
}
int main() {
    double steps=find_step(1.0e-8);
    double pi = find_pi(steps);
    cout<<"steps="<<steps<<" PI=";
    printf("%.5f",pi);
}