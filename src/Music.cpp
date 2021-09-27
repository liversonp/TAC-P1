#include <string>
#include <iostream>
#include "../include/Music.h"
#include "../include/Resources.h"

Music::Music(){}

Music::Music(std::string file){
    Open(file);
}

Music::~Music(){}

void Music::Play(int times){
    Mix_PlayMusic(music, times);
}

void Music::Stop(int msToStop){
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(std::string file){
    music = Resources::GetMusic(file);
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