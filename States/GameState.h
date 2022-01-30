#ifndef GRA2D_GAMESTATE_H
#define GRA2D_GAMESTATE_H
#include "State.h"
#include "../TileMap/TileMap.h"
#include "../Entity/Player/Player.h"
#include "../GameData/GameStateData.h"
#include "../Entity/Items/Items.h"

class GameState : public State{
public:
    /** tekstura tla gry **/
    sf::Sprite* m_BackgroundGame = new sf::Sprite;
    /** tekstura tla gry **/
    sf::Texture * m_BackgroundTexture = new sf::Texture;
    /**Vector obiektow typu przedmioty w grze do zbierania**/
    std::vector<Items*> m_GameItems;
    /**czcionka**/
    sf::Font *m_MenuFont = new sf::Font;
    /** kamera w grze **/
    sf::View view1;
    /** level 1 **/
    TileMap* m_Level_One;
    /** wskaznik na gracza **/
    Player * player;
    /** wskaznik na dane z gry**/
    GameStateData * gameStateData;

    GameState(GameEngine * game);
    ~GameState();
    /** Input czyli reakcja z klawiatura itd.. **/
    void Input();
    /** update czyli aktualizacja **/
    void Update();
    /** draw to wyswietlanie **/
    void Draw();
    /** inicjalizcja danych **/
    void InitData();
    /** usuniecie danych **/
    void UnloadData();


    void InitDataLevel_1();
};


#endif //GRA2D_GAMESTATE_H
