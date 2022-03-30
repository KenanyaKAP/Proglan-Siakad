#include <iostream>
#include <cstring>
#include <vector>

#include "include/user.hpp"
#include "include/VariadicTable.hpp"

using namespace std;

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

// S_User::S_User(const char *username, const char *password, const char *personId, User::Role role)
// {
//     strcpy(this->username, (char*)username);
//     strcpy(this->password, (char*)password);
//     strcpy(this->personId, (char*)personId);
//     this->role = role;
// }

User::User()
{

}
// User::User(const string username, const string password, const string personId, User::Role role)
// {
//     strcpy(this->username, username);
//     this->username[sizeof(this->username) - 1] = '\0';
//     strcpy(this->password, password);
//     this->password[sizeof(this->password) - 1] = '\0';
//     strcpy(this->personId, personId);
//     this->personId[sizeof(this->personId) - 1] = '\0';
//     this->role = role;
// }

User::User(S_User sUser)
{
    this->username = sUser.username;
    this->password = sUser.password;
    this->personId = sUser.personId;
    this->role = sUser.role;
}

User::User(string username, string password, string personId, User::Role role)
    :username(username), password(password), personId(personId), role(role)
{
    // strcpy(this->username, username);
    // this->username[sizeof(this->username) - 1] = '\0';
    // strcpy(this->password, password);
    // this->password[sizeof(this->password) - 1] = '\0';
    // strcpy(this->personId, personId);
    // this->personId[sizeof(this->personId) - 1] = '\0';
    // this->role = role;
}

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

// vector<vector<string>> User::MakeVector(vector<User> *users)
// {
//     vector<vector<string>> vectors;
//     vectors.push_back({"Username", "Role"});
//     for (User &user : *users)
//     {
//         vector<string> row;
//         row.push_back(user.getUsername());
//         row.push_back(getRoleString(user.getRole()));
//         vectors.push_back(row);
//     }
//     return vectors;
// }

// VariadicTable<int, string, string> User::MakeTable(vector<User> *users)
// {
//     VariadicTable<int, string, string> vt({"No", "Username", "Role"});
//     for (int i = 0; i < users->size(); i++)
//     {
//         vt.addRow(i+1, users->at(i).getUsername(), User::GetRoleString(users->at(i).getRole()));
//     }

//     return vt;
// }

vector<tuple<int, string, string>> User::makeTuples(vector<User> *users)
{
    vector<tuple<int, string, string>> tuples;
    for (unsigned int i = 0; i < users->size(); i++)
    {
        tuple<int, string, string> user;
        user = make_tuple(i+1, users->at(i).getUsername(), User::getRoleString(users->at(i).getRole()));
        tuples.push_back(user);
    }
    return tuples;
}

vector<string> User::tuplesHeader(){ return {"No", "Username", "Role"}; }

string User::getUsername(){ return this->username; }

string User::getPassword(){ return this->password; }

string User::getPersonId(){ return this->personId; }

User::Role User::getRole(){ return this->role; }

void User::changePassword(string newPassword)
{
    this->password = newPassword;
}