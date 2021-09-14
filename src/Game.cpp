#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../include/Game.h"

Game* Game::instance = nullptr;

Game::Game(std::string title, int width, int height){
    if(instance != nullptr){
        std::cout << "Erro!\n";
        exit(0);
    }

    this->instance = this;
    
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0){
        std::cout << SDL_GetError() << std::endl;
        exit(0);
    }
    
    if(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == 0){
        std::cout << SDL_GetError() << std::endl;
        exit(0);
    }

    Mix_Init(MIX_INIT_MP3);
    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0){
        std::cout << SDL_GetError() << std::endl;
        exit(0);
    }

    Mix_AllocateChannels(32);

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED , width, height, 0);

    if(window == nullptr){
        std::cout<< SDL_GetError() << std::endl;
        exit(0);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(renderer == nullptr){
        std::cout<< SDL_GetError() << std::endl;
        exit(0);
    }

    srand(time(NULL));

    state = new State;
}

Game::~Game(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

Game& Game::GetInstance(){
    if(instance != nullptr){
        return *instance;
    }

    instance = new Game("Liverson Paulo 180022237", 1024, 600);
    return *instance;
}

State& Game::GetState(){
    return *state;
}

SDL_Renderer* Game::GetRenderer(){
    return renderer;
}

void Game::Run(){
    while(!state->QuitRequested()){
        state->Update(0);
        state->Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
}