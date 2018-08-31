#ifndef SORTER_H
#define SORTER_H

#include <array>
#include <chrono>
#include <thread>

class Sorter{
    private:
    public:
        Sorter();
        ~Sorter();

        //Bubble Sort array template
        template<size_t arraySize>
        std::array<int, arraySize> bubbleSort(std::array<int, arraySize> array){
            for(int i = 0; i < array.size(); i++){
                for(int j = 0; j < array.size() - i - 1; j++){
                    if(array[j] > array[j+1]){
                        int temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = temp;
                    }
                }
            }

            return array;
        }

        //Selection Sort array template
        template<size_t arraySize>
        std::array<int, arraySize> selectionSort(std::array<int, arraySize> array);
        
};

#endif //SORTER_H