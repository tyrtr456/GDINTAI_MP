#ifndef MODELS_MAP_H
#define MODELS_MAP_H

#include "Settings.h"

namespace models{

    class Map  {

    private:

        sf::String *TileMap;
        int TileMapData[HEIGHT_MAP][WIDTH_MAP];
        sf::Texture mTexture;
        sf::Sprite mSprite;

    public:

        Map();

        void break_wall(const int &i, const int &j);
        const char get_tile(const int &i, const int &j) { return TileMap[i][j]; }
        void draw(sf::RenderWindow &window);

    public:
        int getMapDataOnTile(int nRowNo, int nColNo);
        void setMapDataOnTile(int nRowNo, int nColNo, int nVal);
        bool getTilePassable(int i, int j);


        void debug();

    };


}



#endif