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
                        RenderWindow level2(vm, "Level 2");
                        while (level2.isOpen()) {
                            Event event2;
                            while (level2.pollEvent(event2)) {
                                if (event2.type == Event::Closed) {
                                    level2.close();
                                }
                                else if (event2.type == Event::KeyPressed) {
                                    if (event2.key.code == Keyboard::Escape) {
                                        level2.close();
                                    }
                                }
                            }

                            level2.clear();
                            // Draw level 2 contents
                            level2.display();
                        }
                    }
                    else if (x == 2) {
                        RenderWindow level3(vm, "Level 3");
                        while (level3.isOpen()) {
                            Event event3;
                            while (level3.pollEvent(event3)) {
                                if (event3.type == Event::Closed) {
                                    level3.close();
                                }
                                else if (event3.type == Event::KeyPressed) {
                                    if (event3.key.code == Keyboard::Escape) {
                                        level3.close();
                                    }
                                }
                            }

                            level3.clear();
                            // Draw level 3 contents
                            level3.display();
                        }
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
