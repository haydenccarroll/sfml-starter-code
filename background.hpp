/**
 * @file background.hpp
 * @author Hayden Carroll (haydencarroll77@gmail.com)
 * @brief Definition for Backgroud struct
 * @version 0.1
 * @date 2020-11-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once

#include <SFML/Graphics.hpp>
#include <string>


/**
 * @brief Background struct used for displaying a background for a RenderWindow
 * @details Has a texture and a sprite, which can be accessed directly.
 *          Has a function resetBackground(), which is useful for resetting
 *          the background to a different image
 */
struct Background
{
    sf::Texture texture;
    sf::Sprite sprite;
    Background(std::string fileName, sf::RenderWindow &window);
    void resetBackground(const std::string &fileName);

private:
    sf::RenderWindow* window_;

};
