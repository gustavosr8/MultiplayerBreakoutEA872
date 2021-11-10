#include "pontos.h"

pontos::pontos(int value_){
    value=value_;
}

pontos::pontos(){
    value=0;
}

int pontos::getValue(){return value;}
void pontos::setValue(int value_){value=value_;}
float pontos::getHmult(){return h_mult;}
float pontos::getWmult(){return w_mult;}
int  pontos::getX(){return x;}
int  pontos::getY(){return y;}
