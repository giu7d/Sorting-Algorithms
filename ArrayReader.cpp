#include "ArrayReader.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

ArrayReader::ArrayReader(std::string str)
{
    mem_str = str;
    size = memoryStrSize(str);
    cout << "Size set!" << endl;
    array = new int[size];
    cout << "array: " << &array << " at ArrayReader::ArrayReader " << endl;
    setMemToArray(str);
    cout << "Array set!" << endl;
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

    cout << "tmp_str: " << &tmp_str << " at ArrayReader::memoryStrSize " << endl;

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

void ArrayReader::setMemToArray(std::string str)
{
    int i = 0;
    int j = 0;
    char *t_str = new char[str.size()];

    cout << "tmp_str: " << &t_str << " at ArrayReader::setMemToArray " << endl;

    std::strcpy(t_str, str.c_str());

    while (i < str.size())
    {
        int begin = 0;
        int end = 0;

        if (t_str[i] == ':')
        {
            i++;
            begin = i;
            
            while (t_str[i] != ':')
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

    delete[] t_str;
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