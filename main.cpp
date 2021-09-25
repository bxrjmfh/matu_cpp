#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>


using namespace std;

int main() {
    int yy;
    int MM;
    bool is_= false;
    cin>>yy>>MM;
    if(yy%400==0||(yy%4==0&&yy%100!=0)){is_=true;}
    if(MM>12){MM%=12;}
    switch (MM) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            cout<<"days:31";
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            cout<<"days:30";
            break;

        case 2:
            if(is_){
                cout<<"days:29";
            }else{
                cout<<"days:28";
            }
            break;
        default:
            ;
    }
}