#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

#include "include/data.hpp"
#include "include/user.hpp"

#define USERPATH "data/user.bin"

using namespace std;

// Constructor

Data::Data()
{
    // fUser.openUSERPATH, ios::in | ios::out | ios::binary);
    // if (fUser.is_open())
    // {
    //     bFUser = fUser.is_open();
    // }
    // else
    // {
    //     fUser.close();
    //     fUser.openUSERPATH, ios::trunc | ios::in | ios::out | ios::binary);
    //     bFUser = fUser.is_open();
    // }
    // if (!bFUser){ cout << "Error while opening departemen.bin!" << endl; return; }
    
    // // Load Recorded Data
    OpenData<User>(recUser, fUser, USERPATH);
}

// Destructor

Data::~Data()
{
    fUser.close();
}


// User

int Data::getUserSize(){ return this->recUser.size(); }

vector<User>* Data::getAllUser(){ return &this->recUser; }

User* Data::getUser(char* username)
{ 
    for (User& user : recUser)
        if (strcmp(user.getUsername(), username) == 0) 
            return &user; 
    return nullptr; 
}

void Data::removeUser(char* username)
{
    for (size_t i = 0; i < recUser.size(); i++)
        if (strcmp(recUser[i].getUsername(), username) == 0)
            recUser.erase(recUser.begin() + i);

    fUser.close();
    fUser.open(USERPATH, ios::trunc | ios::in | ios::out | ios::binary);
    
    for (size_t i = 0; i < recUser.size(); i++)
        writeData<User>(fUser, i, recUser[i]);
}

void Data::addUser(const char* username, const char* password, const char* personId, User::Role role)
{
    addUser((char*)username, (char*)password, (char*)personId, role);
}

void Data::addUser(char* username, char* password, char* personId, User::Role role)
{
    User newUser(username, password, personId, role);
    recUser.push_back(newUser);
    
    writeData<User>(fUser, getDataSize<User>(fUser), newUser);
}

// Private function

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

template <class T>
void Data::writeData(fstream &dataFile, int position, T input)
{
    dataFile.seekp(position * sizeof(T), ios::beg);
    dataFile.write(reinterpret_cast<char*>(&input), sizeof(T));
}

template <class T>
T Data::readData(fstream& dataFile, int position)
{
    T output;
    dataFile.seekg(position * sizeof(T), ios::beg);
    dataFile.read(reinterpret_cast<char*>(&output), sizeof(T));
    return output;
}

template <class T>
void Data::OpenData(vector<T>& outRecData, fstream& dataFile, const char* filePath)
{
    dataFile.open(filePath, ios::in | ios::out | ios::binary);
    bool bDataFile;
    if (dataFile.is_open())
    {
        bDataFile = dataFile.is_open();
    }
    else
    {
        dataFile.close();
        dataFile.open(filePath, ios::trunc | ios::in | ios::out | ios::binary);
        bDataFile = dataFile.is_open();
    }
    if (!bDataFile){ cout << "Error while opening " << filePath << "!" << endl; exit(1); }

    for (int i = 0; i < getDataSize<T>(dataFile); i++)
    {
        outRecData.push_back(readData<T>(dataFile, i));
    }

    cout << "Success load data from " << filePath << "!" << endl;
}