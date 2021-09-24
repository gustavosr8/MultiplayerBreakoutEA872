#include "bolinha.h"

bolinha::bolinha(int x_, int y_){
    x=x_;
    y=y_;
}

int bolinha::getX(){return x;}
int bolinha::getY(){return y;}
int bolinha::getW(){return w;}
int bolinha::getH(){return h;}
void bolinha::setX(int x_){x=x_;}
void bolinha::setY(int y_){y=y_;}