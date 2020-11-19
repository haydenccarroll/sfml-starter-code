/**
 * @file background.cpp
 * @author Hayden Carroll (haydencarroll77@gmail.com)
 * @brief Implementation for Background struct
 * @version 0.1
 * @date 2020-11-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "background.hpp"

#include <SFML/Graphics.hpp>
#include <string>
#include <cstdlib>


/**
 * @brief Creates a new Background object
 * 
 * @param fileName file name to load background image from
 * @param window   reference to the render window
 */
Background::Background(std::string fileName, sf::RenderWindow &window) :
window_(&window)
{
    resetBackground(fileName);
}


/**
 * @brief resets the background of the sprite given a filename
 * @details Updates texture to the image corresponding to fileName,
 *          resizes the sprite display to the texture size,
 *          and resizes the sprite to the window size
 * @param fileName file name to load background image from
 */
void Background::resetBackground(const std::string &fileName)
{
    if (!texture.loadFromFile(fileName))
    {
        std::exit(EXIT_FAILURE);
    }
    sprite.setTexture(texture, true); // resizes the sprite to texture size

    float width = window_->getSize().x / sprite.getLocalBounds().width;
    float height = window_->getSize().y / sprite.getLocalBounds().height;

    sprite.setScale(width, height); // scales background to screen
}
