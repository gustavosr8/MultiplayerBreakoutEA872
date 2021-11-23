#include "tijolo.h"

tijolo::tijolo(int x_, int y_){
    x=x_;
    y=y_;
}

tijolo::tijolo(){
    x=0;
    y=0;
}

int  tijolo::getX(){return x;}
int  tijolo::getY(){return y;}
int  tijolo::getW(){return w;}
int  tijolo::getH(){return h;}
float tijolo::getHmult(){return h_mult;}
float tijolo::getWmult(){return w_mult;}
float tijolo::getXparam(){return x_param;}
float tijolo::getYparam(){return y_param;}
void tijolo::setXparam(float x_param_){x_param=x_param_;}
void tijolo::setYparam(float y_param_){y_param=y_param_;}
void tijolo::setW(int w_){w=w_;}
void tijolo::setH(int h_){h=h_;}
void tijolo::setX(int x_){x=x_;}
void tijolo::setY(int y_){y=y_;}
