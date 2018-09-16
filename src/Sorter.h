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

        //Bogo Sort array template
        template<size_t arraySize>
        void bogoSort(std::array<int, arraySize>& array, sf::RenderWindow& window){
            bool sorted = false;
            while(!sorted){
                shuffle(array);
                draw(array, -1, -1, window);
                sleep(window, 200);
                for(int i = 0; i < array.size() - 1; i++){
                    sorted = true;
                    if(array[i] < array[i + 1]){
                        sorted = false;
                        break;
                    }
                }
                
            }
        }

        //Merge Sort array template
        template<size_t arraySize>
        void mergeSort(std::array<int, arraySize>& array, sf::RenderWindow& window){
            mergeSortHelper(array, 0, array.size()-1, window);
        }

        //Merge Sort Helper template
        template<size_t arraySize>
        void mergeSortHelper(std::array<int, arraySize>& array, int low, int high, sf::RenderWindow& window){
            if(low < high){
                int middle = (low + high) / 2;

                mergeSortHelper(array, low, middle, window);
                mergeSortHelper(array, middle + 1, high, window);
                merge(array, low, middle, high, window);
            }
        }

        //Merge Template
        template<size_t arraySize>
        void merge(std::array<int, arraySize>& array, int left, int middle, int right, sf::RenderWindow& window){
            //Decleration of Iterator variables and temp array
            int i = left;
            int j = middle + 1;
            int k = left;
            std::array<int, arraySize> temp;

            //Loop to move to combine the two seperate arrays until one is empty
            while(i <= middle && j <= right){
                if(array[i] >= array[j]){
                    temp[k] = array[i];
                    i++;
                }else{
                    temp[k] = array[j];
                    j++;
                }
                k++;
                draw(array, i, j, window);
                sleep(window, 30);
                
            }

            //Move the leftover elements of whichever array still has them
            while(i <= middle){
                temp[k] = array[i];
                i++;
                k++;
            }
            
            while(j <= right){
                temp[k] = array[j];
                j++;
                k++;
            }
            
            //Move all of the elements in the Temp array to the Normal array
            for(k = left; k <= right; k++){
                array[k] = temp[k];
                draw(array, k, -1, window);
                sleep(window, 30);
            }
        }

        //Shuffle Function
        template<size_t arraySize>
        void shuffle(std::array<int, arraySize>& array){
            for(int i = 0; i < array.size(); i++){
                int newIndex = rand() % array.size();
                int temp = array[i];
                array[i] = array[newIndex];
                array[newIndex] = temp;
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
                currentRect.setOutlineColor(sf::Color::Black);
                currentRect.setOutlineThickness(1.5);
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
                if(event.type == sf::Event::Closed){
                    window.close();
                    std::exit(0);
                }
            }
        }
};

#endif //SORTER_H