#include "GameState.h"
#include "MenuState.h"
#include "winState.h"
#include "LoseState.h"
#include "PauseState.h"

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
            m_EnginePtr->PushState(new PauseState(m_EnginePtr));
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

            std::cout << m_GameItems.size() << std::endl;
            delete m_GameItems[i];
            m_GameItems.erase(m_GameItems.begin() + i);
            if(m_GameItems.size()==0){
                std::cout<<"koniec gry" << std::endl;
                gameStateData->boolWinGame=true;
            }
        }
    }
    if(gameStateData->boolWinGame==true){

        m_EnginePtr->ChangeState(new WinState(m_EnginePtr));
    }
    if(gameStateData->boolLoseGame==true){

        m_EnginePtr->ChangeState(new LoseState(m_EnginePtr));
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
    gameStateData->ItemTexture->loadFromFile("./assets/planety.png");
    m_Level_One = new TileMap(m_EnginePtr,gameStateData);
InitDataLevel_1();

}
void GameState::UnloadData() {
    delete m_BackgroundTexture;
    delete m_BackgroundGame;
    delete m_MenuFont;

}



void GameState::InitDataLevel_1() {
    gameStateData->boolWinGame=false;
    gameStateData->boolLoseGame=false;
    if(m_EnginePtr->m_Window->getSize().x>1920){
        m_EnginePtr->m_deltaTime=0.05;
    }
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


//item1
    Items* Item1 = new Items(gameStateData, m_EnginePtr, ITEM);
    Item1->InitItem(player);
    Item1->SetItemPosition(50.0* tempScaleX, 550.0* tempScaleY);
    Item1->SetItemSize(50.0* tempScaleX, 50.0* tempScaleY);
    Item1->SetItemScale(0.5* tempScaleX, 0.5* tempScaleY);
    m_GameItems.push_back(Item1);
//item2
    Items* Item2 = new Items(gameStateData, m_EnginePtr, ITEM);
    Item2->InitItem(player);
    Item2->SetItemPosition(250.0* tempScaleX, 550.0* tempScaleY);
    Item2->SetItemSize(50.0* tempScaleX, 50.0* tempScaleY);
    Item2->SetItemScale(0.5* tempScaleX, 0.5* tempScaleY);
    m_GameItems.push_back(Item2);
    //item3
    Items* Item3 = new Items(gameStateData, m_EnginePtr, ITEM);
    Item3->InitItem(player);
    Item3->SetItemPosition(550.0* tempScaleX, 250.0* tempScaleY);
    Item3->SetItemSize(50.0* tempScaleX, 50.0* tempScaleY);
    Item3->SetItemScale(0.5* tempScaleX, 0.5* tempScaleY);
    m_GameItems.push_back(Item3);
    //item4
    Items* Item4 = new Items(gameStateData, m_EnginePtr, ITEM);
    Item4->InitItem(player);
    Item4->SetItemPosition(700.0* tempScaleX, 250.0* tempScaleY);
    Item4->SetItemSize(50.0* tempScaleX, 50.0* tempScaleY);
    Item4->SetItemScale(0.5* tempScaleX, 0.5* tempScaleY);
    m_GameItems.push_back(Item4);
    //item5
    Items* Item5 = new Items(gameStateData, m_EnginePtr, ITEM);
    Item5->InitItem(player);
    Item5->SetItemPosition(900.0* tempScaleX, 350.0* tempScaleY);
    Item5->SetItemSize(50.0* tempScaleX, 50.0* tempScaleY);
    Item5->SetItemScale(0.5* tempScaleX, 0.5* tempScaleY);
    m_GameItems.push_back(Item5);
    //item6
    Items* Item6 = new Items(gameStateData, m_EnginePtr, ITEM);
    Item6->InitItem(player);
    Item6->SetItemPosition(900.0* tempScaleX, 450.0* tempScaleY);
    Item6->SetItemSize(50.0* tempScaleX, 50.0* tempScaleY);
    Item6->SetItemScale(0.5* tempScaleX, 0.5* tempScaleY);
    m_GameItems.push_back(Item6);
    //item7
    Items* Item7 = new Items(gameStateData, m_EnginePtr, ITEM);
    Item7->InitItem(player);
    Item7->SetItemPosition(1200.0* tempScaleX, 150.0* tempScaleY);
    Item7->SetItemSize(50.0* tempScaleX, 50.0* tempScaleY);
    Item7->SetItemScale(0.5* tempScaleX, 0.5* tempScaleY);
    m_GameItems.push_back(Item7);
    //item8
    Items* Item8 = new Items(gameStateData, m_EnginePtr, ITEM);
    Item8->InitItem(player);
    Item8->SetItemPosition(1500.0* tempScaleX, 150.0* tempScaleY);
    Item8->SetItemSize(50.0* tempScaleX, 50.0* tempScaleY);
    Item8->SetItemScale(0.5* tempScaleX, 0.5* tempScaleY);
    m_GameItems.push_back(Item8);
    //item9
    Items* Item9 = new Items(gameStateData, m_EnginePtr, ITEM);
    Item9->InitItem(player);
    Item9->SetItemPosition(1600.0* tempScaleX, 400.0* tempScaleY);
    Item9->SetItemSize(50.0* tempScaleX, 50.0* tempScaleY);
    Item9->SetItemScale(0.5* tempScaleX, 0.5* tempScaleY);
    m_GameItems.push_back(Item9);
    //item8
    Items* Item10 = new Items(gameStateData, m_EnginePtr, ITEM);
    Item10->InitItem(player);
    Item10->SetItemPosition(1900.0* tempScaleX, 400.0* tempScaleY);
    Item10->SetItemSize(50.0* tempScaleX, 50.0* tempScaleY);
    Item10->SetItemScale(0.5* tempScaleX, 0.5* tempScaleY);
    m_GameItems.push_back(Item10);
}




