#include "../include/Map.h"

Map::Map() {
    this->TileMap = new sf::String[HEIGHT_MAP] {
        "000000000000000000000000000000",
        "00                          00",
        "00                          00",
        "00  11  11  11  11  11  11  00",
        "00  11  11  11  11  11  11  00",
        "00  11  11  11  11  11  11  00",
        "00  11  11  11  11  11  11  00",
        "00  11  11  112211  11  11  00",
        "00  11  11  112211  11  11  00",
        "00  11  11  11  11  11  11  00",
        "00  11  11          11  11  00",
        "00  11  11          11  11  00",
        "00          11  11          00",
        "00          11  11          00",
        "0011  1111          1111  1100",
        "0022  1111          1111  2200",
        "00          11  11          00",
        "00          111111          00",
        "00  11  11  111111  11  11  00",
        "00  11  11  11  11  11  11  00",
        "00  11  11  11  11  11  11  00",
        "00  11  11  11  11  11  11  00",
        "00  11  11          11  11  00",
        "00  11  11          11  11  00",
        "00  11  11   1111   11  11  00",
        "00           1  1           00",
        "00           1  1           00",
        "000000000000000000000000000000",
    };

    this->mTexture.loadFromFile("media/groundSprites.png");
    this->mTexture.setSmooth(true);
    this->mSprite.setTexture(this->mTexture);
}

void Map::break_wall(const int &i, const int &j) {
    this->TileMap[i][j] = ' ';
}

void Map::draw(sf::RenderWindow &window) {
    for (int i(0); i < HEIGHT_MAP; i++)
        for (int j(0); j < WIDTH_MAP; j++) {
            switch (this->TileMap[i][j]) {
                case ' ':
                    mSprite.setTextureRect(sf::IntRect(0, 0, 24, 24));
                    this->TileMapData[i][j] = 1; // 1 denotes passable
                    break;

                case '0':
                    mSprite.setTextureRect(sf::IntRect(72, 0, 24, 24));
                    this->TileMapData[i][j] = -1; // denotes impassable
                    break;

                case '1':
                    mSprite.setTextureRect(sf::IntRect(24, 0, 24, 24));
                    this->TileMapData[i][j] = 2; // denotes destructable
                    break;

                case '2':
                    mSprite.setTextureRect(sf::IntRect(48, 0, 24, 24));
                    this->TileMapData[i][j] = -1; // denotes impassable
                    break;
            }

            mSprite.setPosition(j * 24, i * 24);
            window.draw(mSprite);
        }
    
}

int Map::getMapDataOnTile(int nRowNo, int nColNo){

    return this->TileMapData[nRowNo][nColNo];

}

void Map::setMapDataOnTile(int nRowNo, int nColNo, int nVal){


    this->TileMapData[nRowNo][nColNo] = nVal;


}

bool Map::getTilePassable(int i, int j){
    bool isPassable = true;

    if(this->TileMapData[i][j] != 1) isPassable = false;
    if(this->TileMapData[i+1][j] != 1) isPassable = false;
    if(this->TileMapData[i][j+1] != 1) isPassable = false;
    if(this->TileMapData[i+1][j+1] != 1) isPassable = false;
        
    return isPassable;
}

void Map::debug(){
    for(int i = 0; i < HEIGHT_MAP; i++){
        for(int j = 0; j < WIDTH_MAP; j++){
            if(getTilePassable(i,j)) std::cout<<" ";
            else std::cout<<"█";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl<<std::endl;
}
