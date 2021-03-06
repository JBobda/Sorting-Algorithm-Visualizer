#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>
#include <string>
#include <cstdlib>
#include <time.h>

#include "Sorter.h"

class Application{
    private:
        sf::RenderWindow window;
        Sorter sorter;
        std::array<int, 50> array;
        
        bool sorted;
        uint width;
        uint height;
    public:
        Application(std::string title, uint width, uint height);
        ~Application();
        void run();
        void clear();
        void update();
        void draw(sf::RectangleShape rect);
        void shuffle();
        void display();
};

#endif //APPLICATION_H