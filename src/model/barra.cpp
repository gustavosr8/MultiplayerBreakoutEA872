#include "barra.h"

barra::barra(int x_, int y_){
    x=x_;
    y=y_;
}

int barra::getX(){return x;}
int barra::getY(){return y;}
int barra::getW(){return w;}
int barra::getH(){return h;}
float barra::getHmult(){return h_mult;}
float barra::getWmult(){return w_mult;}
void barra::setW(int w_){w=w_;}
void barra::setH(int h_){h=h_;}
void barra::setX(int x_){x=x_;}
void barra::setY(int y_){y=y_;}
