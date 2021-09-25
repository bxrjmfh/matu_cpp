#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include <cstring>


using namespace std;

int main(){
    string s1,s2;
    cin>>s1;
    for(int i=0;i<s1.size();i++){
        s2.push_back(s1[i]);
    }
    s2.push_back('\\');
    s2.push_back('0');
    cout<<s2;
}