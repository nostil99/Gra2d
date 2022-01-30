//
// Created by Jakub Stawiarz on 29/01/2022.
//

#ifndef GRA2D_ITEMS_H
#define GRA2D_ITEMS_H

#include "../Player/Player.h"

/**rodzaje przedmiotow**/
enum ItemsTypes{
    /**przedmiot do zbierania**/
    ITEM =1,
};
/**typy zebranych przedmiotow**/
enum ItemsStates {
    /**nie zebrano nic**/
    NO_GATHERED_STATE =0,
    /**zebrano przedmiot do zbierania**/
    ITEM_GATHERED_STATE=1,
};

class Items:public Entity {
public:
    /**konstruktor tworzacy obiekt przedmiotu w grze**/
    Items(GameStateData* gamedata,GameEngine* gameEngine,int type) {
        this->m_Gamedata = gamedata;
        this->m_EnginePtr = gameEngine;
        this->m_ItemType = type;
    };
    /**destruktor przdmiotu**/
    ~Items() {
    };
    /**Funkcja Inicjujaca obiekt przyjmuje argument wskaznik na gracza**/
    void InitItem(Player* character);
    /**Funkcja Ustawiajaca collider boxa
    przyjmuje 2 argumenty  szerokosc i wysokosc**/
    void SetItemSize(float width, float height);
    /**Funkcja Ustawiajaca Pozycje przedmioru do zbierania przyjmuje x i y **/
    void SetItemPosition(float x, float y);
    /**Funkcja Ustawiajaca skale textury przedmiotu przyjumje dwa argumenty
    x i y **/
    void SetItemScale(float scale_x, float scale_y);
    /**Funkcja Input do dodawania **/
    void Input();
    /**Funkcja Aktualizujaca o czas przyjmuje deltatime jako argument**/
    int Update(float dt);
    /**Funkcja Wyswietlajaca przedmiot **/
    void Draw();
    /**Funckja Sprawdzajaca kolizje przedmiotu z graczem**/
    int ColisionBottlePlayer();
    /**SFML Obiekt Prostokat boxu kolizji**/
    sf::RectangleShape m_HitBox;
    /**SFML Obiekt Sprite**/
    sf::Sprite m_Item;
    /**Wskaznik na strukture GameData ktora zawiera referencje do obiektow gry**/
    GameStateData* m_Gamedata;
    /**Wskaznik na obiekt/klase gracz**/
    Player* m_CharacterPtr;
    /**Zmienna okreslajaca typ przedmiotu**/
    int m_ItemType;
};


#endif //GRA2D_ITEMS_H
