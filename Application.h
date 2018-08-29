#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>
#include <string>

#include "Sorter.h"

class Application{
    private:
        sf::RenderWindow window;
        std::array<int, 5> array;

    public:
        Application(std::string title, uint width, uint height);
        ~Application();
        void run();
        void clear();
        void update();
        void draw();
        void display();
};

#endif //APPLICATION_H