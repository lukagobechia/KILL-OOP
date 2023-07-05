#include "llevels.h"
using namespace sf;

Levels::Levels(float width, float height)
{
    if (!font.loadFromFile("Fonts/Pixel_Art.ttf")) {
        std::cout << "No font is here";
    }
    
    // Calculate the center position for horizontal and vertical alignment
    float centerX = width / 2;
    float centerY = height / 2;

    // Level 1
    levels[0].setFont(font);
    levels[0].setFillColor(Color::Black);
    levels[0].setString("1");
    levels[0].setCharacterSize(50);

    // Get the local bounds of the text
    FloatRect bounds = levels[0].getLocalBounds();

    // Set the origin to the center of the text
    levels[0].setOrigin(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);

    // Set the position to the left of the center with increased spacing
    levels[0].setPosition(centerX - bounds.width - 50, centerY);

    // level 2
    levels[1].setFont(font);
    levels[1].setFillColor(Color::Black);
    levels[1].setString("2");
    levels[1].setCharacterSize(50);
    
    // Set the origin and position for the "level 2" text
    bounds = levels[1].getLocalBounds();
    levels[1].setOrigin(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);
    levels[1].setPosition(centerX, centerY);

    // level 3
    levels[2].setFont(font);
    levels[2].setFillColor(Color::Black);
    levels[2].setString("3");
    levels[2].setCharacterSize(50);

    // Set the origin and position for the "level 3" text with increased spacing
    bounds = levels[2].getLocalBounds();
    levels[2].setOrigin(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);
    levels[2].setPosition(centerX + bounds.width + 50, centerY);

    // exit
    levels[3].setFont(font);
    levels[3].setFillColor(Color::Black);
    levels[3].setString("EXIT");
    levels[3].setCharacterSize(50);

    // Set the origin and position for the "EXIT" text
    bounds = levels[3].getLocalBounds();
    levels[3].setOrigin(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);
    levels[3].setPosition(centerX, centerY + bounds.height + 50);

    LevelsSelected = -1;
}

// Rest of the code remains the same...

Levels::~Levels()
{

}

// draw main menu
void Levels::draw(RenderWindow& window)
{
    for (int i = 0; i < Max_levels; i++) {
        window.draw(levels[i]);
    }
}

// Move Up
void Levels::MoveUp()
{
    levels[LevelsSelected].setFillColor(Color::Black);
    LevelsSelected--;
    if (LevelsSelected < 0) {
        LevelsSelected = Max_levels - 1;
    }
    levels[LevelsSelected].setFillColor(Color::Blue);
}

// Move Down
void Levels::MoveDown()
{
    levels[LevelsSelected].setFillColor(Color::Black);
    LevelsSelected++;
    if (LevelsSelected >= Max_levels) {
        LevelsSelected = 0;
    }
    levels[LevelsSelected].setFillColor(Color::Blue);
}