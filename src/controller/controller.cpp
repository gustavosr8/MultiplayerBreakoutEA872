#include "controller.h"
#include <iostream> 

void controller::update(){
    const Uint8 *state = v.getState();
    SDL_Rect* barra = v.getBarra();
    SDL_Rect* bolinha = v.getBolinha();
    SDL_PumpEvents();
    int flag = 0;
    if (state[SDL_SCANCODE_LEFT]) {
        if(ba->getX()-veloc >= 0)
            ba->setX(ba->getX()-veloc);
    }
    if (state[SDL_SCANCODE_RIGHT]){
        if(ba->getX()+ba->getW()+veloc <= v.getWidth())
            ba->setX(ba->getX()+veloc);
    } 
    barra->x = ba->getX(); 

    //Movimentação das Bolinhas
    if(bo->getPause() && bo->getExit()){ 
        if(bo->getX() < bo->getW() || bo->getX() >= v.getWidth())
            dirX = -1*dirX;

        if(bo->getY() < bo->getH())
            dirY = -1*dirY; 
        
        if(colisaoBarra()){
            if(state[SDL_SCANCODE_SPACE]){
                bo->setPause(false);
                bo->setX(ba->getX()+(ba->getW()/2));
                bo->setY(ba->getY()-20);
            }
            dirY *= -1;
        }

        colisaoBloco();

        if(bo->getY() >= v.getHeigth()){
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
    
   /*
    if (state[SDL_SCANCODE_A]) bo->setX(bo->getX()-1);
    if (state[SDL_SCANCODE_D]) bo->setX(bo->getX()+1); 
    if (state[SDL_SCANCODE_W]) bo->setY(bo->getY()-1);
    if (state[SDL_SCANCODE_S]) bo->setY(bo->getY()+1);
    bolinha->x = bo->getX();
    bolinha->y = bo->getY();
    */
}

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

    if (l1_x == r1_x || l1_y == r1_y || l2_x == r2_x
        || l2_y == r2_y) {
        // the line cannot have positive overlap
        return false;
    }

    // If one rectangle is on left side of other
    if (l1_x >= r2_x || l2_x >= r1_x){
        return false;
    }
        
    // If one rectangle is above other
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
            //l2_x = barra->x;
            //l2_y = barra->y;
            //r2_x = barra->x + barra->w;
            //r2_y = barra->y + barra->h;

            l2_x = tijolo[i].getX();
            l2_y = tijolo[i].getY();
            r2_x = tijolo[i].getX() + tijolo[i].getW();
            r2_y = tijolo[i].getY() + tijolo[i].getH();
            // To check if either rectangle is actually a line
            // For example :  l1 ={-1,0}  r1={1,1}  l2={0,-1}
            // r2={0,1}

            if (l1_x == r1_x || l1_y == r1_y || l2_x == r2_x
                || l2_y == r2_y) {
                // the line cannot have positive overlap
                continue;
            }

            // If one rectangle is on left side of other
            if (l1_x >= r2_x || l2_x >= r1_x){
                continue;

            }

            // If one rectangle is above other
            if (r1_y <= l2_y || r2_y <= l1_y){
                continue;
            }

            if(l1_x < l2_x || r1_x > r2_x){
                dirX *= -1;
                pontos* p = v.getPonto();
                p->setValue(p->getValue()+10);
                tijolo[i].setEstado(false);
                return true;
            }
            dirY *= -1;
            tijolo[i].setEstado(false);
            pontos* p = v.getPonto();
            p->setValue(p->getValue()+10);
            return true;             
        }
    }
       
}
void controller::start(){
    const Uint8 *state = v.getState();
    if (state[SDL_SCANCODE_S]){
        bo->setExit(true);
        bo->setPause(true);
    }    
}


