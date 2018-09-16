#include "Application.h"

Application::Application(std::string title, uint width, uint height)
    :window({width, height}, title)
    ,sorter{width, height}
    ,width{width}
    ,height{height} {

    sorted = false;
    //Seeds the random number function
    srand(time(NULL));

    //Sets the array
    for(int i = 0; i < array.size(); i++){
        array[i] = height - (height/array.size()) * i;
    }

    //Shuffles the array
    sorter.shuffle(array);

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
        if(!sorted){
            //sorter.bubbleSort(array, window);
            //sorter.selectionSort(array, window);
            sorter.mergeSort(array, window);
            //sorter.bogoSort(array, window);
            sorted = true;
        }
        update(); 
        display();  
    }
}

void Application::clear(){
    window.clear();
}

void Application::update(){
    sf::RectangleShape currentRect((sf::Vector2f(width/array.size(), height)));
    for(int i = 0; i < array.size(); i++){
        currentRect.setFillColor(sf::Color::White);
        currentRect.setOutlineColor(sf::Color::Black);
        currentRect.setOutlineThickness(1.5);      
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