#ifndef MUSIC_H
#define MUSIC_H
#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER

#include <iostream>
#include <string>
#include "SDL_include.h"

class Music{
private:
    Mix_Music* music;
public:
    Music();
    ~Music();
    Music(std::string file);
    void Play(int times = -1);
    void Stop(int msToStop = 1500);
    void Open(std::string file);
    bool IsOpen();
};

#endif