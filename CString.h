//
// Created by Dell on 2021/9/28.
//

#ifndef CPP_CSTRING_H
#define CPP_CSTRING_H

#endif //CPP_CSTRING_H
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
class String{
private:
    char *mystr;    //字符串
    int len;    //字符串长度
public:
    String(){
        len =0;
        mystr =NULL;
        if (mystr != NULL)
        {
            delete []mystr;
            mystr =NULL;
            len = 0;
        }
    }
    String(const char* p){
        len = strlen(p);
        mystr = new char[len+1];
        strcpy(mystr,p);
    }
    String(String &s){
        len = s.len;
        if (len !=0)
        {
            mystr = new char[len+1];
            strcpy(mystr,s.mystr);
        }
    }

    char *GetStr(){return mystr;}
    void ShowStr(){cout<<mystr;}

    bool IsSubstring(const char *str);
    bool IsSubstring(const String &str);
    int str2num();
    void toUppercase();
};