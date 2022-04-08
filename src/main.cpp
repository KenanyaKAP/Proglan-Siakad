#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "include/utils.hpp"
#include "include/save.hpp"
#include "include/data.hpp"

#include "include/user.hpp"
#include "include/departemen.hpp"
#include "include/matkul.hpp"
#include "include/dosen.hpp"
#include "include/tendik.hpp"
#include "include/mahasiswa.hpp"

#define DATAPATH "data/data.bin"
#define USERPATH "data/user.bin"
#define DEPARTEMENPATH "data/departemen.bin"
#define MATKULPATH "data/matkul.bin"
#define DOSENPATH "data/dosen.bin"
#define TENDIKPATH "data/tendik.bin"
#define MAHASISWAPATH "data/mahasiswa.bin"

using namespace std;

Data myData;
vector<User> recUser;
vector<Departemen> recDepartemen;
vector<Matkul> recMatkul;
vector<Dosen> recDosen;
vector<Tendik> recTendik;
vector<Mahasiswa> recMahasiswa;

// ==================================================================

void adminPage(User *user);
void adminMenuPage();
void dosenPage(Dosen *dosen);

void showUserPage();
void showDepartemenPage();
void showDosenPage(string deptId = "\0");
void showTendikPage();
void showMahasiswaPage(string deptId = "\0");

void addDosen(string deptId = "\0");
void addTendik();
void addMahasiswa(string deptId = "\0");

// ==================================================================

void adminPage(User *user)
{
	char menu;
	while (1)
	{
		Utils::clearScreen();
		cout << "Welcome, admin!" << endl;
		cout  << endl;
		cout << "Data statistik:" << endl;
		cout << "  1. Jumlah User                  : " << recUser.size() << " User" << endl;
		cout << "  2. Jumlah Departemen            : " << recDepartemen.size() << " Departemen" << endl;
		cout << "  3. Jumlah Dosen                 : " << recDosen.size() << " Dosen" << endl;
		cout << "  4. Jumlah Tenaga Kependidikan   : " << recTendik.size() << " Tendik" << endl;
		cout << "  5. Jumlah Mahasiswa             : " << recMahasiswa.size() << " Mahasiswa" << endl;
		cout  << endl;
		cout << "Menu: " << endl;
		cout << "  1. Tampilkan User" << endl;
		cout << "  2. Tampilkan Departemen" << endl;
		cout << "  3. Tampilkan Dosen" << endl;
		cout << "  4. Tampilkan Tenaga Kependidikan" << endl;
		cout << "  5. Tampilkan Mahasiswa" << endl;
		cout << "  8. Ganti password" << endl;
		cout << "  9. |Menu Admin|" << endl;
		cout << "  0. Log out" << endl;
		cout << "-> Pilihan: ";
		cin >> menu;
		cin.ignore();
		switch (menu)
		{
		case '0':
			return;
		case '1':
			showUserPage();
			break;
		case '2':
			showDepartemenPage();
			break;
		case '3':
			showDosenPage();
			break;
		case '4':
			showTendikPage();
			break;
		case '5':
			showMahasiswaPage();
			break;
		case '8':
			{
				Utils::clearScreen();
				string oldPass, newPass, reNewPass;
				cout << "Password lama:\n-> ";
				cin >> oldPass;
				cout << "Password baru:\n-> ";
				cin >> newPass;
				cout << "Ketik ulang password baru:\n-> ";
				cin >> reNewPass;
				cin.ignore();

				if (user->getPassword() == oldPass)
				{
					if (newPass == reNewPass)
					{
						user->changePassword(newPass);
						Save::saveData(&recUser, USERPATH);
						cout << endl << "Password berhasil diubah!" << endl;
						cin.ignore();
						return;
					}
				}
				cout << endl << "Password tidak sama!" << endl;
				cin.ignore();
			}
			break;
		case '9':
			adminMenuPage();
			break;
		default:
			break;
		}
	}
}

// ==================================================================

void adminMenuPage()
{
	char menu;

	while (1)
	{
		Utils::clearScreen();
		cout << ": Halaman Menu Admin" << endl << endl;
		cout << "Menu: " << endl;
		cout << "  1. Ubah Semester Pendidikan" << endl;
		cout << "  0. Kembali" << endl;
		cout << "-> Pilihan: ";
		cin >> menu;
		cin.ignore();

		switch (menu)
		{
			case '0':
				return;
			case '1':
				{
					Utils::clearScreen();
					cout << "Semester saat ini " << myData.getSemester() << endl;
					cout << "Anda yakin ingin mengubah semester menjadi " << myData.getSemester() + 1 << " ?" << endl;
					cout << "-> [y/n]: ";
					cin >> menu;
					cin.ignore();

					if (menu == 'Y' || menu == 'y')
					{
						////
					}
				}
				break;
			default:
				break;
		}
	}
}

// ==================================================================

void dosenPage(Dosen *dosen)
{
	char menu;
	
	while (1)
	{
		Utils::clearScreen();
		cout << "Selamat datang " << dosen->getName() << "!" << endl << endl;
		cout << "Menu: " << endl;
		cout << "  1. Ubah password" << endl;
		cout << "  0. Log out" << endl;
		cin >> menu;
		cin.ignore();

		switch (menu)
		{
		case '0':
			return;
		case '1':
			{
				Utils::clearScreen();
				string oldPass, newPass, reNewPass;
				cout << "Password lama:\n-> ";
				cin >> oldPass;
				cout << "Password baru:\n-> ";
				cin >> newPass;
				cout << "Ketik ulang password baru:\n-> ";
				cin >> reNewPass;
				cin.ignore();

				User *user = User::getUserByUname(&recUser, dosen->getNPP());

				if (user->getPassword() == oldPass)
				{
					if (newPass == reNewPass)
					{
						user->changePassword(newPass);
						Save::saveData(&recUser, USERPATH);
						cout << endl << "Password berhasil diubah!" << endl;
						cin.ignore();
						return;
					}
				}
				cout << endl << "Password tidak sama!" << endl;
				cin.ignore();
			}
			break;
		default:
			break;
		}
	}
}

// ==================================================================

void showUserPage()
{
	int index = 0;
	char menu;
	while (1)
	{
		Utils::clearScreen();
		User &user = recUser.at(index);
		cout << ": Data User" << endl << endl;
		cout << "-----------------------------------------------" << endl;
		cout << " " << index + 1 << "/" << recUser.size() << "\t";
		switch (user.getRole())
		{
		case User::Role::Dosen:
			cout << Dosen::getDosenById(&recDosen, user.getPersonId())->getName() << endl;
			break;
		case User::Role::Tendik:
			cout << Tendik::getTendikById(&recTendik, user.getPersonId())->getName() << endl;
			break;
		case User::Role::Mahasiswa:
			cout << Mahasiswa::getMahasiswaById(&recMahasiswa, user.getPersonId())->getName() << endl;
			break;
		default:
			cout << user.getUsername() << endl;
			break;
		}
		cout << "-----------------------------------------------" << endl;
		cout << "Username	: " << user.getUsername() << endl;
		cout << "Role		: " << user.getRoleString() << endl;
		cout << "Person Id	: " << user.getPersonId() << endl;
		cout << "-----------------------------------------------" << endl;
		cout << endl;
		cout << "Menu: " << endl;
		cout << "  1. Tambah User(Admin)" << endl;
		if (index != 0)
			cout << "  2. Hapus User ini" << endl;
		if (index + 1 < int(recUser.size()))
			cout << "  >. Tampilkan Selanjutnya" << endl;
		if (index > 0)
			cout << "  <. Tampilkan Sebelumnya" << endl;
		cout << "  0. Kembali" << endl;
		cout << "-> Pilihan: ";
		cin >> menu;
		cin.ignore();

		switch (menu)
		{
		case '0':
			return;
		case '1':
			{
				string username, password;
				Utils::clearScreen();
				cout << "-> Username: ";
				cin >> username;
				cout << "-> Password: ";
				cin >> password;
				cin.ignore();

				recUser.push_back(User(username, password, User::Role::Admin, myData.lastAdminIdAddOne()));
				Save::saveData(&recUser, USERPATH);
				Save::saveData(&myData, DATAPATH);
				cout << endl << "Berhasil menambahkan admin!" << endl;
				cin.ignore();
			}
			break;
		case '2':
			{
				if (index == 0) break;

				cout << endl << "Anda yakin ingin menghapus " << user.getUsername() << "?" << endl;
				cout << "-> [y/n]: ";
				cin >> menu;
				cin.ignore();
				if (menu == 'y' || menu == 'Y')
				{
					recUser.erase(recUser.begin() + User::getPositionById(&recUser, user.getPersonId()));
					Save::saveData(&recUser, USERPATH);
					cout << endl << "User telah dihapus!" << endl;
					cin.ignore();
				}
			}
			break;
		case '>':
			if (index + 1 < int(recUser.size())) index++;
			break;
		case '<':
			if (index > 0) index--;
			break;
		default:
			break;
		}

		if ((unsigned int)index >= recUser.size()) index = recUser.size() - 1;
	}
}

// ==================================================================

void showDepartemenPage()
{
	int index = 0;
	char menu;

	while (1)
	{
		if (recDepartemen.size() == 0)
		{
			Utils::clearScreen();
			cout << ": Data Departemen Tidak Ditemukan" << endl << endl;
			cout << "Menu: " << endl;
			cout << "  1. Tambah Departemen" << endl;
			cout << "  0. Kembali" << endl;
			cout << "-> Pilihan: ";
			cin >> menu;
			cin.ignore();

			switch (menu)
			{
			case '0':
				return;
			case '1':
				{
					string name, kode;
					Utils::clearScreen();
					cout << "-> Nama Departemen: ";
					getline(cin, name);
					cout << "-> Kode Departemen: ";
					getline(cin, kode);

					recDepartemen.push_back(Departemen(name, kode, myData.lastDepartemenIdAddOne()));
					Save::saveData(&recDepartemen, DEPARTEMENPATH);
					Save::saveData(&myData, DATAPATH);
					cout << endl << "Berhasil menambahkan departemen!" << endl;
					cin.ignore();
				}
				break;
			default:
				break;
			}
		}
		else
		{
			Departemen &departemen = recDepartemen.at(index);
			Utils::clearScreen();
			cout << ": Data Departemen" << endl << endl;
			cout << "-----------------------------------------------" << endl;
			cout << " " << index + 1 << "/" << recDepartemen.size() << "\t" << departemen.getName() << endl;
			cout << "-----------------------------------------------" << endl;
			cout << "Kode Departemen     : " << departemen.getKode() << endl;
			cout << "Jumlah Mata Kuliah  : " << departemen.getAllMatkulId()->size() << endl;
			cout << "Jumlah Dosen        : " << departemen.getAllDosenId()->size() << endl;
			cout << "Jumlah Mahasiswa    : " << departemen.getAllMahasiswaId()->size() << endl;
			cout << "-----------------------------------------------" << endl;
			cout << endl;
			cout << "Menu: " << endl;
			cout << "  1. Tampilkan Semua Mata Kuliah" << endl;
			cout << "  2. Tampilkan Semua Dosen" << endl;
			cout << "  3. Tampilkan Semua Mahasiswa" << endl;
			cout << "  4. Tambah Departemen" << endl;
			cout << "  5. Hapus Departemen ini" << endl;
			if (index + 1 < int(recDepartemen.size()))
				cout << "  >. Tampilkan Selanjutnya" << endl;
			if (index > 0)
				cout << "  <. Tampilkan Sebelumnya" << endl;
			cout << "  0. Kembali" << endl;
			cout << "-> Pilihan: ";
			cin >> menu;
			cin.ignore();

			switch (menu)
			{
			case '0':
				return;
			case '1':
				// showMatkulPage(&departemen);
				break;
			case '2':
				showDosenPage(departemen.getId());
				break;
			case '3':
				showMahasiswaPage(departemen.getId());
				break;
			case '4':
				{
					string name, kode;
					Utils::clearScreen();
					cout << "-> Nama Departemen: ";
					getline(cin, name);
					cout << "-> Kode Departemen: ";
					getline(cin, kode);

					recDepartemen.push_back(Departemen(name, kode, myData.lastDepartemenIdAddOne()));
					Save::saveData(&recDepartemen, DEPARTEMENPATH);
					Save::saveData(&myData, DATAPATH);
					cout << endl << "Berhasil menambahkan departemen!" << endl;
					cin.ignore();
				}
				break;
			case '5':
				{
					cout << endl << "Menghapus departemen juga akan menghapus semua mata kuliah di dalamnya" << endl;
					cout << "Anda yakin ingin menghapus " << departemen.getName() << "?" << endl;
					cout << "-> [y/n]: ";
					cin >> menu;
					cin.ignore();
					if (menu == 'y' || menu == 'Y')
					{
						for (string &matkulId : *departemen.getAllMatkulId())
						{
							recMatkul.erase(recMatkul.begin() + Matkul::getPositionById(&recMatkul, matkulId));
						}
						recDepartemen.erase(recDepartemen.begin() + Departemen::getPositionById(&recDepartemen, departemen.getId()));

						Save::saveData(&recMatkul, MATKULPATH);
						Save::saveData(&recDepartemen, DEPARTEMENPATH);

						cout << endl << "Departemen telah dihapus!" << endl;
						cin.ignore();
					}
				}
				break;
			case '>':
				if (index + 1 < int(recDepartemen.size())) index++;
				break;
			case '<':
				if (index > 0) index--;
				break;
			default:
				break;
			}
		}
		
		if ((unsigned int)index >= recDepartemen.size()) index = recDepartemen.size() - 1;
	}
}

// ==================================================================

// MATKUL MATKUL MATKUL MATKUL MATKUL MATKUL MATKUL MATKUL MATKUL

// ==================================================================

void showDosenPage(string deptId)
{
	int index = 0;
	char menu;

	while (1)
	{
		vector<Dosen*> dosens = Utils::makeVectorPointer(&recDosen);
		if (deptId != "\0")
			dosens = Dosen::getDosensByDeptId(&recDosen, deptId);

		if (dosens.size() == 0)
		{
			Utils::clearScreen();
			cout << ": Data Dosen Tidak Ditemukan" << endl << endl;
			cout << "Menu: " << endl;
			cout << "  1. Tambah Dosen" << endl;
			cout << "  0. Kembali" << endl;
			cout << "-> Pilihan: ";
			cin >> menu;
			cin.ignore();

			switch (menu)
			{
			case '0':
				return;
			case '1':
				addDosen(deptId);
				break;
			default:
				break;
			}
		}
		else
		{
			Dosen &dosen = *dosens.at(index);
			Utils::clearScreen();
			cout << ": Data Dosen "; 
			if (deptId != "\0")
				cout << Departemen::getDepartemenById(&recDepartemen, deptId)->getName();
			cout << endl << endl;
			cout << "-----------------------------------------------" << endl;
			cout << " " << index + 1 << "/" << dosens.size() << "\t" << dosen.getName() << endl;
			cout << "-----------------------------------------------" << endl;
			cout << "NPP                 : " << dosen.getNPP() << endl;
			cout << "Tanggal Lahir       : " << dosen.getTglLahir() << " " << Utils::intToStringMonth(dosen.getBulanLahir()) << " " << dosen.getTahunLahir() << endl;
			cout << "Pendidikan          : " << "S" << dosen.getPendidikan() << endl;
			cout << "Departemen          : " << Departemen::getDepartemenById(&recDepartemen, dosen.getDepartemenId())->getName() << endl;
			cout << "Jumlah Mhs Wali     : " << dosen.getAllMahasiswaWaliId()->size() << endl;
			cout << "-----------------------------------------------" << endl;
			cout << endl;
			cout << "Menu:" << endl;
			cout << "  1. Tambah Dosen ";
			if (deptId != "\0")
				cout << Departemen::getDepartemenById(&recDepartemen, deptId)->getName();
			cout << endl;
			cout << "  2. Hapus Dosen ini" << endl;
			if (index + 1 < int(dosens.size()))
				cout << "  >. Tampilkan Selanjutnya" << endl;
			if (index > 0)
				cout << "  <. Tampilkan Sebelumnya" << endl;
			cout << "  0. Kembali" << endl;
			cout << "-> Pilihan: ";
			cin >> menu;
			cin.ignore();

			switch (menu)
			{
			case '0':
				return;
			case '1':
				addDosen(deptId);
				break;
			case '2':
				{
					cout << endl << "Anda yakin ingin menghapus " << dosen.getName() << "?" << endl;
					cout << "-> [y/n]: ";
					cin >> menu;
					cin.ignore();
					if (menu == 'y' || menu == 'Y')
					{
						recUser.erase(recUser.begin() + User::getPositionById(&recUser, dosen.getUser(&recUser)->getPersonId()));
						Departemen::getDepartemenById(&recDepartemen, dosen.getDepartemenId())->delDosen(dosen.getId());
						recDosen.erase(recDosen.begin() + Dosen::getPositionById(&recDosen, dosen.getId()));

						Save::saveData(&recUser, USERPATH);
						Save::saveData(&recDepartemen, DEPARTEMENPATH);
						Save::saveData(&recDosen, DOSENPATH);

						cout << endl << "Dosen telah dihapus!" << endl;
						cin.ignore();
					}
				}
				break;
			case '>':
				if (index + 1 < int(dosens.size())) index++;
				break;
			case '<':
				if (index > 0) index--;
				break;
			default:
				break;
			}
		}

		dosens = Utils::makeVectorPointer(&recDosen);
		if (deptId != "\0")
			dosens = Dosen::getDosensByDeptId(&recDosen, deptId);
		if ((unsigned int)index >= dosens.size()) index = dosens.size() - 1;
	}
}

// ==================================================================

void showTendikPage()
{
	int index = 0;
	char menu;

	while (1)
	{
		if (recTendik.size() == 0)
		{
			Utils::clearScreen();
			cout << ": Data Tendik Tidak Ditemukan" << endl << endl;
			cout << "Menu: " << endl;
			cout << "  1. Tambah Tendik" << endl;
			cout << "  0. Kembali" << endl;
			cout << "-> Pilihan: ";
			cin >> menu;
			cin.ignore();

			switch (menu)
			{
			case '0':
				return;
			case '1':
				addTendik();
				break;
			default:
				break;
			}
		}
		else
		{
			Tendik &tendik = recTendik.at(index);
			Utils::clearScreen();
			cout << ": Data Tendik" << endl << endl;
			cout << "-----------------------------------------------" << endl;
			cout << " " << index + 1 << "/" << recTendik.size() << "\t" << tendik.getName() << endl;
			cout << "-----------------------------------------------" << endl;
			cout << "NPP                 : " << tendik.getNPP() << endl;
			cout << "Tanggal Lahir       : " << tendik.getTglLahir() << " " << Utils::intToStringMonth(tendik.getBulanLahir()) << " " << tendik.getTahunLahir() << endl;
			cout << "Unit                : " << tendik.getUnit() << endl;
			cout << "-----------------------------------------------" << endl;
			cout << endl;
			cout << "Menu:" << endl;
			cout << "  1. Tambah Tendik" << endl;
			cout << "  2. Hapus Tendik ini" << endl;
			if (index + 1 < int(recTendik.size()))
				cout << "  >. Tampilkan Selanjutnya" << endl;
			if (index > 0)
				cout << "  <. Tampilkan Sebelumnya" << endl;
			cout << "  0. Kembali" << endl;
			cout << "-> Pilihan: ";
			cin >> menu;
			cin.ignore();

			switch (menu)
			{
			case '0':
				return;
			case '1':
				addTendik();
				break;
			case '2':
				{
					cout << endl << "Anda yakin ingin menghapus " << tendik.getName() << "?" << endl;
					cout << "-> [y/n]: ";
					cin >> menu;
					cin.ignore();
					if (menu == 'y' || menu == 'Y')
					{
						recUser.erase(recUser.begin() + User::getPositionById(&recUser, tendik.getUser(&recUser)->getPersonId()));
						recTendik.erase(recTendik.begin() + Tendik::getPositionById(&recTendik, tendik.getId()));

						Save::saveData(&recUser, USERPATH);
						Save::saveData(&recTendik, TENDIKPATH);

						cout << endl << "Tendik telah dihapus!" << endl;
						cin.ignore();
					}
				}
				break;
			case '>':
				if (index + 1 < int(recTendik.size())) index++;
				break;
			case '<':
				if (index > 0) index--;
				break;
			default:
				break;
			}
		}
		
		if ((unsigned int)index >= recTendik.size()) index = recTendik.size() - 1;
	}
}

// ==================================================================

void showMahasiswaPage(string deptId)
{
	int index = 0;
	char menu;

	while (1)
	{
		vector<Mahasiswa*> mahasiswas = Utils::makeVectorPointer(&recMahasiswa);
		if (deptId != "\0")
			mahasiswas = Mahasiswa::getMahasiswasByDeptId(&recMahasiswa, deptId);

		if (mahasiswas.size() == 0)
		{
			Utils::clearScreen();
			cout << ": Data Mahasiswa Tidak Ditemukan" << endl << endl;
			cout << "Menu: " << endl;
			cout << "  1. Tambah Mahasiswa" << endl;
			cout << "  0. Kembali" << endl;
			cout << "-> Pilihan: ";
			cin >> menu;
			cin.ignore();

			switch (menu)
			{
			case '0':
				return;
			case '1':
				addMahasiswa(deptId);
				break;
			default:
				break;
			}
		}
		else
		{
			Mahasiswa &mahasiswa = *mahasiswas.at(index);
			Utils::clearScreen();
			cout << ": Data Mahasiswa" << endl << endl;
			cout << "-----------------------------------------------" << endl;
			cout << " " << index + 1 << "/" << mahasiswas.size() << "\t" << mahasiswa.getName() << endl;
			cout << "-----------------------------------------------" << endl;
			cout << "NRP                 : " << mahasiswa.getNRP() << endl;
			cout << "Departemen          : " << Departemen::getDepartemenById(&recDepartemen, mahasiswa.getDepartemenId())->getName() << endl;
			cout << "Dosen Wali          : " << Dosen::getDosenById(&recDosen, mahasiswa.getDoswalId())->getName() << endl;
			cout << "Tanggal Lahir       : " << mahasiswa.getTglLahir() << " " << Utils::intToStringMonth(mahasiswa.getBulanLahir()) << " " << mahasiswa.getTahunLahir() << endl;
			cout << "Tahun Masuk         : " << mahasiswa.getTahunMasuk() << endl;
			cout << "Semester            : " << mahasiswa.getSemester() << endl;
			cout << "SKS Lulus           : " << mahasiswa.getSKSLulus() << endl;
			cout << "IPK                 : " << mahasiswa.getIPK() << endl;
			cout << "-----------------------------------------------" << endl;
			cout << endl;
			cout << "Menu:" << endl;
			cout << "  1. Tambah Mahasiswa ";
			if (deptId != "\0")
				cout << Departemen::getDepartemenById(&recDepartemen, mahasiswa.getDepartemenId())->getName();
			cout << endl;
			cout << "  2. Hapus Mahasiswa ini" << endl;
			cout << "  3. Ubah Dosen Wali" << endl;
			if (index + 1 < int(mahasiswas.size()))
				cout << "  >. Tampilkan Selanjutnya" << endl;
			if (index > 0)
				cout << "  <. Tampilkan Sebelumnya" << endl;
			cout << "  0. Kembali" << endl;
			cout << "-> Pilihan: ";
			cin >> menu;
			cin.ignore();

			switch (menu)
			{
			case '0':
				return;
			case '1':
				addMahasiswa(deptId);
				break;
			case '2':
				{
					cout << endl << "Anda yakin ingin menghapus " << mahasiswa.getName() << "?" << endl;
					cout << "-> [y/n]: ";
					cin >> menu;
					cin.ignore();
					if (menu == 'y' || menu == 'Y')
					{
						recUser.erase(recUser.begin() + User::getPositionById(&recUser, mahasiswa.getUser(&recUser)->getPersonId()));
						Departemen::getDepartemenById(&recDepartemen, mahasiswa.getDepartemenId())->delMahasiswa(mahasiswa.getId());
						recMahasiswa.erase(recMahasiswa.begin() + Mahasiswa::getPositionById(&recMahasiswa, mahasiswa.getId()));

						Save::saveData(&recUser, USERPATH);
						Save::saveData(&recDepartemen, DEPARTEMENPATH);
						Save::saveData(&recMahasiswa, MAHASISWAPATH);

						cout << endl << "Dosen telah dihapus!" << endl;
						cin.ignore();
					}
				}
				break;
			case '3':
				{
					int page = 1;
					string menu;
					vector<Dosen*> dosenDepartemen = Dosen::getDosensByDeptId(&recDosen, mahasiswa.getDepartemenId());
					while (1)
					{
						Utils::clearScreen();
						Utils::printTable<string, string>(Dosen::makeTuples(&dosenDepartemen), Dosen::tuplesHeader(), page);
						cout << endl;
						cout << "Menu: " << endl;
						cout << " 1~10. Pilih dosen wali" << endl;
						if (page <= int((dosenDepartemen.size() - 1) / 10) && dosenDepartemen.size() > 0)
							cout << "    >. Tampilkan Selanjutnya" << endl;
						if (page > 1)
							cout << "    <. Tampilkan Sebelumnya" << endl;
						cout << "-> Pilihan: ";
						cin >> menu;
						cin.ignore();

						if (menu == ">" && page <= int((dosenDepartemen.size() - 1) / 10) && dosenDepartemen.size() > 0) page++;
						else if (menu == "<" && page > 1) page--;
						else {
							int select;
							stringstream temp(menu);
							temp >> select;
							if (select > 10 * (page - 1) && select <= 10 * page && select <= (int)dosenDepartemen.size())
							{
								cout << endl << "Anda yakin ingin mengubah dosen wali" << endl;
								cout << ": " << mahasiswa.getName() << endl;
								cout << "menjadi" << endl;
								cout << ": " << Dosen::getDosenById(&recDosen, dosenDepartemen.at(select - 1)->getId())->getName() << "?" << endl;
								cout << "-> [y/n]: ";
								cin >> menu;
								cin.ignore();
								
								if (menu == "Y" || menu == "y")
								{
									Dosen::getDosenById(&recDosen, mahasiswa.getDoswalId())->delMahasiswaWaliId(mahasiswa.getId());
									mahasiswa.setDoswalId(dosenDepartemen.at(select - 1)->getId());
									Dosen::getDosenById(&recDosen, mahasiswa.getDoswalId())->addMahasiswaWaliId(mahasiswa.getId());
									Save::saveData(&recMahasiswa, MAHASISWAPATH);
									Save::saveData(&recDosen, DOSENPATH);
									cout << endl << "Dosen Wali telah diubah!" << endl;
									cin.ignore();
								}
								break;
							}
						}
					}
				}
				break;
			case '>':
				if (index + 1 < int(mahasiswas.size())) index++;
				break;
			case '<':
				if (index > 0) index--;
				break;
			default:
				break;
			}
		}
		
		mahasiswas = Utils::makeVectorPointer(&recMahasiswa);
		if (deptId != "\0")
			mahasiswas = Mahasiswa::getMahasiswasByDeptId(&recMahasiswa, deptId);
		if ((unsigned int)index >= mahasiswas.size()) index = mahasiswas.size() - 1;
	}
}

// ==================================================================

void addDosen(string deptId)
{
	if (recDepartemen.size() == 0)
	{
		Utils::clearScreen();
		cout << "Data Departemen Tidak Ditemukan!" << endl;
		cout << "Silahkan membuat Departemen terlebih dahulu!" << endl;
		cin.ignore();
		return;
	}

	string name, departemenDosenId, npp;
	int page = 1, dd, mm, yy, tahunMasuk, pendidikan;
	string menu;

	if (deptId == "\0")
	{
		while (1)
		{
			Utils::clearScreen();
			Utils::printTable<string, string>(Departemen::makeTuples(&recDepartemen), Departemen::tuplesHeader(), page);
			cout << endl;
			cout << "Menu: " << endl;
			cout << " 1~10. Pilih departemen dosen" << endl;
			if (page <= int((recDepartemen.size() - 1) / 10) && recDepartemen.size() > 0)
				cout << "    >. Tampilkan Selanjutnya" << endl;
			if (page > 1)
				cout << "    <. Tampilkan Sebelumnya" << endl;
			cout << "-> Pilihan: ";
			cin >> menu;
			cin.ignore();

			if (menu == ">" && page <= int((recDepartemen.size() - 1) / 10) && recDepartemen.size() > 0) page++;
			else if (menu == "<" && page > 1) page--;
			else {
				int select;
				stringstream temp(menu);
				temp >> select;
				if (select > 10 * (page - 1) && select <= 10 * page && select <= (int)recDepartemen.size())
				{
					departemenDosenId = recDepartemen.at(select - 1).getId();
					break;
				}
			}
		}
	}
	else
	{
		departemenDosenId = deptId;
	}

	Utils::clearScreen();
	cout << "Nama Dosen     : ";
	getline(cin, name);
	cout << "Tanggal Lahir  : ";
	cin >> dd;
	cout << "Bulan Lahir    : ";
	cin >> mm;
	cout << "Tahun Lahir    : ";
	cin >> yy;
	cout << "Tahun Masuk    : ";
	cin >> tahunMasuk;
	cout << "Pendidikan     : S";
	cin >> pendidikan;
	cin.ignore();
	char strTemp[5];
	stringstream ss;
	sprintf(strTemp, "%04d", yy);
	ss << strTemp;
	sprintf(strTemp, "%02d", mm);
	ss << strTemp;
	sprintf(strTemp, "%02d", dd);
	ss << strTemp;
	sprintf(strTemp, "%04d", tahunMasuk);
	ss << strTemp;
	sprintf(strTemp, "%03d", myData.dosenIdCount(to_string(tahunMasuk)));
	ss << strTemp;
	npp = ss.str();
	Dosen newDosen(myData.lastPersonIdAddOne(), name, dd, mm, yy, npp, tahunMasuk, departemenDosenId, pendidikan);
	recDosen.push_back(newDosen);
	Departemen::getDepartemenById(&recDepartemen, departemenDosenId)->addDosen(newDosen.getId());
	Save::saveData(&recDosen, DOSENPATH);
	Save::saveData(&recDepartemen, DEPARTEMENPATH);
	Save::saveData(&myData, DATAPATH);

	cout << endl << "Dosen berhasil dibuat!" << endl;

	ss.str("");
	sprintf(strTemp, "%02d", dd);
	ss << strTemp;
	sprintf(strTemp, "%02d", mm);
	ss << strTemp;
	sprintf(strTemp, "%04d", yy);
	ss << strTemp;

	recUser.push_back(User(newDosen.getNPP(), ss.str(), User::Role::Dosen, newDosen.getId()));
	Save::saveData(&recUser, USERPATH);

	cout << endl << "User Dosen berhasil dibuat!" << endl;
	cout << "Username: NPP" << endl;
	cout << "Password: [ddmmyyyy] tanggal lahir" << endl;
	cin.ignore();
}

// ==================================================================

void addTendik()
{
	string name, npp, unit;
	int dd, mm, yy, tahunMasuk;
	string menu;
	Utils::clearScreen();
	cout << "Nama Tendik    : ";
	getline(cin, name);
	cout << "Tanggal Lahir  : ";
	cin >> dd;
	cout << "Bulan Lahir    : ";
	cin >> mm;
	cout << "Tahun Lahir    : ";
	cin >> yy;
	cout << "Tahun Masuk    : ";
	cin >> tahunMasuk;
	cin.ignore();
	cout << "Masukkan Unit  : ";
	getline(cin, unit);
	char strTemp[5];
	stringstream ss;
	sprintf(strTemp, "%04d", yy);
	ss << strTemp;
	sprintf(strTemp, "%02d", mm);
	ss << strTemp;
	sprintf(strTemp, "%02d", dd);
	ss << strTemp;
	sprintf(strTemp, "%04d", tahunMasuk);
	ss << strTemp;
	sprintf(strTemp, "%03d", myData.dosenIdCount(to_string(tahunMasuk)));
	ss << strTemp;
	npp = ss.str();
	Tendik newTendik(myData.lastPersonIdAddOne(), name, dd, mm, yy, npp, tahunMasuk, unit);
	recTendik.push_back(newTendik);

	Save::saveData(&recTendik, TENDIKPATH);
	Save::saveData(&myData, DATAPATH);

	cout << endl << "Tendik berhasil dibuat!" << endl;

	ss.str("");
	sprintf(strTemp, "%02d", dd);
	ss << strTemp;
	sprintf(strTemp, "%02d", mm);
	ss << strTemp;
	sprintf(strTemp, "%04d", yy);
	ss << strTemp;

	recUser.push_back(User(newTendik.getNPP(), ss.str(), User::Role::Tendik, newTendik.getId()));
	Save::saveData(&recUser, USERPATH);

	cout << endl << "User Tendik berhasil dibuat!" << endl;
	cout << "Username: NPP" << endl;
	cout << "Password: [ddmmyyyy] tanggal lahir" << endl;
	cin.ignore();
}

// ==================================================================

void addMahasiswa(string deptId)
{
	if (recDepartemen.size() == 0)
	{
		Utils::clearScreen();
		cout << "Data Departemen Tidak Ditemukan!" << endl;
		cout << "Silahkan membuat Departemen terlebih dahulu!" << endl;
		cin.ignore();
		return;
	}

	string name, departemenMhsId, nrp, doswalId;
	int page = 1, dd, mm, yy, tahunMasuk;
	string menu;

	if (deptId == "\0")
	{
		while (1)
		{
			Utils::clearScreen();
			Utils::printTable<string, string>(Departemen::makeTuples(&recDepartemen), Departemen::tuplesHeader(), page);
			cout << endl;
			cout << "Menu: " << endl;
			cout << " 1~10. Pilih departemen mahasiswa" << endl;
			if (page <= int((recDepartemen.size() - 1) / 10) && recDepartemen.size() > 0)
				cout << "    >. Tampilkan Selanjutnya" << endl;
			if (page > 1)
				cout << "    <. Tampilkan Sebelumnya" << endl;
			cout << "-> Pilihan: ";
			cin >> menu;
			cin.ignore();

			if (menu == ">" && page <= int((recDepartemen.size() - 1) / 10) && recDepartemen.size() > 0) page++;
			else if (menu == "<" && page > 1) page--;
			else {
				int select;
				stringstream temp(menu);
				temp >> select;
				if (select > 10 * (page - 1) && select <= 10 * page && select <= (int)recDepartemen.size())
				{
					departemenMhsId = recDepartemen.at(select - 1).getId();
					break;
				}
			}
		}
	}
	else
	{
		departemenMhsId = deptId;
	}


	if (Departemen::getDepartemenById(&recDepartemen, departemenMhsId)->getAllDosenId()->size() == 0)
	{
		Utils::clearScreen();
		cout << "Data Dosen Wali Tidak Ditemukan!" << endl;
		cout << "Silahkan membuat Dosen di Departemen ini terlebih dahulu!" << endl;
		cin.ignore();
		return;
	}

	page = 1;
	vector<Dosen*> dosenDepartemen = Dosen::getDosensByDeptId(&recDosen, departemenMhsId);
	while (1)
	{
		Utils::clearScreen();
		Utils::printTable<string, string>(Dosen::makeTuples(&dosenDepartemen), Dosen::tuplesHeader(), page);
		cout << endl;
		cout << "Menu: " << endl;
		cout << " 1~10. Pilih dosen wali" << endl;
		if (page <= int((dosenDepartemen.size() - 1) / 10) && dosenDepartemen.size() > 0)
			cout << "    >. Tampilkan Selanjutnya" << endl;
		if (page > 1)
			cout << "    <. Tampilkan Sebelumnya" << endl;
		cout << "-> Pilihan: ";
		cin >> menu;
		cin.ignore();

		if (menu == ">" && page <= int((dosenDepartemen.size() - 1) / 10) && dosenDepartemen.size() > 0) page++;
		else if (menu == "<" && page > 1) page--;
		else {
			int select;
			stringstream temp(menu);
			temp >> select;
			if (select > 10 * (page - 1) && select <= 10 * page && select <= (int)dosenDepartemen.size())
			{
				doswalId = dosenDepartemen.at(select - 1)->getId();
				break;
			}
		}
	}

	Utils::clearScreen();
	cout << "Nama Mahasiswa : ";
	getline(cin, name);
	cout << "Tanggal Lahir  : ";
	cin >> dd;
	cout << "Bulan Lahir    : ";
	cin >> mm;
	cout << "Tahun Lahir    : ";
	cin >> yy;
	cout << "Tahun Masuk    : ";
	cin >> tahunMasuk;
	cin.ignore();
	char strTemp[5];
	stringstream ss;
	ss << Departemen::getDepartemenById(&recDepartemen, departemenMhsId)->getKode();
	int tempTahunMasuk = tahunMasuk % 100;
	ss << tempTahunMasuk;
	ss << 1;
	sprintf(strTemp, "%03d", Departemen::getDepartemenById(&recDepartemen, departemenMhsId)->getAllMahasiswaId()->size() + 1);
	ss << strTemp;
	nrp = ss.str();
	Mahasiswa newMahasiswa(myData.lastPersonIdAddOne(), name, dd, mm, yy, nrp, departemenMhsId, doswalId, tahunMasuk);
	recMahasiswa.push_back(newMahasiswa);
	Departemen::getDepartemenById(&recDepartemen, departemenMhsId)->addMahasiswa(newMahasiswa.getId());
	Dosen::getDosenById(&recDosen, doswalId)->addMahasiswaWaliId(newMahasiswa.getId());
	Save::saveData(&recMahasiswa, MAHASISWAPATH);
	Save::saveData(&recDepartemen, DEPARTEMENPATH);
	Save::saveData(&recDosen, DOSENPATH);
	Save::saveData(&myData, DATAPATH);

	cout << endl << "Mahasiswa berhasil dibuat!" << endl; 

	ss.str("");
	sprintf(strTemp, "%02d", dd);
	ss << strTemp;
	sprintf(strTemp, "%02d", mm);
	ss << strTemp;
	sprintf(strTemp, "%04d", yy);
	ss << strTemp;

	recUser.push_back(User(newMahasiswa.getNRP(), ss.str(), User::Role::Mahasiswa, newMahasiswa.getId()));
	Save::saveData(&recUser, USERPATH);

	cout << endl << "User Dosen berhasil dibuat!" << endl;
	cout << "Username: NPP" << endl;
	cout << "Password: [ddmmyyyy] tanggal lahir" << endl;
	cin.ignore();
}

// ==================================================================

int main()
{
	Save::loadData(myData, DATAPATH);
	Save::loadData(recUser, USERPATH);
	Save::loadData(recDepartemen, DEPARTEMENPATH);
	Save::loadData(recMatkul, MATKULPATH);
	Save::loadData(recDosen, DOSENPATH);
	Save::loadData(recTendik, TENDIKPATH);
	Save::loadData(recMahasiswa, MAHASISWAPATH);

	if (recUser.size() == 0)
	{
		recUser.push_back(User("admin", "Admin", User::Role::Admin, myData.lastAdminIdAddOne()));
		Save::saveData(&recUser, USERPATH);
		Save::saveData(&myData, DATAPATH);
	}

	string usernameInp, passwordInp;
	while (1)
	{
		Utils::clearScreen();
		cout << " ____  _       _             _ " << endl;
		cout << "/ ___|(_) __ _| | ____ _  __| |" << endl;
		cout << "\\___ \\| |/ _` | |/ / _` |/ _` |" << endl;
		cout << " ___) | | (_| |   < (_| | (_| |" << endl;
		cout << "|____/|_|\\__,_|_|\\_\\__,_|\\__,_|" << endl;
		cout << endl;
		cout << "by Kenanya Keandra 5024_004" << endl;
		cout << "Default" << endl;
		cout << "Username: admin" << endl;
		cout << "Password: Admin" << endl;
		cout << endl;
		cout << endl;
		cout << "-> Username: ";
		cin >> usernameInp;
		cout << "-> Password: ";
		cin >> passwordInp;
		cin.ignore();
		if (User *user = User::getUserByUname(&recUser, usernameInp))
		{
			if (user->getPassword() == passwordInp)
			{
				switch (user->getRole())
				{
				case 0:
					adminPage(user);
					break;
				case 1:
					dosenPage(Dosen::getDosenById(&recDosen, user->getPersonId()));
					break;
				case 2:
					cout << "Selamat datang, Tendik!\n";
					cin.ignore();
					break;
				case 3:
					cout << "Selamat datang, Mahasiswa!\n";
					cin.ignore();
					break;
				default:
					break;
				}
			}
			else
			{
				cout << "\nUsername atau Password tidak cocok!";
				cin.ignore();
			}
		}
		else
		{
			cout << "\nUsername atau Password tidak cocok!";
			cin.ignore();
		}		
	}

	cout << "Done";
	return 0;
}