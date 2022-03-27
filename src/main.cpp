#include <iostream>
#include <stdlib.h>

#include "include/data.hpp"
#include "include/user.hpp"

using namespace std;

int main()
{
	string temp;

	Data data;

	string usernameInput;
	string passwordInput;

	// while (1)
	// {
	// 	system("cls");
	// 	// cout << "░██████╗██╗░█████╗░██╗░░██╗░█████╗░██████╗░" << endl;
	// 	// cout << "██╔════╝██║██╔══██╗██║░██╔╝██╔══██╗██╔══██╗" << endl;
	// 	// cout << "╚█████╗░██║███████║█████═╝░███████║██║░░██║" << endl;
	// 	// cout << "░╚═══██╗██║██╔══██║██╔═██╗░██╔══██║██║░░██║" << endl;
	// 	// cout << "██████╔╝██║██║░░██║██║░╚██╗██║░░██║██████╔╝" << endl;
	// 	// cout << "╚═════╝░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝╚═════╝░" << endl;
	// 	cout << "by Kenanya Keandra Adriel Prasetyo" << endl << endl << endl;
	// 	cout << "Username/ID : ";
	// 	cin >> usernameInput;
	// 	cout << "Password    : ";
	// 	cin >> passwordInput;

	// 	// Check is username exist
	// 	// if (auto user = data.getUserByUsername(usernameInput))
	// 	// {
	// 	// 	cout << "Username good" << endl;
	// 	// 	if (user->getPassword() == passwordInput)
	// 	// 	{
	// 	// 		cout << "Success Login!" << endl;
	// 	// 	}
	// 	// }
	// 	// else
	// 	// {
	// 	// 	cout << "Account not found!" << endl;
	// 	// }
	// 	cin.ignore();
	// }
	// char s1[] = "admin1";
	// char s2[] = "Admin1";
	// char s3[] = "adminId";
	// data.addUser(s1, s2, s3, User::Role::Admin);

	// data.addUser("admin", "Admin", "adminId", User::Role::Admin);
	// data.addUser("admin2", "Admin2", "adminId", User::Role::Admin);
	// data.addUser("admin3", "Admin3", "adminId", User::Role::Admin);
	// data.addUser("admin4", "Admin4", "adminId", User::Role::Admin);
	// data.addUser("admin5", "Admin5", "adminId", User::Role::Admin);

	// data.removeUser((char*)"admin1");

	vector<User>* users = data.getAllUser();

	for (User& toto : *users)
	{
		cout << toto.getUsername() << " | ";
		cout << toto.getPassword() << " | ";
		cout << toto.getPersonId() << " | ";
		cout << toto.getRole() << endl;
	}

	cout << "Done";
	return 0;
}
