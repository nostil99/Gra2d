//
// Created by Jakub Stawiarz on 01/12/2021.
//

#include "TileMap.h"
#include <string>
#include <stdio.h>

void TileMap::Init( const int TileLevel) {

    platforma2.loadFromFile("./assets/platforma1.png");
    platforma1.loadFromFile("./assets/platforma2.png");
    platforma3.loadFromFile("./assets/platforma3.png");
    killPlatform.loadFromFile("./assets/BlackPlatform.png");

        InitLevel(m_TileGridLevel1);

}
void TileMap::Update() {

}
void TileMap::Draw(const sf::View& gameView) {
    for (int i = 0; i < m_layerStatic.size(); i++) {
        if ((m_layerStatic[i].m_x >= (gameView.getCenter().x - gameView.getSize().x / 2 - 50.0f)) &&
            (m_layerStatic[i].m_x <= (gameView.getCenter().x + gameView.getSize().x / 2 + 50.0f))) {
            if (m_layerStatic[i].m_type == PLATFORMA1) {
                m_EnginePtr->m_Window->draw(m_layerStatic[i].m_vertex, &platforma2);
            }
            if (m_layerStatic[i].m_type == PLATFORMA2) {
                m_EnginePtr->m_Window->draw(m_layerStatic[i].m_vertex, &platforma1);
            }
            if (m_layerStatic[i].m_type == PLATFORMA3) {
                m_EnginePtr->m_Window->draw(m_layerStatic[i].m_vertex, &platforma3);
            }
            if (m_layerStatic[i].m_type == KILLPLATFORM) {
                m_EnginePtr->m_Window->draw(m_layerStatic[i].m_vertex, &killPlatform);

            }

        }
    }
    for (int i = 0; i < m_layerStatic.size(); i++) {
        m_EnginePtr->m_Window->draw(m_layerStatic[i].boxCollider);
    }
}
void TileMap::InitLevel(int arr[][50]) {
    double temp_width = 50.0 * (double)m_EnginePtr->m_Window->getSize().x / 1280.0;
    double temp_height = 50.0 * (double)m_EnginePtr->m_Window->getSize().y / 720.0;
    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 50; j++) {
            if (arr[i][j] == PLATFORMA1) {
                Tile temp;
                temp.Init(j * temp_width, i * temp_height, temp_width, temp_height, arr[i][j]);
                m_layerStatic.push_back(temp);
            }
            if (arr[i][j] == PLATFORMA2) {
                Tile temp;
                temp.Init(j * temp_width, i * temp_height, temp_width, temp_height, arr[i][j]);
                m_layerStatic.push_back(temp);
            }
            if (arr[i][j] == PLATFORMA3) {
                Tile temp;
                temp.Init(j * temp_width, i * temp_height, temp_width, temp_height, arr[i][j]);
                m_layerStatic.push_back(temp);
            }
            if (arr[i][j] == KILLPLATFORM) {
                Tile temp;
                temp.Init(j * temp_width, i * temp_height, temp_width, temp_height, arr[i][j]);
                m_layerStatic.push_back(temp);
            }

        }
}
void TileMap::UnloadLevel() {
    m_layerStatic.clear();

}
