

#ifndef GRA2D_MENUSTATE_H
#define GRA2D_MENUSTATE_H
#include "State.h"
#include "../GUI/Button.h"


class MenuState : public State{
public:
    Button* m_HelpButton;
    Button* m_PlayButton;
    Button* m_SettingsButton;
    Button* m_ExitButton;
    sf::Vector2f m_MousePosition_View;
    sf::Texture* menuBackground;
    sf::Font *menuFont;
    sf::Sprite* m_BackgroundMenu;
    sf::Music* m_MenuMusic;
public:
    MenuState(GameEngine * gra);
    ~MenuState();

    void Input();
    void Update();
    void Draw();
    void InitData();
    void UnloadData();


};
#endif //GRA2D_MENUSTATE_H
