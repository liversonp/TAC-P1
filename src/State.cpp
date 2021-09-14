#include <string>
#include <iostream>
#include "../include/State.h"

State::State(){
    quitRequested = false;
    GameObject* go = new GameObject();
    go->AddComponent(new Sprite(*go, "./assets/img/ocean.jpg"));
	objectArray.emplace_back(go);
    LoadAssets();
    music->Play();
}

State::~State(){
    objectArray.clear();
}

void State::Input() {
	SDL_Event event;
	int mouseX, mouseY;

	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&mouseX, &mouseY);

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
	while (SDL_PollEvent(&event)) {

		// Se o evento for quit, setar a flag para terminação
		if(event.type == SDL_QUIT) {
			quitRequested = true;
		}
		
		// Se o evento for clique...
		if(event.type == SDL_MOUSEBUTTONDOWN) {

			// Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
			for(int i = objectArray.size() - 1; i >= 0; --i) {
				// Obtem o ponteiro e casta pra Face.
				GameObject* go = (GameObject*) objectArray[i].get();
				// Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
				// O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
				// ao usar get(), violamos esse princípio e estamos menos seguros.
				// Esse código, assim como a classe Face, é provisório. Futuramente, para
				// chamar funções de GameObjects, use objectArray[i]->função() direto.

				if(go->box.IsInside( {(float)mouseX, (float)mouseY} ) ) {
					Face* face = (Face*)go->GetComponent( "Face" );
					if ( nullptr != face && face->IsAlive()) {
						// Aplica dano
						face->Damage(std::rand() % 10 + 10);
						// Sai do loop (só queremos acertar um)
						break;
					}
				}
			}
		}
		if( event.type == SDL_KEYDOWN ) {
			// Se a tecla for ESC, setar a flag de quit
			if( event.key.keysym.sym == SDLK_ESCAPE ) {
				quitRequested = true;
			}
			// Se não, crie um objeto
			else {
				Vec2 objPos = Vec2( 200, 0 ).Rotation( -3.14159265358979323846 + 3.14159265358979323846*(rand() % 1001)/500.0 ) + Vec2( mouseX, mouseY );
				AddObject((int)objPos.x, (int)objPos.y);
			}
		}
	}
}

void  State::LoadAssets(){
    music = new Music("./assets/audio/stageState.ogg");
}

void State::Update(float dt){
    Input();

    for(auto& objeto : objectArray){ //Possivel futuro erro, mas pode ser q n, qlqr coisa usar &&
        objeto->Update(dt);
    }

    for(unsigned long int i =0;i<objectArray.size();++i){
        if(objectArray[i]->IsDead()){
           objectArray.erase(objectArray.begin()+i); 
        }
    }
}

void State::Render(){
    for(auto& objeto : objectArray){ //Possivel futuro erro 2, mas pode ser q n, qlqr coisa usar &&
        objeto->Render();
    }
}

void State::AddObject(int mouseX, int mouseY){
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