/**
 * @file gameState.hpp
 * @author Hayden Carroll (haydencarroll77@gmail.com)
 * @brief Definition of GameState class
 * @version 0.1
 * @date 2020-11-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once

#include "game.hpp"

namespace std {class stack<class T>;};
namespace sf {class RenderWindow; class Event;};


/**
 * @brief An abstract class used to handle input, update, and render the game
 * @details This class is used within Game, as a way to make the game logic
 *          dependent on what state the game is in (such as MainMenu)
 * 
 */
class GameState
{
public:
    GameState(sf::RenderWindow &window, Game &game): window_(window), 
                                                     subState_(nullptr),
                                                     game_(game){};
    virtual ~GameState(){};
    virtual void handleInput(sf::Event &event) = 0;
    virtual void update() = 0;
    virtual void render() = 0;

protected:

    std::stack<GameState*>& getGameStateStack(){return game_.gameStateStack_;};
    GameState *subState_;
    sf::RenderWindow &window_;
    Game &game_;
};
