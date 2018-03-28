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

void ArraySort::radixSort()
{
    int i;
    int exp = 1; 
    int m = 0; 
    
    int* bucket = new int[size]; 
    int* tmp = new int[size];

    for (i = 0; i < size; i++)
    {
        if (array[i] > m)
        {
            m = array[i];
        }
    }

    while ((m / exp) > 0)
    {
        for (i = 0; i < size; i++)
        {
            bucket[i] = 0;
        }
        for (i = 0; i < size; i++)
        {
            bucket[(array[i] / exp) % 10]++;
        }
        for (i = 1; i < size; i++)
        {
            bucket[i] += bucket[i - 1];
        }
        for (i = (size - 1); i >= 0; i--)
        {
            tmp[--bucket[(array[i] / exp) % 10]] = array[i];
        }
        for (i = 0; i < size; i++)
        {
            array[i] = tmp[i];
        }
        exp *= 10;
    }

    delete[] bucket;
    delete[] tmp;
}

void ArraySort::mergeSort()
{
    mergeFunc(array, size);
}

void ArraySort::merge(int *a, int *l, int nL, int *r, int nR)
{
    // int nL = sizeof(l)/sizeof(int);
    // int nR = sizeof(r)/sizeof(int);
    int i = 0, j = 0, k = 0;
    while (i < nL && j < nR)
    {
        if (l[i] < r[j])
            a[k++] = l[i++];
        else
            a[k++] = r[j++];
    }
    while (i < nL)
    {
        a[k++] = l[i++];
    }
    while (j < nR)
    {
        a[k++] = r[j++];
    }
}

void ArraySort::mergeFunc(int *a, int s)
{
    if (s < 2)
        return;
    int mid = s / 2;
    int *left = new int[mid];
    int *right = new int[s - mid];

    for (int i = 0; i < mid; i++)
        left[i] = a[i];
    for (int i = mid; i < s; i++)
        right[i - mid] = a[i];
    mergeFunc(left, mid);
    mergeFunc(right, s - mid);
    merge(a, left, mid, right, s - mid);
}

void ArraySort::quickSort()
{
    int n = size - 1;
    quickFunc(array, 0, n);
}

void ArraySort::quickFunc(int *arr, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = arr[(i + j) / 2];
    int temp;

    while (i <= j)
    {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quickFunc(arr, low, j);
    if (i < high)
        quickFunc(arr, i, high);
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