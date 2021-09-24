#include "barra.h"

barra::barra(int x_, int y_){
    x=x_;
    y=y_;
}

int barra::getX(){return x;}
int barra::getY(){return y;}
int barra::getW(){return w;}
int barra::getH(){return h;}
void barra::setX(int x_){x=x_;}
void barra::setY(int y_){y=y_;}