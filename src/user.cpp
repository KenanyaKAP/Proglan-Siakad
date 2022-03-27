#include <iostream>
#include <cstring>

#include "include/user.hpp"

using namespace std;

User::User()
{

}
User::User(const char username[], const char password[], const char personId[], User::Role role)
{
    strcpy(this->username, username);
    this->username[sizeof(this->username) - 1] = '\0';
    strcpy(this->password, password);
    this->password[sizeof(this->password) - 1] = '\0';
    strcpy(this->personId, personId);
    this->personId[sizeof(this->personId) - 1] = '\0';
    this->role = role;
}
User::User(char username[], char password[], char personId[], User::Role role)
{
    username[sizeof(this->username) - 1] = '\0';
    strcpy(this->username, username);
    password[sizeof(this->password) - 1] = '\0';
    strcpy(this->password, password);
    personId[sizeof(this->personId) - 1] = '\0';
    strcpy(this->personId, personId);
    this->role = role;
}

char* User::getUsername(){ return this->username; }

char* User::getPassword(){ return this->password; }

char* User::getPersonId(){ return this->personId; }

User::Role User::getRole(){ return this->role; }

void User::changePassword(char newPassword[])
{
    newPassword[sizeof(this->password) - 1] = '\0';
    strcpy(this->password, newPassword);
}