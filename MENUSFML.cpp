#include <iostream>
#include <SFML/Graphics.hpp>
#include "MainMenu.h"
using namespace sf;

//Render Windowsrc
Vector2f viewSize(1000,720);
VideoMode vm(viewSize.x,viewSize.y);
RenderWindow MENU(vm, "Main Menu", Style::Default);

MainMenu mainMenu(MENU.getSize().x,MENU.getSize().y);



int main(){
    
//set background
RectangleShape background;
background.setSize(Vector2f(1000,720));
Texture Maintexture;
Maintexture.loadFromFile("Texture/bg.jpg");
background.setTexture(&Maintexture);

while(MENU.isOpen())
{

    Event event;
    while(MENU.pollEvent(event)){
        if(event.type == Event::Closed)
        {
            MENU.close();
        }

        if(event.type == Event::KeyReleased)
        {
            if(event.key.code == Keyboard::Up){
                mainMenu.MoveUp();
                break;
            }
            if (event.key.code == Keyboard::Down) {
                mainMenu.MoveDown();
                break;
            }
            if(event.key.code == Keyboard::Return){
                RenderWindow Play(vm,"game_name");

                int x = mainMenu.MainMenuPressed();

                if(x == 0)
                {
                    while(Play.isOpen()){
                        Event playevent;
                        while (Play.pollEvent(playevent))
                        {
                           if(playevent.type == Event::Closed)
                           {
                                Play.close();
                           }
                           if(playevent.type == Event::KeyPressed)
                           {
                            if(playevent.key.code == Keyboard::Escape)
                            {
                                Play.close();
                            }
                               
                           }                          
                        }
                        Play.clear();
                        Play.display();
                    }

                }
                if(x == 1){
                    MENU.close();
                    break;
                }
            } 
        } 
    }
    MENU.clear();
    MENU.draw(background);     
    mainMenu.draw(MENU);
    MENU.display();
  }
}

