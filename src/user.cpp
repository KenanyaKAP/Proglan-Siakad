#include <iostream>
#include <vector>
#include <tuple>

#include "include/user.hpp"

using namespace std;

// ========================== Constructor ===========================
User::User(string username, string password, User::Role role, string personId)
:username(username), password(password), role(role), personId(personId){}
// ==================================================================



// ======================== Private Function ========================
// ==================================================================



// ======================== Public Function =========================
string User::getUsername(){ return this->username; }

string User::getPassword(){ return this->password; }

User::Role User::getRole(){ return this->role; }

string User::getRoleString()
{
    switch (role)
    {
    case User::Role::Admin:
        return "Admin";
    case User::Role::Dosen:
        return "Dosen";
    case User::Role::Tendik:
        return "Tendik";
    case User::Role::Mahasiswa:
        return "Mahasiswa";
    }
    return '\0';
}

string User::getPersonId(){ return this->personId; }

void User::changePassword(string newPassword){ this->password = newPassword; }
// ==================================================================



// ===================== Static Public Function =====================
User *User::getUser(vector<User> *list, string username)
{
    for (User &user : *list)
        if (user.getUsername() == username)
            return &user;
    return nullptr;
}

int User::getPosition(std::vector<User> *list, User *target)
{
    for (unsigned int i = 0; i < list->size(); i++)
        if (list->at(i).getPersonId() == target->getPersonId())
            return i;
    cout << "Cannot find position of " << target->getUsername() << endl;
    exit(0);
}
// ==================================================================