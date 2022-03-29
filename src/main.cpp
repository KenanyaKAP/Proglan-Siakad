#include <iostream>
#include <cstring>
#include <cstdlib>

#include "include/utils.hpp"
#include "include/data.hpp"
#include "include/user.hpp"

using namespace std;

void AdminPage();
void ShowDepartemen();

int main()
{
	Data data;

	cin.ignore();

	// data.addUser("admin", "Admin", "adminId", User::Role::Admin);

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
		cout << "-> Password: ";
		cin >> passwordInput;
		cin.ignore();
		switch (data.loginUser((char*)usernameInput.c_str(), (char*)passwordInput.c_str()))
		{
		case 0: // Admin
			AdminPage();
			break;
		case 1: // Dosen
			cout << "You are Dosen!" << endl;
			break;
		case 2: // Tendik
			cout << "You are Tendik!" << endl;
			break;
		case 3: // Mahasiswa
			cout << "You are Mahasiswa!" << endl;
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

void AdminPage()
{
	while(1)
	{
		clearScreen();
		int menu;
		cout << "Welcome, Admin!" << endl << endl;
		cout << "  1. Jumlah Departemen            : " << "BLOM" << " Departemen" << endl;
		cout << "  2. Jumlah Dosen                 : " << "BLOM" << " Dosen" << endl;
		cout << "  3. Jumlah Tenaga Kependidikan   : " << "BLOM" << " Tendik" << endl;
		cout << "  4. Jumlah Mahasiswa             : " << "BLOM" << " Mahasiswa" << endl;
		cout << endl;
		cout << "Menu: " << endl;
		cout << "  1. Tampilkan semua Departemen" << endl;
		cout << "  2. Tampilkan semua Dosen" << endl;
		cout << "  3. Tampilkan semua Tenaga Kependidikan" << endl;
		cout << "  4. Tampilkan semua Mahasiswa" << endl;
		cout << "  5. Tambah Departemen" << endl;
		cout << "  6. Tambah Dosen" << endl;
		cout << "  7. Tambah Tenaga Kependidikan" << endl;
		cout << "  8. Tambah Mahasiswa" << endl;
		cout << "  0. Log out" << endl;
		cout << "-> Pilihan: ";
		cin >> menu;
		switch (menu)
		{
		case 0:
			return;
		case 1:
			ShowDepartemen();
			break;
		default:
			break;
		}
	}
}

void ShowDepartemen()
{
	
}