#include <string>
#include <iostream>
#include "../include/Music.h"

Music::Music(){}

Music::Music(std::string file){
    Open(file);
}

void Music::Play(int times){
    Mix_PlayMusic(music, times);
}

void Music::Stop(int msToStop){
    int stopMusic = Mix_FadeOutMusic(msToStop);
}

void Music::Open(std::string file){
    music = Mix_LoadMUS(file.c_str());
    if(music == nullptr){
        std::cout << SDL_GetError() << std::endl;
        exit(0);
    }
}

bool Music::IsOpen(){
    if(music){
        return true;
    }
    else{
        return false;
    }
}

Music::~Music(){
    Mix_FreeMusic(music);
}