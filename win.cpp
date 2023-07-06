#include "win.h"
using namespace sf;

MainMenu::MainMenu(float width, float height)
{
    if (!font.loadFromFile("Fonts/Pixel_Art.ttf")) {
        std::cout << "No font is here";
    }

    // Calculate the center position for horizontal and vertical alignment
    float centerX = width / 2;
    float centerY = height / 2;

    // restart
    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(Color::Black);
    mainMenu[1].setString("RESTART");
    mainMenu[1].setCharacterSize(50);
    mainMenu[1].setOrigin(mainMenu[1].getLocalBounds().width / 2, mainMenu[1].getLocalBounds().height / 2);
    mainMenu[1].setPosition(centerX, centerY -50);

    // menu
    mainMenu[2].setFont(font);
    mainMenu[2].setFillColor(Color::Black);
    mainMenu[2].setString("MENU");
    mainMenu[2].setCharacterSize(50);
    mainMenu[2].setOrigin(mainMenu[2].getLocalBounds().width / 2, mainMenu[2].getLocalBounds().height / 2);
    mainMenu[2].setPosition(centerX, centerY + mainMenu[2].getLocalBounds().height -30);

    // exit
    mainMenu[3].setFont(font);
    mainMenu[3].setFillColor(Color::Black);
    mainMenu[3].setString("EXIT");
    mainMenu[3].setCharacterSize(50);
    mainMenu[3].setOrigin(mainMenu[3].getLocalBounds().width / 2, mainMenu[3].getLocalBounds().height / 2);
    mainMenu[3].setPosition(centerX, centerY + 2 * (mainMenu[3].getLocalBounds().height) -20);

    MainMenuSelected = 0;
}

MainMenu::~MainMenu()
{

}

// draw main menu
void MainMenu::draw(RenderWindow& window){
    for(int i = 0; i< Max_main_menu; i++){
        window.draw(mainMenu[i]);
    }
}
//Move Up
void MainMenu::MoveUp()
{
    if(MainMenuSelected - 1 >= 0){
        mainMenu[MainMenuSelected].setFillColor(Color::Black);
       
        MainMenuSelected --;
        if(MainMenuSelected == 1){
            MainMenuSelected ==  2;
        }
        mainMenu[MainMenuSelected].setFillColor(Color::Blue);  
    }
}
//MoveUp
void MainMenu::MoveDown()
{
    if(MainMenuSelected + 1 <= Max_main_menu){
        mainMenu[MainMenuSelected].setFillColor(Color::Black);
        MainMenuSelected++;
        
        if(MainMenuSelected == Max_main_menu){
            MainMenuSelected = 0;
        }
        
        mainMenu[MainMenuSelected].setFillColor(Color::Blue);
    }
}
