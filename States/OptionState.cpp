#include "OptionState.h"
#include "MenuState.h"
OptionState::OptionState(GameEngine * game) {
m_EnginePtr=game;
InitData();
}

OptionState::~OptionState() {
    UnloadData();
}

void OptionState::Input() {

    m_MousePosition_View = m_EnginePtr->m_Window->mapPixelToCoords(sf::Mouse::getPosition(*m_EnginePtr->m_Window));
    while (m_EnginePtr->m_Window->pollEvent(*event)) {
        if (event->type == sf::Event::Closed) {
            m_EnginePtr->m_Window->close();
        }
        m_SoundON->ButtonInput(m_MousePosition_View);
        m_SoundOFF->ButtonInput(m_MousePosition_View);
        m_BackButton->ButtonInput(m_MousePosition_View);
        m_ResoultionFullscreen->ButtonInput(m_MousePosition_View);
        m_Resoultion1->ButtonInput(m_MousePosition_View);
        m_Resoultion2->ButtonInput(m_MousePosition_View);
    }
}

void OptionState::Update() {
    if (m_BackButton->ButtonUpdate()) {
        m_EnginePtr->ChangeState(new MenuState(m_EnginePtr));
        return;
    }
    if (m_Resoultion1->ButtonUpdate()) {
        const int screen_width = 1280;
        const int screen_height = 720;
        SaveSettings(screen_width, screen_height);
        if(m_EnginePtr->m_Fullscreen){

        }
        else
        {
            m_EnginePtr->m_Window->setSize(sf::Vector2u(screen_width,screen_height));
            m_EnginePtr->ChangeState(new OptionState(m_EnginePtr));
        }
        return;
    }
    if (m_Resoultion2->ButtonUpdate()) {
        const int screen_width = 1600;
        const int screen_height = 900;
        SaveSettings(screen_width, screen_height);
        if(m_EnginePtr->m_Fullscreen){

        }
        else
        {
            m_EnginePtr->m_Window->setSize(sf::Vector2u(screen_width,screen_height));
            m_EnginePtr->ChangeState(new OptionState(m_EnginePtr));
        }
        return;
    }
    if (m_ResoultionFullscreen->ButtonUpdate()) {
        if(m_EnginePtr->m_Fullscreen)
        {
        m_EnginePtr->m_WindowVideoMode->getFullscreenModes();
        }else{
            bool fullscreen = true;
            SaveSettings(fullscreen);
            }

        return;
    }
    if (m_SoundON->ButtonUpdate()) {
        bool soundON = true;
        SaveSound(soundON);
        return;
    }
    if (m_SoundOFF->ButtonUpdate()) {
        bool soundOFF = false;
        SaveSound(soundOFF);
        return;
    }
}

void OptionState::Draw() {
    m_EnginePtr->m_Window->draw(*m_BackgroundOptionsMenu);
    m_SoundON->ButtonDraw(m_EnginePtr);
    m_SoundOFF->ButtonDraw(m_EnginePtr);
    m_BackButton->ButtonDraw(m_EnginePtr);
    m_ResoultionFullscreen->ButtonDraw(m_EnginePtr);
    m_Resoultion1->ButtonDraw(m_EnginePtr);
    m_Resoultion2->ButtonDraw(m_EnginePtr);
}

void OptionState::InitData() {

    optionsBackground = new sf::Texture;
    m_BackgroundOptionsMenu = new sf::Sprite;
    optionsFont = new sf::Font;
    m_OptionsMusic = new sf::Music;

    double tempCalculateWidth = 2.3*((m_EnginePtr->m_Window->getSize().x*100.0)/1280);
    double tempCalculateHeight = 0.5 * ((m_EnginePtr->m_Window->getSize().y * 100.0) / 720);
    double tempCalculateX = (m_EnginePtr->m_Window->getSize().x/2.0) - (tempCalculateWidth/2.0);
    double tempCalculateY = (m_EnginePtr->m_Window->getSize().y/3.0) - (tempCalculateHeight/2.0);
    double tempCalculateSpace =  ((m_EnginePtr->m_Window->getSize().x)-4*tempCalculateWidth)/5.0;
    double tempSpaceX = 10.0;



    optionsBackground->loadFromFile("./assets/Background.png");
    optionsFont->loadFromFile("./assets/MenuFont.ttf");
    m_OptionsMusic->openFromFile("./assets/MenuSong.wav");

    float ScaleOptionX=(float)m_EnginePtr->m_Window->getSize().x/(float)optionsBackground->getSize().x;
    float ScaleOptionY=(float)m_EnginePtr->m_Window->getSize().y/(float)optionsBackground->getSize().y;

    m_SoundON = new Button(tempCalculateX - tempCalculateWidth/2 -tempSpaceX, tempCalculateY, tempCalculateWidth, tempCalculateHeight, *optionsFont, "Sound ON");
    m_SoundOFF = new Button(tempCalculateX + tempCalculateWidth/2 + tempSpaceX, tempCalculateY, tempCalculateWidth, tempCalculateHeight, *optionsFont, "Sound OFF");
    m_Resoultion1 = new Button(tempCalculateX - tempCalculateWidth/2 -tempSpaceX, tempCalculateY+tempCalculateSpace, tempCalculateWidth, tempCalculateHeight, *optionsFont, "1280x720");
    m_Resoultion2 = new Button(tempCalculateX + tempCalculateWidth / 2 +tempSpaceX, tempCalculateY +tempCalculateSpace, tempCalculateWidth, tempCalculateHeight, *optionsFont, "1600x900");
    m_ResoultionFullscreen= new Button(tempCalculateX, tempCalculateY +tempCalculateSpace *2,tempCalculateWidth, tempCalculateHeight, *optionsFont, "Fullscreen");
    m_BackButton = new Button(tempCalculateX, tempCalculateY +tempCalculateSpace * 4, tempCalculateWidth, tempCalculateHeight, *optionsFont, "Back");
    m_BackgroundOptionsMenu->setTexture(*optionsBackground);
    m_BackgroundOptionsMenu->setPosition(sf::Vector2f(0.f, 0.f));
    m_BackgroundOptionsMenu->setScale(ScaleOptionX, ScaleOptionY);
    if (m_EnginePtr->m_Sound) {
        m_OptionsMusic->setVolume(50.0f);
        m_OptionsMusic->play();
    }
}

void OptionState::SaveSettings(bool fullscreen) {
    std::ofstream config("./GameSettings.ini", std::ios::out | std::ios::trunc);
    if (config.is_open()) {
        config << m_EnginePtr->m_WindowVideoMode->width << std::endl;
        config << m_EnginePtr->m_WindowVideoMode->height << std::endl;
        config << fullscreen << std::endl;
    }
    config.close();
}

void OptionState::SaveSettings(int screen_w, int screen_h) {
    std::ofstream config("./GameSettings.ini", std::ios::out | std::ios::trunc);
    if (config.is_open()) {
        m_WindowHeight = screen_h;
        m_WindowWidth = screen_w;
        config << m_WindowWidth<< std::endl;
        config << m_WindowHeight << std::endl;
        config << 0 << std::endl;
    }
    config.close();
}

void OptionState::SaveSound(bool sound) {
    std::ifstream config_read("./GameSettings.ini");
    if (config_read.is_open()) {
        config_read >> m_WindowWidth;
        config_read >> m_WindowHeight;
        config_read >> m_EnginePtr->m_Fullscreen;
    }
    config_read.close();

    std::ofstream config_write("./GameSettings.ini", std::ios::out | std::ios::trunc);
    if (config_write.is_open()) {
        m_EnginePtr->m_Sound = sound;
        config_write << m_WindowWidth << std::endl;
        config_write << m_WindowHeight << std::endl;
        config_write << m_EnginePtr->m_Fullscreen << std::endl;
        config_write << m_EnginePtr->m_Sound << std::endl;
    }
    config_write.close();
}

void OptionState::UnloadData() {
    m_OptionsMusic->stop();
    //std::cout << "OPTIONS MENU DESTRUCTOR 2" << '\n';
    delete m_BackButton;
    m_BackButton = nullptr;
    delete m_SoundON;
    m_SoundON = nullptr;
    delete m_SoundOFF;
    m_SoundOFF = nullptr;
    delete m_Resoultion1;
    m_Resoultion1 = nullptr;
    delete m_Resoultion2;
    m_Resoultion2 = nullptr;
    delete m_ResoultionFullscreen;
    m_ResoultionFullscreen = nullptr;
    delete optionsBackground;
    delete optionsFont;
    delete m_BackgroundOptionsMenu;
    delete m_OptionsMusic;
}