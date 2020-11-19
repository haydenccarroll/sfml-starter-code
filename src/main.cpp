/**
 * @file main.cpp
 * @author Hayden Carroll (haydencarroll77@gmail.com)
 * @brief Creates a window and a game instance, and runs the game
 * @version 0.1
 * @date 2020-11-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "gameState.hpp"
#include "mainMenu.hpp"


/**
 * @brief Runs the game
 * 
 * @return EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(600, 800), "{PROJECT_NAME}");
    Game game(window);
    game.run();
}
