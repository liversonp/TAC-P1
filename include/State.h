#ifndef STATE_H
#define STATE_H
#define INCLUDE_SDL

#include <iostream>
#include <string>
#include "SDL_include.h"
#include "Sprite.h"
#include "Music.h"

class State{
private:
    Sprite* bg;
    Music* music;
    bool quitResquest;
public:
    State();
    bool QuitRequested();
    void LoadAssets();
    void Update(/*float dt*/);
    void Render();
};

#endif