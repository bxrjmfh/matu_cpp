#include <iostream>
#include <math.h>
#include "CString.h"

bool String::IsSubstring(const char *str) {
    string Substr = str;
    string string_main = this->GetStr();
    int flag = 0;
    for (int i = 0; i <= this->len - Substr.size(); i++) {
        for (int j = i; j - i < Substr.size(); j++) {
            if (Substr[j - i] != string_main[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            i = i + Substr.size() - 1;
        }
    }
    if (flag==0){
        return true;
    }else{
        return false;
    }
};
bool String::IsSubstring(const String &str) {
    string Substr = str.mystr;
    string string_main = this->GetStr();
    int flag = 0;
    for (int i = 0; i <= this->len - Substr.size(); i++) {
        for (int j = i; j - i < Substr.size(); j++) {
            if (Substr[j - i] != string_main[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            i = i + Substr.size() - 1;
        }
    }
    if (flag==0){
        return true;
    }else{
        return false;
    }
};
int String::str2num() {
    int out=0;
    string str=this->GetStr();
    for(int i=0;i<this->len;i++){
        if(str[i]>='0'&&str[i]<='9'){
            i=i*10+(int)str[i]-48;
        }
    }
    return out;
}
void String::toUppercase(){
    string str=this->GetStr();
    for(int i=0;i<this->len;i++){
        if(str[i]>='a'&&str[i]<='z'){
            str[i]+=32;
        }
    }
}