#include "vida.h"

vida::vida(int value_){
    value=value_;
}

vida::vida(){
    value=0;
}
int vida::getValue(){return value;}
void vida::setValue(int value_){value=value_;}
float vida::getHmult(){return h_mult;}
float vida::getWmult(){return w_mult;}
int  vida::getX(){return x;}
int  vida::getY(){return y;}