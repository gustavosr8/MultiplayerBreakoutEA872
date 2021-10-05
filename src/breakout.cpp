#include "../include/view.h"
#include "../include/controller.h"
#include "../include/tijolo.h"
#include "../include/bolinha.h"
#include "../include/barra.h"
#include "../include/pontos.h"
#include "../include/vida.h"
#include <iostream>
#include <vector>


int main(){
    
    //Inicializa os objetos da aplicação
    
    //Tijolos
    std::vector<tijolo> t;
    
    int k = 0;
    for(int i = 0; i < 7; i++){
        for(int j = 1; j < 6; j++){
            tijolo NewTijolo(i, j);
            t.push_back(NewTijolo);
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

    //Ciclo de atualização e renderização
    while(rodando){
        c.start();
        if(l.getValue() > 0 && t.size() > 0){ 
                c.update();
                v.render();
        }else if(t.size() < 1){
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