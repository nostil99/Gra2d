#include "GameEngine.h"
#include "../States/MenuState.h"


GameEngine::GameEngine() {
    m_deltaTime=0.01f;
    filename = "../GameSettings.ini";
    m_Window = new sf::RenderWindow;
    m_WindowVideoMode = new sf::VideoMode;
    m_Window->setFramerateLimit(60);
    m_Window->setVerticalSyncEnabled(false);
    bool fullscreen = false;
    m_Sound = true;
    if (!ReadSettings()) {
        m_WindowVideoMode->width = WINDOW_WIDTH;
        m_WindowVideoMode->height = WINDOW_HEIGHT;
        m_Window->create(*m_WindowVideoMode, "Gra2d");
        std::ofstream config("../GameSettings.ini", std::ios::out | std::ios::trunc);
        if (config.is_open()) {
            config << m_WindowVideoMode->width<<std::endl;
            config << m_WindowVideoMode->height<<std::endl;
            config << fullscreen << std::endl;
            config << m_Sound << std::endl;
        }
        config.close();
    }
    else {
        std::ifstream config("./GameSettings.ini");
        if (config.is_open()) {
            config >> m_WindowVideoMode->width;
            config >> m_WindowVideoMode->height;
            config >> fullscreen;
            config >> m_Sound;
        }
        config.close();
        if (fullscreen == true) {
            m_Window->create(m_WindowVideoMode->getFullscreenModes()[0], "gra2d", sf::Style::Fullscreen);
        }
        else {
            m_Window->create(*m_WindowVideoMode, "gra2d");
        }
    }
    m_Fullscreen = fullscreen;
}
GameEngine::~GameEngine() {
    for (auto it = m_States.begin(); it != m_States.end(); it++) {
        delete *it;
    }
    m_States.clear();
    std::cout << m_States.size() << '\n';
    delete m_Window;
    m_Window = nullptr;
    delete m_WindowVideoMode;
    m_WindowVideoMode= nullptr;
}
void GameEngine::Run(){
    m_States.push_back(new MenuState(this));
    while (m_Window->isOpen())
    {
        Input();
        Update();
        Draw();
    }
}
void GameEngine::Input() {
    if (!m_States.empty()) {
        m_States.back()->Input();

    }
    else {
        m_Window->close();
    }
}
void GameEngine::Update()
{
    if (!m_States.empty()){
        m_States.back()->Update(); //(top)

    }
    else {
        m_Window->close();
    }
}
void GameEngine::Draw() {
    if (!m_States.empty()) {
        m_Window->clear();
        m_States.back()->Draw();
        m_Window->display();
    }
    else {
        m_Window->close();
    }
}

void GameEngine::ChangeState(State* state) {
    delete m_States.back();
    m_States.pop_back();
    m_States.push_back(state);
}
void GameEngine::PushState(State* state) {
    m_States.push_back(state);
}
void GameEngine::PopState() {
    delete m_States.back();
    m_States.pop_back();
}
bool GameEngine::ReadSettings() {
    if (std::ifstream(filename)) {
        return true;
    } else {
        return false;
    }

}



