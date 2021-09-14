#ifndef RECT_H
#define RECT_H

#include <iostream>
#include "vec2.h"
#include "SDL_include.h"
#include <cmath>

class Rect{
public:
    float x;
    float y;
    float w;
    float h;

    Rect();
    Rect(float x, float y, float w, float h);
    ~Rect();
    void SomaRV(Vec2 pos);
    Vec2 Center();
    float RectDist(Rect r1, Rect r2);
    bool IsInside(Vec2 point);
};

#endif