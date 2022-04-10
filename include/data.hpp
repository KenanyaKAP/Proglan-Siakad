#ifndef __DATA_HPP__
#define __DATA_HPP__

#include <iostream>
#include <vector>
#include <tuple>

struct Data {
public:
    enum MasaFRS {
        Belum,
        Isi,
        Lewat
    };

private:
    MasaFRS masaFRS;
    std::string lastAdminId;
    std::string lastPersonId;
    std::string lastDepartemenId;
    std::string lastMatkulId;
    std::string lastFRSId;
    std::vector<std::tuple<std::string, int>> dosenId;
    std::vector<std::tuple<std::string, int>> mahasiswaId;

public:
    Data();

    Data::MasaFRS getMasaFRS();
    std::string getMasaFRSString();
    std::string getLastAdminId();
    std::string getLastPersonId();
    std::string getLastDepartemenId();
    std::string getLastMatkulId();
    std::string getLastFRSId();
    std::vector<std::tuple<std::string, int>> *getDosenId();
    std::vector<std::tuple<std::string, int>> *getMahasiswaId();
    
    void setMasaFRS(Data::MasaFRS masa);
    void setLastAdminId(std::string last);
    void setLastPersonId(std::string last);
    void setLastDepartemenId(std::string last);
    void setLastMatkulId(std::string last);
    void setLastFRSId(std::string last);
    void setDosenId(std::vector<std::tuple<std::string, int>> *data);
    void setMahasiswaId(std::vector<std::tuple<std::string, int>> *data);

    std::string lastAdminIdAddOne();
    std::string lastPersonIdAddOne();
    std::string lastDepartemenIdAddOne();
    std::string lastMatkulIdAddOne();
    std::string lastFRSIdAddOne();

    int dosenIdCount(std::string tahun);
    int mahasiswaIdCount(std::string departemenId);
};

#endif