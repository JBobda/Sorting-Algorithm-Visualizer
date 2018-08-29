#include "Application.h"

Application::Application(std::string title, uint width, uint height)
    :window({width, height}, title),
    array{5, 3, 8, 2, 12} {

    //Sets the window in the middle of the screen
    window.setPosition(sf::Vector2i
                    (sf::VideoMode::getDesktopMode().width/2 - window.getSize().x/2
                    ,sf::VideoMode::getDesktopMode().height/2 - window.getSize().y/2));
}

Application::~Application(){

}

void Application::run(){
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
        }


        clear();
        display();
    }
}

void Application::clear(){
    window.clear();
}

void Application::update(){

}

void Application::draw(){

}

void Application::display(){
    window.display();
}