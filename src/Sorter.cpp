#include "Sorter.h"

Sorter::Sorter(){}

Sorter::~Sorter(){}

//Bubble Sort array template
template<size_t arraySize>
std::array<int, arraySize> Sorter::bubbleSort(std::array<int, arraySize> array){
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
std::array<int, arraySize> Sorter::selectionSort(std::array<int, arraySize> array){
    return array;
}