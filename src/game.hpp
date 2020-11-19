/**
 * @file game.hpp
 * @author Hayden Carroll (haydencarroll77@gmail.com)
 * @brief Definition for Game class
 * @version 0.1
 * @date 2020-11-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once

#include <stack>

namespace sf {class RenderWindow;};
class GameState;


/**
 * @brief superclass that contains the whole game
 * 
 */
class Game
{
public:

    Game(sf::RenderWindow& window);
    void run();

protected:
    sf::RenderWindow& window_;
    std::stack<GameState*> gameStateStack_;

    friend class GameState;


};
