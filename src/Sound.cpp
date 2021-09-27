#include "../include/Sound.h"
#include "../include/Resources.h"

Sound::Sound(GameObject& associated):Component(associated){
    chunk = nullptr;
}

Sound::Sound(GameObject& associated, std::string file):Component(associated){
    chunk = nullptr;
    Open(file);
}

Sound::~Sound(){}

void Sound::Play(int times){
    channel = Mix_PlayChannel(-1,chunk, times-1);
}

void Sound::Stop(){
    Mix_HaltChannel(channel);
}

void Sound::Open(std::string file){
    chunk = Resources::GetSound(file);
    if(chunk == nullptr){
        std::cout << SDL_GetError() << std::endl;
        exit(0);
    }
}
void Sound::Render(){}

bool Sound::IsOpen(){
    if(chunk != nullptr){
        return true;
    }
    return false;
}

void Sound::Update(float dt){}

bool Sound::IsPlaying(){
    if(IsOpen() && channel <= 32 && channel >= 0){
        return Mix_Playing(channel);
    }
    return false;
}

bool Sound::Is(std::string type){
    if(type == "Sound"){
        return true;
    }
    return false;
}