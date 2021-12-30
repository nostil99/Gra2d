#ifndef GRA2D_STATE_H
#define GRA2D_STATE_H
#include <iostream>
#include "../GameEngine/GameEngine.h"
class State {
public:
    virtual ~State() {}
    virtual void Input() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    GameEngine* m_EnginePtr;
    sf::Event * event = new sf::Event;
};
#endif //GRA2D_STATE_H
