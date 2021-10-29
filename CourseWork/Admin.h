#include <iostream>
#include "User.h"
#include "Keys.h"

using namespace std;

class Admin : public User // ����� ��������� �� �����
{
private:
	static int counter;
public:
	Admin() = delete; // ������ �� �������� ������� ������
	Admin(string type);
	void Input();
	void Output();
	void AdminMenu();
	~Admin();
};
