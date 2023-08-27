#include "GameObjects/Player.hpp"

void Player::HandleEvent(SDL_Event &e){
    if(e.type == SDL_KEYDOWN && e.key.repeat == 0) {
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            ObjectsColliding(EntityStorage::renderBuffer);
            if(pos.y + Utils::ENTITY_SIZE == Utils::SCREEN_HEIGHT || collidingInDirection[Utils::Direction::SOUTH]){
                isJumping = true;
                jumpStart = pos.y;
            }
            break;
        // case SDLK_DOWN:
        //     vel.y += MAX_VELOCITY;
        //     break;
        case SDLK_LEFT:
            vel.x -= MAX_VELOCITY;
            break;
        case SDLK_RIGHT:
            vel.x += MAX_VELOCITY;
            break;
        case SDLK_DELETE:
            EntityStorage::DeleteFromEntityBuffer(this);
            return;
        }
    }else if(e.type == SDL_KEYUP && e.key.repeat == 0) {
        switch (e.key.keysym.sym)
        {
        // case SDLK_UP:
        //     vel.y += MAX_VELOCITY;
        //     break;
        // case SDLK_DOWN:
        //     vel.y -= MAX_VELOCITY;
        //     break;
        case SDLK_LEFT:
            vel.x += MAX_VELOCITY;
            break;
        case SDLK_RIGHT:
            vel.x -= MAX_VELOCITY;
            break;
        }
    }
}

void Player::Move() {
    //Jumping and gravity
    if(isJumping) {
        if(pos.y >= jumpStart - Utils::JUMP_HEIGHT){
            vel.y = -1;
        }else {
            isJumping = false;
            vel.y = 0;
        }
    }else {
        ApplyGravity();
    }

    //Move and update collisions
    pos.x += vel.x;
    ObjectsColliding(EntityStorage::renderBuffer);
    if(
        ((pos.x < 0) || (pos.x + Utils::ENTITY_SIZE > Utils::SCREEN_WIDTH)) || 
        (collidingInDirection[Utils::Direction::EAST] || collidingInDirection[Utils::Direction::WEST])
    ) {
        pos.x -= vel.x;
    }

    ObjectsColliding(EntityStorage::renderBuffer);
    pos.y += vel.y;
    if(
        (pos.y < 0) || 
        (pos.y + Utils::ENTITY_SIZE > Utils::SCREEN_HEIGHT) ||
        ((collidingInDirection[Utils::Direction::SOUTH] && !isJumping) || collidingInDirection[Utils::Direction::NORTH])
    ) {
        pos.y -= vel.y;
        vel.y = 0;
    }
}

bool Player::CheckCollision(SDL_Rect* a, SDL_Rect* b) {

    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a->x;
    rightA = a->x + a->w;
    topA = a->y;
    bottomA = a->y + a->h;

    //Calculate the sides of rect B
    leftB = b->x;
    rightB = b->x + b->w;
    topB = b->y;
    bottomB = b->y + b->h;

    if((bottomA >= topB && !(bottomA > topB)) && (leftA <= rightB && rightA >= leftB))
    {
        std::cout<<"south"<<std::endl;
        collidingInDirection[Utils::Direction::SOUTH] = true;
        return true;
    }
    if((topA <= bottomB && !(topA < bottomB)) && (leftA <= rightB && rightA >= leftB))
    {
        std::cout<<"north"<<std::endl;
        collidingInDirection[Utils::Direction::NORTH] = true;
        return true;
    }

    if((rightA >= leftB && leftA <= leftB) && (bottomA >= topB && topA <= bottomB))
    {
        std::cout<<"east"<<std::endl;
        collidingInDirection[Utils::Direction::EAST] = true;
        return true;
    }

    if((leftA <= rightB && rightA >= rightB) && (bottomA >= topB && topA <= bottomB))
    {
        std::cout<<"west"<<std::endl;
        collidingInDirection[Utils::Direction::WEST] = true;
        return true;
    }

    return false;
}

std::vector<Entity*> Player::ObjectsColliding(std::vector<Entity*> renderBuffer) {
    std::vector<Entity*> collidingObjects; 
    isColliding = true;

    collidingInDirection = {
        {Utils::Direction::NORTH, false},
        {Utils::Direction::EAST, false},
        {Utils::Direction::SOUTH, false},
        {Utils::Direction::WEST, false}
    };

    for(Entity* entity : renderBuffer) {
        if(this != entity){
            //DEPRECATED BROKEN

            // //Checking x axis collision
            // bool isCollidingXL = ((pos.x >= entity->GetPos().x && pos.x < + entity->GetPos().x + Utils::ENTITY_SIZE));
            // bool isCollidingXS = ((entity->GetPos().x > pos.x && entity->GetPos().x < pos.x + Utils::ENTITY_SIZE + 1));

            // //Checking y axis collision
            // bool isCollidingYL = ((pos.y >= entity->GetPos().y && pos.y < + entity->GetPos().y + Utils::ENTITY_SIZE));
            // bool isCollidingYS = ((entity->GetPos().y > pos.y && entity->GetPos().y < pos.y + Utils::ENTITY_SIZE));

            // if((isCollidingXL || isCollidingXS) && (isCollidingYL || isCollidingYS)) {
            //     if(isCollidingXL && !isCollidingYS) {
            //         collidingInDirection[Utils::Direction::EAST] = true;
            //         std::cout << "EAST" << std::endl;
            //     }

            //     if(isCollidingXS && !isCollidingYS) {
            //         collidingInDirection[Utils::Direction::WEST] = true;
            //         std::cout << "WEST" << std::endl;
            //     }

            //     if(isCollidingYL) {
            //         collidingInDirection[Utils::Direction::NORTH] = true;
            //         std::cout << "NORTH" << std::endl;
            //     }

            //     if(isCollidingYS) {
            //         collidingInDirection[Utils::Direction::SOUTH] = true;
            //         std::cout << "SOUTH" << std::endl;
            //     }

            //     collidingObjects.push_back(entity);
            //     isColliding = true;

            if(CheckCollision(GetPos(), entity->GetPos())){
                collidingObjects.push_back(entity);
            }
        }
    }

    if(collidingObjects.size() < 1){ 
        isColliding = false;
    }

    return collidingObjects;
}

void Player::ApplyGravity() {
    vel.y = Utils::GRAVITY;
}