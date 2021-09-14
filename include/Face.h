#ifndef FACE_H
#define FACE_H

#include <iostream>
#include <string>
#include "SDL_include.h"
#include "Component.h"
#include "GameObject.h"

class Face: public Component{
private:
    int hitpoints;

public:
    Face(GameObject& associated);
    void Damage(int damage);
    void Update(float dt);
    void Render();
    bool Is(std::string type);
    bool IsAlive();
};

#endif