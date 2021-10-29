#include <iostream>																							//
#include <fstream>																							//
#include "Admin.h"																							// ����������� ��������� �
#include "Student.h"																						// ����� �������
#include "Menu.h"																							//
#include <string>																							//
																											//
using namespace std;																						//
																											//
int main()																									//
{																											//
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);                                                        // ���������� ����
	CONSOLE_CURSOR_INFO structCursorInfo;																	// ����� ������� �������
	GetConsoleCursorInfo(handle, &structCursorInfo);														//
	structCursorInfo.bVisible = FALSE;																		//
	SetConsoleCursorInfo(handle, &structCursorInfo);														//
	string type;																							// ������������� ����(�������,��� �����)
	Menu obj;																								// ����� ������� ������ ����
	obj.PrintLogin();																						//
	system("cls");																							//
	obj.ChooseYourType(type);																				// ����� ����� ��������� ��� �������
	system("cls");																							//
	if (type == "Student")																					// �������� �������� ��� ��������
	{																										//
		Student student(type);																				// ������������� ������� ������ �������
		string choose;																						// ����� ������������ ��� ������������������
		student.LogReg(choose);																				//
		if (choose == "Login")																				// �������� �������� ��� �����
		{																									//
			string name;																					// ��� �����
			system("cls");																					//
			SetConsoleTextAttribute(handle, 15);															//
			cout << "Enter your name: ";																	//
			cin >> name;																					//
			while (name == "Admin")																			// ���� ������ ����� ��� ������� - ���������� �������� ���
			{																								//
				cout << "\nEnter your name: ";																//
				cin >> name;																				//
			}																								//
			name += ".txt";																					//
			ifstream in(name);																				// ��������� ���� � ������� ������������
			if (in.is_open() == true)																		//
			{																								//
				string temp;																				//
				in >> temp;																					// 
				string password;																			//
				system("cls");																				//
				cout << "\nEnter your password: ";															// ����� ������
				cin >> temp;																				//
				do																							//
				{																							//
					if (in.is_open() == true)																// ���� ���� ����� ���� - ��������� ������
					{																						//
						in >> password;																		//
						if (password == temp)																//
						{																					//
							in.close();																		//
							break;																			//
						}																					//
					}																						//
				} while (!in.eof());																		//
				if (password == temp)																		//
				{																							//
					system("cls");																			// ������ ��������� - �������� ���� ��������
					in.close();																				//
					student.StudentMenu(name);																//
					system("cls");																			//
				}																							//
				else																						//
				{																							//
					cout << "\nWrong password\n";															// ������ �� ��������� - ��������� ���������
					in.close();																				//
					return 0;																				//
				}																							//
			}																								//
			else																							//
			{																								//
				cout << "\nUser doesn't exist";																// ���� ��� ������ �������� - ��������� ���������
				in.close();																					//
				return 0;																					//
			}																								//
		}																									//
		else																								// ���� �� ������ ���������������� ������������,
		{																									// �� �� �������� ����������� ������ ������ �������
			SetConsoleTextAttribute(handle, 15);															//
			system("cls");																					//
			student.Input();																				//
			system("cls");																					//
			student.StudentMenu();																			//
		}																									//
	}																										//
	else																									// ���� �� ������� ��� �������
	{																										//
		Admin admin(type);																					// ������ ������ ������ �����
		ifstream in("Admin.txt");																			// ��������� ��� ������
		if (in.is_open() == true)																			// ���� ����� ��� ���� - ��������� ������� �����
		{																									// ������� ����� ����� ����� ��,��� � � ��������
			string temp;																					//
			in >> temp;																						//
			string password;																				//
			system("cls");																					//
			cout << "\nEnter your password: ";																//
			cin >> temp;																					//
			do																								//
			{																								//
				if (in.is_open() == true)																	//
				{																							//
					in >> password;																			//
					if (password == temp)																	//
					{																						//
						in.close();																			//
						break;																				//
					}																						//
				}																							//
			} while (!in.eof());																			//
			if (password == temp)																			//
			{																								//
				system("cls");																				//
				admin.AdminMenu();																			//
			}																								//
			else																							//
			{																								//
				cout << "\nWrong password\n";																//
				in.close();																					//
				return 0;																					//
			}																								//
		}																									//
		else																								// ���� ��� ������� �� ������� ������ ���,
		{																									// �� ���������� ����������� ������ ������ �����
			in.close();																						//
			system("cls");																					//
			admin.Input();																					//
			system("cls");																					//
			admin.AdminMenu();																				//
		}																									//
	}																										//
}																											//