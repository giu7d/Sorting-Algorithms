#include "ArraySort.h"
#include <iostream>

using namespace std;

ArraySort::ArraySort(int *a, int s)
{
    size = s;
    array = new int[size];
    array = a;
}

ArraySort::~ArraySort()
{
    delete[] array;
}

void ArraySort::shellSort()
{
    int tmp, gap, i, j;

    for (gap = (size / 2); gap > 0; gap /= 2)
    {
        for (i = gap; i < size; i += 1)
        {
            tmp = array[i];

            for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
            {
                array[j] = array[j - gap];
            }

            array[j] = tmp;    
        }
    }
}

void ArraySort::selectionSort()
{
    int i, j, min;

    for (i = 0; i < (size - 1); i++)
    {
        min = i;
        for (j = (i + 1); j < size; j++)
        {
            if (array[j] < array[min]){
                min = j;
            }
        }
        
        swap(&array[min], &array[i]);
    }
}

void ArraySort::swap(int *arrayX, int *arrayY)
{
    int tmp = *arrayX;
    *arrayX = *arrayY;
    *arrayY = tmp;
}

void ArraySort::reverseArray()
{
    int tmp;
    int i = 0;
    int j = size - 1;

    while (i < j)
    {
        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
        i++;
        j--;
    }
}

void ArraySort::printArray()
{
    for (int i = 0; i < size; ++i)
        cout << array[i] << endl;
}

int* ArraySort::getArray()
{
    return array;
}

int ArraySort::getSize()
{
    return size;
}