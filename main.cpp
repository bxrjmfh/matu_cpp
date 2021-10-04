#include <iostream>
#include "CString.h"
#include <string>

using namespace std;

int EditString::IsSubString(int start, const char* str) {
    string Substr = str;
    string string_main = this->GetStr();
    if (start > len - Substr.size()) {
        return -1;
    }
    else {
        int flag = 0;
        for (int i = start ; i <= this->len - Substr.size()+1; i++) {
            flag = 0;
            for (int j = i; j - i < Substr.size(); j++) {
                if (Substr[j - i] != string_main[j]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                return i;
            }
        }

        if (flag != 0) {
            return -1;
        }
    }
}

void EditString::EditChar(char s, char d) {
    for (int i = 0; i < len; i++) {
        if (mystr[i] == s) {
            mystr[i] = d;
        }
    }
}

void EditString::EditSub(char* subs, char* subd) {
    string change_to = subd;
    string to_change = subs;
    string final_str;

    int location = 0;
    while (location<len) {
        int temp = IsSubString(location, subs);
        if (temp >= 0) {
            for (int i = location; i < temp; i++) {
                final_str.push_back(mystr[i]);
            }
            for (int i = 0; i < change_to.size(); i++) {
                final_str.push_back(change_to[i]);
            }
            location = temp+to_change.size();
        }
        else {
            final_str.push_back(mystr[location]);
            location++;
        }
    }
    this->len =final_str.size();
    char* tep_char = new char[len+1];
    final_str.copy(tep_char, len);
    tep_char[len] = '\0';
    this->mystr = tep_char;
    return;
}

void EditString::DeleteChar(char ch) {
    string temp;
    int counter = 0;
    for (int i = 0; i < len; i++) {
        if (mystr[i] == ch) {
            counter++;
            continue;
        }
        temp.push_back(mystr[i]);
    }
    this->len -= counter;
    char* tep_char = new char[len+1];
    temp.copy(tep_char, len);
    tep_char[len] = '\0';
    this->mystr = tep_char;
}

void EditString::DeleteSub(char* sub) {
    string to_del = sub;
    string final_str;

    int location = 0;
    while (location < len) {
        int temp = IsSubString(location, sub);
        if (temp >= 0) {
            for (int i = location ; i < temp; i++) {
                final_str.push_back(mystr[i]);
            }
            location = temp + to_del.size();
        }
        else {
            final_str.push_back(mystr[location]);
            location++;
        }
    }
    this->len = final_str.size();
    char* tep_char = new char[len + 1];
    final_str.copy(tep_char, len);
    tep_char[len] = '\0';
    this->mystr = tep_char;
    return;
}

int main() {

    EditString es("testtesttest");

    es.DeleteSub("es");
    es.showStr();
}