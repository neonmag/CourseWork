#include <iostream>																//
#include "User.h"																//
																				//
using namespace std;															//
																				//
class Student : public User														// ������� - ����� ��������� �� �����
{																				//
private:																		//
	int countOfFinishedTests;													// ��������� ���� ��� ���������� ���������� ������ ����������� ��������
public:																			//
	Student() = delete;															// ��������� ��������� ������ ������� ������
	Student(string type);														// 
	void Input();																// ����� ����� ��������
	void Output();																// ����� ������
	void LogReg(string &choose);												// ����� ����� ������� � �����������
	void StudentMenu();															// ���� ��������,�������� �� ������������
	void StudentMenu(string fileName);											// ����� ��������,� �������� �� ������
	void SetCountOfFinishedTests(int countOfFinishedTests);						// ����� ��� ��� ���-�� ���������� ������
	void PassTheTest();															// ����������� �����
	int GetCountOfFinishedTests();												// ����� ��� ��� ��� - �� ���������� ������
	~Student();																	// ����������
};																				//