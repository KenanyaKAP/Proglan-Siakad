#include <iostream>
#include <cstring>
#include <vector>

#include "include/user.hpp"
#include "include/VariadicTable.hpp"

using namespace std;

// ======================= Constructor ==============================
User::User()
{

}

User::User(string username, string password, string personId, User::Role role)
    :username(username), password(password), personId(personId), role(role){}

User::User(S_User sUser)
{
    this->username = sUser.username;
    this->password = sUser.password;
    this->personId = sUser.personId;
    this->role = sUser.role;
}
// ==================================================================



// ======================== Private Function ========================
string User::getRoleString(User::Role role)
{
    switch (role)
    {
    case 0:
        return "Admin";
        break;
    case 1:
        return "Dosen";
        break;
    case 2:
        return "Tendik";
        break;
    case 3:
        return "Mahasiswa";
        break;
    default:
        return "None";
        break;
    }
}
// ==================================================================



// ======================== Public Function =========================
vector<tuple<string, string>> User::makeTuples(vector<User> *users)
{
    vector<tuple<string, string>> tuples;
    for (unsigned int i = 0; i < users->size(); i++)
    {
        tuple<string, string> user;
        user = make_tuple(users->at(i).getUsername(), User::getRoleString(users->at(i).getRole()));
        tuples.push_back(user);
    }
    return tuples;
}

vector<string> User::tuplesHeader(){ return {"Username", "Role"}; }

string User::getUsername(){ return this->username; }

string User::getPassword(){ return this->password; }

string User::getPersonId(){ return this->personId; }

User::Role User::getRole(){ return this->role; }

void User::changePassword(string newPassword){ this->password = newPassword; }
// ==================================================================



// ======================= Class for Save User ======================
S_User::S_User(){}

S_User::S_User(User user)
{
    strcpy(this->username, user.getUsername().c_str());
    this->username[sizeof(username)/sizeof(char) - 1] = '\0';
    strcpy(this->password, user.getPassword().c_str());
    this->password[sizeof(password)/sizeof(char) - 1] = '\0';
    strcpy(this->personId, user.getPersonId().c_str());
    this->personId[sizeof(personId)/sizeof(char) - 1] = '\0';
    this->role = user.getRole();
}
// ==================================================================