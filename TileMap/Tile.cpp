//
// Created by Jakub Stawiarz on 01/12/2021.
//

#include "Tile.h"



void Tile::Init(float x, float y, float width, float height, int type) {
    m_type = type;
    m_vertex.setPrimitiveType(sf::Quads);
    m_vertex.resize(width * height * 4);
    this->m_x = x;
    this->m_y = y;
    this->m_width = width;
    this->m_height = height;
    m_vertex[0].position=sf::Vector2f(m_x,m_y);
    m_vertex[1].position = sf::Vector2f(m_x+m_width ,m_y);
    m_vertex[2].position = sf::Vector2f(m_x + m_width, m_height + m_y);
    m_vertex[3].position = sf::Vector2f(m_x,m_y+m_height);

    m_vertex[0].texCoords = sf::Vector2f(1,1);
    m_vertex[1].texCoords = sf::Vector2f(50,1);
    m_vertex[2].texCoords = sf::Vector2f(50,50);
    m_vertex[3].texCoords = sf::Vector2f(1, 50);
    boxCollider.setPosition(sf::Vector2f(m_x, m_y));
    boxCollider.setSize(sf::Vector2f(m_width, m_height));
    boxCollider.setFillColor(sf::Color::Transparent);
    //boxCollider.setOutlineColor(sf::Color::Green);
    //boxCollider.setOutlineThickness(1);
}
void Tile::Update() {

}
void Tile::Draw() {
}