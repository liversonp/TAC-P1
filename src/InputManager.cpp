#include "../include/InputManager.h"

InputManager& InputManager::GetInstance(){
    static InputManager instance;
    return instance;
}

InputManager::InputManager(){
    for(int i=0;i<6;++i){
        mouseState[i] = false;
        mouseUpdate[i] = 0;
    }

    for(int i=0;i<416;++i){
        mouseState[i] = false;
        mouseUpdate[i] = 0;
    }

    updateCounter = 0;
    quitRequested = false;
    mouseX = 0;
    mouseY = 0;
}

InputManager::~InputManager(){}

void InputManager::Update(){
    SDL_Event event;
    quitRequested = false;
    updateCounter++;
    SDL_GetMouseState(&mouseX, &mouseY);

    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            quitRequested = true;
        }
        
        if(event.type == SDL_MOUSEBUTTONDOWN){
            mouseState[event.button.button] = true;
            mouseUpdate[event.button.button] = updateCounter;
        }
        
        if(event.type == SDL_MOUSEBUTTONUP){
            mouseState[event.button.button] = false;
            mouseUpdate[event.button.button] = updateCounter;
        }

        if(event.type == SDL_KEYDOWN && !event.key.repeat){
            if(event.key.keysym.sym > 0x7F){ 
                keyState[event.key.keysym.sym-0x3FFFFF81] = true;
                keyUpdate[event.key.keysym.sym-0x3FFFFF81] = updateCounter;
            }
            else{
                keyState[event.key.keysym.sym] = true;
                keyUpdate[event.key.keysym.sym] = updateCounter;
            }
        }

        if(event.type == SDL_KEYUP){
            if(event.key.keysym.sym > 0x7F){ 
                keyState[event.key.keysym.sym-0x3FFFFF81] = false;
                keyUpdate[event.key.keysym.sym-0x3FFFFF81] = updateCounter;
            }
            else{
                keyState[event.key.keysym.sym] = false;
                keyUpdate[event.key.keysym.sym] = updateCounter;
            }
        }
    }
}

bool InputManager::KeyPress(int key){
    if(key > 0x7F){
        return (keyUpdate[key-0x3FFFFF81] == updateCounter && keyState[key] == true);
    }
    else{
        return (keyUpdate[key] == updateCounter && keyState[key] == true);
    }
}

bool InputManager::KeyRelease(int key){
    if(key > 0x7F){
        return (keyUpdate[key-0x3FFFFF81] == updateCounter && keyState[key] == false);
    }
    else{
        return (keyUpdate[key] == updateCounter && keyState[key] == false);
    }
}

bool InputManager::IsKeyDown(int key){
    if(key > 0x7F){
        return keyState[key-0x3FFFFF81];
    }
    else{
        return keyState[key];
    }
}

bool InputManager::MousePress(int button){
    return (mouseUpdate[button] == updateCounter && mouseState[button] == true);
}

bool InputManager::MouseRelease(int button){
    return (mouseUpdate[button] == updateCounter && mouseState[button] == false);
}

bool InputManager::IsMouseDown(int button){
    return mouseState[button];
}

int InputManager::GetMouseX(){
    return mouseX;
}

int InputManager::GetMouseY(){
    return mouseY;
}

bool InputManager::QuitRequested(){
    return quitRequested;
}