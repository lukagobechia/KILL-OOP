#include <iostream>
#include <cstdlib> // For system() function
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "win.h"

using namespace sf;

// Render Window
Vector2f viewSize(1000, 720);
VideoMode vm(viewSize.x, viewSize.y);
RenderWindow MENU(vm, "Main Menu", Style::Default);

MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);



int main()
{
    // Set background
    RectangleShape background;
    background.setSize(Vector2f(1000, 720));
    Texture Maintexture;
    Maintexture.loadFromFile("Texture/bg.jpg");
    background.setTexture(&Maintexture);

    // Create "you win" text
    Font font;
    font.loadFromFile("Fonts/Pixel_Art.ttf"); // Replace with the path to your font file
    Text winText("You Win!", font, 80);
    winText.setFillColor(Color::Green);
    winText.setStyle(Text::Bold);
    winText.setPosition(viewSize.x / 2 - winText.getGlobalBounds().width / 2, viewSize.y / 2 - 200);


    bool isGameOver = false; // Track game over state

    while (MENU.isOpen())
    {
        Event event;
        while (MENU.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                MENU.close();
            }

            if (event.type == Event::KeyReleased)
            {
                if (event.key.code == Keyboard::Up)
                {
                    mainMenu.MoveUp();
                    break;
                }
                if (event.key.code == Keyboard::Down)
                {
                    mainMenu.MoveDown();
                    break;
                }
                if (event.key.code == Keyboard::Return)
                {
                    int x = mainMenu.MainMenuPressed();

                    if (x == 1)
                    {
                        MENU.close();
                        system("game.exe");
                    }
                    if (x == 2)
                    {
                        MENU.close();
                        system("MainLevels.exe");
                    }
                    if (x == 3)
                    {
                        MENU.close();
                        isGameOver = true;
                        break;
                    }
                }
            }
        }
        MENU.clear();
        MENU.draw(background);
        mainMenu.draw(MENU);
        MENU.draw(winText);
        MENU.display();
    }
}
