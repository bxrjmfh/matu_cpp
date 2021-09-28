#include <iostream>
#include <math.h>
#include "CDate.h"

Date::Date(int y, int m, int d) {
    if (m >= 1 && m <= 12) {
        this->month = m;
    } else {
        cout << "Invalid month!"<<endl;
        this->month = 1;
    }
    switch (this->month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (d >= 1 && d <= 31) {
                this->day = d;
            } else {
                cout << "Invalid day!"<<endl;
                this->day = 1;
            }
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            if (d >= 1 && d <= 30) {
                this->day = d;
            } else {
                cout << "Invalid day!";
                this->day = 1;
            }
            break;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                if (d >= 1 && d <= 29) {
                    this->day = d;
                } else {
                    cout << "Invalid day!";
                    this->day = 1;
                }
            } else {
                if (d >= 1 && d <= 28) {
                    this->day = d;
                } else {
                    cout << "Invalid day!";
                    this->day = 1;
                }
            }
            break;
        default:
            break;
    }
    this->year=y;
}

int Date::days(int year, int month) {
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
            break;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                return 29;
            } else {
                return 28;
            }
            break;
        default:
            break;
    }
}

void Date::NewDay() {
    int month_flag = 0;
    int year_flag = 0;

    switch (this->month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (this->day == 31) {
                this->day = 1;
                month_flag++;
            } else {
                this->day += 1;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (this->day == 30) {
                this->day = 1;
                month_flag++;
            } else {
                this->day += 1;
            }
            break;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                if (this->day == 29) {
                    this->day = 1;
                    month_flag++;
                } else {
                    this->day += 1;
                }
            } else {
                if (this->day == 28) {
                    this->day = 1;
                    month_flag++;
                } else {
                    this->day += 1;
                }
            }
            break;
        default:
            break;
    }

    if (this->month < 12) {
        this->month += month_flag;
    } else {
        this->month = 1;
        year_flag++;
    }

    this->year += year_flag;
}