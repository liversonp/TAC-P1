#include "../include/Face.h"
#include "../include/Sound.h"

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
    Sound* morte = (Sound*)associated.GetComponent("Sound");
    if(hitpoints <= 0 && !morte->IsPlaying()){
        associated.RequestDelete();
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