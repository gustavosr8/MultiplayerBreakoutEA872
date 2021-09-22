#include "model.h"
#include "view.h"
#include "controller.h"
#include "tijolo.h"

int main(){
    tijolo t = tijolo(0,0);
    model m = model(0,0);
    view v = view(m, &t);
    v.init();
    controller c = controller(v,m);

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