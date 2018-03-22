// g++ (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609
// -std=c++11 - parametro p/ compilar.

#include <iostream>
#include <fstream>
#include <string>

#include "ArrayReader.h"
#include "ArraySort.h"

using namespace std;


std::string getMemorieString(std::string str)
{
    std::string str_mem;
    streampos size;
    char *memblock;

    str.insert(str.size(), ".txt");

    ifstream file(str.c_str(), ios::in | ios::binary | ios::ate);

    if (file.is_open())
    {
        size = file.tellg();
        memblock = new char[size];

        file.seekg(0, ios::beg);
        file.read(memblock, size);
        file.close();

        str_mem = memblock;

        delete[] memblock;

        return str_mem;
    }

    else
        return NULL;
}

void outFile(int* array, int size, std::string file_name)
{

    file_name.insert(file_name.size(), ".txt");

    std::ofstream out(file_name.c_str());

    out << ">" << size;

    for (int i = 0; i < size; i++)
    {
        out << ":" << array[i];
    }

    out.close();
}



int main()
{
    
    int key;
    
    std::string file_name;
    std::string str_array;

    
    cout << "Nome do Arquivo .txt (sem extensão): " << endl;
    cin >> file_name;
    cout << "1 - Shell Sort, 2 - Selection Sort: " << endl;
    cin >> key;

    str_array = getMemorieString(file_name);


    ArrayReader reader(str_array);
    ArraySort sorter(reader.getArray(), reader.getSize());


    if(key == 1)
    {   
        file_name.insert(file_name.size(), "_shellSort");

        sorter.shellSort();
        outFile(sorter.getArray(), sorter.getSize(), file_name);
        // sorter.printArray();
        cout << endl << file_name << " criado com sucesso." << endl;
    }
    else if (key == 2)
    {
        file_name.insert(file_name.size(), "_selectionSort");

        sorter.selectionSort();
        outFile(sorter.getArray(), sorter.getSize(), file_name);
        cout << endl << file_name << " criado com sucesso." << endl;
        
        // sorter.printArray();
    }


    return 0;
}