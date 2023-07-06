#include <iostream>
#include <SFML/Graphics.hpp>
#include "llevels.h"
#include <cstdlib> // For system() function

using namespace sf;

int main() {
    Vector2f viewSize(1000, 720);
    VideoMode vm(viewSize.x, viewSize.y);
    RenderWindow LEVELS(vm, "LEVELS", Style::Default);
    Levels levels(LEVELS.getSize().x, LEVELS.getSize().y);

    RectangleShape background;
    background.setSize(Vector2f(1000, 720));
    Texture Maintexture;
    Maintexture.loadFromFile("Texture/bg.jpg");
    background.setTexture(&Maintexture);

    while (LEVELS.isOpen()) {
        Event event;
        while (LEVELS.pollEvent(event)) {
            if (event.type == Event::Closed) {
                LEVELS.close();
            }

            if (event.type == Event::KeyReleased) {
                if (event.key.code == Keyboard::Up) {
                    levels.MoveUp();
                }
                else if (event.key.code == Keyboard::Down) {
                    levels.MoveDown();
                }
                else if (event.key.code == Keyboard::Return) {
                    int x = levels.LevelsPressed();

                    if (x == 0)
                    {
                        LEVELS.close();
                        system("game.exe");
                    }
                    else if (x == 1) {
                        LEVELS.close();
                        system("game1.exe");
                    
                    }
                    else if (x == 2) {
                        LEVELS.close();
                        system("game2.exe");
                        
                    }
                    else if (x == 3) {
                        LEVELS.close();
                    }
                }
            }
        }

        LEVELS.clear();
        LEVELS.draw(background);
        levels.draw(LEVELS);
        LEVELS.display();
    }

    return 0;
}
