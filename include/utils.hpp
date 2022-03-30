#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include <iostream>
#include <cstdlib>
#include <vector>
#include <tuple>

#include "include/VariadicTable.hpp"

using namespace std;

void clearScreen()
{
    system("@cls||clear");
}

template <class... T>
void printTable(vector<tuple<T...>> data, vector<string> header, unsigned int page)
{
    tuple<int, T...> nullTuple;
    header.insert(header.begin(), "No");
    VariadicTable<int, T...> vt(header);
    for (unsigned int i = 10*(page-1); i < 10*page; i++)
    {
        if (i < data.size())
        {
            vt.addRow(tuple_cat(make_tuple(i+1), data[i]));
        }
        else
        {
            vt.addRow(nullTuple);
        }
    }
    
    vt.print(cout);
}

#endif