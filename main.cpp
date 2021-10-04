#include"Location.h"

Location& Location::operator+(Location &offset) {

    x+=offset.x;
    y+=offset.y;
    return *this;
}
Location& Location::operator-(Location &offset) {

    x-=offset.x;
    y-=offset.y;
    return *this;
}