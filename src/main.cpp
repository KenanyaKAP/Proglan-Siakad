#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <tuple>

#include "include/utils.hpp"
#include "include/data.hpp"
#include "include/user.hpp"
#include "include/VariadicTable.hpp"

using namespace std;
// using namespace Utils;

void adminPage(string username);
void menuUser();
void addUser();
void removeUser();

Data recData;

int main()
{
	// data.addUser("admin", "Admin", "adminId", User::Role::Admin);

	// recData.addUser("admin", "Admin", "adminId", User::Role::Admin);
	// recData.addUser("admin1", "Admin1", "adminId", User::Role::Admin);
	// recData.addUser("admin2", "Admin2", "adminId", User::Role::Admin);
	// recData.addUser("admin3", "Admin3", "adminId", User::Role::Admin);
	// recData.addUser("admin4", "Admin4", "adminId", User::Role::Admin);
	// recData.addUser("admin5", "Admin5", "adminId", User::Role::Admin);
	// recData.addUser("admin6", "Admin6", "adminId", User::Role::Admin);
	// recData.addUser("admin7", "Admin7", "adminId", User::Role::Admin);
	// recData.addUser("admin8", "Admin8", "adminId", User::Role::Admin);
	// recData.addUser("admin9", "Admin9", "adminId", User::Role::Admin);
	// recData.addUser("admin10", "Admin10", "adminId", User::Role::Admin);
	// recData.addUser("admin11", "Admin11", "adminId", User::Role::Admin);
	// recData.addUser("admin12", "Admin12", "adminId", User::Role::Admin);
	// adminPage();

	// printTable<string, int>(,)
	// VariadicTable<int, string, string> vt({"No", "Username", "Role"});
	// vector<tuple<int, string, string>> Ah;
	// tuple<int, string, string> yes = make_tuple(1, "admin", "Admin");
	// Ah.push_back(yes);
	// vt.addRow(Ah[0]);
	// vt.print(cout);

	// exit(0);

	string usernameInput;
	string passwordInput;

	while (1)
	{
		clearScreen();
		cout << " ____  _       _             _ " << endl;
		cout << "/ ___|(_) __ _| | ____ _  __| |" << endl;
		cout << "\\___ \\| |/ _` | |/ / _` |/ _` |" << endl;
		cout << " ___) | | (_| |   < (_| | (_| |" << endl;
		cout << "|____/|_|\\__,_|_|\\_\\__,_|\\__,_|" << endl << endl;
		cout << "by Kenanya" << endl << endl << endl;
		cout << "-> Username: ";
		cin >> usernameInput;
		// getline(cin, usernameInput);
		cout << "-> Password: ";
		cin >> passwordInput;
		// getline(cin, passwordInput);
		cin.ignore();
		switch (recData.loginUser(usernameInput, passwordInput))
		{
		case 0: // Admin
			adminPage(usernameInput);
			break;
		case 1: // Dosen
			cout << "You are Dosen!" << endl;
			cin.ignore();
			break;
		case 2: // Tendik
			cout << "You are Tendik!" << endl;
			cin.ignore();
			break;
		case 3: // Mahasiswa
			cout << "You are Mahasiswa!" << endl;
			cin.ignore();
			break;
		default: // Error
			cout << "\nUsername/ID or password is incorrect!" << endl;
			cin.ignore();
			break;
		}
	}

	cout << "Done";
	return 0;
}

void adminPage(string username)
{
	while(1)
	{
		clearScreen();
		int menu;
		cout << "Welcome, " << username << "!" << endl << endl;
		cout << "  1. Jumlah User                  : " << recData.getUserSize() << " User" << endl;
		cout << "  2. Jumlah Departemen            : " << "BLOM" << " Departemen" << endl;
		cout << "  3. Jumlah Dosen                 : " << "BLOM" << " Dosen" << endl;
		cout << "  4. Jumlah Tenaga Kependidikan   : " << "BLOM" << " Tendik" << endl;
		cout << "  5. Jumlah Mahasiswa             : " << "BLOM" << " Mahasiswa" << endl;
		cout << endl;
		cout << "Menu: " << endl;
		cout << "  1. Tampilkan User" << endl;
		cout << "  2. Tampilkan Departemen" << endl;
		cout << "  3. Tampilkan Dosen" << endl;
		cout << "  4. Tampilkan Tenaga Kependidikan" << endl;
		cout << "  5. Tampilkan Mahasiswa" << endl;
		cout << "  0. Log out" << endl;
		cout << "-> Pilihan: ";
		cin >> menu;
		cin.ignore();

		switch (menu)
		{
		case 0:
			return;
		case 1:
			menuUser();
			break;
		default:
			break;
		}
	}
}

void menuUser()
{
	int page = 1;
	while (1)
	{
		char menu;
		clearScreen();
		printTable(User::makeTuples(recData.getAllUser()), User::tuplesHeader(), page);
		cout << "Menu: " << endl;
		cout << "  1. Tambah User(Admin)" << endl;
		cout << "  2. Hapus User" << endl;
		cout << "  3. Ganti Password" << endl;
		cout << "  >. Tampilkan Selanjutnya" << endl;
		cout << "  <. Tampilkan Sebelumnya" << endl;
		cout << "  0. Kembali" << endl;
		cout << "-> Pilihan: ";
		cin >> menu;
		switch (menu)
		{
		case '0':
			return;
		case '1':
			addUser();
			break;
		case '2':
			removeUser();
			break;
		case '>':
			page++;
			break;
		case '<':
			page--;
			break;
		default:
			break;
		}
	}
}

void addUser()
{
	string username, password;
	clearScreen();
	cout << "-> Username: ";
	cin >> username;
	cout << "-> Password: ";
	cin >> password;
	recData.addUser(username, password, "adminId", User::Role::Admin);
	cout << endl << "Berhasil menambahkan admin!" << endl;
	cin.ignore();
	cin.ignore();
}

void removeUser()
{
	int page = 1;
	while (1)
	{
		char menu;
		clearScreen();
		printTable(User::makeTuples(recData.getAllUser()), User::tuplesHeader(), page);
		cout << "Menu: " << endl;
		cout << " 1~10. Pilih user yang akan dihapus" << endl;
		cout << "    >. Tampilkan Selanjutnya" << endl;
		cout << "    <. Tampilkan Sebelumnya" << endl;
		cout << "    0. Kembali" << endl;
		cout << "-> Pilihan: ";
		cin >> menu;
		switch (menu)
		{
		case '0':
			return;
		case '1':
			// addUser();
			break;
		case '2':
			// removeUser();
			break;
		case '>':
			page++;
			break;
		case '<':
			page--;
			break;
		default:
			break;
		}
	}
}