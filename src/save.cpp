#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>

#include "include/save.hpp"
#include "include/utils.hpp"
#include "include/user.hpp"
#include "include/departemen.hpp"

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



// ========================    Departemen    ========================
void Save::saveData(vector<Departemen> *data, const char *path)
{
    fstream file;
    file.open(path, ios::trunc | ios::out | ios::in);
    if (!file.is_open()){ cout << "Error while opening " << path << "!" << endl; exit(1); }
    
    for (Departemen &dept : *data)
    {
        file << Utils::encrypt(dept.getName()) << '\0';
        file << Utils::encrypt(dept.getKode()) << '\0';
        file << Utils::encrypt(dept.getId()) << '\0';
        file << Utils::encrypt(to_string(dept.getAllMatkulId()->size())) << '\0';
        for (string &matkulId : *dept.getAllMatkulId())
            file << Utils::encrypt(matkulId) << '\0';
        file << Utils::encrypt(to_string(dept.getAllDosenId()->size())) << '\0';
        for (string &dosenId : *dept.getAllDosenId())
            file << Utils::encrypt(dosenId) << '\0';
        file << Utils::encrypt(to_string(dept.getAllMahasiswaId()->size())) << '\0';
        for (string &mhsId : *dept.getAllMahasiswaId())
            file << Utils::encrypt(mhsId) << '\0';
        file << endl;
    }
}

void Save::loadData(vector<Departemen> &out, const char *path)
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
        
        Departemen departemen{dataString[0], dataString[1], dataString[2]};
        int v1 = 3;
        int v2 = 4 + stoi(dataString[v1]);
        int v3 = 5 + stoi(dataString[v1]) + stoi(dataString[v2]);
        for (int i = v1 + 1; i < v2; i++)
            departemen.addMatkul(dataString[i]);
        for (int i = v2 + 1; i < v3; i++)
            departemen.addDosen(dataString[i]);
        for (int i = v3 + 1; i < v3 + stoi(dataString[v3]) + 1; i++)
            departemen.addMahasiswa(dataString[i]);
        out.push_back(departemen);
    }
}
// ==================================================================



// ===========================    User    ===========================
// ==================================================================