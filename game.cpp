/**
 * @file game.cpp
 * @author Hayden Carroll (haydencarroll77@gmail.com)
 * @brief Implementation for Game class
 * @version 0.1
 * @date 2020-11-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "game.hpp"

#include <cstdlib>
#include <utility> // std::pair
#include <stack>
#include <SFML/Graphics.hpp>

#include "gameState.hpp"
#include "mainMenu.hpp"


/**
 * @brief Creates a new Game object
 * 
 * @param window reference to a RenderWindow
 */
Game::Game(sf::RenderWindow &window) :
window_(window)
{
    GameState *startState = new MainMenu(window, *this);
    gameStateStack_.push(startState);
}


/**
 * @brief runs the Game in a loop until window closes
 * 
 */
void Game::run()
{
    while (window_.isOpen() && !gameStateStack_.empty())
    {
        GameState *currentState = gameStateStack_.top();
        sf::Event event;

        window_.clear(sf::Color::Black);

        currentState->handleInput(event);
        currentState->update();
        currentState->render();

        window_.display();
    }

    std::exit(EXIT_SUCCESS);
}
