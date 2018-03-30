#ifndef ArraySort_H
#define ArraySort_H

class ArraySort
{
  private:
    int* array;
    int size;
    
    void quickFunc(int *arr, int low, int high);
    void merge(int *a, int *l, int nL, int *r, int nR);
    void mergeFunc(int *a, int s);
    void heap(int *a, int n);
    void heapFunc(int *a, int i, int n);
    void swap(int *aX, int *aY);

  public:  
    ArraySort(int *a, int s);
    ~ArraySort();
  
    void shellSort();
    void selectionSort();
    void quickSort();
    void mergeSort();
    void radixSort();
    void heapSort();
    
    void reverseArray();
    void printArray();
    int *getArray();
    int getSize();
};

#endif