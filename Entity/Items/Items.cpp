//
// Created by Jakub Stawiarz on 29/01/2022.
//

#include "Items.h"

void Items::InitItem(Player* character) {
    this->m_CharacterPtr = character;
    m_HitBox.setFillColor(sf::Color::Transparent);
    if (m_ItemType == ITEM) {
        m_Item.setTexture(*m_Gamedata->ItemTexture);
    }
}
void Items::SetItemSize(float width, float height) {
    m_HitBox.setSize(sf::Vector2f(width, height));
}
void Items::SetItemPosition(float x, float y) {
    m_HitBox.setPosition(sf::Vector2f(x, y));
    m_Item.setPosition(sf::Vector2f(x, y));
}
void Items::SetItemScale(float scale_x, float scale_y) {
    m_Item.scale(sf::Vector2f(scale_x, scale_y));
}
void Items::Input() {
}
int Items::Update(float dt) {
    int check = ColisionBottlePlayer();
    return check;
}
void Items::Draw() {
    m_EnginePtr->m_Window->draw(m_Item);
    m_EnginePtr->m_Window->draw(m_HitBox);
}
int Items::ColisionBottlePlayer() {
    sf::FloatRect playerbounds = m_CharacterPtr->m_HitBox.getGlobalBounds();
    sf::FloatRect wallbounds = m_HitBox.getGlobalBounds();
    sf::FloatRect playerboundsNextPos = playerbounds;
    playerboundsNextPos.left = playerboundsNextPos.left + m_CharacterPtr->m_PlayerVelocityX * m_EnginePtr->m_deltaTime;
    playerboundsNextPos.top = playerboundsNextPos.top + m_CharacterPtr->m_PlayerVelocityY * m_EnginePtr->m_deltaTime;
    if (wallbounds.intersects(playerboundsNextPos)) {
        if (m_ItemType == ITEM) {
            return ITEM_GATHERED_STATE;
        }
    }
    return NO_GATHERED_STATE;
}
