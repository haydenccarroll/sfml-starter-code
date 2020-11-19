/**
 * @file mainMenu.hpp
 * @author Hayden Carroll (haydencarroll77@gmail.com)
 * @brief definition of the MainMenu class
 * @version 0.1
 * @date 2020-11-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once

#include "gameState.hpp"
#include "background.hpp"

namespace sf
{
    class RenderWindow;
    class Event;
}
class Game;


/**
 * @brief Child of GameState, used to provide implementation for the 
 *        main menu of the game
 * 
 */
class MainMenu : public GameState
{
public:
    MainMenu(sf::RenderWindow &window, Game &game);
    ~MainMenu(){};
    virtual void handleInput(sf::Event &event);
    virtual void update();
    virtual void render();

private:
    Background background_;

};
