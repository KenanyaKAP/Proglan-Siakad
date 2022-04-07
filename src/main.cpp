#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <sstream>

#include "include/save.hpp"
#include "include/utils.hpp"
#include "include/data.hpp"
#include "include/VariadicTable.hpp"

#include "include/person.hpp"
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

void adminPage(User *user);
void dosenPage(Dosen *dosen);

void showUserPage(vector<User> *users);
void showDepartemenPage(vector<Departemen> *departemens);
void showMatkulPage(Departemen *departemen);
void showDosenPage(vector<Dosen> *dosens);
void showTendikPage(vector<Tendik> *tendiks);
void showMahasiswaPage(vector<Mahasiswa> *mahasiswas);

void addDosen();
void addTendik();
void addMahasiswa();

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
		case '4':
			showTendikPage(&recTendik);
			break;
		case '5':
			showMahasiswaPage(&recMahasiswa);
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

void dosenPage(Dosen *dosen)
{
	char menu;
	while (1)
	{
		Utils::clearScreen();
		cout << "Welcome Dosen: " << dosen->getName() << "!" << endl;
		cout << endl << "COMING SOON!" << endl << endl;
		cout << "Menu: " << endl;
		cout << "  0. Kembali" << endl;
		cout << "-> Pilihan: ";
		cin >> menu;
		cin.ignore();

		switch (menu)
		{
		case '0':
			return;
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
		cout << " " << index + 1 << "/" << users->size() << "\t";
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
			cout << "  2. Tampilkan Semua Dosen" << endl;
			cout << "  3. Tampilkan Semua Mahasiswa" << endl;
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
				showDosenPage(&recDosen);
				break;
			case '3':
				showMahasiswaPage(&recMahasiswa);
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
			cout << "  1. Tambah Mata Kuliah" << endl;
			cout << "  2. Hapus Mata Kuliah ini" << endl;
			if (index + 1 < int(matkuls.size()))
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
			case '2':
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
	int index = 0;
	char menu;

	while (1)
	{
		if (dosens->size() == 0)
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
				addDosen();
				break;
			default:
				break;
			}
		}
		else
		{
			Dosen &dosen = dosens->at(index);
			Utils::clearScreen();
			cout << ": Data Dosen" << endl << endl;
			cout << "-----------------------------------------------" << endl;
			cout << " " << index + 1 << "/" << dosens->size() << "\t" << dosen.getName() << endl;
			cout << "-----------------------------------------------" << endl;
			cout << "NPP                 : " << dosen.getNPP() << endl;
			cout << "Tanggal Lahir       : " << dosen.getTglLahir() << " " << Utils::intToStringMonth(dosen.getBulanLahir()) << " " << dosen.getTahunLahir() << endl;
			cout << "Pendidikan          : " << "S" << dosen.getPendidikan() << endl;
			cout << "Departemen          : " << Departemen::getDepartemenById(&recDepartemen, dosen.getDepartemenId())->getName() << endl;
			cout << "-----------------------------------------------" << endl;
			cout << endl;
			cout << "Menu:" << endl;
			cout << "  1. Tambah Dosen" << endl;
			cout << "  2. Hapus Dosen ini" << endl;
			if (index + 1 < int(dosens->size()))
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
				addDosen();
				break;
			case '2':
				{
					cout << endl << "Anda yakin ingin menghapus " << dosen.getName() << "?" << endl;
					cout << "-> [y/n]: ";
					cin >> menu;
					cin.ignore();
					if (menu == 'y' || menu == 'Y')
					{
						recUser.erase(recUser.begin() + User::getPosition(&recUser, dosen.getUser(&recUser)));
						Departemen::getDepartemenById(&recDepartemen, dosen.getDepartemenId())->delDosen(dosen.getId());
						recDosen.erase(recDosen.begin() + Dosen::getPosition(&recDosen, &dosen));

						Save::saveData(&recUser, USERPATH);
						Save::saveData(&recDepartemen, DEPARTEMENPATH);
						Save::saveData(&recDosen, DOSENPATH);

						cout << endl << "Dosen telah dihapus!" << endl;
						cin.ignore();
					}
				}
				break;
			case '>':
				if (index + 1 < int(dosens->size())) index++;
				break;
			case '<':
				if (index > 0) index--;
				break;
			default:
				break;
			}
		}

		if ((unsigned int)index >= dosens->size()) index = dosens->size() - 1;
	}
}

// ==================================================================

void showTendikPage(vector<Tendik> *tendiks)
{
	int index = 0;
	char menu;

	while (1)
	{
		if (tendiks->size() == 0)
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
			Tendik &tendik = tendiks->at(index);
			Utils::clearScreen();
			cout << ": Data Tendik" << endl << endl;
			cout << "-----------------------------------------------" << endl;
			cout << " " << index + 1 << "/" << tendiks->size() << "\t" << tendik.getName() << endl;
			cout << "-----------------------------------------------" << endl;
			cout << "NPP                 : " << tendik.getNPP() << endl;
			cout << "Tanggal Lahir       : " << tendik.getTglLahir() << " " << Utils::intToStringMonth(tendik.getBulanLahir()) << " " << tendik.getTahunLahir() << endl;
			cout << "Unit                : " << tendik.getUnit() << endl;
			cout << "-----------------------------------------------" << endl;
			cout << endl;
			cout << "Menu:" << endl;
			cout << "  1. Tambah Tendik" << endl;
			cout << "  2. Hapus Tendik ini" << endl;
			if (index + 1 < int(tendiks->size()))
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
						recUser.erase(recUser.begin() + User::getPosition(&recUser, tendik.getUser(&recUser)));
						recTendik.erase(recTendik.begin() + Tendik::getPosition(&recTendik, &tendik));

						Save::saveData(&recUser, USERPATH);
						Save::saveData(&recTendik, TENDIKPATH);

						cout << endl << "Tendik telah dihapus!" << endl;
						cin.ignore();
					}
				}
				break;
			case '>':
				if (index + 1 < int(tendiks->size())) index++;
				break;
			case '<':
				if (index > 0) index--;
				break;
			default:
				break;
			}
		}
		
		if ((unsigned int)index >= tendiks->size()) index = tendiks->size() - 1;
	}
}

// ==================================================================

void showMahasiswaPage(vector<Mahasiswa> *mahasiswas)
{
	int index = 0;
	char menu;

	while (1)
	{
		if (mahasiswas->size() == 0)
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
				addMahasiswa();
				break;
			default:
				break;
			}
		}
		else
		{
			Mahasiswa &mahasiswa = mahasiswas->at(index);
			Utils::clearScreen();
			cout << ": Data Mahasiswa" << endl << endl;
			cout << "-----------------------------------------------" << endl;
			cout << " " << index + 1 << "/" << mahasiswas->size() << "\t" << mahasiswa.getName() << endl;
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
			cout << "  1. Tambah Mahasiswa" << endl;
			cout << "  2. Hapus Mahasiswa ini" << endl;
			if (index + 1 < int(mahasiswas->size()))
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
				addMahasiswa();
				break;
			case '2':
				{
					cout << endl << "Anda yakin ingin menghapus " << mahasiswa.getName() << "?" << endl;
					cout << "-> [y/n]: ";
					cin >> menu;
					cin.ignore();
					if (menu == 'y' || menu == 'Y')
					{
						recUser.erase(recUser.begin() + User::getPosition(&recUser, mahasiswa.getUser(&recUser)));
						Departemen::getDepartemenById(&recDepartemen, mahasiswa.getDepartemenId())->delMahasiswa(mahasiswa.getId());
						recMahasiswa.erase(recMahasiswa.begin() + Mahasiswa::getPosition(&recMahasiswa, &mahasiswa));

						Save::saveData(&recUser, USERPATH);
						Save::saveData(&recDepartemen, DEPARTEMENPATH);
						Save::saveData(&recMahasiswa, MAHASISWAPATH);

						cout << endl << "Dosen telah dihapus!" << endl;
						cin.ignore();
					}
				}
				break;
			case '>':
				if (index + 1 < int(mahasiswas->size())) index++;
				break;
			case '<':
				if (index > 0) index--;
				break;
			default:
				break;
			}
		}
		
		if ((unsigned int)index >= mahasiswas->size()) index = mahasiswas->size() - 1;
	}
}

// ==================================================================

void addDosen()
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
	sprintf(strTemp, "%03d", myData.tahunCount(to_string(tahunMasuk)));
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
	sprintf(strTemp, "%03d", myData.tahunCount(to_string(tahunMasuk)));
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

void addMahasiswa()
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

	if (Departemen::getDepartemenById(&recDepartemen, departemenMhsId)->getAllDosenId()->size() == 0)
	{
		Utils::clearScreen();
		cout << "Data Dosen Wali Tidak Ditemukan!" << endl;
		cout << "Silahkan membuat Dosen di Departemen ini terlebih dahulu!" << endl;
		cin.ignore();
		return;
	}

	page = 1;
	vector<Dosen> dosenDepartemen = Dosen::getAllDosenByDepartemenId(&recDosen, departemenMhsId);
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
				doswalId = dosenDepartemen.at(select - 1).getId();
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
	Save::saveData(&recMahasiswa, MAHASISWAPATH);
	Save::saveData(&recDepartemen, DEPARTEMENPATH);
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
		recUser.push_back(User("admin", "Admin", User::Role::Admin, "ADMIN"));
		Save::saveData(&recUser, USERPATH);
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
		cout << "Default:" << endl;
		cout << "Username: admin" << endl;
		cout << "Password: Admin" << endl;
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
					dosenPage(Dosen::getDosenById(&recDosen, user->getPersonId()));
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