#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>
#include <string>
#include "GameObject.h"
#include "SDL_include.h"

//LEMBRAR DE MUDAR O SPRITE DEPOIS

class GameObject;

class Component{
protected:
    GameObject& associated;

public:
    Component(GameObject& associated);
    virtual ~Component();
    virtual void Update(float dt) = 0;
    virtual void Render() = 0;
    virtual bool Is(std::string type) = 0;
};

#endif