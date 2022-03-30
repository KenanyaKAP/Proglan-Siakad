#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>

#include "include/utils.hpp"
#include "include/data.hpp"
#include "include/user.hpp"

using namespace std;

void AdminPage();
void ShowDepartemen();

Data recData;

int main()
{
	// data.addUser("admin", "Admin", "adminId", User::Role::Admin);

	// AdminPage();

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
		switch (recData.loginUser((char*)usernameInput.c_str(), (char*)passwordInput.c_str()))
		{
		case 0: // Admin
			AdminPage();
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

void AdminPage()
{
	while(1)
	{
		clearScreen();
		int menu;
		cout << "Welcome, Admin!" << endl << endl;
		cout << "  1. Jumlah User                  : " << recData.getUserSize() << " User" << endl;
		cout << "  2. Jumlah Departemen            : " << "BLOM" << " Departemen" << endl;
		cout << "  3. Jumlah Dosen                 : " << "BLOM" << " Dosen" << endl;
		cout << "  4. Jumlah Tenaga Kependidikan   : " << "BLOM" << " Tendik" << endl;
		cout << "  5. Jumlah Mahasiswa             : " << "BLOM" << " Mahasiswa" << endl;
		cout << endl;
		cout << "Menu: " << endl;
		cout << "  1. User" << endl;
		cout << "  2. Departemen" << endl;
		cout << "  9. Load Data" << endl;
		cout << "  0. Log out" << endl;
		cout << "-> Pilihan: ";
		cin >> menu;
		cin.ignore();

		vector<vector<string>> userVector = User::MakeVector(recData.getAllUser());
		switch (menu)
		{
		case 0:
			return;
		case 1:
			cin >> menu;
			cout << "No\t" << "Username\t" << "Role" << endl;
			printVector(userVector, 1);
			cin.ignore();
			cin.ignore();
			break;
		default:
			break;
		}
	}
}