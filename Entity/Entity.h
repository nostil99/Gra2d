//
// Created by Jakub Stawiarz on 01/12/2021.
//



#ifndef GRA2D_ENTITY_H
#include "../GameEngine/GameEngine.h"


class Entity {
public:
    /**Metoda Wirtualna Input**/
    virtual void Input()= 0;
    /**Metoda Wirtualna Update**/
    virtual int Update(float dt) = 0;
    /**Metoda Wirtualna Draw**/
    virtual void Draw() = 0;
    /**Virtualny Destructor**/
    virtual ~Entity() {};
    /**Wskaznik na silnik gry**/
    GameEngine* m_EnginePtr;
private:
};




#endif //GRA2D_ENTITY_H
