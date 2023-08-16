#include "GameObjects/Entity.hpp"

class Tile : public Entity {
public:
    Tile(Vector2f _pos, int _scale, SDL_Texture* _tex):Entity(_pos, _scale, _tex){};
};