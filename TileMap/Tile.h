//
// Created by Jakub Stawiarz on 01/12/2021.
//

#ifndef GRA2D_TILE_H
#define GRA2D_TILE_H
#include <SFML/Graphics.hpp>

class Tile {
public:
        /**Konstruktor**/
        Tile() {}
        /**Destruktor **/
        ~Tile() {};
        /**Funkcja inicjujaca tilemape przyjmuje x szerokosc tilemapy y wysokosc tilemapy
         czyli szerokosc elementu  wysokosc elementu oraz  typ **/
        void Init(float x, float y, float width, float height, int type);
        /**Funkcja Update**/
        void Update();
        /**Fuknkcja Draw**/
        void Draw();
        /**Zmienne szerokosci i wysokosci tablicy tilemapy**/
        float m_x, m_y;
        /**Zmienna Szerokosc obiektu w tilemapie**/
        float m_width;
        /**Zmienna wysokosci w height**/
        float m_height;
        /**SFML Vertex Array**/
        sf::VertexArray m_vertex;
        /**Typ**/
        int m_type;
        /**RectangleShape**/
        sf::RectangleShape boxCollider;
};


#endif //GRA2D_TILE_H
