#include <iostream>
#include "CSet.h"
#include <vector>

using namespace std;

Set& Set::operator+=(int e) {

    int flag = 0;
    for (int i = 1; i <= this->n; i++) {
        if (this->pS[i] == e) {
            flag += 1;
            break;
        }
    }
    if (flag == 0) {
        int* temp_pS = new int[this->n + 2];
        for (int i = 1; i <= this->n; i++) {
            temp_pS[i] = this->pS[i];
        }
        temp_pS[n + 1] = e;
        this->n = this->n + 1;
        this->pS = temp_pS;
    }

    return *this;

}

Set& Set::operator-=(int e) {
    int flag = 0;
    if (this->n == 0) {
        return *this;
    }
    for (int i = 1; i <= this->n; i++) {
        if (this->pS[i] == e) {
            flag += 1;
            break;
        }
    }
    if (flag == 1) {
        int* temp = new int[n];
        int j = 1;
        for (int i = 1; i <= this->n; i++) {
            if (this->pS[i] != e) {
                temp[j++] = this->pS[i];
            }
        }
        this->n -= 1;
        this->pS = temp;
    }

    return *this;
}

bool Set::operator<=(const Set& s) const {
    if (s.n < this->n) {
        return false;
    }
    else if (this->n == 0) {
        return true;
    }
    else {
        int flag = 0;
        bool status = false;
        for (int i = 1; i <= this->n; i++) {
            for (int j = 1; j <= s.n; j++) {
                if (this->pS[i] == s.pS[j]) {
                    flag = 1;
                }
            }
            if (flag == 0) {
                status = false;
                break;
            }
            else {
                flag = 0;
                status = true;
            }
        } //集合的下标从1开始，集合中不能有重复元素
        return status;
    }
}

bool Set::operator==(const Set& s) const {
    if (s.n != this->n) {
        return false;
    }
    else if (s.n == 0) {
        return true;
    }
    else {
        int flag = 0;
        bool status = false;
        for (int i = 1; i <= this->n; i++) {
            for (int j = 1; j <= s.n; j++) {
                if (this->pS[i] == s.pS[j]) {
                    flag = 1;
                }
            }
            if (flag == 0) {
                status = false;
                break;
            }
            else {
                flag = 0;
                status = true;
            }
        } //集合的下标从1开始，集合中不能有重复元素
        return status;
    }
}

Set Set::operator|(const Set& s) const {
    Set ret;
    if (s == *this || *this <= s) {
        for (int i = 1; i <= s.n; i++) {
            ret += s.pS[i];
        }

    }
    else {
        for (int i = 1; i <= this->n; i++) {
            ret += this->pS[i];
        }
        for (int i = 1; i <= s.n; i++) {
            ret += s.pS[i];
        }

    }
    return ret;
}

Set Set::operator&(const Set& s) const {
    Set ret;
    if (*this <= s) {
        for (int i = 1; i <= this->n; i++) {
            ret += this->pS[i];
        }
        return ret;
    }
    else {
        for (int i = 1; i <= this->n; i++) {
            for (int j = 1; j <= s.n; j++) {
                if (this->pS[i] == s.pS[j]) {
                    ret += this->pS[i];
                }
            }
        } //集合的下标从1开始，集合中不能有重复元素
    }
    return ret;
}

Set Set::operator-(const Set& s) const {
    Set ret;
    vector<int> temp;
    for (int i = 1; i <= this->n; i++) {
        ret += this->pS[i];
    } //集合的下标从1开始，集合中不能有重复元素
    for (int i = 1; i <= s.n; i++) {
        ret -= s.pS[i];
    }
    return ret;
}

int main() {
    Set s1 ,s2;
    s1 += 1; s1 += 3; s2 += 2; s2 += 1;
    ;//{3}
    (s1 - s2).ShowElement();
}