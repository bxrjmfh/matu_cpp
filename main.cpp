#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include <cstring>


using namespace std;
int SubStrNum(char* str, char* substr) {
    string Str = str;
    string Substr = substr;
    int counter = 0;
    for (int i = 0; i <= Str.size() - Substr.size(); i++) {
        int flag = 0;
        for (int j = i; j-i < Substr.size(); j++) {
            if (Substr[j - i] != Str[j]) {
                flag = 1;

                break;
            }
        }
        if (flag == 0) {
            counter++;
            i = i + Substr.size()-1;
        }
    }
    cout << "match times=" << counter;
    return counter;
}
int main() {
    char s1[] = "sadasadsadsasdssdasd";
    char s2[] = "da";
    int p= SubStrNum(s1,s2 );
}