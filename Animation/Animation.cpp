//
// Created by Jakub Stawiarz on 05/12/2021.
//

#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imagecount, float switchtime) {
    this->m_ImageCount = imagecount;
    this->m_SwitchTime = switchtime;
    m_TotalTime = 0.0f;
    m_CurrentImage.x = 0;
    TextureRect.width = texture->getSize().x / float(m_ImageCount.x);
    TextureRect.height = texture->getSize().y / float(m_ImageCount.y);
}
Animation::~Animation() {

}
void Animation::Update(int row, float dt) {
    m_CurrentImage.y = row;
    m_TotalTime = m_TotalTime + dt;
    if (m_TotalTime >= m_SwitchTime) {
        m_TotalTime = m_TotalTime - m_SwitchTime;
        m_CurrentImage.x = m_CurrentImage.x + 1;
        if (m_CurrentImage.x >= m_ImageCount.x) {
            m_CurrentImage.x = 0;
        }
    }
    TextureRect.left = m_CurrentImage.x * TextureRect.width;
    TextureRect.top = m_CurrentImage.y * TextureRect.height;
}