//
// Created by liaohui on 2021/11/18.
//

#include "CString.h"
#include <cmath>
//判定字符串str是否为当前String对象的子串，是则返回true,否则返回false。
bool String::IsSubstring(const char *str) {
    //空字符串
    if(str[0] == 0)
    {
        return true;
    }
    else{
        for(int i=0;mystr[i];i++){
            int k=i,j=0;
            // k表示s1当前遍历的位置，j表示s2当前遍历的位置
            for(;str[j];++k,++j){
                // 一旦有不相同，跳出循环
                if(mystr[k]!=str[j]){
                    break;
                }
            }
            // 如果已经遍历完了s2才跳出的循环
            if( str[j]==0){
                // 返回最开始的s1的起始位置
                return i;
            }
        }
        return -1;
    }
}
// 判断String对象str是否为当前String对象的子串，是则返回true,否则返回false。
bool String::IsSubstring(const String &str) {
    return this->IsSubstring(str.mystr);
}
//将当前String对象转化为数字，转换时忽略出数字以外的字符，
int String::str2num() {
    if(mystr == NULL)
    {
        return -1;
    }
    char* newstr;
    int len2 = 0;
    for(int i = 0;i<len;i++)
    {
        if(mystr[i]>= 0 && mystr[i]<=9)
        {
            newstr[len2++] = mystr[i];
        }
    }
    int sum = 0;
    for(int j = 0;j<len2;j++)
    {
        sum+=pow((double)newstr[j],len2-1-j);
    }
    return sum;
}
//将String的字符串的字母全部转化为大写字母。
void String::toUppercase() {
    for(int i = 0;i<len;i++)
    {
        if(mystr[i]>=97&&mystr[i]<=122)
        {
            mystr[i]-=32;
        }
    }
}
