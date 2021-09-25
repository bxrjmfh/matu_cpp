#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include <cstring>
#include <algorithm>


using namespace std;
string sminus(string s1, string s2) {
    string out;
    //    s1-s2
    //   判断是不是需要交换
    int alremain = 0;
    int max = 0;
    if(s1==s2){return "0";}

    if (s2.size() > s1.size() ||
    (s1.size() == s2.size() && s2[0] > s1[0])) {
        s1.swap(s2);
        alremain = 1;
    }
    max = s1.size();
    int remain = 0;

    for (int i = s1.size()-1, j = s2.size()-1; i >= 0 && j >= 0; i--, j--) {
        if (s1[i] < (s2[j] + remain)) {
            out.push_back(s1[i] +10- (s2[j] + remain) + 48);
            remain = 1;
        }
        else {
            out.push_back(s1[i] - s2[j] - remain + 48);
            remain = 0;
        }
        s1.erase(s1.size()-1,1);
        s2.erase(s2.size()-1,1);
    }
    if (!s1.empty() && s2.empty())
    {//被减数为空
        while (!s1.empty()) {
            if (s1[s1.size() - 1] == 48) {
                out.push_back('9');
                remain = 1;
            }
            else {
                out.push_back(s1[s1.size() - 1]-remain);
                remain = 0;
            }
            s1.erase(s1.size()-1,1);
        }
    }
    while (out.size() < max) {
        out.push_back('0');
    }
    if (alremain == 1) {
        out.push_back('-');
    }
    else {
        out.push_back('+');
    }

    reverse(out.begin(), out.end());
    return out;
}
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << sminus(s1, s2);
}