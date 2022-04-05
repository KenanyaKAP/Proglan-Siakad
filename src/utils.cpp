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

string Utils::intToStringMonth(int monthInt)
{
    switch (monthInt)
    {
    case 1:
        return "Januari";
    case 2:
        return "Februari";
    case 3:
        return "Maret";
    case 4:
        return "April";
    case 5:
        return "Mei";
    case 6:
        return "Juni";
    case 7:
        return "Juli";
    case 8:
        return "Agustus";
    case 9:
        return "September";
    case 10:
        return "Oktober";
    case 11:
        return "November";
    case 12:
        return "Desember";
    default:
        return "-";
    }
}