#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include <iostream>
#include <vector>

void clearScreen();

// void printTable(std::vector<std::vector<std::string>> data, int page);
template <class... Ts>
void printTable(std::vector<Ts...> data, int page);

#endif