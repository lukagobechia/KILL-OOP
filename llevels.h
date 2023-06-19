#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

#define Max_levels 4

class Levels
{
public: 
    Levels(float width, float height);

    void draw(RenderWindow& window);
    void MoveUp();
    void MoveDown();
    int LevelsPressed() {
        return LevelsSelected;
    }
    ~Levels();

private:
    int LevelsSelected;
    Font font;
    Text levels[Max_levels];
};
