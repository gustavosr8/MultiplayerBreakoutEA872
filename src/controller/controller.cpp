#include "controller.h"

void controller::update(){
    const Uint8 *state = v.getState();
    SDL_Rect* target = v.getTarget();
    SDL_PumpEvents();
    if (state[SDL_SCANCODE_LEFT]) m.setX(m.getX()-1);
    if (state[SDL_SCANCODE_RIGHT]) m.setX(m.getX()+1);
    if (state[SDL_SCANCODE_UP]) m.setY(m.getY()-1);
    if (state[SDL_SCANCODE_DOWN]) m.setY(m.getY()+1);
    target->x = m.getX();
    target->y = m.getY();
}