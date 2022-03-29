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

    User tata("Yose", "osee!234", "p_6", User::Role::Mahasiswa);

    // S_User sUser(tata);

    // writeData<S_User>(1, sUser, "data/fuser.bin");
    
    // // S_User toto = readData<S_User>(fUser, 0, "data/fuser.bin");
    
    // vector<User> users = loadData<User, S_User>("data/fuser.bin");
    
    // cout << users[1].getUsername() << "|";
    // cout << users[1].getPassword() << "|";
    // cout << users[1].getPersonId() << "|";
    // cout << users[1].getRole() << "|YESSSSSSSSs" << endl;
    writeData<User, S_User>(5, tata, USERPATH);
    recUser = loadData<User, S_User>(USERPATH);
    for (User user : recUser)
    {
        cout << user.getUsername() << "|";
        cout << user.getPassword() << "|";
        cout << user.getPersonId() << "|";
        cout << user.getRole() << endl;
    }
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

template <class Base, class Save>
void Data::writeData(int position, Base input, const char *filePath)
{
    fstream dataFile;
    dataFile.open(filePath, ios::out | ios::in | ios::binary);
    bool bDataFile = dataFile.is_open();
    if (!bDataFile){ cout << "Error while opening " << filePath << "!" << endl; exit(1); }

    // User tata("Ken", "Ken!234", "p_0", User::Role::Mahasiswa);

    // S_User sUser(tata);

    // writeData<S_User>(1, sUser, "data/fuser.bin");
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

    return data;
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