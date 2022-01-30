#ifndef GRA2D_BUTTON_H
#define GRA2D_BUTTON_H
#include <SFML/Graphics.hpp>
#include "../GameEngine/GameEngine.h"
#include <string>

enum BUTTON_STATES {
    BUTTON_PRESSED,
    BUTTON_HOVER,
    BUTTON_IDLE,
};
struct Colors{
    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color pressedColor;
};
class Button{
public:
    /** Konstruktor przycisku przyjmuje x,y,szerokosc,wysokosc,czcionka,tekst **/
    Button(float x, float y, double width, double height, sf::Font font, std::string text) {
        m_ButtonColors = new Colors;
        m_ButtonColors->pressedColor = sf::Color(20, 20, 20, 200);
        m_ButtonColors->hoverColor = sf::Color(200, 255, 255, 200);
        m_ButtonColors->idleColor = sf::Color(255, 255, 255, 60);
        m_ButtonShape.setPosition(sf::Vector2f (x, y));
        m_ButtonShape.setSize(sf::Vector2f(width, height));
        //m_ButtonShape.setOutlineThickness(2.f);
        //m_ButtonShape.setOutlineColor(sf::Color::Black);
        m_ButtonFont = font;
        m_ButtonText.setFont(m_ButtonFont);
        m_ButtonText.setString(text);
        m_ButtonText.setFillColor(sf::Color::White);
        m_ButtonText.setCharacterSize(40);
        //m_ButtonText.setOutlineColor(sf::Color::Black);
        //m_ButtonText.setOutlineThickness(1.f);
        // m_ButtonText.setLetterSpacing(2.f);
        m_ButtonText.setPosition(m_ButtonShape.getPosition().x +(m_ButtonShape.getGlobalBounds().width / 2.f)-(m_ButtonText.getGlobalBounds().width/2.f),
                                 m_ButtonShape.getPosition().y +(m_ButtonShape.getGlobalBounds().height / 2.f)-(m_ButtonText.getGlobalBounds().height/2.f)-10.0);
        m_ButtonShape.setFillColor(m_ButtonColors->idleColor);
        m_ButtonState = BUTTON_IDLE;
    }
    ~Button() {
        delete m_ButtonColors;
        m_ButtonColors = nullptr;
    }
    /** odpowiada za pokazywanie interakcji z przyciskiem **/
    void ButtonInput(sf::Vector2f mousepos) {
        m_ButtonState = BUTTON_IDLE;
        if (m_ButtonShape.getGlobalBounds().contains(mousepos)) {
            m_ButtonState = BUTTON_HOVER;
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                m_ButtonState =BUTTON_PRESSED;
            }
        }
    }
    /** aktualizuje stan **/
    bool ButtonUpdate() {
        if (m_ButtonState == BUTTON_IDLE) {
            m_ButtonShape.setFillColor(m_ButtonColors->idleColor);
            return false;
        }
        else if (m_ButtonState == BUTTON_HOVER) {
            m_ButtonShape.setFillColor(m_ButtonColors->hoverColor);
            return false;
        }
        else if (m_ButtonState == BUTTON_PRESSED) {
            m_ButtonShape.setFillColor(m_ButtonColors->pressedColor);
            return true;
        }
        return false;
    }
    /** rysuje przycisk **/
    void ButtonDraw(GameEngine* enginePtr) {
        enginePtr->m_Window->draw(m_ButtonShape);
        enginePtr->m_Window->draw(m_ButtonText);
    }
public:
    sf::RectangleShape m_ButtonShape;
    sf::Font m_ButtonFont;
    sf::Text m_ButtonText;
    Colors* m_ButtonColors;
    int m_ButtonState;
};

#endif //GRA2D_BUTTON_H
