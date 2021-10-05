#include "controller.h"
#include <iostream> 

void controller::update(){
    
    const Uint8 *state = v.getState();
    SDL_Rect* barra = v.getBarra();
    SDL_Rect* bolinha = v.getBolinha();
    SDL_PumpEvents();
    int flag = 0;

    //Movimentacao da barra
    if (state[SDL_SCANCODE_LEFT]) {     //Se pressiona o direcional esquerdo, decrementa X
        if(ba->getX()-veloc >= 0)
            ba->setX(ba->getX()-veloc);
    }
    if (state[SDL_SCANCODE_RIGHT]){     //Se pressiona o direcional direito, incrementa X
        if(ba->getX()+ba->getW()+veloc <= v.getWidth())
            ba->setX(ba->getX()+veloc);
    } 
    barra->x = ba->getX(); 

    //Movimentação das Bolinhas
    if(bo->getPause() && bo->getExit()){ 
        if(bo->getX() < bo->getW() || bo->getX() >= v.getWidth()) //Colisão com asa bordas da tela
            dirX = -1*dirX;

        if(bo->getY() < bo->getH())
            dirY = -1*dirY; 
        
        if(colisaoBarra()){
            if(state[SDL_SCANCODE_SPACE]){ //Se a tecla espaco for pressionada, a bolinha pausa no meio da barra
                bo->setPause(false);
                bo->setX(ba->getX()+(ba->getW()/2));
                bo->setY(ba->getY()-20);
            }
            dirY *= -1;
        }

        colisaoBloco(); //Checa a colisao com os blocos e toma as devidas decisoes sobre a movimentacao internamente

        if(bo->getY() >= v.getHeigth()){ //caso a bolinha saia por baixo da tela, reinicia o movimento e diminui uma vida
            bo->setX(ba->getX()+(ba->getW()/2));
            bo->setY(ba->getY()-20);
            dirY = -1*dirY;
            bo->setExit(false);
            vida* vi = v.getVida();
            vi->setValue(vi->getValue()-1);
        }

        bo->setY(bo->getY()+dirY);
        bo->setX(bo->getX()+dirX);
        bolinha->x = bo->getX();
        bolinha->y = bo->getY();
    }else if (!bo->getExit()){
        bo->setX(ba->getX()+(ba->getW()/2));
        bo->setY(ba->getY()-20);
        bolinha->x = bo->getX();
        bolinha->y = bo->getY();
        dirY = 5;
    }else{
        bo->setX(ba->getX()+(ba->getW()/2));
        bo->setY(ba->getY()-20);
        bolinha->x = bo->getX();
        bolinha->y = bo->getY();
        if(!state[SDL_SCANCODE_SPACE]){
            dirY = 5;
            bo->setPause(true);
        }
    }
}

//Os algoritimos de colisao checam duas opcoes:
// - Um objeto esta a esquerda do outro
// - Um objeto esta acima do outro
//Caso ambas as opcoes sejam falsas, houve colisao

bool controller::colisaoBarra(){


    SDL_Rect* bolinha = v.getBolinha();
    SDL_Rect* barra = v.getBarra();
    int l1_x, l1_y, r1_x, r1_y, l2_x, l2_y, r2_x, r2_y;

        
    l1_x = bolinha->x + dirX;
    l1_y = bolinha->y + dirY;
    r1_x = bolinha->x + bolinha->w + dirX;
    r1_y = bolinha->y + bolinha->h + dirY; 
    l2_x = barra->x;
    l2_y = barra->y;
    r2_x = barra->x + barra->w;
    r2_y = barra->y + barra->h;

    // Se um objeto esta a esquerda do outro
    if (l1_x >= r2_x || l2_x >= r1_x){
        return false;
    }
        
    // Se um objeto esta a direita do outrp
    if (r1_y <= l2_y || r2_y <= l1_y){
        return false;
    }
    return true;    
}

bool controller::colisaoBloco(){

    SDL_Rect* bolinha = v.getBolinha();
    tijolo* tijolo = v.getTijolos();
    int l1_x, l1_y, r1_x, r1_y, l2_x, l2_y, r2_x, r2_y;

    for(int i  = 0; i < 100; i++){
        
        if(tijolo[i].getEstado()){
            l1_x = bolinha->x + dirX;
            l1_y = bolinha->y + dirY;
            r1_x = bolinha->x + bolinha->w + dirX;
            r1_y = bolinha->y + bolinha->h + dirY; 


            l2_x = tijolo[i].getX();
            l2_y = tijolo[i].getY();
            r2_x = tijolo[i].getX() + tijolo[i].getW();
            r2_y = tijolo[i].getY() + tijolo[i].getH();

            // Se um objeto esta a esquerda do outro
            if (l1_x >= r2_x || l2_x >= r1_x){
                continue;

            }

            // Se um objeto esta acima do outro
            if (r1_y <= l2_y || r2_y <= l1_y){
                continue;
            }

            //Caso haja colisao, destroi o bloco e atualiza a pontuacao
            pontos* p = v.getPonto();
            tijolo[i].setEstado(false);
            p->setValue(p->getValue()+10);

            //Caso a colisao seja lateral, inverte a movimentacao lateral da bolinha
            if(l1_x < l2_x || r1_x > r2_x){
                dirX *= -1;
                return true;
            }
            dirY *= -1;
            return true;             
        }
    }
       
}

//Se o botao S for pressionado, inicia o jogo
void controller::start(){
    const Uint8 *state = v.getState();
    if (state[SDL_SCANCODE_S]){
        bo->setExit(true);
        bo->setPause(true);
    }    
}

//Se o botao Esc for pressionado, finaliza o jogo
bool controller::finish(){
    const Uint8 *state = v.getState();
    if (state[SDL_SCANCODE_ESCAPE]){
        return true;
    } 
    return false;   
}

