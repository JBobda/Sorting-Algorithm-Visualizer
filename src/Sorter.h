#ifndef SORTER_H
#define SORTER_H

#include <array>

class Sorter{
    private:
    public:
        Sorter();
        ~Sorter();
        std::array<int, 5> bubbleSort(std::array<int, 5> array);
        std::array<int, 5> selectionSort(std::array<int, 5> array);
};

#endif //SORTER_H