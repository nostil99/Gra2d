#ifndef GRA2D_STATE_H
#define GRA2D_STATE_H
#include <iostream>
#include "../GameEngine/GameEngine.h"
class State {
public:
    virtual ~State() {}
    /** obsluga urzadzen wyjscia **/
    virtual void Input() = 0;
    /** aktualizacja**/
    virtual void Update() = 0;
    /** wyswietlanie **/
    virtual void Draw() = 0;
    /** wskaznik na silnik **/
    GameEngine* m_EnginePtr;
    /**zdarzenia **/
    sf::Event * event = new sf::Event;
};
#endif //GRA2D_STATE_H
