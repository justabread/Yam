#pragma once
#include <iostream>

class Vector2f {
public:
    float x, y;

    Vector2f(): x(0.0f), y(0.0f) {};
    Vector2f(float _x, float _y): x(_x), y(_y) {};

    void print() {
        std::cout << x << ", " << y << std::endl;
    }
};