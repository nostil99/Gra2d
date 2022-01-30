//
// Created by Jakub Stawiarz on 30/01/2022.
//

#ifndef GRA2D_WINSTATE_H
#define GRA2D_WINSTATE_H


#include "State.h"
#include "../GUI/Button.h"

/**Klasa WonGameState**/
class WinState:public State {
public:
/**Konstruktor tworzacy obiekt klasy przyjmuje za parametr silnik gryr**/
    WinState(GameEngine* engine_ptr);
    /**Destruktor**/
    ~WinState();
    /**Funkja Input**/
    void Input();
    /**Funkcja Update**/
    void Update();
    /**Funkcja Draw**/
    void Draw();
    /**Wskaznik do  textury tla won**/
    sf::Texture* backgroundTexture;
    /**Wskaznik do textury tytul won**/
    sf::Texture* titleTexture;
    /**Wskaznik do font won**/
    sf::Font* wonFont;
    /**Wskaznik do sprite tlo won**/
    sf::Sprite* m_BackgroundWon;
    /**Wskaznik do sprite tytul won**/
    sf::Sprite* m_TitleWon;
    /**Wskaznik na przycisk Back**/
    Button* m_BackButton;
    /**Wskaznik na przycisk Exit**/
    Button* m_ExitButton;
    /**Pozycja myszy wedlug view**/
    sf::Vector2f m_MousePosition_View;
    /**Kamera**/
    sf::View view2;
    /**tytul wygtanej tekstowy**/
    sf::Text *text;

private:
    /**Funkcja inicjujaca date**/
    void InitData();
    /**Funkcja usuwajaca date**/
    void UnloadData();

};


#endif //GRA2D_WINSTATE_H
