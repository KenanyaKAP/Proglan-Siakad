#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "include/save.hpp"
#include "include/utils.hpp"

#include "include/person.hpp"
#include "include/user.hpp"
#include "include/departemen.hpp"
#include "include/matkul.hpp"

#define USERPATH "data/user.bin"
#define DEPARTEMENPATH "data/departemen.bin"
#define MATKULPATH "data/matkul.bin"

using namespace std;

vector<User> recUser;
vector<Departemen> recDepartemen;
vector<Matkul> recMatkul;

void adminPage(User *user);
void showUserPage(vector<User> *users);
void showDepartemenPage(vector<Departemen> *departemens);
void showDetailDepartemen(vector<Departemen> *departemens);
void showMatkulPage(vector<Matkul*> *matkuls);

// ==================================================================	

void adminPage(User *user)
{
	int menu;
	while (1)
	{
		Utils::clearScreen();
		cout << "Welcome, admin!" << endl;
		cout  << endl;
		cout << "  1. Jumlah User                  : " << recUser.size() << " User" << endl;
		cout << "  2. Jumlah Departemen            : " << recDepartemen.size() << " Departemen" << endl;
		cout << "  3. Jumlah Dosen                 : " << 0 << " Dosen" << endl;
		cout << "  4. Jumlah Tenaga Kependidikan   : " << 0 << " Tendik" << endl;
		cout << "  5. Jumlah Mahasiswa             : " << 0 << " Mahasiswa" << endl;
		cout  << endl;
		cout << "Menu: " << endl;
		cout << "  1. Tampilkan User" << endl;
		cout << "  2. Tampilkan Departemen" << endl;
		cout << "  3. Tampilkan Dosen" << endl;
		cout << "  4. Tampilkan Tenaga Kependidikan" << endl;
		cout << "  5. Tampilkan Mahasiswa" << endl;
		cout << "  9. Ganti password" << endl;
		cout << "  0. Log out" << endl;
		cout << "-> Pilihan: ";
		cin >> menu;
		cin.ignore();
		switch (menu)
		{
		case 0:
			return;
		case 1:
			showUserPage(&recUser);
			break;
		case 2:
			showDepartemenPage(&recDepartemen);
			break;
		case 9:
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
		default:
			break;
		}
	}
}

// ==================================================================

void showUserPage(vector<User> *users)
{
	int page = 1;
	char menu;
	while (1)
	{
		Utils::clearScreen();
		Utils::printTable<string, string>(User::makeTuples(users), User::tuplesHeader(), page);
		cout << endl;
		cout << "Menu: " << endl;
		cout << "  1. Tambah User(Admin)" << endl;
		cout << "  2. Hapus User" << endl;
		if (page <= int((users->size() - 1) / 10) && users->size() > 0)
			cout << "  >. Tampilkan Selanjutnya" << endl;
		if (page > 1)
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

				recUser.push_back(User(username, password, User::Role::Admin, Person::personIdAddOne(recUser.back().getPersonId())));
				Save::saveData(&recUser, USERPATH);
				cout << endl << "Berhasil menambahkan admin!" << endl;
				cin.ignore();
			}
			break;
		case '2':
			{
				while (1)
				{
					string menu;
					Utils::clearScreen();
					cout << "\tHAPUS USER" << endl;
					Utils::printTable<string, string>(User::makeTuples(users), User::tuplesHeader(), page);
					cout << endl;
					cout << "Menu: " << endl;
					cout << " 1~10. Pilih user yang akan dihapus" << endl;
					if (page <= int((users->size() - 1) / 10) && users->size() > 0)
						cout << "    >. Tampilkan Selanjutnya" << endl;
					if (page > 1)
						cout << "    <. Tampilkan Sebelumnya" << endl;
					cout << "    0. Kembali" << endl;
					cout << "-> Pilihan: ";
					cin >> menu;
					cin.ignore();

					if (menu == "0") break;
					else if (menu == ">" && page <= int((users->size() - 1) / 10) && users->size() > 0) page++;
					else if (menu == "<" && page > 1) page--;
					else {
						int select;
						stringstream temp(menu);
						temp >> select;
						if (select > 10 * (page - 1) && select <= 10 * page && select <= (int)users->size())
						{
							cout << endl << "Anda yakin ingin menghapus " << users->at(select - 1).getUsername() << endl;
							cout << "-> [y/n]: ";
							cin >> menu;
							cin.ignore();
							if (menu == "y" || menu == "Y")
							{
								recUser.erase(recUser.begin() + select - 1);
								Save::saveData(&recUser, USERPATH);
								cout << endl << "User telah dihapus!" << endl;
								cin.ignore();
							}
							break;
						}
					}
				}
			}
			break;
		case '>':
			if (page <= int((users->size() - 1) / 10) && users->size() > 0) page++;
			break;
		case '<':
			if (page > 1) page--;
			break;
		default:
			break;
		}
	}
}

// ==================================================================

void showDepartemenPage(vector<Departemen> *departemens)
{
	int page = 1;
	char menu;
	while (1)
	{
		Utils::clearScreen();
		Utils::printTable<string, string>(Departemen::makeTuples(departemens), Departemen::tuplesHeader(), page);
		cout << endl;
		cout << "Menu: " << endl;
		cout << "  1. Tambah Departemen" << endl;
		cout << "  2. Hapus Departemen" << endl;
		cout << "  3. Tampilkan Detail" << endl;
		if (page <= int((departemens->size() - 1) / 10) && departemens->size() > 0)
			cout << "  >. Tampilkan Selanjutnya" << endl;
		if (page > 1)
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
				string name, kode;
				Utils::clearScreen();
				cout << "-> Nama Departemen: ";
				getline(cin, name);
				cout << "-> Kode Departemen: ";
				getline(cin, kode);

				recDepartemen.push_back(Departemen(name, kode, (recDepartemen.size() > 0) ? Departemen::departemenIdAddOne(recDepartemen.back().getId()) : "d_0"));
				Save::saveData(&recDepartemen, DEPARTEMENPATH);
				cout << endl << "Berhasil menambahkan departemen!" << endl;
				cin.ignore();
			}
			break;
		case '2':
			{
				while (1)
				{
					string menu;
					Utils::clearScreen();
					cout << "\tHAPUS DEPARTEMEN" << endl;
					Utils::printTable<string, string>(Departemen::makeTuples(departemens), Departemen::tuplesHeader(), page);
					cout << endl;
					cout << "Menu: " << endl;
					cout << " 1~10. Pilih departemen yang akan dihapus" << endl;
					if (page <= int((departemens->size() - 1) / 10) && departemens->size() > 0)
						cout << "    >. Tampilkan Selanjutnya" << endl;
					if (page > 1)
						cout << "    <. Tampilkan Sebelumnya" << endl;
					cout << "    0. Kembali" << endl;
					cout << "-> Pilihan: ";
					cin >> menu;
					cin.ignore();

					if (menu == "0") break;
					else if (menu == ">" && page <= int((departemens->size() - 1) / 10) && departemens->size() > 0) page++;
					else if (menu == "<" && page > 1) page--;
					else {
						int select;
						stringstream temp(menu);
						temp >> select;
						if (select > 10 * (page - 1) && select <= 10 * page && select <= (int)departemens->size())
						{
							cout << endl << "Menghapus departemen juga akan menghapus semua mata kuliah di dalamnya" << endl;
							cout << "Anda yakin ingin menghapus " << departemens->at(select - 1).getName() << endl;
							cout << "-> [y/n]: ";
							cin >> menu;
							cin.ignore();
							if (menu == "y" || menu == "Y")
							{
								recDepartemen.erase(recDepartemen.begin() + select - 1);
								Save::saveData(&recDepartemen, DEPARTEMENPATH);

								// MENGHAPUS SEMUA MATA KULIAH DIDALAMNYA!!!
								// MENGHAPUS SEMUA MATA KULIAH DIDALAMNYA!!!
								// MENGHAPUS SEMUA MATA KULIAH DIDALAMNYA!!!
								// MENGHAPUS SEMUA MATA KULIAH DIDALAMNYA!!!
								// MENGHAPUS SEMUA MATA KULIAH DIDALAMNYA!!!

								cout << endl << "Departemen telah dihapus!" << endl;
								cin.ignore();
							}
							break;
						}
					}
				}
			}
			break;
		case '3':
			showDetailDepartemen(departemens);
			break;
		case '>':
			if (page <= int((departemens->size() - 1) / 10) && departemens->size() > 0) page++;
			break;
		case '<':
			if (page > 1) page--;
			break;
		default:
			break;
		}
	}
}

// ==================================================================

void showDetailDepartemen(vector<Departemen> *departemens)
{
	int index = 0;
	Departemen &departemen = departemens->at(index);
	char menu;
	while (1)
	{
		Utils::clearScreen();
		cout << "-----------------------------------------------" << endl;
		cout << " " << index + 1 << "/" << departemens->size() << "\t" << departemen.getName() << endl;
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
		cout << "  4. Tambah Mata Kuliah" << endl;
		if (index + 1 < int(departemens->size()))
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
			showMatkulPage(Matkul::getMatkulByDepartemenId(&recMatkul, departemen.getId()));
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			{
				string matkulName, matkulKode;
				int matkulSKS;
				Utils::clearScreen();
				cout << "Nama mata kuliah	: ";
				getline(cin, matkulName);
				cout << "Kode mata kuliah	: ";
				getline(cin, matkulName);
				cout << "SKS mata kuliah	: ";
				cin >> matkulSKS;
				
				// recMatkul.push_back(Matkul(matkulName, matkulKode, matkulSKS, (recMatkul.size() > 0) ? Matkul::matkulIdAddOne(recMatkul.back().getId()) : "m_0"));
				// Save::saveData(&recMatkul, MATKULPATH);
				
				// Save::saveData(&recDepartemen, DEPARTEMENPATH);
			}
			break;
		case '>':
			if (index + 1 < int(departemens->size())) index++;
			break;
		case '<':
			if (index > 0) index--;
			break;
		default:
			break;
		}
	}
}

// ==================================================================

void showMatkulPage(vector<Matkul*> *matkuls)
{
	if (!matkuls)
	{
		cout << endl << "Departemen tidak memiliki mata kuliah!" << endl;
		cin.ignore();
		return;
	}

	int index = 0;
	Matkul *matkul = matkuls->at(index);
	char menu;
	while (1)
	{
		cout << "-----------------------------------------------" << endl;
		cout << " " << index + 1 << "/" << matkuls->size() << "\t" << matkul->getName() << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "Kode                :" << matkul->getKode() << endl;
		cout << "SKS                 :" << matkul->getSKS() << endl;
		cout << "Jumlah Kelas        :" << matkul->getAllKelasId()->size() << endl;
		cout << "Jumlah Pengampu     :" << matkul->getAllDosenId()->size() << endl;
		cout << "-----------------------------------------------" << endl;
		cout << endl;
		cout << "Menu:" << endl;
		cout << "  1. Tampilkan Semua Kelas" << endl;
		cout << "  >. Tampilkan Selanjutnya" << endl;
		cout << "  <. Tampilkan Sebelumnya" << endl;
		cout << "  0. Kembali" << endl;
		cout << "-> Pilihan: " << endl;
		cin >> menu;
		cin.ignore();
	}
}

// ==================================================================



// ==================================================================

int main()
{
	vector<Matkul> temp;
	// temp.push_back(Matkul("Pemrograman Lanjutan", "EC123456", 3, "m_0", "d_0"));
	// temp[0].addDosen("p_0");
	// temp[0].addDosen("p_1");
	// temp[0].addKelas("k_0");
	// temp[0].addKelas("k_1");
	// temp[0].addKelas("k_2");
	// temp[0].addKelas("k_3");
	// temp.push_back(Matkul("Rangkaian Listrik", "EW123456", 2, "m_1", "d_0"));
	// temp.push_back(Matkul("Fisika 2", "SF123456", 3, "m_2", "d_0"));
	// temp.push_back(Matkul("Kimia 1", "SK123456", 3, "m_3", "d_0"));
	// temp.push_back(Matkul("Bahasa Indonesia", "UG123456", 3, "m_4", "d_0"));

	// Save::saveData(&temp, MATKULPATH);
	Save::loadData(temp, MATKULPATH);

	for (Matkul &matkul : temp)
	{
		cout << matkul.getName() << endl;
		cout << matkul.getKode() << endl;
		cout << matkul.getSKS() << endl;
		cout << matkul.getId() << endl;
		cout << matkul.getDepartemenId() << endl;
		for (string &dosenId : *matkul.getAllDosenId())
		{
			cout << dosenId << "|";
		}
		cout << endl;
		for (string &kelasId : *matkul.getAllKelasId())
		{
			cout << kelasId << "|";
		}
		cout << endl;
		cout << endl;
	}

	exit(0);

	Save::loadData(recUser, USERPATH);
	Save::loadData(recDepartemen, DEPARTEMENPATH);

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
		cout << endl;
		cout << endl;
		cout << "-> Username: ";
		cin >> usernameInp;
		cout << "-> Password: ";
		cin >> passwordInp;
		cin.ignore();
		if (User *user = User::getUser(&recUser, usernameInp))
		{
			if (user->getPassword() == passwordInp)
			{
				switch (user->getRole())
				{
				case 0:
					adminPage(user);
					break;
				case 1:
					cout << "You r Dosen\n";
					cin.ignore();
					break;
				case 2:
					cout << "You r Tendik\n";
					cin.ignore();
					break;
				case 3:
					cout << "You r Mahasiswa\n";
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