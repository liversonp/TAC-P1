#ifndef STATE_H
#define STATE_H
#define INCLUDE_SDL

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "SDL_include.h"
#include "Sprite.h"
#include "Music.h"
#include "GameObject.h"
#include "Sound.h"
#include "Face.h"

class State{
private:
    Music* music;
    bool quitRequested;
    std::vector<std::unique_ptr<GameObject>> objectArray;

    void Input();
    void AddObject(int mouseX, int mouseY);

public:
    State();
    ~State();
    bool QuitRequested();
    void LoadAssets();
    void Update(float dt);
    void Render();
};

#endif