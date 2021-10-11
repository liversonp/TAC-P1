#ifndef VEC2_H
#define VEC2_H

#include <iostream>
#include <cmath>

class Vec2{
public:
    float x;
    float y;

    Vec2();
    Vec2(float x, float y);
    ~Vec2();
    bool HasMagnitude();
    Vec2 operator+(const Vec2 &point);
    Vec2 operator-(const Vec2 &point);
    Vec2 operator*(float escalar);
    float Magnitude();
    void CalcNormalizado();
    float DistPoints(Vec2 p1, Vec2 p2);
    float InclinationX(Vec2 v);
    float InclinationBPoints(Vec2 p1, Vec2 p2);
    Vec2 Rotation(float angle);
};

#endif