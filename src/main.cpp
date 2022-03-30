#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <tuple>
#include <sstream>

#include "include/data.hpp"
#include "include/utils.hpp"
#include "include/user.hpp"
#include "include/VariadicTable.hpp"

using namespace std;

void adminPage(string username);
void menuUser(string username);
void addUser();
void removeUser();
void changePass(string username);

Data recData;

int main()
{
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
		cout << "-> Password: ";
		cin >> passwordInput;
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
			menuUser(username);
			break;
		case 9:
			changePass(username);
			break;
		default:
			break;
		}
	}
}

void menuUser(string username)
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
		cout << "  >. Tampilkan Selanjutnya" << endl;
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
	cin.ignore();

	recData.addUser(username, password, "adminId", User::Role::Admin);
	cout << endl << "Berhasil menambahkan admin!" << endl;
	cin.ignore();
}

void removeUser()
{
	int page = 1;
	while (1)
	{
		string menu;
		clearScreen();
		printTable(User::makeTuples(recData.getAllUser()), User::tuplesHeader(), page);
		cout << "Menu: " << endl;
		cout << " 1~10. Pilih user yang akan dihapus" << endl;
		cout << "    >. Tampilkan Selanjutnya" << endl;
		cout << "    <. Tampilkan Sebelumnya" << endl;
		cout << "    0. Kembali" << endl;
		cout << "-> Pilihan: ";
		cin >> menu;
		cin.ignore();

		if (menu == "0"){
			return;
		} else if (menu == ">"){
			page++;
		} else if (menu == "<"){
			page--;
		}
		else {
			int select;
			stringstream temp(menu);
			temp >> select;
			if (select > 10 * (page - 1) && select <= recData.getUserSize())
			{
				cout << endl << "Anda yakin ingin menghapus " << recData.getUser(select - 1)->getUsername() << endl;
				cout << "-> [y/n]: ";
				cin >> menu;
				if (menu == "y" || menu == "Y")
				{
					recData.removeUser(select - 1);
					cout << endl << "User telah dihapus!" << endl;
					cin.ignore();
				}
				return;
			}
		}
	}
}

void changePass(string username)
{
	clearScreen();
	string oldPass, newPass, reNewPass;
	cout << "Password lama:\n-> ";
	cin >> oldPass;
	cout << "Password baru:\n-> ";
	cin >> newPass;
	cout << "Ketik ulang password baru:\n-> ";
	cin >> reNewPass;
	cin.ignore();

	User *user = recData.getUser(username);
	if (user->getPassword() == oldPass)
	{
		if (newPass == reNewPass)
		{
			user->changePassword(newPass);
			recData.updateUser(username);
			cout << endl << "Password berhasil diubah!" << endl;
			cin.ignore();
			return;
		}
	}
	cout << endl << "Password tidak sama!" << endl;
	cin.ignore();
}