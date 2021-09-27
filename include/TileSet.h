#ifndef TILESET_H
#define TILESET_H

#include <iostream>
#include <string>
#include "Sprite.h"
#include "GameObject.h"

class TileSet{
protected:
    GameObject& associated;

private:
    Sprite* tileSet;
    int rows;
    int columns;
    int tileWidth;
    int tileHeight;

public:
    TileSet(int tileWidth, int tileHeight, std::string file, GameObject& associated);
    ~TileSet();
    void RenderTile(int index, float x, float y);
    int GetTileWidth();
    int GetTileHeight();
};

#endif