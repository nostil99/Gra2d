//
// Created by Jakub Stawiarz on 01/12/2021.
//

#ifndef GRA2D_TILEMAP_H
#define GRA2D_TILEMAP_H
#include "SFML/Graphics.hpp"
#include "Tile.h"
#include <vector>
#include "../GameEngine/GameEngine.h"
#include "../GameData/GameStateData.h"

/**Emnu Tekstur**/
enum TileTypes {
/**brake tekstury**/
    NONE=0,
    /**PLATFORMA1**/
    PLATFORMA1=1,
    /**PLATFORMA2**/
    PLATFORMA2=2,
    /**PLATFORMA3**/
    PLATFORMA3=3,
    /**KILLPLATFORM**/
    KILLPLATFORM=4,
};
/**enum leveli tilemapy**/
enum TileLevels {
/**level 1**/
    TILE_LEVEL_1=1,
};

class TileMap {
public:
    sf::Texture platforma1;
    sf::Texture platforma2;
    sf::Texture platforma3;
    sf::Texture killPlatform;
/**Konstruktor tworzacy obiekt przyjmuje wskaznik na silnik gry**/
    TileMap(GameEngine* engine,GameStateData * gameStateData) {

        this->m_EnginePtr = engine;

    }
    /**Destrukor**/
    ~TileMap() {
        m_layerStatic.clear();

    };
    /**Funkcja Init przyjmuje argument na  aktualny level w grze**/
    void Init(const int TileLevel);
    /**Funkcja Update**/
    void Update();
    /**Funckja Draw przyjmuje argument kamera**/
    void Draw(const sf::View& gameView);
    /**Funkcja inicjuje level**/
    void InitLevel(int arr[][50]);
    /**Funkcja usuwa date**/
    void UnloadLevel();
public:
    /**Vector objektow tile**/
    std::vector<Tile> m_layerStatic;
private:
    /**Wskaznik na silnik gry**/
    GameEngine* m_EnginePtr;
    /**level1**/
    int m_TileGridLevel1[17][50]=
            {{2,1,2,3,4,1,1,2,1,2,4,4,4,1,2,4,4,4,4,1,1,2,3,4,1,2,1,1,2,3,4,2,1,3,2,1,2,3,4,1,2,3,2,3,2,1,2,1,1,2,},
            {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
            {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
            {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
            {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,2,},
            {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
            {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,4,4,0,2,},
            {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,0,2,},
            {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
            {2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,1,2,3,3,3,2,1,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
            {2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,2,},
            {2,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
            {2,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,},
            {2,2,2,2,2,2,2,2,2,4,4,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,},
            {2,2,2,2,2,2,2,2,2,4,4,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,},
            {2,2,2,2,2,2,2,2,2,4,4,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,},
            {2,2,2,2,2,2,2,2,2,4,4,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,}};

};


#endif //GRA2D_TILEMAP_H
