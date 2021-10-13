#include "pontos.h"

pontos::pontos(int value_){
    value=value_;
}

pontos::pontos(){
    value=0;
}

int pontos::getValue(){return value;}
void pontos::setValue(int value_){value=value_;}
