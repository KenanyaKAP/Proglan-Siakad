#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>

#include "include/save.hpp"
#include "include/utils.hpp"
#include "include/user.hpp"

using namespace std;

// ===========================    User    ===========================
void Save::saveData(vector<User> *data, const char *path)
{
    fstream file;
    file.open(path, ios::trunc | ios::out | ios::in);
    if (!file.is_open()){ cout << "Error while opening " << path << "!" << endl; exit(1); }

    for (User &user : *data)
    {
        file << Utils::encrypt(user.getUsername()) << '\0';
        file << Utils::encrypt(user.getPassword()) << '\0';
        file << Utils::encrypt(to_string(user.getRole())) << '\0';
        stringstream ss;
        ss << user.getPersonId();
        file << Utils::encrypt(ss.str()) << '\n';
    }
}

void Save::loadData(vector<User> &out, const char *path)
{
    fstream file;
    file.open(path, ios::in);
    if (!file.is_open())
    {
        file.close();
        file.open(path, ios::trunc | ios::out | ios::in);
    }
    if (!file.is_open()){ cout << "Error while opening " << path << "!" << endl; exit(1); }

    string data;
    while (getline(file, data))
    {
        string temp;
        stringstream ssData(Utils::decrypt(data));
        
        vector<string> dataString;
        while (getline(ssData, temp, '\0'))
            dataString.push_back(temp);
        
        User user{dataString[0], dataString[1], (User::Role)stoi(dataString[2]), dataString[3]};
        out.push_back(user);
    }
}
// ==================================================================