#include <iostream>
#include <cstring>
#include <stdlib.h>

#include "include/data.hpp"
#include "include/user.hpp"

using namespace std;

int main()
{
	Data data;

	// data.addUser("admin", "Admin", "adminId", User::Role::Admin);

	string usernameInput;
	string passwordInput;

	while (1)
	{
		system("cls");
		cout << " ____  _       _             _ " << endl;
		cout << "/ ___|(_) __ _| | ____ _  __| |" << endl;
		cout << "\\___ \\| |/ _` | |/ / _` |/ _` |" << endl;
		cout << " ___) | | (_| |   < (_| | (_| |" << endl;
		cout << "|____/|_|\\__,_|_|\\_\\__,_|\\__,_|" << endl << endl;
		cout << "by Kenanya" << endl << endl << endl;
		cout << "Username/ID : ";
		cin >> usernameInput;
		cout << "Password    : ";
		cin >> passwordInput;

		// Check is username exist
		if (auto user = data.getUser((char*)usernameInput.c_str()))
		{
			cout << "Username good" << endl;
			if (strcmp(user->getPassword(), "Admin "))
			{
				cout << "Success Login!" << endl;
			}
			cout << user->getPassword();
		}
		else
		{
			cout << "Account not found!" << endl;
		}
		cin.ignore();
		cin.ignore();
		cin.ignore();
		cin.ignore();
	}

	cout << "Done";
	return 0;
}
