#include "../include/view.h"
#include "../include/controller.h"
#include "../include/tijolo.h"
#include "../include/bolinha.h"
#include "../include/barra.h"
#include "../include/pontos.h"
#include "../include/vida.h"
#include "../include/container.h"
#include "../include/json.hpp"
#include <iostream>
#include <fstream>
#include <vector>

using nlohmann::json;

int main(){
    
    //Inicializa os objetos da aplicação
    
    //Tijolos
    std::vector<tijolo> t;
    
    for(int i = 0; i < 7; i++){
        for(int j = 1; j < 6; j++){
            tijolo NewTijolo(i, j);
            t.push_back(NewTijolo);
        }
    }
    
    bolinha bol = bolinha(8, 7);
    barra bar = barra(8, 8);
    pontos p = pontos(0);
    vida l = vida();
    l.setValue(4);
    view v = view(t, &bar, &bol, &p, &l);
    v.init();
    controller c = controller(v, &bar, &bol);

    bool rodando = true;
    SDL_Event evento;

    container cntr;
    cntr.v = l;
    cntr.ba = bar;
    cntr.bo = bol;
    cntr.p = p;
    cntr.t = t;

    json j;
    j["Container"] = cntr;
    std::ofstream f;
    f.open("teste.json");
    f << j;
    f.close();

    //Ciclo de atualização e renderização
    while(rodando){
        c.start();
        if(c.save()){
            cntr.v = l;
            cntr.ba = bar;
            cntr.bo = bol;
            cntr.p = p;
            cntr.t = t;
            j["Container"] = cntr;
            std::ofstream f;
            f.open("teste.json");
            f << j;
            f.close();
        }
        if(c.load()){
            std::ifstream f;
            f.open("teste.json");
            f >> j;
            f.close();
            cntr = j["Container"];
            l = cntr.v;
            bar = cntr.ba;
            bol.setX(cntr.ba.getX()+cntr.ba.getW()/2);
            bol.setY(cntr.ba.getY()-cntr.bo.getH());
            p = cntr.p;
            t = cntr.t;
        }
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