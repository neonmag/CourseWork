#include "User.h"

User::User(string type)
{
	this->type = type;
}

string User::GetLogin()
{
	return this->login;
}

string User::GetPassword()
{
	return this->password;
}

void User::SetLogin(string login)
{
	this->login = login;
}

void User::SetPassword(string password)
{
	this->password = password;
}
