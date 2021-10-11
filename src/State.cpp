#include <string>
#include <iostream>
#include "../include/State.h"
#include "../include/TileMap.h"
#include "../include/TileSet.h"
#include "../include/InputManager.h"
#include "../include/Camera.h"
#include "../include/CameraFollower.h"

State::State(){
    quitRequested = false;
    
	GameObject* go = new GameObject();
    go->AddComponent(new Sprite(*go, "./assets/img/ocean.jpg"));
	go->AddComponent(new CameraFollower(*go));
	objectArray.emplace_back(go);
	
	GameObject* tileObject = new GameObject();
	TileSet* set = new TileSet(64,64, "./assets/img/tileset.png",*tileObject);
	TileMap* mapa = new TileMap(*tileObject, "./map/tileMap.txt", set);
	tileObject->AddComponent(mapa);
	objectArray.emplace_back(tileObject);

    LoadAssets();
    music->Play();
}

State::~State(){
    objectArray.clear();
}

void  State::LoadAssets(){
    music = new Music("./assets/audio/stageState.ogg");
}

void State::Update(float dt){
	InputManager& inputManager = InputManager::GetInstance();
	Camera::Update(dt);
	quitRequested = (inputManager.QuitRequested() || inputManager.KeyPress(ESCAPE_KEY));
    if(inputManager.KeyPress(SPACE_KEY)){
		Vec2 objPos = Vec2( 200, 0 ).Rotation( -3.14159265358979323846 + 3.14159265358979323846*(rand() % 1001)/500.0 ) + Vec2( inputManager.GetMouseX(), inputManager.GetMouseY());
		AddObject((int)objPos.x, (int)objPos.y);
	}

    for(auto& objeto : objectArray){
        objeto->Update(dt);
    }

    for(unsigned long int i =0;i<objectArray.size();++i){
        if(objectArray[i]->IsDead()){
           objectArray.erase(objectArray.begin()+i); 
        }
    }
}

void State::Render(){
    for(auto& objeto : objectArray){
        objeto->Render();
    }
}

void State::AddObject(int mouseX, int mouseY){
	mouseX += Camera::pos.x;
	mouseY += Camera::pos.y;
    GameObject* enemy = new GameObject();
    enemy->AddComponent(new Sprite(*enemy, "./assets/img/penguinface.png"));
    enemy->box.x = mouseX-(enemy->box.w/2);
    enemy->box.y = mouseY-(enemy->box.h/2);
    enemy->AddComponent(new Sound(*enemy, "./assets/audio/boom.wav"));
    enemy->AddComponent(new Face(*enemy));
    objectArray.emplace_back(enemy);
}

bool State::QuitRequested(){
    return quitRequested;
}