#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdarg.h>

#include "include/utils.hpp"
#include "include/user.hpp"
#include "include/VariadicTable.hpp"

using namespace std;

void clearScreen()
{
    system("@cls||clear");
}

template <class... Ts>
void printTable(vector<Ts...> data, int page)
{
    VariadicTable<Ts...> vt;
    for (Ts... row : data)
    {
        vt.addRow(row);
    }
    vt.print();
    // for (int i = 10*(page-1); i < 10*(page); i++)
    // {
    //     cout << i+1 << "\t";
    //     if (i < data.size())
    //     {
    //         for (int j = 0; j < data[i].size(); j++)
    //         {
    //             cout << data[i][j] << "\t";
    //         }
    //     }
    //     cout << endl;
    // }
}