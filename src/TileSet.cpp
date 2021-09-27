#include "../include/TileSet.h"

TileSet::TileSet(int tileWidth, int tileHeight, std::string file, GameObject& associated):associated(associated){
    this->tileWidth = tileWidth;
    this->tileHeight = tileHeight;
    tileSet = new Sprite(associated, file);
    if(tileSet != nullptr){
        rows = tileSet->GetWidth() / tileWidth;
        columns = tileSet->GetHeight() / tileHeight;
    }
}

TileSet::~TileSet(){}

void TileSet::RenderTile(int index, float x, float y){
    if(index >= 0 && index < rows*columns){
        int tileX = index % rows;
        int tileY = index / rows;
        tileSet->SetClip(tileX*tileWidth, tileY*tileHeight, tileWidth, tileHeight);
        tileSet->Render(x, y);
    }
}

int TileSet::GetTileWidth(){
    return tileWidth;
}

int TileSet::GetTileHeight(){
    return tileHeight;
}