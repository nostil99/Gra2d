#ifndef GRA2D_GAMESTATE_H
#define GRA2D_GAMESTATE_H
#include "State.h"
#include "../TileMap/TileMap.h"
#include "../Entity/Player/Player.h"
#include "../GameData/GameStateData.h"
class GameState : public State{
public:
    sf::Sprite* m_BackgroundGame = new sf::Sprite;
    sf::Texture * m_BackgroundTexture = new sf::Texture;

    sf::Font *m_MenuFont = new sf::Font;
    sf::View view1;
    TileMap* m_Level_One;

    Player * player;
    GameStateData * gameStateData;

    GameState(GameEngine * game);
    ~GameState();

    void Input();
    void Update();
    void Draw();
    void InitData();
    void UnloadData();


    void InitDataLevel_1();
};


#endif //GRA2D_GAMESTATE_H
