#ifndef ArrayReader_H
#define ArrayReader_H

#include <string>

class ArrayReader
{

  private:
    int *array;
    int size;
    std::string mem_str;

    int memoryStrSize(std::string str);
    int *getMemorieArray(std::string str, int s);

  public:
    ArrayReader(std::string str);
    ~ArrayReader();
    
    void printArray();
    int *getArray();
    int getSize();
};

#endif