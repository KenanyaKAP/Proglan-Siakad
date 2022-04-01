#include <iostream>
#include <string>

#include "include/utils.hpp"

#define ENCRYPTCOUNT 3727

using namespace std;

void Utils::clearScreen()
{
    system("@cls||clear");
}

string Utils::encrypt(string input)
{
    for (string::iterator it = input.begin(); it != input.end(); it++)
        *it += ENCRYPTCOUNT;
    return input;
}

string Utils::decrypt(string input)
{
    for (string::iterator it = input.begin(); it != input.end(); it++)
    {
        if (*it != '\0')
            *it -= ENCRYPTCOUNT;
    }
    return input;
}

