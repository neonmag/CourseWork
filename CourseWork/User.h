#pragma once
#include <iostream>

using namespace std;

class User // Базовый класс для потомков админ и студент
{
protected:
	string type;
	string login;
	string password;
public:
	User() = delete;
	User(string type);
	string GetLogin();
	string GetPassword();
	void SetLogin(string login);
	void SetPassword(string password);
};

