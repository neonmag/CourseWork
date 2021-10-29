#include <iostream>
#include "User.h"
#include "Keys.h"

using namespace std;

class Admin : public User // Класс наследник от юзера
{
private:
	static int counter;
public:
	Admin() = delete; // Запрет на создание пустого класса
	Admin(string type);
	void Input();
	void Output();
	void AdminMenu();
	~Admin();
};
