#ifndef GRA2D_GAMEENGINE_H
#define GRA2D_GAMEENGINE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>


class State;
class GameEngine {
public:

    enum WindowSize {
        /**Domyslna Szerokosc Okna Gry**/
        WINDOW_WIDTH =1280,
        /**Domyslny Wysokosc Okna Gry**/
        WINDOW_HEIGHT =720,
    };
    /**vector sluzacy jako stos przechowujacy state gry**/
    std::vector<State*> m_States;
    /**Okno gry klasa SFML**/
    sf::RenderWindow* m_Window;
    /**Klasa Silnika Gry**/
    sf::VideoMode* m_WindowVideoMode;
    /**Zmienna sluzaca do wyciszania lub dzialania dzwieku w grze**/
    bool m_Sound;
    std::string filename;
    /**Zmienna m_deltaTime**/
    float m_deltaTime;

    /**Funckja do update Delta Time**/
    void UpdateDeltaTime();
    GameEngine();
    ~GameEngine();
    void Run();
    void Input();
    void Update();
    void Draw();
    void ChangeState(State* state);
    /**Funkcja push na stos przyjmuje argument dany state gry**/
    void PushState(State* state);
    /**Funkcja do sciagniecia ze stosu przyjmuje argument dany state gry**/
    void PopState();
    /**Funkcja do odczytania opcji z pliku**/
    bool ReadSettings();
    /**Zmienna m_Fullscreen**/
    bool m_Fullscreen;
};


#endif //GRA2D_GAMEENGINE_H
