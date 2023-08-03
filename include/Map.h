#ifndef MODELS_MAP_H
#define MODELS_MAP_H

#include "Settings.h"
#include "../enum/EnumMapType.h"

namespace models{

    class Map  {

    private:

        sf::String *TileMap;
        int TileMapData[HEIGHT_MAP][WIDTH_MAP];
        sf::Texture mTexture;
        sf::Sprite mSprite;
        MapType EType;

    public:

        Map(MapType EType);

        void break_wall(const int &i, const int &j);
        const char get_tile(const int &i, const int &j) { return TileMap[i][j]; }
        void draw(sf::RenderWindow &window);

    public:
        int getMapDataOnTile(int nRowNo, int nColNo);
        void setMapDataOnTile(int nRowNo, int nColNo, int nVal);
        bool getTilePassable(int i, int j);
        MapType getMapType();
        void setMap(MapType Etype);

        void debug();

    };


}



#endif