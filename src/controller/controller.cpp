#include "../../include/controller.h"
#include <iostream> 

void controller::update(){
    std::vector<barra> &barra_ = v.getBarras();
    bool space_on = false;
    for(int i=0; i < barra_.size(); i++){
        if(keyb[i].Space())
            space_on = true;
    }

    for(int i=0; i < barra_.size(); i++){
        updateMovimento(&barra_[i], keyb[i], space_on);
    }
}

void controller::updateMovimento(barra* ba, teclado keyb, bool space_on){
    std::vector<std::vector<tijolo> >&tijolo_ = v.getTijolos();
    //SDL_Rect* barra = v.getBarra();
    SDL_Rect* bolinha = v.getBolinha();
    SDL_PumpEvents();
    int flag = 0;

    //Movimentacao da barra
    if (keyb.Left()) {     //Se pressiona o direcional esquerdo, decrementa X
        if(ba->getX()-veloc >= 0 && ba->getX()-veloc >= ba->getLeftLim())
            ba->setX(ba->getX()-veloc);
            
    }
    if (keyb.Rigth()){     //Se pressiona o direcional direito, incrementa X
        if(ba->getX()+ba->getW()+veloc <= v.getWidth() && ba->getX()+ba->getW()+veloc <= ba->getRightLim())
            ba->setX(ba->getX()+veloc);
    } 
    //barra->x = ba->getX(); 

    //Movimentação das Bolinhas
    if(bo->getPause() && bo->getExit()){ 
        if(bo->getX() < bo->getW() || bo->getX() >= v.getWidth()) //Colisão com asa bordas da tela
            bo->setDirX(-1*bo->getDirX());

        if(bo->getY() < bo->getH())
            bo->setDirY(-1*bo->getDirY());
        
        if(ba->isVisible() && colisaoBarra(ba)){
            if(keyb.Space()){ //Se a tecla espaco for pressionada, a bolinha pausa no meio da barra
                bo->setPause(false);
                bo->setX(ba->getX()+(ba->getW()/2));
                bo->setY(ba->getY()-bo->getH());
            }
            else{bo->setDirY(-1*bo->getDirY());}
        }

        colisaoBloco(); //Checa a colisao com os blocos de tijolo e toma as devidas decisoes sobre a movimentacao internamente

        if(bo->getY() >= v.getHeigth()){ //caso a bolinha saia por baixo da tela, reinicia o movimento e diminui uma vida
            if(tijolo_.size() == 1){
                bo->setX(ba->getX()+(ba->getW()/2));
                bo->setY(ba->getY()-20);
                bo->setExit(false);
                vida* vi = v.getVida();
                vi->setValue(vi->getValue()-1);
            } 
            bo->setDirY(-1*bo->getDirY());   
        }

        bo->setY(bo->getY()+bo->getDirY());
        bo->setX(bo->getX()+bo->getDirX());
        bolinha->x = bo->getX();
        bolinha->y = bo->getY();
    }else if (!bo->getExit()){
        bo->setX(ba->getX()+(ba->getW()/2));
        bo->setY(ba->getY()-bo->getH());
        bo->setDirY(5);
        bo->setDirX(5);
        bolinha->x = bo->getX();
        bolinha->y = bo->getY();
    }else{
        if(keyb.Space()){
            bo->setX(ba->getX()+(ba->getW()/2));
            bo->setY(ba->getY()-bo->getH());
            bolinha->x = bo->getX();
            bolinha->y = bo->getY();
        }    
        else{
            bo->setDirY(5);
            bo->setPause(true);
        }
    }
}

//Os algoritimos de colisao checam duas opcoes:
// - Um objeto esta a esquerda do outro
// - Um objeto esta acima do outro
//Caso ambas as opcoes sejam falsas, houve colisao

bool controller::colisaoBarra(barra* barra){


    SDL_Rect* bolinha = v.getBolinha();
    //std::vector<barra> &barra_ = v.getBarras();

    int l1_x, l1_y, r1_x, r1_y, l2_x, l2_y, r2_x, r2_y;

    //for(int i=0; i < barra_.size(); i++){
        
        l1_x = bolinha->x + bo->getDirX();
        l1_y = bolinha->y + bo->getDirY();
        r1_x = bolinha->x + bolinha->w + bo->getDirX();
        r1_y = bolinha->y + bolinha->h + bo->getDirY(); 
        l2_x = barra->getX();
        l2_y = barra->getY();
        r2_x = barra->getX() + barra->getW();
        r2_y = barra->getY() + barra->getH();

        // Se um objeto esta a esquerda do outro
        if (l1_x >= r2_x || l2_x >= r1_x){
            return false;
        }
            
        // Se um objeto esta a direita do outrp
        if (r1_y <= l2_y || r2_y <= l1_y){
            return false;
        }
    //}
    return true;    
}

bool controller::colisaoBloco(){

    SDL_Rect* bolinha = v.getBolinha();
    std::vector<std::vector<tijolo> >&tijolo_ = v.getTijolos();
    int l1_x, l1_y, r1_x, r1_y, l2_x, l2_y, r2_x, r2_y;

    for(int i=0; i<tijolo_.size(); i++){
        for(int j=0; j<tijolo_[i].size(); j++){
            l1_x = bolinha->x + bo->getDirX();
            l1_y = bolinha->y + bo->getDirY();
            r1_x = bolinha->x + bolinha->w + bo->getDirX();
            r1_y = bolinha->y + bolinha->h + bo->getDirY(); 
            l2_x = tijolo_[i][j].getX();
            l2_y = tijolo_[i][j].getY();
            r2_x = tijolo_[i][j].getX() + tijolo_[i][j].getW();
            r2_y = tijolo_[i][j].getY() + tijolo_[i][j].getH();
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
            tijolo_[i].erase(tijolo_[i].begin()+j);

            p->setValue(p->getValue()+10);
            //Caso a colisao seja lateral, inverte a movimentacao lateral da bolinha
            if(l1_x < l2_x || r1_x > r2_x){
                bo->setDirX(-1*bo->getDirX());
                return true;
            }
            bo->setDirY(-1*bo->getDirY());
            return true;
        }                 
    }
    return false;
}

//Se o botao S for pressionado, inicia o jogo
void controller::start(int user){
    
    if (keyb[user].Start()){
        bo->setExit(true);
        bo->setPause(true);
    }    
}

//Se o botao Esc for pressionado, finaliza o jogo
bool controller::save(int user){
    if (keyb[user].Save()){
        return true;
    } 
    return false;   
}

//Se o botao Esc for pressionado, finaliza o jogo
bool controller::load(int user){
    if (keyb[user].Load()){
        bo->setExit(false);
        bo->setPause(false);
        return true;
    } 
    return false;   
}

//Se o botao Esc for pressionado, finaliza o jogo
bool controller::finish(int user){
    if (keyb[user].Exit()){
        return true;
    } 
    return false;   
}



