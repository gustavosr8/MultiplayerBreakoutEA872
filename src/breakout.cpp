#include "view.h"
#include "controller.h"
#include "tijolo.h"
#include "bolinha.h"
#include "barra.h"
#include "pontos.h"
#include "vida.h"
#include <vector>
#include <iostream>


int main(){
    //Adicionando Tijolo
    tijolo* t = (tijolo * ) malloc (100* sizeof(tijolo)); 
    //Flag quando acaba as vidas
    bool perdeu = true;
    int k = 0;

    for(int i = 0; i < 7; i++){
        for(int j = 1; j < 6; j++){
            t[k]= tijolo((((i))), (((j))));
            k++;
        }
    }
    
    bolinha bol = bolinha(8, 7);
    barra bar = barra(8, 8);
    pontos p = pontos(0);
    vida l = vida(4);

    view v = view(t, &bar, &bol, &p, &l);
    v.init();
    controller c = controller(v, &bar, &bol);

    bool rodando = true;
    SDL_Event evento;

    while(rodando){
        c.start();
        if(l.getValue() > 0 && v.quantidadeTijolos() > 0){ 
                c.update();
                v.render();
        }else if(v.quantidadeTijolos() < 1){
            v.ganhou();
        }else{
            v.perdeu();
        }
        while(SDL_PollEvent(&evento)){
            if(evento.type == SDL_QUIT){
                rodando = false;
            }
        }

        if(c.finish()){
            rodando = false;
        }
    }
    v.quit();
    
    return 0;
}