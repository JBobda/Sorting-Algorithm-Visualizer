#include "Application.h"

Application::Application(std::string title, uint width, uint height)
    :window({width, height}, title)
    ,width{width}
    ,height{height} {

    //Seeds the random number function
    srand(time(NULL));

    for(int i = 0; i < array.size(); i++){
        array[i] = rand() % height;
    }

    //Sets the window in the middle of the screen
    window.setPosition(sf::Vector2i
                    (sf::VideoMode::getDesktopMode().width/2 - window.getSize().x/2
                    ,sf::VideoMode::getDesktopMode().height/2 - window.getSize().y/2));
}

Application::~Application(){}

void Application::run(){
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
        }

        clear();

        array = sorter.bubbleSort(array);
        update();
        display();
    }
}

void Application::clear(){
    window.clear();
}

void Application::update(){
    for(int i = 0; i < array.size(); i++){
        sf::RectangleShape currentRect((sf::Vector2f(width/array.size(), height)));
        currentRect.setFillColor(sf::Color::White);      
        currentRect.setPosition(i * currentRect.getSize().x, array[i]);
        draw(currentRect);
    }

}

void Application::draw(sf::RectangleShape rect){
    window.draw(rect);
}

void Application::display(){
    window.display();
}