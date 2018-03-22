#ifndef ArraySort_H
#define ArraySort_H

class ArraySort
{
    private:
        int* array;
        int size;
        void swap(int *arrayX, int *arrayY);

      public:
        ArraySort(int* a, int s);
        ~ArraySort();
        void shellSort();
        void selectionSort();
        void reverseArray();
        void printArray();
        int *getArray();
        int getSize();
};

#endif