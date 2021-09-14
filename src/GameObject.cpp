#include "../include/GameObject.h"

GameObject::GameObject(){
    isDead = false;
}

GameObject::~GameObject(){}

void GameObject::Update(float dt){
    for(auto& element : components){
        element->Update(dt);
    }
}

void GameObject::Render(){
    for(auto& element : components){
        element->Render();
    }
}

bool GameObject::IsDead(){
    return isDead;
}

void GameObject::RequestDelete(){
    isDead = true;
}

void GameObject::AddComponent(Component* cpt){
    components.emplace_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt){
    for(unsigned long int i=0;i<components.size();i++){
        if(components[i].get() == cpt){
            components.erase(components.begin()+i);
        }
    }
}

Component* GameObject::GetComponent(std::string type){
    for(auto& element : components){
        if(element->Is(type)){
            return element.get();
        }
    }
    return nullptr;
}