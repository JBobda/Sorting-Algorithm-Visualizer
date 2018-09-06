#ifndef SORTER_H
#define SORTER_H

#include <SFML/Graphics.hpp>
#include <array>
#include <chrono>
#include <thread>
#include <iostream>

class Sorter{
    private:
        uint width;
        uint height;
    public:
        Sorter(uint width, uint height);
        ~Sorter();

        //Bubble Sort array template
        template<size_t arraySize>
        void bubbleSort(std::array<int, arraySize>& array, sf::RenderWindow& window){
            for(int i = 0; i < array.size(); i++){
                for(int j = 0; j < array.size() - i - 1; j++){
                    if(array[j] < array[j+1]){
                        swap(array, j, j + 1, window);
                    }
                }
            }
        }

        //Selection Sort array template
        template<size_t arraySize>
        void selectionSort(std::array<int, arraySize>& array, sf::RenderWindow& window){
            for(int i = 0; i < array.size(); i++){
                int minIndex = i;
                for(int j = i + 1; j < array.size(); j++){
                    if(array[minIndex] < array[j]){
                        minIndex = j;
                    }
                    draw(array, i, j, window);
                    sleep(window, 30);
                }
                swap(array, i, minIndex, window);
            }
        }

        //Swap function
        template<size_t arraySize>
        void swap(std::array<int, arraySize>& array, int previous, int next, sf::RenderWindow& window){
            int temp = array[previous];
            array[previous] = array[next];
            array[next] = temp;

            draw(array, previous, next, window);
            sleep(window, 30);
        }

        //Draw Function
        template<size_t arraySize>
        void draw(std::array<int, arraySize>& array, int previous, int next, sf::RenderWindow& window){
            //Draws the updated array to the screen
            sf::RectangleShape currentRect((sf::Vector2f(width/array.size(), height)));
            for(int i = 0; i < array.size(); i++){
                currentRect.setFillColor(sf::Color::White);
                if(i == previous) currentRect.setFillColor(sf::Color(67, 130, 232, 255));
                if(i == next) currentRect.setFillColor(sf::Color(9, 34, 76, 150));      
                currentRect.setPosition(i * currentRect.getSize().x, array[i]);
                
                window.draw(currentRect);
            }

            //Displays and clears the newly drawn array
            window.display();
            window.clear();
        }

        //Sleep function to sleep the process but keep taking in user input
        void sleep(sf::RenderWindow& window, uint timeMS){
            //Sleeps the program but continues to check for input to stay responsive
            std::this_thread::sleep_for(std::chrono::milliseconds(timeMS));
            sf::Event event;
            while(window.pollEvent(event)){
                if(event.type == sf::Event::Closed)
                    window.close();
            }
        }
};

#endif //SORTER_H