#include "ArrayReader.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

ArrayReader::ArrayReader(std::string str)
{
    mem_str = str;
    size = memoryStrSize(str);
    array = new int[size];
    array = getMemorieArray(str, size);
}

ArrayReader::~ArrayReader()
{
    // delete[] array;
}

int ArrayReader::memoryStrSize(std::string str)
{

    int i = 0;
    int begin = 0;
    int end = 0;
    char *tmp_str = new char[str.size()];
    std::strcpy(tmp_str, str.c_str());

    if (tmp_str[i] == '>')
    {
        i++;
        begin = i;

        while (tmp_str[i] != ':')
        {
            end = i;
            i++;
        }

        delete[] tmp_str;
        return std::stoi(str.substr(begin, end));
    }
}

int *ArrayReader::getMemorieArray(std::string str, int s)
{
    int i = 0;
    int j = 0;
    int *array = new int[s];
    char *tmp_str = new char[str.size()];

    std::strcpy(tmp_str, str.c_str());

    while (i < str.size())
    {

        int begin = 0;
        int end = 0;

        if (tmp_str[i] == ':')
        {
            i++;
            begin = i;

            while (tmp_str[i] != ':')
            {
                end = i;
                i++;
            }

            array[j] = std::stoi(str.substr(begin, end));
            j++;
        }
        else
        {
            i++;
        }
    }

    return array;
}

void ArrayReader::printArray()
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << endl;
    }
}

int* ArrayReader::getArray()
{
   return array;
}

int ArrayReader::getSize()
{
    return size;
}