// #include "FileToArray.h"
// #include <iostream>
// #include <fstream>

// using namespace std;

// FileToArray::FileToArray(std::string str)
// {
//     file_name = new char[str];
//     std::strcpy(file_name, str.c_str());

//     ifstream file_stream(file_name);

//     Stream s = new BufferedStream(file_stream);

//     setArraywithFile();
// }

// FileToArray::~FileToArray()
// {
//     delete[] file_name;
//     delete[] array;
// }

// // int FileToArray::memoryStrSize()
// // {
// //     int i = 0;
// //     int begin = 0;
// //     int end = 0;

// //     char *tmp_str = new char[str.size()];
// //     std::strcpy(tmp_str, str.c_str());

// //     cout << "tmp_str: " << &tmp_str << " at ArrayReader::memoryStrSize " << endl;

// //     if (tmp_str[i] == '>')
// //     {
// //         i++;
// //         begin = i;

// //         while (tmp_str[i] != ':')
// //         {
// //             end = i;
// //             i++;
// //         }

// //         delete[] tmp_str;
// //         return std::stoi(str.substr(begin, end));
// //     }
// // }

// void FileToArray::setArraywithFile()
// {
//     using())
//     {
//         int data = ReadInt32(s);
//         for (int y = 0; y < data; y++)
//                 array[y, x] = ReadInt32(s);
//     }
// }

// int ReadInt32(Stream s)
// { // edited to improve handling of multiple spaces etc
//     int b;
//     // skip any preceeding
//     while ((b = s.ReadByte()) >= 0 && (b < '0' || b > '9'))
//     {
//     }
//     if (b < 0)
//         throw new EndOfStreamException();

//     int result = b - '0';
//     while ((b = s.ReadByte()) >= '0' && b <= '9')
//     {
//         result = result * 10 + (b - '0');
//     }
//     return result;
// }