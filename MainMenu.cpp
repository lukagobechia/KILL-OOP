#include "MainMenu.h"
using namespace sf;

MainMenu::MainMenu(float width, float height)
{
    if(!font.loadFromFile("Fonts/Pixel_Art.ttf")){
        std::cout << "No font is here";
    }

    // play

    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(Color::Black);
    mainMenu[0].setString("START");
    mainMenu[0].setCharacterSize(50);
    mainMenu[0].setPosition(395,300);
    // exit
    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(Color::Black);
    mainMenu[1].setString("EXIT");
    mainMenu[1].setCharacterSize(50);
    mainMenu[1].setPosition(422,350);

    MainMenuSelected = -1;
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
