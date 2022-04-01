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
User *User::getUser(vector<User> *users, string username)
{
    for (User &user : *users)
        if (user.getUsername() == username)
            return &user;
    return nullptr;
}

vector<tuple<string, string>> User::makeTuples(vector<User> *users)
{
    vector<tuple<string, string>> tuples;
    for (unsigned int i = 0; i < users->size(); i++)
    {
        tuple<string, string> user;
        user = make_tuple(users->at(i).getUsername(), users->at(i).getRoleString());
        tuples.push_back(user);
    }
    return tuples;
}

vector<string> User::tuplesHeader(){ return {"Username", "Role"}; }
// ==================================================================