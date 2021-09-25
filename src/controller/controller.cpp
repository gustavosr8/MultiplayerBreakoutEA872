#include "controller.h"
#include <iostream> 

void controller::update(){
    const Uint8 *state = v.getState();
    SDL_Rect* barra = v.getBarra();
    SDL_Rect* bolinha = v.getBolinha();
    SDL_PumpEvents();
    if (state[SDL_SCANCODE_LEFT]) ba->setX(ba->getX()-1);
    if (state[SDL_SCANCODE_RIGHT]) ba->setX(ba->getX()+1);
    if (state[SDL_SCANCODE_UP]) ba->setY(ba->getY()-1);
    if (state[SDL_SCANCODE_DOWN]) ba->setY(ba->getY()+1);
    barra->x = ba->getX();
    barra->y = ba->getY();  

    //Movimentação das Bolinhas

    if(bo->getX() <= 20 || bo->getX() >= v.getWidth())
        dirX = -1*dirX;

    if(bo->getY() <= 20 || bo->getY() >= v.getHeigth())
        dirY = -1*dirY; 
    
    if(encontro())
        dirY = -1*dirY;  
    
    bo->setY(bo->getY()+dirY);
    bo->setX(bo->getX()+dirX);

    bolinha->x = bo->getX();
    bolinha->y = bo->getY();


   /*
    if (state[SDL_SCANCODE_A]) bo->setX(bo->getX()-1);
    if (state[SDL_SCANCODE_D]) bo->setX(bo->getX()+1); 
    if (state[SDL_SCANCODE_W]) bo->setY(bo->getY()-1);
    if (state[SDL_SCANCODE_S]) bo->setY(bo->getY()+1);
    bolinha->x = bo->getX();
    bolinha->y = bo->getY();
    */
}

bool controller::encontro()
{   const Uint8 *state = v.getState();
    SDL_Rect* bolinha = v.getBolinha();
    SDL_Rect* barra = v.getBarra();
    tijolo* tijolo = v.getTijolos();
    int l1_x, l1_y, r1_x, r1_y, l2_x, l2_y, r2_x, r2_y;

    //for(int i  = 0; i < 100; i++){
        
        l1_x = bolinha->x;
        l1_y = bolinha->y;
        r1_x = bolinha->x + bolinha->w;
        r1_y = bolinha->y + bolinha->h; 
        l2_x = barra->x;
        l2_y = barra->y;
        r2_x = barra->x + barra->w;
        r2_y = barra->y + barra->h;

        /*l2_x = tijolo[i].getX();
        l2_y = tijolo[i].getY();
        r2_x = tijolo[i].getX() + tijolo[i].getW();
        r2_y = tijolo[i].getY() + tijolo[i].getH();*/
        // To check if either rectangle is actually a line
        // For example :  l1 ={-1,0}  r1={1,1}  l2={0,-1}
        // r2={0,1}
    
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
    //}
    return true;   
}