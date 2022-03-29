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

// Constructor

Data::Data()
{

    // // Load Recorded Data
    // OpenData<User>(recUser, fUser, USERPATH);


    fstream fSuser;

    User tata("Ken", "Ken!234", "p_0", User::Role::Mahasiswa);

    S_User sUser(tata);

    writeData<S_User>(fSuser, 1, sUser, "data/fuser.bin");
    
    // S_User toto = readData<S_User>(fUser, 0, "data/fuser.bin");
    
    User done(loadData<User, S_User>(fSuser, "data/fuser.bin"));
    
    cout << done.getUsername() << "|";
    cout << done.getPassword() << "|";
    cout << done.getPersonId() << "|";
    cout << done.getRole() << "|YESSSSSSSSs" << endl;
}

// Destructor

Data::~Data()
{
    // fUser.close();
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
void Data::writeData(fstream &dataFile, int position, T input, const char *filePath)
{
    dataFile.open(filePath, ios::out | ios::in | ios::binary);
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







    dataFile.seekp(position * sizeof(T), ios::beg);
    dataFile.write(reinterpret_cast<char*>(&input), sizeof(T));

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

// template <class T>
// void Data::OpenData(vector<T>& outRecData, fstream& dataFile, const char *filePath)
// {
//     dataFile.open(filePath, ios::out | ios::in | ios::binary);
//     bool bDataFile;
//     if (dataFile.is_open())
//     {
//         bDataFile = dataFile.is_open();
//     }
//     else
//     {
//         dataFile.close();
//         dataFile.open(filePath, ios::trunc | ios::out | ios::in | ios::binary);
//         bDataFile = dataFile.is_open();
//     }
//     if (!bDataFile){ cout << "Error while opening " << filePath << "!" << endl; exit(1); }

//     for (int i = 0; i < getDataSize<T>(dataFile); i++)
//     {
//         outRecData.push_back(readData<T>(dataFile, i));
//     }

//     cout << "Success load data from " << filePath << "!" << endl;
// }

template <class Base, class Save>
Base Data::loadData(std::fstream& dataFile, const char *filePath)
{
    dataFile.open(filePath, ios::in | ios::binary);
    bool bDataFile;
    if (dataFile.is_open())
    {
        bDataFile = dataFile.is_open();
    }
    else
    {
        dataFile.close();
        dataFile.open(filePath, ios::trunc | ios::in | ios::binary);
        bDataFile = dataFile.is_open();
    }
    if (!bDataFile){ cout << "Error while opening " << filePath << "!" << endl; exit(1); }

    Save save = readData<Save>(dataFile, 1);
    Base base(save);
    return base;
}

// User

int Data::getUserSize(){ return this->recUser.size(); }

vector<User> *Data::getAllUser(){ return &this->recUser; }

User *Data::getUser(char *username)
{ 
    for (User& user : recUser)
        if (strcmp(user.getUsername().c_str(), username) == 0) 
            return &user; 
    return nullptr; 
}

void Data::removeUser(char *username)
{
    // for (size_t i = 0; i < recUser.size(); i++)
    //     if (strcmp(recUser[i].getUsername().c_str(), username) == 0)
    //         recUser.erase(recUser.begin() + i);

    // fUser.close();
    // fUser.open(USERPATH, ios::trunc | ios::in | ios::out | ios::binary);
    
    // // for (size_t i = 0; i < recUser.size(); i++)
    //     // writeData<User>(fUser, i, recUser[i]);
}

void Data::addUser(const char *username, const char *password, const char *personId, User::Role role)
{
    addUser((char*)username, (char*)password, (char*)personId, role);
}

void Data::addUser(char *username, char *password, char *personId, User::Role role)
{
    User newUser(username, password, personId, role);
    recUser.push_back(newUser);
    
    // writeData<User>(fUser, getDataSize<User>(fUser), newUser);
}

int Data::loginUser(char *username, char *password)
{
    for (User &user : recUser)
    {
        if (strcmp(username, user.getUsername().c_str()) == 0 && strcmp(password, user.getPassword().c_str()) == 0)
            return user.getRole();
    }
    return -1;
}