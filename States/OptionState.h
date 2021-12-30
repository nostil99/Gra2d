#ifndef GRA2D_OPTIONSTATE_H
#define GRA2D_OPTIONSTATE_H
#include "../GUI/Button.h"
#include "State.h"

class OptionState: public State{
private:
    float m_WindowWidth;
    float m_WindowHeight;

public:

    sf::Texture *optionsBackground;
    sf::Font *optionsFont;
    sf::Sprite *m_BackgroundOptionsMenu;
    sf::Music *m_OptionsMusic;
    Button* m_SoundOFF;
    Button* m_SoundON;
    Button* m_Resoultion1;
    Button* m_Resoultion2;
    Button* m_ResoultionFullscreen;
    Button* m_BackButton;
    sf::Vector2f m_MousePosition_View;

    OptionState(GameEngine * game);
    ~OptionState();

    void Input();
    void Update();
    void Draw();
    void InitData();
    void UnloadData();
    void SaveSettings(bool fullscreen);

    void SaveSettings(int screen_w, int screen_h);
    void SaveSound(bool sound);

};
#endif //GRA2D_OPTIONSTATE_H
