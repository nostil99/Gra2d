//
// Created by Jakub Stawiarz on 05/11/2021.
//

#include "MenuState.h"
#include "OptionState.h"
#include "GameState.h"
MenuState::MenuState(GameEngine * gra) {
    m_EnginePtr = gra;
    InitData();
}
MenuState::~MenuState(){
    UnloadData();
}
void MenuState::Input()
{

    m_MousePosition_View = m_EnginePtr->m_Window->mapPixelToCoords(sf::Mouse::getPosition(*m_EnginePtr->m_Window));
    while (m_EnginePtr->m_Window->pollEvent(*event)) {
        if (event->type == sf::Event::Closed) {
            m_EnginePtr->m_Window->close();
        }
        m_PlayButton->ButtonInput(m_MousePosition_View);
        m_HelpButton->ButtonInput(m_MousePosition_View);
        m_SettingsButton->ButtonInput(m_MousePosition_View);
        m_ExitButton->ButtonInput(m_MousePosition_View);
    }
}
void MenuState::Update() {
    if (m_PlayButton->ButtonUpdate()) {
        m_MenuMusic->stop();
        sf::Time delayTime = sf::seconds(0.3);
        sf::sleep(delayTime);
        m_EnginePtr->PushState(new GameState(m_EnginePtr));
        return;
    }
    if(m_SettingsButton->ButtonUpdate()){
        sf::Time delayTime = sf::seconds(0.1);
        sf::sleep(delayTime);
        m_EnginePtr->ChangeState(new OptionState(m_EnginePtr));
        return;
    }
    if (m_HelpButton->ButtonUpdate()) {
        sf::Time delayTime = sf::seconds(0.1);
        sf::sleep(delayTime);


        return;
    }
    if(m_ExitButton->ButtonUpdate()){
        sf::Time delayTime = sf::seconds(0.1);
        sf::sleep(delayTime);
        m_EnginePtr->m_Window->close();
        return;
    }
}
void MenuState::Draw() {
    m_EnginePtr->m_Window->draw(*m_BackgroundMenu);
    m_PlayButton->ButtonDraw(m_EnginePtr);
    m_SettingsButton->ButtonDraw(m_EnginePtr);
    m_ExitButton->ButtonDraw(m_EnginePtr);
    m_HelpButton->ButtonDraw(m_EnginePtr);
}
void MenuState::InitData() {
    m_BackgroundMenu = new sf::Sprite;
    menuFont = new sf::Font;
    menuBackground = new sf::Texture;
    m_MenuMusic = new sf::Music;
    menuBackground->loadFromFile("./assets/Background.png");
    menuFont->loadFromFile("./assets/MenuFont.ttf");
    m_MenuMusic->openFromFile("./assets/MenuSong.wav");


    float tempCalculateWidth = 2.3*((m_EnginePtr->m_Window->getSize().x*100.f)/1280);
    float tempCalculateHeight = 0.5 * ((m_EnginePtr->m_Window->getSize().y * 100.f) / 720);
    float tempCalculateX = (m_EnginePtr->m_Window->getSize().x/2.0) - (tempCalculateWidth/2.0);
    float tempCalculateY = (m_EnginePtr->m_Window->getSize().y/3.0) - (tempCalculateHeight/2.0);
    float tempCalculateSpaceY=  ((m_EnginePtr->m_Window->getSize().y)-4*tempCalculateHeight)/8.0;

    float xScaleMenu=(float)m_EnginePtr->m_Window->getSize().x/(float)menuBackground->getSize().x;
    float yScaleMenu=(float)m_EnginePtr->m_Window->getSize().y/(float)menuBackground->getSize().y;

    std::cout<<tempCalculateHeight<<std::endl;
    std::cout<<tempCalculateX<<std::endl;
    std::cout<<tempCalculateHeight<<std::endl;

    m_PlayButton = new Button(tempCalculateX, tempCalculateY, tempCalculateWidth, tempCalculateHeight, *menuFont, "Start");
    m_SettingsButton = new Button(tempCalculateX, tempCalculateY+tempCalculateSpaceY, tempCalculateWidth, tempCalculateHeight, *menuFont, "Opcje");
    m_HelpButton = new Button(tempCalculateX, tempCalculateY + tempCalculateSpaceY*2, tempCalculateWidth, tempCalculateHeight, *menuFont, "Pomoc");
    m_ExitButton = new Button(tempCalculateX, tempCalculateY+ tempCalculateSpaceY*3, tempCalculateWidth, tempCalculateHeight, *menuFont, "Koniec");
    m_BackgroundMenu->setTexture(*menuBackground);
    m_BackgroundMenu->setPosition(sf::Vector2f(0.f, 0.f));
    m_BackgroundMenu->setScale(xScaleMenu, yScaleMenu);

    if (m_EnginePtr->m_Sound) {
        m_MenuMusic->setVolume(50.0f);
        m_MenuMusic->play();
    }

}

void MenuState::UnloadData() {
    m_MenuMusic->stop();
    delete m_PlayButton;
    m_PlayButton = nullptr;
    delete m_SettingsButton;
    m_SettingsButton = nullptr;
    delete m_ExitButton;
    m_ExitButton = nullptr;
    delete m_HelpButton;
    m_HelpButton = nullptr;
    delete menuBackground;
    delete menuFont;
    delete m_BackgroundMenu;

}