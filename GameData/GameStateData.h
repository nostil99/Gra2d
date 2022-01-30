//
// Created by Jakub Stawiarz on 06/12/2021.
//

#ifndef GRA2D_GAMESTATEDATA_H
#define GRA2D_GAMESTATEDATA_H
struct  GameStateData
{
    ~GameStateData() {
        delete backgroundTexture;
        delete m_BackgroundGame;
        delete playerSpriteSheet;
        delete blackdirtTexture;
        delete m_GameMusic;
    }

    /**Wskaznik do textury tlo**/
    sf::Texture* backgroundTexture;
    /**Wskaznik do textury gracza**/
    sf::Texture* playerSpriteSheet;
    /**Wskaznik do textury czarny blok**/
    sf::Texture* blackdirtTexture;
    /**Wskaznik do sprite background**/
    sf::Sprite* m_BackgroundGame;
    /**Wskaznik do muzyki w grze**/
    sf::Music* m_GameMusic;

    /**Wskaznik do teksury itemu w grze**/
    sf::Texture *ItemTexture;
};
#endif //GRA2D_GAMESTATEDATA_H
