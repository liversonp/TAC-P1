#include "../include/Resources.h"
#include "../include/Game.h"

std::unordered_map <std::string, SDL_Texture*> Resources::imageTable;
std::unordered_map <std::string, Mix_Music*> Resources::musicTable;
std::unordered_map <std::string, Mix_Chunk*> Resources::soundTable;

SDL_Texture* Resources::GetImage(std::string file){
    if(imageTable.find(file) != imageTable.end()){
        return imageTable[file];
    }

    else{
        Game &game = Game::GetInstance();
        SDL_Texture* textura = IMG_LoadTexture(game.GetRenderer(), file.c_str());
        if(textura != nullptr){
            imageTable.emplace(file,textura);
        }
        return textura;
    }
}

void Resources::ClearImages(){
    for(auto item : imageTable){
        SDL_DestroyTexture(item.second);
    }
    imageTable.clear();
}

Mix_Music* Resources::GetMusic(std::string file){
    if(musicTable.find(file) != musicTable.end()){
        return musicTable[file];
    }

    else{
        Mix_Music* musica = Mix_LoadMUS(file.c_str());
        if(musica != nullptr){
            musicTable.emplace(file,musica);
        }
        return musica;
    }
}

void Resources::ClearMusics(){
    for(auto item : musicTable){
        Mix_FreeMusic(item.second);
    }
    musicTable.clear();
}

Mix_Chunk* Resources::GetSound(std::string file){
    if(soundTable.find(file) != soundTable.end()){
        return soundTable[file];
    }

    else{
        Mix_Chunk* som = Mix_LoadWAV(file.c_str());
        if(som != nullptr){
            soundTable.emplace(file,som);
        }
        return som;
    }
}

void Resources::ClearSounds(){
    for(auto item : soundTable){
        Mix_FreeChunk(item.second);
    }
    soundTable.clear();
}