#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include <iostream>
#include <cstdlib>
#include <vector>
#include <tuple>

#include "include/VariadicTable.hpp"

using namespace std;

namespace Utils {
    void clearScreen();
    string encrypt(string input);
    string decrypt(string input);
    string intToStringMonth(int monthInt);

    template <class... T>
    void printTable(vector<tuple<T...>> data, vector<string> header, unsigned int page);

    template <class T>
    vector<T*> makeVectorPointer(vector<T> *input);
}

template <class... T>
void Utils::printTable(vector<tuple<T...>> data, vector<string> header, unsigned int page)
{
    header.insert(header.begin(), "No");
    VariadicTable<int, T...> vt(header);
    for (unsigned int i = 10*(page-1); i < 10*page; i++)
    {
        if (i < data.size())
        {
            vt.addRow(tuple_cat(make_tuple(i+1), data[i]));
        }
    }
    
    vt.print(cout);
}

template <class T>
vector<T*> Utils::makeVectorPointer(vector<T> *input)
{
    vector<T*> output;
    for (T &element : *input)
        output.push_back(&element);
    return output;
}

#endif