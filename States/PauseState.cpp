//
// Created by Jakub Stawiarz on 30/01/2022.
//

#include "PauseState.h"
#include <iostream>
PauseState::PauseState(GameEngine* UDEngine) {
    m_EnginePtr = UDEngine;
    InitData();
}
PauseState::~PauseState() {
    UnloadData();
}
void PauseState::Input()
{
    sf::Event event;
    m_MousePosition_View = m_EnginePtr->m_Window->mapPixelToCoords(sf::Mouse::getPosition(*m_EnginePtr->m_Window));
    while (m_EnginePtr->m_Window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_EnginePtr->m_Window->close();
        }
    }
    m_BackButton->ButtonInput(m_MousePosition_View);
    m_ExitButton->ButtonInput(m_MousePosition_View);
}
void PauseState::Update() {
    if (m_BackButton->ButtonUpdate()) {
        sf::Time delayTime = sf::seconds(0.1);
        sf::sleep(delayTime);
        m_EnginePtr->PopState();
        return;
    }
    if (m_ExitButton->ButtonUpdate()) {
        sf::Time delayTime = sf::seconds(0.1);
        sf::sleep(delayTime);
        m_EnginePtr->m_Window->close();
        return;
    }
}
void PauseState::Draw() {
    m_EnginePtr->m_Window->draw(*m_BackgroundWon);
    m_EnginePtr->m_Window->draw(*text);

    m_BackButton->ButtonDraw(m_EnginePtr);
    m_ExitButton->ButtonDraw(m_EnginePtr);

}

void PauseState::InitData() {

    backgroundTexture = new sf::Texture;
    titleTexture = new sf::Texture;
    m_BackgroundWon = new sf::Sprite;
    m_TitleWon = new sf::Sprite;
    wonFont = new sf::Font;
    text= new sf::Text;

    backgroundTexture->loadFromFile("./assets/Background.png");
    wonFont->loadFromFile("./assets/MenuFont.ttf");
    text->setFont(*wonFont);
    text->setString("Pause");
    text->setFillColor(sf::Color::Red);
    text->setCharacterSize(90);
    text->setPosition((m_EnginePtr->m_Window->getSize().x / 2)-100.0f,150.f);

    m_BackgroundWon->setTexture(*backgroundTexture);
    m_TitleWon->setTexture(*titleTexture);

    m_BackgroundWon->setPosition(sf::Vector2f(0.0, 0.0));
    m_TitleWon->setScale(sf::Vector2f(0.9, 0.9));
    m_TitleWon->setPosition(sf::Vector2f((m_EnginePtr->m_Window->getSize().x / 2) - 385.f, 100));


    float tempCalculateWidth = 2.28 * ((m_EnginePtr->m_Window->getSize().x * 100) / 1280);
    float tempCalculateHeight = 0.51 * ((m_EnginePtr->m_Window->getSize().y * 100) / 720);
    float tempCalculateX = 5.26 * ((m_EnginePtr->m_Window->getSize().x * 100) / 1280);
    float tempCalculateY = 1.25 * ((m_EnginePtr->m_Window->getSize().y * 100) / 720);
    float tempScaleX = (1.0 * (((m_EnginePtr->m_Window->getSize().x) / 1280.0)));
    float tempScaleY = (1.0 * (((m_EnginePtr->m_Window->getSize().y) / 720.0)));
    m_BackgroundWon->setScale(tempScaleX, tempScaleY);
    m_BackButton = new Button(tempCalculateX, tempCalculateY * 2, tempCalculateWidth, tempCalculateHeight, *wonFont, "kontynuj");
    m_ExitButton = new Button(tempCalculateX, tempCalculateY *3, tempCalculateWidth, tempCalculateHeight, *wonFont, "Exit");
    view2.setCenter(sf::Vector2f((((float)m_EnginePtr->m_Window->getSize().x) / 2.0), ((float)m_EnginePtr->m_Window->getSize().y) / 2.0));
    view2.setSize(sf::Vector2f(m_EnginePtr->m_Window->getSize().x, m_EnginePtr->m_Window->getSize().y));
    m_EnginePtr->m_Window->setView(view2);
}
void PauseState::UnloadData() {
    //std::cout << "WON STATE DESTRUCTOR 2" << '\n';
    delete m_ExitButton;
    delete m_BackButton;
}