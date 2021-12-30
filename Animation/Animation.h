#ifndef _ANIMATION_MANAGER_HPP_
#define _ANIMATION_MANAGER_HPP_
#include <SFML/Graphics.hpp>
/**Klasa do obslugi animacji**/
class Animation
{
public:
    /**Konstruktor przyjmuje texture, ilosc spritow w spritesheet
    oraz czas po jakim powinna zmienic sie klatka animacji**/
    Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchtime);
    /**Destruktor Animacji**/
    ~Animation();
    /**Funkcja przyjmuje ktory typ - row animacji powinnien byc odtworzony oraz delta time**/
    void Update(int row, float dt);
    /**Structura SFML**/
    sf::IntRect TextureRect;
private:
    /**Ilosc obrazow w animacji**/
    sf::Vector2u m_ImageCount;
    /**Aktualna klatka animacji**/
    sf::Vector2u m_CurrentImage;
    /**Calkowity czas animacji**/
    float m_TotalTime;
    /**Czas zmiany klatki**/
    float m_SwitchTime;

};
#endif
