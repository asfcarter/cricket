#include <cstring>
#include "fielder.h"

void Fielder::set_position(int x1,int y1){
x=x1;
y=y1;
}

void Fielder::set_x(int x1){
x=x1;
}

void Fielder::set_y(int y1){
y=y1;
}

int Fielder::get_x() const{
return x;
}

int Fielder::get_y() const{
return y;
}

Fielder & Fielder::operator=(const Fielder &f){
x=f.x;
y=f.y;
return *this;
}


