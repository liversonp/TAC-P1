#include <string>
#include <iostream>
#include "../include/Sprite.h"
#include "../include/Game.h"
#include "../include/Resources.h"

Sprite::Sprite(GameObject& associated):Component(associated){}

Sprite::Sprite(GameObject& associated, std::string file):Component(associated){
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite(){}

void Sprite::Open(std::string file){
    SDL_Texture* TEXTURE = Resources::GetImage(file);
    if(TEXTURE != nullptr){
        texture = TEXTURE;
    }
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    SetClip(0,0,width,height);
    associated.box.w = width;
    associated.box.h = height;
}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect.h = h;
    clipRect.w = w;
    clipRect.x = x;
    clipRect.y = y;
}

void Sprite::Render(){
    Render(associated.box.x, associated.box.y);
}

void Sprite::Render(float x, float y){
    Game& game = Game::GetInstance();
    SDL_Rect dstrect;
    dstrect.x = x;
    dstrect.y = y;
    dstrect.h = clipRect.h;
    dstrect.w = clipRect.w;
    SDL_RenderCopy(game.GetRenderer(), texture, &clipRect, &dstrect);
}

void Sprite::Update(float dt){}

bool Sprite::Is(std::string type){
    if(type == "Sprite"){
        return true;
    }
    return false;
}

int Sprite::GetWidth(){
    return width;
}

int Sprite::GetHeight(){
    return height;
}

bool Sprite::IsOpen(){
    if(texture != nullptr){
        return true;
    }
    else{
        return false;
    }
}