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

	// char s1[] = "5024211004";
	// char s2[] = "myITSKen73";
	// char s3[] = "p_1";
	// data.addUser(s1, s2, s3, User::Role::Mahasiswa);

	// data.removeUser((char*)"toto");

	vector<User>* users = data.getAllUser();

	for (User& toto : *users)
	{
		cout << toto.getUsername() << " | ";
		cout << toto.getPassword() << " | ";
		cout << toto.getPersonId() << " | ";
		cout << toto.getRole() << endl;
	}

	return 0;
}
