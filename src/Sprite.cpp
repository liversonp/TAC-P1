#include <string>
#include <iostream>
#include "../include/Sprite.h"
#include "../include/Game.h"

Sprite::Sprite(){}

Sprite::Sprite(std::string file){
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite(){
    SDL_DestroyTexture(texture);
}

void Sprite::Open(std::string file){
    if(texture != nullptr){
        SDL_DestroyTexture(texture);
    }
    Game &game = Game::GetInstance();
    SDL_Texture* TEXTURE = IMG_LoadTexture(game.GetRenderer(), file.c_str());
    if(TEXTURE != nullptr){
        texture = TEXTURE;
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    SetClip(0,0,width,height);
}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect.h = h;
    clipRect.w = w;
    clipRect.x = x;
    clipRect.y = y;
}

void Sprite::Render(int x, int y){
    Game& game = Game::GetInstance();
    SDL_Rect dstrect;
    dstrect.x = x;
    dstrect.y = y;
    dstrect.h = clipRect.h;
    dstrect.w = clipRect.w;
    SDL_RenderCopy(game.GetRenderer(), texture, &clipRect, &dstrect);
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