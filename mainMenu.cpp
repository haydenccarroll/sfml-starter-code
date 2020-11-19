/**
 * @file mainMenu.cpp
 * @author Hayden Carroll (haydencarroll77@gmail.com)
 * @brief Implementation of MainMenu class 
 * @version 0.1
 * @date 2020-11-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "mainMenu.hpp"

#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "background.hpp"


/**
 * @brief Creates a new MainMenu object
 * 
 * @param window reference to RenderWindow object
 * @param game  reference to Game object
 */
MainMenu::MainMenu(sf::RenderWindow &window, Game &game) :
GameState(window, game),
background_("../assets/mainMenuBackground.png", window)
{
}


/**
 * @brief handles input, given an event object each frame
 * 
 * @param event event object
 */
void MainMenu::handleInput(sf::Event &event)
{
     while (window_.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window_.close();
        
        if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
                case sf::Keyboard::Space:
                    getGameStateStack().pop(); // pops itself off the state stack

                    break;
                case sf::Keyboard::Up:
                    GameState* secondMenu = new MainMenu(window_, game_);
                    getGameStateStack().push(secondMenu); // push new menu to stack
                    break;
            }
        }
    }
}


/**
 * @brief performs all necessary updates each frame
 * 
 */
void MainMenu::update()
{
}


/**
 * @brief renders all necessary objects each frame
 * 
 */
void MainMenu::render()
{
    window_.draw(background_.sprite); 
}
