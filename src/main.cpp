#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "include/save.hpp"
#include "include/utils.hpp"
#include "include/data.hpp"

#include "include/person.hpp"
#include "include/user.hpp"
#include "include/departemen.hpp"
#include "include/matkul.hpp"
#include "include/dosen.hpp"

#define DATAPATH "data/data.bin"
#define USERPATH "data/user.bin"
#define DEPARTEMENPATH "data/departemen.bin"
#define MATKULPATH "data/matkul.bin"

using namespace std;

Data myData;
vector<User> recUser;
vector<Departemen> recDepartemen;
vector<Matkul> recMatkul;
vector<Dosen> recDosen;

void adminPage(User *user);
void showUserPage(vector<User> *users);
void showDepartemenPage(vector<Departemen> *departemens);
void showMatkulPage(Departemen *departemen);
void showDosenPage(vector<Dosen> *dosens);

// ==================================================================	

void adminPage(User *user)
{
	char menu;
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
		case '0':
			return;
		case '1':
			showUserPage(&recUser);
			break;
		case '2':
			showDepartemenPage(&recDepartemen);
			break;
		case '3':
			showDosenPage(&recDosen);
			break;
		case '9':
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
	int index = 0;
	char menu;
	while (1)
	{
		Utils::clearScreen();
		User &user = users->at(index);
		cout << ": Data User" << endl << endl;
		cout << "-----------------------------------------------" << endl;
		cout << " " << index + 1 << "/" << users->size() << "\t" << user.getUsername() << endl;
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
		if (index + 1 < int(users->size()))
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

				recUser.push_back(User(username, password, User::Role::Admin, "ADMIN"));
				Save::saveData(&recUser, USERPATH);
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
					recUser.erase(recUser.begin() + User::getPosition(&recUser, &user));
					Save::saveData(&recUser, USERPATH);
					cout << endl << "User telah dihapus!" << endl;
					cin.ignore();
				}
				break;
			}
			break;
		case '>':
			if (index + 1 < int(users->size())) index++;
			break;
		case '<':
			if (index > 0) index--;
			break;
		default:
			break;
		}

		if ((unsigned int)index >= users->size()) index = users->size() - 1;
	}
}

// ==================================================================

void showDepartemenPage(vector<Departemen> *departemens)
{
	int index = 0;
	char menu;

	while (1)
	{
		if (departemens->size() == 0)
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
			Departemen &departemen = departemens->at(index);
			Utils::clearScreen();
			cout << ": Data Departemen" << endl << endl;
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
			cout << "  2. Tampilkan Semua Dosen" << endl;									////
			cout << "  3. Tampilkan Semua Mahasiswa" << endl;								////
			cout << "  4. Tambah Departemen" << endl;
			cout << "  5. Hapus Departemen ini" << endl;
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
				showMatkulPage(&departemen);
				break;
			case '2':
				break;
			case '3':
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
							recMatkul.erase(recMatkul.begin() + Matkul::getPosition(&recMatkul, matkulId));
						}
						recDepartemen.erase(recDepartemen.begin() + Departemen::getPosition(&recDepartemen, &departemen));

						Save::saveData(&recMatkul, MATKULPATH);
						Save::saveData(&recDepartemen, DEPARTEMENPATH);

						cout << endl << "Departemen telah dihapus!" << endl;
						cin.ignore();
					}
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
		
		if ((unsigned int)index >= departemens->size()) index = departemens->size() - 1;
	}
}

// ==================================================================

void showMatkulPage(Departemen *departemen)
{
	int index = 0;
	char menu;

	while (1)
	{
		vector<Matkul*> matkuls = Matkul::getMatkulsByDepartemenId(&recMatkul, departemen->getId());

		if (matkuls.size() == 0)
		{
			Utils::clearScreen();
			cout << ": Data Mata Kuliah Departemen " << departemen->getName() << " Tidak Ditemukan" << endl << endl;
			cout << "Menu: " << endl;
			cout << "  1. Tambah Mata Kuliah" << endl;
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
					string matkulName, matkulKode;
					int matkulSKS;
					Utils::clearScreen();
					cout << "Nama mata kuliah   : ";
					getline(cin, matkulName);
					cout << "Kode mata kuliah   : ";
					getline(cin, matkulKode);
					cout << "SKS mata kuliah    : ";
					cin >> matkulSKS;
					cin.ignore();

					Matkul matkulTemp = Matkul(matkulName, matkulKode, matkulSKS, myData.lastMatkulIdAddOne(), departemen->getId());
					departemen->addMatkul(matkulTemp.getId());
					recMatkul.push_back(matkulTemp);
					Save::saveData(&recMatkul, MATKULPATH);
					Save::saveData(&recDepartemen, DEPARTEMENPATH);
					Save::saveData(&myData, DATAPATH);

					cout << endl << "Matkul telah ditambahkan!" << endl;
					cin.ignore();
				}
				break;
			default:
				break;
			}
		}
		else
		{
			Matkul *matkul = matkuls.at(index);
			Utils::clearScreen();
			cout << ": Departemen " << departemen->getName() << endl << endl;
			cout << "-----------------------------------------------" << endl;
			cout << " " << index + 1 << "/" << matkuls.size() << "\t" << matkul->getName() << endl;
			cout << "-----------------------------------------------" << endl;
			cout << "Kode                :" << matkul->getKode() << endl;
			cout << "SKS                 :" << matkul->getSKS() << endl;
			cout << "Jumlah Kelas        :" << matkul->getAllKelasId()->size() << endl;
			cout << "Jumlah Pengampu     :" << matkul->getAllDosenId()->size() << endl;
			cout << "-----------------------------------------------" << endl;
			cout << endl;
			cout << "Menu:" << endl;
			cout << "  1. Tampilkan Semua Pengampu" << endl;								////
			cout << "  2. Tambah Mata Kuliah" << endl;
			cout << "  3. Hapus Mata Kuliah ini" << endl;
			if (index + 1 < int(matkuls.size()))
				cout << "  >. Tampilkan Selanjutnya" << endl;
			if (index > 0)
				cout << "  <. Tampilkan Sebelumnya" << endl;
			cout << "  0. Kembali" << endl;
			cout << "-> Pilihan: " << endl;
			cin >> menu;
			cin.ignore();

			switch (menu)
			{
			case '0':
				return;
			case '1':
				break;
			case '2':
				{
					string matkulName, matkulKode;
					int matkulSKS;
					Utils::clearScreen();
					cout << "Nama mata kuliah   : ";
					getline(cin, matkulName);
					cout << "Kode mata kuliah   : ";
					getline(cin, matkulKode);
					cout << "SKS mata kuliah    : ";
					cin >> matkulSKS;
					cin.ignore();

					Matkul matkulTemp = Matkul(matkulName, matkulKode, matkulSKS, myData.lastMatkulIdAddOne(), departemen->getId());
					departemen->addMatkul(matkulTemp.getId());
					recMatkul.push_back(matkulTemp);
					Save::saveData(&recMatkul, MATKULPATH);
					Save::saveData(&recDepartemen, DEPARTEMENPATH);
					Save::saveData(&myData, DATAPATH);

					cout << endl << "Matkul telah ditambahkan!" << endl;
					cin.ignore();
				}
				break;
			case '3':
				{
					cout << "Anda yakin ingin menghapus " << matkul->getName() << "?" << endl;
					cout << "-> [y/n]: ";
					cin >> menu;
					cin.ignore();
					if (menu == 'y' || menu == 'Y')
					{
						recMatkul.erase(recMatkul.begin() + Matkul::getPosition(&recMatkul, matkul));;
						departemen->delMatkul(matkul->getId());
						
						Save::saveData(&recMatkul, MATKULPATH);
						Save::saveData(&recDepartemen, DEPARTEMENPATH);

						cout << endl << "Mata kuliah telah dihapus!" << endl;
						cin.ignore();
					}
				}
				break;
			case '>':
				if (index + 1 < int(matkuls.size())) index++;
				break;
			case '<':
				if (index > 0) index--;
				break;
			default:
				break;
			}
		}

		matkuls = Matkul::getMatkulsByDepartemenId(&recMatkul, departemen->getId());
		if ((unsigned int)index >= matkuls.size()) index = matkuls.size() - 1;
	}
}

// ==================================================================

void showDosenPage(vector<Dosen> *dosens)
{
	// int index = 0;
	// char menu;

	// while (1)
	// {
	// 	vector<Matkul*> matkuls = Matkul::getMatkulsByDepartemenId(&recMatkul, departemen->getId());

	// 	if (matkuls.size() == 0)
	// 	{
	// 		Utils::clearScreen();
	// 		cout << ": Data Mata Kuliah Departemen " << departemen->getName() << " Tidak Ditemukan" << endl << endl;
	// 		cout << "Menu: " << endl;
	// 		cout << "  1. Tambah Mata Kuliah" << endl;
	// 		cout << "  0. Kembali" << endl;
	// 		cout << "-> Pilihan: ";
	// 		cin >> menu;
	// 		cin.ignore();

	// 		switch (menu)
	// 		{
	// 		case '0':
	// 			return;
	// 		case '1':
	// 			{
	// 				string matkulName, matkulKode;
	// 				int matkulSKS;
	// 				Utils::clearScreen();
	// 				cout << "Nama mata kuliah   : ";
	// 				getline(cin, matkulName);
	// 				cout << "Kode mata kuliah   : ";
	// 				getline(cin, matkulKode);
	// 				cout << "SKS mata kuliah    : ";
	// 				cin >> matkulSKS;
	// 				cin.ignore();

	// 				Matkul matkulTemp = Matkul(matkulName, matkulKode, matkulSKS, myData.lastMatkulIdAddOne(), departemen->getId());
	// 				departemen->addMatkul(matkulTemp.getId());
	// 				recMatkul.push_back(matkulTemp);
	// 				Save::saveData(&recMatkul, MATKULPATH);
	// 				Save::saveData(&recDepartemen, DEPARTEMENPATH);
	// 				Save::saveData(&myData, DATAPATH);

	// 				cout << endl << "Matkul telah ditambahkan!" << endl;
	// 				cin.ignore();
	// 			}
	// 			break;
	// 		default:
	// 			break;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		Matkul *matkul = matkuls.at(index);
	// 		Utils::clearScreen();
	// 		cout << ": Departemen " << departemen->getName() << endl << endl;
	// 		cout << "-----------------------------------------------" << endl;
	// 		cout << " " << index + 1 << "/" << matkuls.size() << "\t" << matkul->getName() << endl;
	// 		cout << "-----------------------------------------------" << endl;
	// 		cout << "Kode                :" << matkul->getKode() << endl;
	// 		cout << "SKS                 :" << matkul->getSKS() << endl;
	// 		cout << "Jumlah Kelas        :" << matkul->getAllKelasId()->size() << endl;
	// 		cout << "Jumlah Pengampu     :" << matkul->getAllDosenId()->size() << endl;
	// 		cout << "-----------------------------------------------" << endl;
	// 		cout << endl;
	// 		cout << "Menu:" << endl;
	// 		cout << "  1. Tampilkan Semua Pengampu" << endl;								////
	// 		cout << "  2. Tambah Mata Kuliah" << endl;
	// 		cout << "  3. Hapus Mata Kuliah ini" << endl;
	// 		if (index + 1 < int(matkuls.size()))
	// 			cout << "  >. Tampilkan Selanjutnya" << endl;
	// 		if (index > 0)
	// 			cout << "  <. Tampilkan Sebelumnya" << endl;
	// 		cout << "  0. Kembali" << endl;
	// 		cout << "-> Pilihan: " << endl;
	// 		cin >> menu;
	// 		cin.ignore();

	// 		switch (menu)
	// 		{
	// 		case '0':
	// 			return;
	// 		case '1':
	// 			break;
	// 		case '2':
	// 			{
	// 				string matkulName, matkulKode;
	// 				int matkulSKS;
	// 				Utils::clearScreen();
	// 				cout << "Nama mata kuliah   : ";
	// 				getline(cin, matkulName);
	// 				cout << "Kode mata kuliah   : ";
	// 				getline(cin, matkulKode);
	// 				cout << "SKS mata kuliah    : ";
	// 				cin >> matkulSKS;
	// 				cin.ignore();

	// 				Matkul matkulTemp = Matkul(matkulName, matkulKode, matkulSKS, myData.lastMatkulIdAddOne(), departemen->getId());
	// 				departemen->addMatkul(matkulTemp.getId());
	// 				recMatkul.push_back(matkulTemp);
	// 				Save::saveData(&recMatkul, MATKULPATH);
	// 				Save::saveData(&recDepartemen, DEPARTEMENPATH);
	// 				Save::saveData(&myData, DATAPATH);

	// 				cout << endl << "Matkul telah ditambahkan!" << endl;
	// 				cin.ignore();
	// 			}
	// 			break;
	// 		case '3':
	// 			{
	// 				cout << "Anda yakin ingin menghapus " << matkul->getName() << "?" << endl;
	// 				cout << "-> [y/n]: ";
	// 				cin >> menu;
	// 				cin.ignore();
	// 				if (menu == 'y' || menu == 'Y')
	// 				{
	// 					recMatkul.erase(recMatkul.begin() + Matkul::getPosition(&recMatkul, matkul));;
	// 					departemen->delMatkul(matkul->getId());
						
	// 					Save::saveData(&recMatkul, MATKULPATH);
	// 					Save::saveData(&recDepartemen, DEPARTEMENPATH);

	// 					cout << endl << "Mata kuliah telah dihapus!" << endl;
	// 					cin.ignore();
	// 				}
	// 			}
	// 			break;
	// 		case '>':
	// 			if (index + 1 < int(matkuls.size())) index++;
	// 			break;
	// 		case '<':
	// 			if (index > 0) index--;
	// 			break;
	// 		default:
	// 			break;
	// 		}
	// 	}

	// 	matkuls = Matkul::getMatkulsByDepartemenId(&recMatkul, departemen->getId());
	// 	if ((unsigned int)index >= matkuls.size()) index = matkuls.size() - 1;
	// }
}

// ==================================================================



// ==================================================================

int main()
{
	Save::loadData(myData, DATAPATH);
	Save::loadData(recUser, USERPATH);
	Save::loadData(recDepartemen, DEPARTEMENPATH);
	Save::loadData(recMatkul, MATKULPATH);

	if (recUser.size() == 0)
	{
		recUser.push_back(User("admin", "Admin", User::Role::Admin, "ADMIN"));
		Save::saveData(&recUser, USERPATH);
	}

	// printf("%p\n", &recMatkul[0]);
	// printf("%p\n", &recMatkul[1]);

	// cin.ignore();

	// recMatkul.push_back(Matkul("Fisika 1", "SF100501", 3, "m_0", "d_0"));
	// recMatkul.push_back(Matkul("Fisika 2", "SF100502", 3, "m_1", "d_0"));

	// Save::saveData(&recMatkul, MATKULPATH);
	// Save::loadData(recMatkul, MATKULPATH);

	// for (Matkul &matkul : recMatkul)
	// {
	// 	cout << "Name: " << matkul.getName() << endl;
	// 	cout << "Kode: " << matkul.getKode() << endl;
	// 	cout << "SKS : " << matkul.getSKS() << endl;
	// 	cout << "ID  : " << matkul.getId() << endl;
	// 	cout << "DID : " << matkul.getDepartemenId() << endl;
	// 	for (string &dosenId : *matkul.getAllDosenId())
	// 	{
	// 		cout << dosenId << "|";
	// 	}
	// 	cout << endl;
	// 	for (string &kelasId : *matkul.getAllKelasId())
	// 	{
	// 		cout << kelasId << "|";
	// 	}
	// 	cout << endl;
	// 	cout << endl;
	// }

	// exit(0);

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