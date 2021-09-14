#include "../include/Rect.h"

Rect::Rect(){
    x = 0;
    y = 0;
    h = 0;
    w = 0;
}

Rect::Rect(float x, float y, float h, float w){
    this->x = x;
    this->y = y;
    this->h = h;
    this->w = w;
}

Rect::~Rect(){}

void Rect::SomaRV(Vec2 pos){
    x += pos.x;
    y += pos.y;
}

Vec2 Rect::Center(){
    Vec2 temp;
    temp.x = x+(w/2);
    temp.y = y+(h/2);   
    return temp;
}

float Rect::RectDist(Rect r1, Rect r2){
    Vec2 p1;
    p1 = r1.Center();
    Vec2 p2;
    p2 = r2.Center();
    float distance = p1.DistPoints(p1,p2);
    return distance;
}


bool Rect::IsInside(Vec2 point){
    if(point.x >= x && x+w >= point.x && point.y >= y && y+h >= point.y){
        return true;
    }
    return false;
}