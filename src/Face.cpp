#include "../include/Face.h"
#include "../include/Sound.h"
#include "../include/InputManager.h"
#include "../include/Camera.h"

Face::Face(GameObject& associated):Component(associated){
    hitpoints = 30;
}

void Face::Damage(int damage){
    hitpoints -= damage;
    if(hitpoints <= 0){
        Sound* morte = (Sound*)associated.GetComponent("Sound");
        associated.RemoveComponent(associated.GetComponent("Sprite"));
        if(morte != nullptr && !morte->IsPlaying()){
            morte->Play();
        }
    }
}

void Face::Update(float dt){
    InputManager& inputManager = InputManager::GetInstance();
    Sound* morte = (Sound*)associated.GetComponent("Sound");
    if(hitpoints <= 0 && !morte->IsPlaying()){
        associated.RequestDelete();
    }
    if(inputManager.IsMouseDown(LEFT_MOUSE_BUTTON) && associated.box.IsInside(Vec2(inputManager.GetMouseX()+Camera::pos.x,inputManager.GetMouseY()+Camera::pos.y))){
        Damage(std::rand() % 10 + 10);
    }
}

void Face::Render(){}

bool Face::Is(std::string type){
    if(type == "Face"){
        return true;
    }
    return false;
}

bool Face::IsAlive(){
    if(hitpoints <= 0){
        return false;
    }
    return true;
}