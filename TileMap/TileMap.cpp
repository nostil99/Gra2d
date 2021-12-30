//
// Created by Jakub Stawiarz on 01/12/2021.
//

#include "TileMap.h"
#include <string>
#include <stdio.h>

void TileMap::Init( const int TileLevel) {

    blackdirtTexture.loadFromFile("./assets/BlackPlatform.png");

        InitLevel(m_TileGridLevel1);

}
void TileMap::Update() {

}
void TileMap::Draw(const sf::View& gameView) {
    for (int i = 0; i < m_layerStatic.size(); i++) {
        if ((m_layerStatic[i].m_x >= (gameView.getCenter().x - gameView.getSize().x / 2 - 50.0f)) &&
            (m_layerStatic[i].m_x <= (gameView.getCenter().x + gameView.getSize().x / 2 + 50.0f))) {

            if (m_layerStatic[i].m_type == WALL) {
                m_EnginePtr->m_Window->draw(m_layerStatic[i].m_vertex, &blackdirtTexture);
            }

        }
    }
    for (int i = 0; i < m_layerStatic.size(); i++) {
        m_EnginePtr->m_Window->draw(m_layerStatic[i].boxCollider);
    }
}
void TileMap::InitLevel(int arr[][50]) {
    double temp_width = 50.0 * (double)m_EnginePtr->m_Window->getSize().x / 1280.0;
    double object_width = 200.0 * (double)m_EnginePtr->m_Window->getSize().x / 1280.0;
    double temp_height = 50.0 * (double)m_EnginePtr->m_Window->getSize().y / 720.0;
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 50; j++) {

            if (arr[i][j] == WALL) {
                Tile temp;
                temp.Init(j * temp_width, i * temp_height, temp_width, temp_height, arr[i][j]);
                m_layerStatic.push_back(temp);
            }

        }
}
void TileMap::UnloadLevel() {
    m_layerStatic.clear();

}
