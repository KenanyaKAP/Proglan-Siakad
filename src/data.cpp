#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

#include "include/data.hpp"
#include "include/user.hpp"
#include "include/departemen.hpp"

#define USERPATH "data/user.bin"
#define DEPARTEMENPATH "data/departemen.bin"

using namespace std;

// ======================= Constructor ==============================
Data::Data()
{
    recUser = loadData<User, S_User>(USERPATH);
}
// ==================================================================



// ======================== Private Function ========================
template <class T>
int Data::getDataSize(fstream& dataFile)
{
    int start, end;
    dataFile.seekg(0, ios::beg);
    start = dataFile.tellg();
    dataFile.seekg(0, ios::end);
    end = dataFile.tellg();
    return (end - start)/sizeof(T);
}

template <class Base, class Save>
void Data::writeData(int position, Base input, const char *filePath)
{
    fstream dataFile;
    dataFile.open(filePath, ios::out | ios::in | ios::binary);
    bool bDataFile = dataFile.is_open();
    if (!bDataFile){ cout << "Error while opening " << filePath << "!" << endl; exit(1); }

    Save save(input);

    dataFile.seekp(position * sizeof(Save), ios::beg);
    dataFile.write(reinterpret_cast<char*>(&save), sizeof(Save));

    dataFile.close();
}

template <class T>
T Data::readData(fstream& dataFile, int position)
{
    T output;
    dataFile.seekg(position * sizeof(T), ios::beg);
    dataFile.read(reinterpret_cast<char*>(&output), sizeof(T));

    return output;
}

template <class Base, class Save>
vector<Base> Data::loadData(const char *filePath)
{
    fstream dataFile;
    dataFile.open(filePath, ios::in | ios::binary);
    bool bDataFile;
    if (dataFile.is_open())
    {
        bDataFile = dataFile.is_open();
    }
    else
    {
        dataFile.close();
        dataFile.open(filePath, ios::trunc | ios::out | ios::in | ios::binary);
        bDataFile = dataFile.is_open();
    }
    if (!bDataFile){ cout << "Error while opening " << filePath << "!" << endl; exit(1); }

    vector<Base> data;
    for (int i = 0; i < getDataSize<Save>(dataFile); i++)
    {
        Save save = readData<Save>(dataFile, i);
        Base base(save);
        data.push_back(base);
    }

    dataFile.close();
    return data;
}
// ==================================================================



// ======================== Public Function =========================
int Data::loginUser(string username, string password)
{
    for (User &user : recUser)
    {
        if (strcmp(username.c_str(), user.getUsername().c_str()) == 0 && strcmp(password.c_str(), user.getPassword().c_str()) == 0)
            return user.getRole();
    }
    return -1;
}
// ==================================================================



// ==========================    USER    ============================
int Data::getUserSize(){ return this->recUser.size(); }

vector<User> *Data::getAllUser(){ return &this->recUser; }

User *Data::getUser(int index)
{
    if (index >= 0 && index < (int)recUser.size())
        return &recUser[index];
    return nullptr;
}

User *Data::getUser(string username)
{ 
    for (User& user : recUser)
        if (strcmp(user.getUsername().c_str(), username.c_str()) == 0) 
            return &user; 
    return nullptr; 
}

void Data::updateUser(std::string username)
{
    for (unsigned int i = 0; i < recUser.size(); i++)
    {
        if (strcmp(recUser[i].getUsername().c_str(), username.c_str()) == 0)
        {
            writeData<User, S_User>(i, recUser[i], USERPATH);
            return;
        }
    }
}

void Data::addUser(string username, string password, string personId, User::Role role)
{
    User newUser(username, password, personId, role);
    writeData<User, S_User>(recUser.size(), newUser, USERPATH);
    recUser = loadData<User, S_User>(USERPATH);
}

void Data::removeUser(int index)
{
    recUser.erase(recUser.begin() + index);

    fstream dataFile;
    dataFile.open(USERPATH, ios::trunc | ios::out | ios::in | ios::binary);
    
    for (size_t i = 0; i < recUser.size(); i++)
        writeData<User, S_User>(i, recUser[i], USERPATH);
    
    dataFile.close();
}

void Data::removeUser(string username)
{
    for (size_t i = 0; i < recUser.size(); i++)
        if (strcmp(recUser[i].getUsername().c_str(), username.c_str()) == 0)
            recUser.erase(recUser.begin() + i);

    fstream dataFile;
    dataFile.open(USERPATH, ios::trunc | ios::out | ios::in | ios::binary);
    
    for (size_t i = 0; i < recUser.size(); i++)
        writeData<User, S_User>(i, recUser[i], USERPATH);
    
    dataFile.close();
}
// ==================================================================