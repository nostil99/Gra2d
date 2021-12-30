#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_
#include <vector>
#include "../../TileMap/TileMap.h"
#include "../../Animation/Animation.h"
#include "../Entity.h"



/**Enum zawierajacy informacje o nacisnietym klawiszu**/
enum InputStates {
    /**Brak wcisnietego klawisza**/
    NO_INPUT = 0,
    /**Skok czyli spacja**/
    JUMP = 1,
    /**Ruch w prawo, klawisz D**/
    MOVE_RIGHT = 2,
    /**Ruch w lewo, klawisz A**/
    MOVE_LEFT = 3,
    /**Ruch w gore klawisz W / wersja developerska / nie uzywana przez gracza**/
    MOVE_UP =4,
    /**Ruch w dol, klawisz S / wersja developerska / nie uzywana przez gracza**/
    MOVE_DOWN=5,


};
/**Enum zawierajacy stany gry**/
enum GameStatus
{
    /**Stan domyslny**/
    DEFAULT_STATE = 0,
};
/**Enum zawierajacy informacje o stanach animacji postaci**/
enum AnimationStates {
    /**Animacja spoczynek**/
    IDLE_ANIMATION =0,
    /**Animacja biegu**/
    RUN_ANIMATION=1,
    /**Animacja skoku**/
    JUMP_ANIMATION=2,


};
/**Klasa gracza**/
class Player:public Entity
{
public:

    /**Konstruktor Gracza przyjmuje agrumenty, wskaznik  na silnik i wskaznik na game data**/
    Player(GameEngine* gameEngine, GameStateData* gamedata);
    /**Destruktor gracza**/
    ~Player();
    /**Funkcja Inicujaca garcza przyjmuje argument wskaznik na obiekt mapy**/
    void InitPlayer(TileMap* tilemap);
    /**Funkcja ustawia rozmiar gracza przyjmuje argumenty width i height**/
    void SetPlayerSize(float width, float height);
    /**Funkcja ustawia pozycje gracza przyjmuje argumenty x i y**/
    void SetPlayerPosition(float x, float y);
    /**Funkcja ustawia skale tekstury gracza przyjmuje argumenty  scale_x i scale_y**/
    void SetPlayerScale(float scale_x, float scale_y);
    /**Funkcja ustawia  predkosc gracza**/
    void SetPlayerSpeed(float speed);
    /**funkcja ustawia wysokosc skoku gracza**/
    void SetPlayerJump(float jump);
    /**Funkcja Input**/
    void Input();
    /**Funkcja Update**/
    int Update(float dt);
    /**Funkcja Draw**/
    void Draw();
    /**Funkcja sprawdza kolizje gracza z mapa**/
    void ColisionPlayerTilemap();
    /**SFML RectangleShape**/
    sf::RectangleShape m_HitBox;
    /**SFML sprite**/
    sf::Sprite m_Player;
    /**Wskaznik date gry**/
    /**SFML View kamera gracza**/
    sf::View m_PlayerCamera;

    /**Wskaznik na obiekt mapy**/
    TileMap* m_Tilemap;
    /**Zmienna odpowiedzialna za grawitacje**/
    float  m_GravityY;
    /**Zmienna predkosc gracza na osi X**/
    float  m_PlayerVelocityX;
    /**Zmienna predkosc gracza na osi Y**/
    float  m_PlayerVelocityY;
    /**Zmienna przetrzymujaca informacje czy skok jest mozliwy**/
    bool m_Jump;
    /**Zmienna przechowujaca predkosc gracza**/
    float m_PlayerSpeed;
    /**Zmiennna przetrzymujaca  aktualny stan ruchu gracza**/
    int m_MoveState;
    /**Zmienna przechowujaca stan gry**/
    int m_CheckGameStatus;
    /**Zmienna przechowujaca  aktualny stan/typ animacji**/
    int m_AnimationState;
    /**Wskaznik na obiekt animacji gracza**/
    Animation* m_PlayerAnimation;
    /**Zmienna przechowujaca informacje czy mozna obrocic teksture wertykalnie**/
    bool m_CheckFlip;
/**Wskaznik date gry**/
    GameStateData* m_Gamedata;
    int m_LastInput;
    /**zmienna odpowiadajaca za przenikanie w kolizji*/
    bool colison;
    /**zmiena odpowiadajaca czy postac jest w pomietrzu*/
    bool inAir;
private:
    /**Zmienna przehcowujaca informacje o skali gracza X**/
    float m_PlayerScale_X;
    /**Zmienna przechowujaca o skali gracza Y**/
    float m_PlayerScale_Y;
    /**Zmiennna przechowujaca wartosc, zasieg skoku**/
    float m_PlayerJump;
};

#endif

