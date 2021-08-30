#include <string>
#include <iostream>
#include "../include/State.h"

State::State(){
    quitResquest = false;
    bg = new Sprite("./assets/img/ocean.jpg");
    LoadAssets();
    music->Play();
}

void  State::LoadAssets(){
    music = new Music("./assets/audio/stageState.ogg");
}

void State::Update(/*float dt*/){
    if(SDL_QuitRequested()){
        quitResquest = true;
    }
}

void State::Render(){
    bg->Render(0,0);
}

bool State::QuitRequested(){
    return quitResquest;
}