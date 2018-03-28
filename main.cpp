// g++ (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609
// -std=c++11 - parametro p/ compilar.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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


int main(int argc, char *argv[])
{

    std::vector<std::string> args(argv, argv + argc);

    if (args[1] == "--help" || args[2] == "--help")
    {
        cout << "usage: ./main file [options]" << endl
             << "options:" << endl
             << "--shell-sort     \t Shell sort a file" << endl
             << "--selection-sort \t Selection sort a file" << endl
             << "--quick-sort     \t Quick sort a file" << endl
             << "--merge-sort     \t Merge sort a file" << endl
             << "--radix-sort     \t Radix sort a file" << endl;

        return 0;
    }
    else if (argc != 3){
        cout << "error: unsuported parameter\n use: --help" << endl;
        return 1;
    }

    std::string file_name = args[1].substr(0, args[1].size() - 4);
    std::string str_array = getMemorieString(file_name);

    ArrayReader reader(str_array);
    ArraySort sorter(reader.getArray(), reader.getSize());

    if(args[2] == "--shell-sort")
    {
        file_name.insert(file_name.size(), "_shellSort");
        sorter.shellSort();
        outFile(sorter.getArray(), sorter.getSize(), file_name);
        cout << endl << file_name << " criado com sucesso." << endl;
    }
    if(args[2] == "--selection-sort")
    {
        file_name.insert(file_name.size(), "_selectionSort");
        sorter.selectionSort();
        outFile(sorter.getArray(), sorter.getSize(), file_name);
        cout << endl << file_name << " criado com sucesso." << endl;
    }
    if (args[2] == "--quick-sort")
    {
        file_name.insert(file_name.size(), "_quickSort");
        sorter.quickSort();
        outFile(sorter.getArray(), sorter.getSize(), file_name);
        cout << endl << file_name << " criado com sucesso." << endl;
    }
    if (args[2] == "--merge-sort")
    {
        file_name.insert(file_name.size(), "_mergeSort");
        sorter.mergeSort();
        outFile(sorter.getArray(), sorter.getSize(), file_name);
        cout << endl
             << file_name << " criado com sucesso." << endl;
    }
    if (args[2] == "--radix-sort")
    {
        file_name.insert(file_name.size(), "_radixSort");
        sorter.radixSort();
        outFile(sorter.getArray(), sorter.getSize(), file_name);
        cout << endl
             << file_name << " criado com sucesso." << endl;
    }
    

    return 0;
}