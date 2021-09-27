#include "../include/TileMap.h"
#include <fstream>

TileMap::TileMap(GameObject& associated, std::string file, TileSet* tileSet):Component(associated){
    Load(file);
    this->tileSet = tileSet;
}

void TileMap::Load(std::string file){
    std::ifstream mapa;
    std::string linha;
    std::string matriz;
    std::string token;
    size_t p = 0;
    mapa.open(file,std::ios::in);
    if(mapa.is_open()){
        while(std::getline(mapa,linha)){
            matriz += linha;
        }
        mapa.close();
    }
    while((p = matriz.find(",")) != std::string::npos){
        token = matriz.substr(0,p);
        tileMatrix.push_back(stoi(token) - 1);
        matriz.erase(0,p+1);
    }

    mapWidth = tileMatrix[0]+1;
    mapHeight = tileMatrix[1]+1;
    mapDepth = tileMatrix[2]+1;
    
    tileMatrix.erase(tileMatrix.begin(),tileMatrix.begin()+3);
}

void TileMap::SetTileSet(TileSet* tileSet){
    this->tileSet = tileSet;
}

int TileMap::At(int x, int y, int z){
    return (z * mapWidth * mapHeight) + (y * mapWidth) + x;
}

void TileMap::Render(){
    for(int i=0; i < mapDepth; i++){
        RenderLayer(i,associated.box.x, associated.box.y);
    }
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY){
    int pos;
    int index;
    for(int i = 0;i < mapHeight;i++){
        for(int j = 0;j < mapWidth;j++){
            pos = At(j,i,layer);
            index = tileMatrix[pos];
            tileSet->RenderTile(index, j*tileSet->GetTileWidth(),i*tileSet->GetTileHeight());
        }
    }
}

void TileMap::Update(float dt){}

bool TileMap::Is(std::string type){
    if(type == "TileMap"){
        return true;
    }
    return false;
}

int TileMap::GetWidth(){
    return mapWidth;
}

int TileMap::GetHeight(){
    return mapHeight;
}

int TileMap::GetDepth(){
    return mapDepth;
}