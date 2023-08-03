#include "../include/Map.h"


Map::Map(MapType EType) {

    this->EType = EType;

    if(this->EType == SPREAD){ /*Comment: true to its name, SPREAD is named as such as it is a relatively large map with a spread out environment, which encourages
                                play that involves holding corners and baiting enemies into advantageous positions*/

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

    }
    else if(this->EType == FORTRESS){ /*FORTRESS is a tighter map than SPREAD, which can hinder player movement and focuses on the players ability to chart a path by
                                        carving their own path through the environment, strategic players will form their own plays in this map*/

        this->TileMap = new sf::String[HEIGHT_MAP] {
        "000000000000000000000000000000",
        "00          11      11      00",
        "00          11      11  22  00",
        "00  11  11  22  22  11  11  00",
        "00  11  11  22  22  11  11  00",
        "00  11  11  11  11  11  11  00",
        "00  11  11  11  11  11  11  00",
        "00  22  22  111111  22  22  00",
        "00  11  11  111111  11  11  00",
        "00  11  11  11  11  11  11  00",
        "00  11  11          11  11  00",
        "00  22  22          22  22  00",
        "00          22  22          00",
        "00          22  22          00",
        "0011  1111          1111  1100",
        "0022  1111          1111  2200",
        "00          22  22    11    00",
        "00          111111   2222   00",
        "00  11  11  111111  11  11  00",
        "00  11  11  11  11  11  11  00",
        "00  11  11  11  11  11  11  00",
        "00  11  11  11  11  11  11  00",
        "00  11  11          11  11  00",
        "00  11  11          11  11  00",
        "00  11  11   2222   11  11  00",
        "00  22  22   1  1           00",
        "00           2  2           00",
        "000000000000000000000000000000",
        };


    }

    else if(this->EType == PLAINS) /*PLAINS is the most open of the three maps, promoting the players ability to dodge projectiles and position on the fly*/{

        this->TileMap = new sf::String[HEIGHT_MAP] {
        "000000000000000000000000000000",
        "00    2                  2  00",
        "00    2                  2  00",
        "00                          00",
        "00                          00",
        "00          11  11          00",
        "00                          00",
        "00  22  2222       2222 22  00",
        "00  11  11          11  11  00",
        "00  11  11          11  11  00",
        "00  11  11          11  11  00",
        "00                          00",
        "00                          00",
        "0022                        00",
        "0011  1111            1111  00",
        "0011  1111    22      1111  00",
        "00                    22    00",
        "00                          00",
        "00  22  22                  00",
        "00  11  11                  00",
        "00  11      11  11  11      00",
        "00  11                      00",
        "00  11  11                  00",
        "00  11  11                  00",
        "00  22  22  12122121    222200",
        "00                          00",
        "                            00",
        "000000000000000000000000000000",
        };



    }
    
    

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

MapType Map::getMapType(){

    return this->EType;

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
