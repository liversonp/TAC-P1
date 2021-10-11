#include "../include/Camera.h"
#include "../include/InputManager.h"

Vec2 Camera::pos;
Vec2 Camera::speed;
GameObject* Camera::focus = nullptr;

void Camera::Follow(GameObject* newFocus){
    focus = newFocus;
}

void Camera::Unfollow(){
    focus = nullptr;
}

void Camera::Update(float dt){
    if(focus == nullptr){
        InputManager& input = InputManager::GetInstance();
        
        if(input.IsKeyDown(LEFT_ARROW_KEY)){
            speed = speed+Vec2(-1,0);
        }
        
        if(input.IsKeyDown(RIGHT_ARROW_KEY)){
            speed = speed+Vec2(1,0);
        }
        
        if(input.IsKeyDown(UP_ARROW_KEY)){
            speed = speed+Vec2(0,-1);
        }
        
        if(input.IsKeyDown(DOWN_ARROW_KEY)){
            speed = speed+Vec2(0,1);
        }

        speed.CalcNormalizado();
        pos = pos + (speed*dt*400);
        speed.x = 0;
        speed.y = 0;
    }
    else{
        pos.x = 512;
        pos.y = 300;
        Unfollow();
    }
}