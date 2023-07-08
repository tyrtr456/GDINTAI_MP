#ifndef MODELS_MAP_H
#define MODELS_MAP_H

namespace models{

    class Map  {

    private:

        static const int HEIGHT_MAP = 28;
        static const int WIDTH_MAP = 30;

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


    };


}



#endif