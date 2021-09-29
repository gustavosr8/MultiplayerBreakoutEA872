#include "tijolo.h"

tijolo::tijolo(int x_, int y_){
    x=x_;
    y=y_;
}

int  tijolo::getX(){return x;}
int  tijolo::getY(){return y;}
int  tijolo::getW(){return w;}
int  tijolo::getH(){return h;}
bool tijolo::getEstado(){return estado;}
float tijolo::getHmult(){return h_mult;}
float tijolo::getWmult(){return w_mult;}
void tijolo::setW(int w_){w=w_;}
void tijolo::setH(int h_){h=h_;}
void tijolo::setX(int x_){x=x_;}
void tijolo::setY(int y_){y=y_;}
void tijolo::setEstado(bool e){estado = e;}