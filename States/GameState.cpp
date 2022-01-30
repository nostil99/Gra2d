#include "GameState.h"
#include "MenuState.h"

GameState::GameState(GameEngine * game) {
    m_EnginePtr=game;

    InitData();
}
GameState::~GameState() {
    UnloadData();
}

void GameState::Input() {
    while (m_EnginePtr->m_Window->pollEvent(*event)) {
        if (event->type == sf::Event::Closed) {
            m_EnginePtr->m_Window->close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            m_EnginePtr->ChangeState(new MenuState(m_EnginePtr));
            return;
        }
    }
    player->Input();
}
void GameState::Draw() {

    m_EnginePtr->m_Window->draw(* m_BackgroundGame);
    m_Level_One->Draw(m_EnginePtr->m_Window->getView());
    player->Draw();
    for (int i = 0; i < m_GameItems.size(); i++) {
        m_GameItems[i]->Draw();
    }

}
void GameState::Update() {
   player->Update(m_EnginePtr->m_deltaTime);
    int checkItems = NO_GATHERED_STATE;
    for (int i = 0; i < m_GameItems.size(); i++) {
        checkItems = m_GameItems[i]->ColisionBottlePlayer();
        if (checkItems == ITEM_GATHERED_STATE) {
            delete m_GameItems[i];
            m_GameItems.erase(m_GameItems.begin() + i);
        }
    }
   return;
}
void GameState::InitData() {


    gameStateData = new GameStateData();
    m_BackgroundGame = new sf::Sprite;
    m_BackgroundTexture->loadFromFile("./assets/Background.png");
    m_BackgroundGame->setTexture(*m_BackgroundTexture);
    m_MenuFont->loadFromFile("./assets/MenuFont.ttf");
    gameStateData->playerSpriteSheet = new sf::Texture;
    gameStateData->playerSpriteSheet->loadFromFile("./assets/playerAsset.png");


    gameStateData->ItemTexture = new sf::Texture;
    gameStateData->ItemTexture->loadFromFile("./assets/Whysky.png");
    m_Level_One = new TileMap(m_EnginePtr);
InitDataLevel_1();

}
void GameState::UnloadData() {
    delete m_BackgroundTexture;
    delete m_BackgroundGame;
    delete m_MenuFont;

}



void GameState::InitDataLevel_1() {
    float tempScaleX = (1.0 * (((m_EnginePtr->m_Window->getSize().x) / 1280.0)));
    float tempScaleY = (1.0 * (((m_EnginePtr->m_Window->getSize().y) / 720.0)));


    view1.setCenter(sf::Vector2f((((float)m_EnginePtr->m_Window->getSize().x) / 2.0),
                                ((float)m_EnginePtr->m_Window->getSize().y) / 2.0));
    view1.setSize(sf::Vector2f(m_EnginePtr->m_Window->getSize().x, m_EnginePtr->m_Window->getSize().y));
    m_EnginePtr->m_Window->setView(view1);
    m_Level_One->Init(1);

    //FUNKCJA
    //Player
    player = new Player(m_EnginePtr,gameStateData);
    player->InitPlayer(m_Level_One);

    player->SetPlayerSize(50.0*tempScaleX, 70.0*tempScaleY);
    player->SetPlayerPosition(150.0*tempScaleX, 250.0*tempScaleY);
    player->SetPlayerScale(tempScaleX, tempScaleY);
    int temp_second_Y = 0.0f;
    int temp_second_X = 0.0f;
    if (tempScaleX > 1.0f) {
        temp_second_X=tempScaleX* tempScaleX * 5.0;
    }
    else {
        temp_second_X = tempScaleX;
    }
    player->SetPlayerSpeed(800.0f*temp_second_X);
    if (tempScaleY > 1.0f) {
        temp_second_Y = 1.0f;
    }
    else {
        temp_second_Y = tempScaleY;
    }
    player->SetPlayerJump(1200.0f*temp_second_Y);



    Items* Item1 = new Items(gameStateData, m_EnginePtr, ITEM);
    Item1->InitItem(player);
    Item1->SetItemPosition(50.0* tempScaleX, 550.0* tempScaleY);
    Item1->SetItemSize(50.0* tempScaleX, 50.0* tempScaleY);
    Item1->SetItemScale(0.5* tempScaleX, 0.5* tempScaleY);
    m_GameItems.push_back(Item1);
}




