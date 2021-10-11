#include "../include/CameraFollower.h"
#include "../include/Camera.h"

CameraFollower::CameraFollower(GameObject& associated):Component(associated){}

void CameraFollower::Update(float dt){
    associated.box.x = Camera::pos.x;
    associated.box.y = Camera::pos.y;
}

void CameraFollower::Render(){}

bool CameraFollower::Is(std::string type){
    if(type == "CameraFollower"){
        return true;
    }
    return false;
}