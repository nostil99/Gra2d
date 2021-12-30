#include "Player.h"
Player::Player(GameEngine* gameEngine, GameStateData* gamedata) {
    this->m_EnginePtr = gameEngine;
    this->m_Gamedata = gamedata;
    m_PlayerAnimation = new Animation(m_Gamedata->playerSpriteSheet, sf::Vector2u(4, 3), 0.25f);

}
Player::~Player() {
    delete m_PlayerAnimation;

}
void Player::InitPlayer(TileMap* tilemap) {
    this->m_Tilemap = tilemap;
    m_Player.setTexture(*m_Gamedata->playerSpriteSheet);
    m_HitBox.setFillColor(sf::Color::Red);
    //----------------------------------------------
    //m_HitBox.setOutlineColor(sf::Color::Red);
    //m_HitBox.setOutlineThickness(1);
    //----------------------------------------------
    m_PlayerVelocityX = 0.0f;
    m_PlayerVelocityY = 0.0f;
    float tempScaleX = (1.0 * (((m_EnginePtr->m_Window->getSize().x) / 1280.0)));
    float tempScaleY = (1.0 * (((m_EnginePtr->m_Window->getSize().y) / 720.0)));
    m_GravityY = 10.0f *tempScaleY;
    //Testowanie
    m_PlayerSpeed = 0.0f;
    m_Jump = true;
    //Initialization of PlayerCamera
    m_PlayerCamera.setCenter(sf::Vector2f((((float)m_EnginePtr->m_Window->getSize().x) / 2.0),
                                          ((float)m_EnginePtr->m_Window->getSize().y) / 2.0));
    m_PlayerCamera.setSize(sf::Vector2f(m_EnginePtr->m_Window->getSize().x, m_EnginePtr->m_Window->getSize().y));
    m_PlayerScale_X=0.0f;
    m_PlayerScale_Y=0.0f;
    m_MoveState= NO_INPUT;
    m_CheckGameStatus = DEFAULT_STATE;
    m_AnimationState = IDLE_ANIMATION;
    m_CheckFlip = false;



    m_LastInput = MOVE_RIGHT;

    colison = true;
    inAir=true;

}
void Player::SetPlayerSize(float width, float height) {
    //Pomyslimy nad redukcja pointerow
    m_HitBox.setSize(sf::Vector2f(width, height));

}
void Player::SetPlayerPosition(float x, float y) {
    m_Player.setPosition(x,y);
    m_HitBox.setPosition(x,y);
}
void Player::SetPlayerScale(float scale_x, float scale_y) {
    m_PlayerScale_X = scale_x;
    m_PlayerScale_Y = scale_y;
    m_Player.setScale(scale_x,scale_y);
}
void Player::Input() {
    m_PlayerVelocityX = m_PlayerVelocityX / 2;
    m_PlayerVelocityY = m_PlayerVelocityY + m_GravityY;

    sf::Event event;

    while (m_EnginePtr->m_Window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_EnginePtr->m_Window->close();
        }
    }


    //Do usniecia!!!
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        m_PlayerVelocityY = -(m_PlayerSpeed);
        m_MoveState = MOVE_UP;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        m_PlayerVelocityX = -m_PlayerSpeed;
        m_MoveState = MOVE_LEFT;
        m_LastInput = MOVE_LEFT;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        m_PlayerVelocityY = m_PlayerSpeed;
        m_MoveState = MOVE_DOWN;

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        m_PlayerVelocityX = m_PlayerSpeed;
        //Move to Update
        m_MoveState = MOVE_RIGHT;
        m_LastInput = MOVE_RIGHT;
    }
    if (m_Jump == true) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            m_PlayerVelocityY = -(m_PlayerJump);
            m_Jump = false;
            m_MoveState = JUMP;
            m_AnimationState = JUMP_ANIMATION;
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::K)){
        if(colison){
            colison=false;
        }
        else{
            colison=true;
        }
    }
}
int Player::Update(float dt) {
    //Kolizja z tilemap


    ColisionPlayerTilemap();
    //Kolizja z borderem
    if (m_HitBox.getPosition().y > m_EnginePtr->m_Window->getSize().y) {
       m_PlayerVelocityY = 0.0;
       m_HitBox.setPosition(m_HitBox.getPosition().x, m_HitBox.getPosition().y - m_HitBox.getGlobalBounds().width);
   }
    m_HitBox.move(m_PlayerVelocityX * dt, m_PlayerVelocityY * dt);
    m_Player.setPosition((m_HitBox.getPosition().x- m_HitBox.getGlobalBounds().width/((float)2)),
                       (m_HitBox.getPosition().y- (m_HitBox.getGlobalBounds().height / ((float)2))+10.0f));

//    if(inAir){
//
//
//            if (m_Player.getPosition().x + 50.0 <= (m_HitBox.getGlobalBounds().width * 50.0 - m_EnginePtr->m_Window->getSize().x / 2))
//            {
//                m_PlayerCamera.move(m_PlayerVelocityX*dt, m_PlayerVelocityY*dt);
//                //m_Gamedata->m_BackgroundGame->move(m_PlayerVelocityX * dt, 0);
//
//            }
//
//    }
//    if(!inAir){
//        m_PlayerCamera.move(m_PlayerVelocityX*dt, m_PlayerVelocityY*dt);
//
//    }

    if (m_MoveState==MOVE_LEFT) {
        if ((m_PlayerCamera.getCenter().x - (m_EnginePtr->m_Window->getSize().x / 2)) >= 0.0)
        {
            if (m_Player.getPosition().x + 50.0 <= (m_HitBox.getGlobalBounds().width * 50.0 - m_EnginePtr->m_Window->getSize().x / 2))
            {
                m_PlayerCamera.move(m_PlayerVelocityX * dt, 0.0);
                //m_Gamedata->m_BackgroundGame->move(m_PlayerVelocityX * dt, 0);
                m_EnginePtr->m_Window->setView(m_PlayerCamera);
            }
        }
    }
    if (m_MoveState == MOVE_RIGHT) {
        if ((m_Player.getPosition().x + 50.0) >= m_PlayerCamera.getCenter().x)
        {

            if (m_Player.getPosition().x + 50.0 <= (m_HitBox.getGlobalBounds().width * 50.0- m_EnginePtr->m_Window->getSize().x / 2))
            {
                m_PlayerCamera.move(m_PlayerVelocityX * dt, 0);
                //m_Gamedata->m_BackgroundGame->move(m_PlayerVelocityX * dt, 0);;
                m_EnginePtr->m_Window->setView(m_PlayerCamera);
            }
        }
    }
    //Animacje
    if (m_MoveState == NO_INPUT) {
        m_AnimationState = IDLE_ANIMATION;
    }
    if (m_MoveState == MOVE_RIGHT) {
        m_CheckFlip = false;
        m_Player.setScale(m_PlayerScale_X, m_PlayerScale_Y);
        if (m_AnimationState != JUMP_ANIMATION) {
            m_AnimationState = RUN_ANIMATION;
        }
        m_MoveState = NO_INPUT;

    }
    if (m_MoveState == MOVE_LEFT) {
        m_CheckFlip = true;
        m_Player.setScale(-m_PlayerScale_X, m_PlayerScale_Y);
        if (m_AnimationState != JUMP_ANIMATION) {
            m_AnimationState = RUN_ANIMATION;
        }
        m_MoveState = NO_INPUT;
    }


    if (m_CheckFlip == true) {
        m_Player.setPosition(m_Player.getPosition().x + m_Player.getGlobalBounds().width, m_Player.getPosition().y);
    }
    m_PlayerAnimation->Update(m_AnimationState, dt);
    m_Player.setTextureRect(m_PlayerAnimation->TextureRect);


    m_EnginePtr->m_Window->setView(m_PlayerCamera);
    return m_CheckGameStatus;
}
void Player::Draw() {

    m_EnginePtr->m_Window->draw(m_Player);
    m_EnginePtr->m_Window->draw(m_HitBox);

}
void Player::SetPlayerSpeed(float speed) {
    m_PlayerSpeed = 200;
}
void Player::ColisionPlayerTilemap() {
    for (int i = 0; i < m_Tilemap->m_layerStatic.size(); i++) {
        sf::FloatRect playerbounds = m_HitBox.getGlobalBounds();
        sf::FloatRect wallbounds = m_Tilemap->m_layerStatic[i].boxCollider.getGlobalBounds();
        sf::FloatRect playerboundsNextPos = playerbounds;
        playerboundsNextPos.left = playerboundsNextPos.left + m_PlayerVelocityX * m_EnginePtr->m_deltaTime;
        playerboundsNextPos.top = playerboundsNextPos.top + m_PlayerVelocityY * m_EnginePtr->m_deltaTime;
        if (wallbounds.intersects(playerboundsNextPos)) {



                //Right Player Collision
                if (playerbounds.left < wallbounds.left &&
                    playerbounds.left + playerbounds.width < wallbounds.left + wallbounds.width
                    && playerbounds.top < wallbounds.top + wallbounds.height
                    && playerbounds.top + playerbounds.height > wallbounds.top
                        ) {
                    if(colison) {
                        m_PlayerVelocityX = 0.0;
                        m_HitBox.setPosition(wallbounds.left - playerbounds.width, playerbounds.top);
                    }
                }
                    //Left Player Collision
                else if (playerbounds.left > wallbounds.left &&
                         playerbounds.left + playerbounds.width > wallbounds.left + wallbounds.width
                         && playerbounds.top < wallbounds.top + wallbounds.height
                         && playerbounds.top + playerbounds.height > wallbounds.top) {
                    if(colison) {
                        m_PlayerVelocityX = 0.0;
                        m_HitBox.setPosition(wallbounds.left + wallbounds.width, playerbounds.top);
                    }
                }

                //Top Player Collision
            else if ((playerbounds.top > wallbounds.top &&
                     playerbounds.top + playerbounds.height > wallbounds.top + wallbounds.height
                     && playerbounds.left<wallbounds.left + wallbounds.width
                     && playerbounds.left + playerbounds.width>wallbounds.left)
                     || playerbounds.top<0

                    )
            {
                m_PlayerVelocityY = 0.0;
                m_HitBox.setPosition(playerbounds.left, wallbounds.top + wallbounds.height);
            }
                //Bottom Player Collision
            else if (playerbounds.top < wallbounds.top &&
                     playerbounds.top + playerbounds.height < wallbounds.top + wallbounds.height
                     && playerbounds.left<wallbounds.left + wallbounds.width
                     && playerbounds.left + playerbounds.width>wallbounds.left
                    )

            {
                m_PlayerVelocityY = 0.0;
                m_Jump = true;
                m_AnimationState = IDLE_ANIMATION;
                m_HitBox.setPosition(playerbounds.left, wallbounds.top - playerbounds.height);
            }
            else{
                inAir=true;
            }

            if(playerbounds.left<10
            ){
                m_PlayerVelocityX = 0.0;
                m_HitBox.setPosition(playerbounds.left+10, 0);
                std::cout<<"dziala"<<std::endl;
            }
        }
        std::cout<< "x  " << m_Player.getPosition().x <<"  y" << m_Player.getPosition().y <<std::endl;
    }

}


void Player::SetPlayerJump(float jump) {
    m_PlayerJump = jump;
}