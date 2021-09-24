#include "model.h"
#include "view.h"
#include "controller.h"
#include "tijolo.h"
#include "bolinha.h"
#include "barra.h"

int main(){
    //Adicionando Tijolo
    tijolo* t = (tijolo * ) malloc (100* sizeof(tijolo)); 
    int k = 0;
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 5; j++){
            t[k]= tijolo((((i)*270)+20), (((j)*90)+20));
            k++;
        }
    }

    bolinha bol = bolinha(960,540);
    barra bar = barra(960, 570);

    model m = model(0,0);
    view v = view(m, t, &bar, &bol);
    v.init();
    controller c = controller(v, &bar, &bol);

    bool rodando = true;
    SDL_Event evento;

    while(rodando){
        c.update();

        while(SDL_PollEvent(&evento)){
            if(evento.type == SDL_QUIT){
                rodando = false;
            }
        }
        v.render();
    }
    v.quit();
    
    return 0;
}