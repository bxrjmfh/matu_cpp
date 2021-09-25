#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include <cstring>


using namespace std;
void Matrix_Mul(int a[3][2], int b[2][4]){
    for(int j=0;j<3;j++){
        for(int i=0;i<4;i++){
            cout<<a[j][0]*b[0][i]+a[j][1]*b[1][i]<<" ";
        }
        cout<<endl;
    }

}
int main(){
    int a[3][2] ={{1,2}, {3,4},  {5,6}},   b[2][4]={{1,0,1,1},{0,1,0,1}};
    Matrix_Mul(a,b);


}