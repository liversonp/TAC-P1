#ifndef SPRITE_H
#define SPRITE_H
#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE 

#include <iostream>
#include <string>
#include "SDL_include.h"
#include "Component.h"

class Sprite: public Component{
private:
    SDL_Texture* texture;
    int width;
    int height;
    SDL_Rect clipRect;

public:
    Sprite(GameObject& associated);
    Sprite(GameObject& associated ,std::string file);
    ~Sprite();
    void Open(std::string file);
    void SetClip(int x, int y, int w, int h);
    void Update(float dt);
    void Render();
    void Render(float x, float y);
    bool Is(std::string type);
    int GetWidth();
    int GetHeight();
    bool IsOpen();
};


#endif