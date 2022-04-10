#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>

#include "include/save.hpp"
#include "include/utils.hpp"
#include "include/data.hpp"
#include "include/user.hpp"
#include "include/departemen.hpp"
#include "include/matkul.hpp"
#include "include/dosen.hpp"
#include "include/tendik.hpp"
#include "include/mahasiswa.hpp"
#include "include/frs.hpp"

using namespace std;

// ===========================    Data    ===========================
void Save::saveData(Data *data, const char *path)
{
    fstream file;
    file.open(path, ios::trunc | ios::out | ios::in);
    if (!file.is_open()){ cout << "Error while opening " << path << "!" << endl; exit(1); }

    file << Utils::encrypt(to_string(data->getMasaFRS())) << '\0';
    file << Utils::encrypt(data->getLastAdminId()) << '\0';
    file << Utils::encrypt(data->getLastPersonId()) << '\0';
    file << Utils::encrypt(data->getLastDepartemenId()) << '\0';
    file << Utils::encrypt(data->getLastMatkulId()) << '\0';
    file << Utils::encrypt(data->getLastFRSId()) << '\0';
    file << Utils::encrypt(to_string(data->getDosenId()->size())) << '\0';
    for (tuple<string, int> &dosen : *data->getDosenId())
    {
        file << Utils::encrypt(get<0>(dosen)) << '\0';
        file << Utils::encrypt(to_string(get<1>(dosen))) << '\0';
    }
    file << Utils::encrypt(to_string(data->getMahasiswaId()->size())) << '\0';
    for (tuple<string, int> &mahasiswa : *data->getMahasiswaId())
    {
        file << Utils::encrypt(get<0>(mahasiswa)) << '\0';
        file << Utils::encrypt(to_string(get<1>(mahasiswa))) << '\0';
    }
    file << endl;
}

void Save::loadData(Data &out, const char *path)
{
    fstream file;
    file.open(path, ios::in);
    if (!file.is_open())
    {
        file.close();
        file.open(path, ios::trunc | ios::out | ios::in);
    }
    if (!file.is_open()){ cout << "Error while opening " << path << "!" << endl; exit(1); }

    string data, temp;
    if (getline(file, data))
    {
        stringstream ssData(Utils::decrypt(data));
        vector<string> dataString;
        while (getline(ssData, temp, '\0'))
            dataString.push_back(temp);
        
        // out.setSemester(stoi(dataString[0]));
        out.setMasaFRS((Data::MasaFRS)stoi(dataString[0]));
        out.setLastAdminId(dataString[1]);
        out.setLastPersonId(dataString[2]);
        out.setLastDepartemenId(dataString[3]);
        out.setLastMatkulId(dataString[4]);
        out.setLastFRSId(dataString[5]);

        int v1 = 6;
        int v2 = 7 + stoi(dataString[v1]) * 2;
        vector<tuple<string, int>> temp;
        for (int i = v1 + 1; i < v2; i += 2)
        {
            temp.push_back(make_tuple(dataString[i], stoi(dataString[i + 1])));
        }
        out.setDosenId(&temp);
        for (int i = v2 + 1; i < v2 + 1 + stoi(dataString[v2]) * 2; i += 2)
        {
            temp.push_back(make_tuple(dataString[i], stoi(dataString[i + 1])));
        }
        out.setMahasiswaId(&temp);
    }
}
// ==================================================================



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



// ==========================    Matkul    ==========================
void Save::saveData(vector<Matkul> *data, const char *path)
{
    fstream file;
    file.open(path, ios::trunc | ios::out | ios::in);
    if (!file.is_open()){ cout << "Error while opening " << path << "!" << endl; exit(1); }

    for (Matkul &matkul : *data)
    {
        file << Utils::encrypt(matkul.getName()) << '\0';
        file << Utils::encrypt(matkul.getKode()) << '\0';
        file << Utils::encrypt(to_string(matkul.getSKS())) << '\0';
        file << Utils::encrypt(matkul.getId()) << '\0';
        file << Utils::encrypt(matkul.getDepartemenId()) << endl;
    }
}

void Save::loadData(vector<Matkul> &out, const char *path)
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
        
        Matkul matkul(dataString[0], dataString[1], stoi(dataString[2]), dataString[3], dataString[4]);
        out.push_back(matkul);
    }
}
// ==================================================================



// ==========================    Dosen    ===========================
void Save::saveData(vector<Dosen> *data, const char *path)
{
    fstream file;
    file.open(path, ios::trunc | ios::out | ios::in);
    if (!file.is_open()){ cout << "Error while opening " << path << "!" << endl; exit(1); }

    for (Dosen &dosen : *data)
    {
        file << Utils::encrypt(dosen.getId()) << '\0';
        file << Utils::encrypt(dosen.getName()) << '\0';
        file << Utils::encrypt(to_string(dosen.getTglLahir())) << '\0';
        file << Utils::encrypt(to_string(dosen.getBulanLahir())) << '\0';
        file << Utils::encrypt(to_string(dosen.getTahunLahir())) << '\0';
        file << Utils::encrypt(dosen.getNPP()) << '\0';
        file << Utils::encrypt(to_string(dosen.getTahunMasuk())) << '\0';
        file << Utils::encrypt(dosen.getDepartemenId()) << '\0';
        file << Utils::encrypt(to_string(dosen.getPendidikan())) << '\0';
        file << Utils::encrypt(to_string(dosen.getAllKelasAjarId()->size())) << '\0';
        for (string &kelasId : *dosen.getAllKelasAjarId())
        {
            file << Utils::encrypt(kelasId) << '\0';
        }
        file << Utils::encrypt(to_string(dosen.getAllMahasiswaWaliId()->size())) << '\0';
        for (string &mahasiswaId : *dosen.getAllMahasiswaWaliId())
        {
            file << Utils::encrypt(mahasiswaId) << '\0';
        }
        file << endl;
    }
}

void Save::loadData(vector<Dosen> &out, const char *path)
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
        
        Dosen dosen(dataString[0], dataString[1], stoi(dataString[2]), stoi(dataString[3]), stoi(dataString[4]), dataString[5], stoi(dataString[6]), dataString[7], stoi(dataString[8]));
        int v1 = 9;
        int v2 = 10 + stoi(dataString[v1]);
        for (int i = v1 + 1; i < v2; i++)
            dosen.addKelasAjarId(dataString[i]);
        for (int i = v2 + 1; i < v2 + 1 + stoi(dataString[v2]); i++)
            dosen.addMahasiswaWaliId(dataString[i]);
        out.push_back(dosen);
    }
}
// ==================================================================



// ==========================    Tendik    ==========================
void Save::saveData(vector<Tendik> *data, const char *path)
{
    fstream file;
    file.open(path, ios::trunc | ios::out | ios::in);
    if (!file.is_open()){ cout << "Error while opening " << path << "!" << endl; exit(1); }

    for (Tendik &tendik : *data)
    {
        file << Utils::encrypt(tendik.getId()) << '\0';
        file << Utils::encrypt(tendik.getName()) << '\0';
        file << Utils::encrypt(to_string(tendik.getTglLahir())) << '\0';
        file << Utils::encrypt(to_string(tendik.getBulanLahir())) << '\0';
        file << Utils::encrypt(to_string(tendik.getTahunLahir())) << '\0';
        file << Utils::encrypt(tendik.getNPP()) << '\0';
        file << Utils::encrypt(to_string(tendik.getTahunMasuk())) << '\0';
        file << Utils::encrypt(tendik.getUnit()) << '\n';
    }
}

void Save::loadData(vector<Tendik> &out, const char *path)
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
        
        Tendik tendik(dataString[0], dataString[1], stoi(dataString[2]), stoi(dataString[3]), stoi(dataString[4]), dataString[5], stoi(dataString[6]), dataString[7]);
        out.push_back(tendik);
    }
}
// ==================================================================



// =========================    Mahasiswa    ========================
void Save::saveData(vector<Mahasiswa> *data, const char *path)
{
    fstream file;
    file.open(path, ios::trunc | ios::out | ios::in);
    if (!file.is_open()){ cout << "Error while opening " << path << "!" << endl; exit(1); }

    for (Mahasiswa &mahasiswa : *data)
    {
        file << Utils::encrypt(mahasiswa.getId()) << '\0';
        file << Utils::encrypt(mahasiswa.getName()) << '\0';
        file << Utils::encrypt(to_string(mahasiswa.getTglLahir())) << '\0';
        file << Utils::encrypt(to_string(mahasiswa.getBulanLahir())) << '\0';
        file << Utils::encrypt(to_string(mahasiswa.getTahunLahir())) << '\0';
        file << Utils::encrypt(mahasiswa.getNRP()) << '\0';
        file << Utils::encrypt(mahasiswa.getDepartemenId()) << '\0';
        file << Utils::encrypt(mahasiswa.getDoswalId()) << '\0';
        file << Utils::encrypt(mahasiswa.getFRSId()) << '\0';
        file << Utils::encrypt(to_string(mahasiswa.getTahunMasuk())) << '\0';
        file << Utils::encrypt(to_string(mahasiswa.getSemester())) << '\0';
        file << Utils::encrypt(to_string(mahasiswa.getSKSLulus())) << '\0';
        for (unsigned int i = 0; i < 14; i++)
        {
            file << Utils::encrypt(to_string(mahasiswa.getAllIPS()->at(i))) << '\0';
        }
        file << endl;
    }
}

void Save::loadData(vector<Mahasiswa> &out, const char *path)
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
        
        Mahasiswa mahasiswa(dataString[0], dataString[1], stoi(dataString[2]), stoi(dataString[3]), stoi(dataString[4]), dataString[5], dataString[6], dataString[7], dataString[8], stoi(dataString[9]));
        
        mahasiswa.setSemester(stoi(dataString[10]));
        mahasiswa.setSKSLulus(stoi(dataString[11]));
        for (int i = 12; i < 26; i++)
        {
            mahasiswa.setIPS(i - 11, stof(dataString[i]));
        }

        out.push_back(mahasiswa);
    }
}
// ==================================================================



// ============================    FRS    ===========================
void Save::saveData(vector<FRS> *data, const char *path)
{
    fstream file;
    file.open(path, ios::trunc | ios::out | ios::in);
    if (!file.is_open()){ cout << "Error while opening " << path << "!" << endl; exit(1); }

    for (FRS &frs : *data)
    {
        file << Utils::encrypt(frs.getId()) << '\0';
        file << Utils::encrypt(to_string(frs.getStatus())) << '\0';
        file << Utils::encrypt(to_string(frs.getAllMatkulId()->size())) << '\0';
        for (unsigned int i = 0; i < frs.getAllMatkulId()->size(); i++)
        {
            file << Utils::encrypt(frs.getAllMatkulId()->at(i)) << '\0';
            file << Utils::encrypt(to_string(frs.getAllMatkulSKS()->at(i))) << '\0';
            file << Utils::encrypt(to_string(frs.getAllNilaiMatkul()->at(i))) << '\0';
        }
        file << endl;
    }
}

void Save::loadData(vector<FRS> &out, const char *path)
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
        
        FRS frs(dataString[0]);
        frs.setStatus((FRS::Status)stoi(dataString[1]));
        
        int v1 = 2;

        for (int i = v1 + 1; i < v1 + 1 + stoi(dataString[v1]) * 3; i += 3)
        {
            frs.addMatkul(dataString[i], stoi(dataString[i+1]), stof(dataString[i+2]));
        }
        
        out.push_back(frs);
    }
}
// ==================================================================



// =========================    Template    =========================
// ==================================================================