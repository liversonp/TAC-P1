#include "../include/Vec2.h"

Vec2::Vec2(){
    x = 0;
    y = 0;
}

Vec2::Vec2(float x, float y){
    this->x = x;
    this->y = y;
}

Vec2::~Vec2(){}

Vec2 Vec2::operator+(const Vec2 &point){
    Vec2 temp;
    temp.x = point.x + x;
    temp.y = point.y + y;
    return temp;
}

Vec2 Vec2::operator-(const Vec2 &point){
    Vec2 temp;
    temp.x = x - point.x;
    temp.y = y - point.y;
    return temp;
}

Vec2 Vec2::operator*(int escalar){
    Vec2 temp;
    temp.x = x * escalar;
    temp.y = y * escalar;
    return temp;
}

float Vec2::Magnitude(){
    float magnitude = sqrt((pow(x,2)+pow(y,2)));
    return magnitude;
}

bool Vec2::HasMagnitude(){
    if(Magnitude() != 0){
        return true;
    }
    return false;
}

void Vec2::CalcNormalizado(){
    if(HasMagnitude()){
        x = x/(Magnitude());
        y = y/(Magnitude());
    }
}

float Vec2::DistPoints(Vec2 p1, Vec2 p2){
    Vec2 distance;
    distance.x = abs(p1.x-p2.x);
    distance.y = abs(p1.y-p2.y);
    float magnitude = distance.Magnitude();
    return magnitude;
}

float Vec2::InclinationX(Vec2 v){
    float inclination = atan2(v.y, v.x)*180/3.14159265358979323846;
    return inclination;
}

float Vec2::InclinationBPoints(Vec2 p1, Vec2 p2){
    float inclination = atan2(p2.y - p1.y, p2.x - p1.x)*180/3.14159265358979323846;
    return inclination;
}

Vec2 Vec2::Rotation(float angle){
    Vec2 temp;
    temp.x = x * cos(angle) - y * sin(angle);
    temp.y = y * cos(angle) + x * sin(angle);
    return temp;
}

