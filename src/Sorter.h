#ifndef SORTER_H
#define SORTER_H

#include <array>

class Sorter{
    private:
    public:
        Sorter();
        ~Sorter();
        //Bubble Sort array template
        template<size_t arraySize>
        std::array<int, arraySize> bubbleSort(std::array<int, arraySize> array);

        //Selection Sort array template
        template<size_t arraySize>
        std::array<int, arraySize> selectionSort(std::array<int, arraySize> array);
        
};

#endif //SORTER_H