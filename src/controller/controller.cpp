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

    //Movimentação da Bolinhas
    if(bo->getY() <= 0)
        dir = 5; 
    if (bo->getY() >= v.getHeigth())
        dir = -5;

    if(encontro())
        bo->setY(bo->getY()); 
    else
        bo->setY(bo->getY()+dir); 

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
        l1_y = bolinha->y+dir;
        r1_x = bolinha->x + bolinha->w;
        r1_y = bolinha->y + bolinha->h;; 
        l2_x = barra->x;
        l2_y = barra->y;
        r2_x = barra->x + barra->w;
        r2_y = barra->y + barra->h;;

        /*l2_x = tijolo[i].getX();
        l2_y = tijolo[i].getY();
        r2_x = tijolo[i].getX() + tijolo[i].getW();
        r2_y = tijolo[i].getY() + tijolo[i].getH();*/
        // To check if either rectangle is actually a line
        // For example :  l1 ={-1,0}  r1={1,1}  l2={0,-1}
        // r2={0,1}
    
        if (l1_x == r1_x || l1_y == r1_y || l2_x == r2_x
            || l2_y == r2_y) {
            std::cout << "Caso 1\n";
            // the line cannot have positive overlap
            return false;
        }
    
        // If one rectangle is on left side of other
        if (l1_x >= r2_x || l2_x >= r1_x){
            std::cout << "Caso 2\n";
            return false;
    
        }
            
        // If one rectangle is above other
        if (r1_y >= l2_y || r2_y >= l1_y){
            std::cout << "Caso 3\n";
            return false;
        }
    //}
    std::cout << "Caso 4\n";
    return true;   
}