#include <iostream>
#include <string>
// #include <conio.h>
#include <termios.h>
#include <stdio.h>

#include "include/utils.hpp"

#define ENCRYPTCOUNT 333

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

// ================= Getch for Linux =================
static struct termios old, current;

void initTermios(int echo) 
{
  tcgetattr(0, &old);
  current = old;
  current.c_lflag &= ~ICANON;
  if (echo) {
      current.c_lflag |= ECHO;
  } else {
      current.c_lflag &= ~ECHO;
  }
  tcsetattr(0, TCSANOW, &current);
}

void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

char getch(void) 
{
  return getch_(0);
}
// ===================================================

string Utils::takePassword()
{
    char pass[1000];
    int i = 0;
    char a;
    while(true)
    {
        a = getch();
        if(a == '\b' && i >= 1)
        {
            cout << "\b \b";
            --i;
        }
        else if(a == '\r')
        {
            pass[i] = '\0';
            break;
        }
        else if (a == 3)
        {
            exit(0);
        }
        else
        {
            pass[i] = a;
            ++i;
            cout << "*";
        }
    }
    cout << endl;
    return string(pass);    
}

