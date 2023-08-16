#include "GameObjects/Player.hpp"

void Player::HandleEvent(SDL_Event &e, EntityStorage* entityStorage){
    if(e.type == SDL_KEYDOWN && e.key.repeat == 0) {
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            vel.y -= MAX_VELOCITY;
            break;
        case SDLK_DOWN:
            vel.y += MAX_VELOCITY;
            break;
        case SDLK_LEFT:
            vel.x -= MAX_VELOCITY;
            break;
        case SDLK_RIGHT:
            vel.x += MAX_VELOCITY;
            break;
        case SDLK_DELETE:
            entityStorage->DeleteFromEntityBuffer(this);
            return;
        }
    }else if(e.type == SDL_KEYUP && e.key.repeat == 0) {
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            vel.y += MAX_VELOCITY;
            break;
        case SDLK_DOWN:
            vel.y -= MAX_VELOCITY;
            break;
        case SDLK_LEFT:
            vel.x += MAX_VELOCITY;
            break;
        case SDLK_RIGHT:
            vel.x -= MAX_VELOCITY;
            break;
        }
    }

    Move();
}

void Player::Move() {
    pos.x += vel.x;
    if((pos.x < 0) || (pos.x + Utils::ENTITY_SIZE > Utils::SCREEN_WIDTH)) {
        pos.x -= vel.x;
    }

    pos.y += vel.y;
    if((pos.y < 0) || (pos.y + Utils::ENTITY_SIZE > Utils::SCREEN_HEIGHT)) {
        pos.y -= vel.y;
    }
}