#ifndef ArraySort_H
#define ArraySort_H

class ArraySort
{
  private:
    int* array;
    int size;
    void swap(int *arrayX, int *arrayY);
    void merge(int *a, int *l, int nL, int *r, int nR);
    void quickFunc(int *arr, int low, int high);
    void mergeFunc(int *a, int s);

  public: 
    ArraySort(int *a, int s);
    ~ArraySort();
  
    void shellSort();
    void selectionSort();
    void quickSort();
    void mergeSort();
    void radixSort();
    
    void reverseArray();
    void printArray();
    int *getArray();
    int getSize();
};

#endif