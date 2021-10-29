#include "Menu.h"																		//
																						//
Menu::Menu()																			// ����������� �� ���������,������
{																						//
																						//
}																						//
																						//
void Menu::PrintLogin()																	// ����� ��� ������ ���������� ����
{																						//
	COORD position{ 40,0 };																//
	string puncts[2] = { "Login","Exit" };												// ������ ����
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);											//
	SetConsoleCursorPosition(h, position);												//
	cout << puncts[0];																	//
	position.Y += 2;																	//
	SetConsoleCursorPosition(h, position);												//
	cout << puncts[1];																	//
	int key = 0;																		// ���������� ��� ���������� ������� ������
	while (key != Keys::Back)															// ���� �� �������� escape - ��������� �����������
	{																					// ����������� switch - case ��� �������������� ���� + ������ ������
		key = _getch();																	// ����� Enter
		switch (key)																	//
		{																				//
		case Keys::Down:																//
			if (position.Y == 2)														//
			{																			//
				SetConsoleTextAttribute(h, 10);											//
				SetConsoleCursorPosition(h, position);									//
				cout << puncts[1];														//
			}																			//
			else																		//
			{																			//
				SetConsoleTextAttribute(h, 15);											//
				SetConsoleCursorPosition(h, position);									//
				cout << puncts[0];														//
				position.Y += 2;														//
				SetConsoleTextAttribute(h, 10);											//
				SetConsoleCursorPosition(h, position);									//
				cout << puncts[1];														//
			}																			//
			break;																		//
		case Keys::Up:																	//
			if (position.Y == 0)														//
			{																			//
				SetConsoleTextAttribute(h, 10);											//
				SetConsoleCursorPosition(h, position);									//
				cout << puncts[0];														//
			}																			//
			else																		//
			{																			//
				SetConsoleTextAttribute(h, 15);											//
				SetConsoleCursorPosition(h, position);									//
				cout << puncts[1];														//
				position.Y -= 2;														//
				SetConsoleTextAttribute(h, 10);											//
				SetConsoleCursorPosition(h, position);									//
				cout << puncts[0];														//
			}																			//
			break;																		//
		case Keys::Enter:																//
			if (position.Y == 2)														//
			{																			//
				exit(0);																//
			}																			//
			else																		//
			{																			//
				position = { 0,0 };														//
				SetConsoleCursorPosition(h, position);									//
				SetConsoleTextAttribute(h, 15);											//
				return;																	//
			}																			//
			break;																		//
		case Keys::Back:																//
			exit(0);																	//
		}																				//
	}																					//
}																						//
																						//
void Menu::ChooseYourType(string &type)													// ����� ��� �����������,�����, ��� �������
{																						//
	string types[2] = { "Are you admin?","Are you student?" };							// ����� ������� ����
	COORD position{ 40,0 };																//
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);											//
	SetConsoleCursorPosition(h, position);												//
	cout << types[0];																	//
	position.Y += 2;																	//
	SetConsoleCursorPosition(h, position);												//
	cout << types[1];																	//
	int key = 0;																		//
	while (key != Keys::Back)															// 
	{																					//
		key = _getch();																	//
		switch (key)																	// ����������� ��� �������������� ���� � ������ ������� ����
		{																				//
		case Keys::Down:																//
			if (position.Y == 2)														//
			{																			//
				SetConsoleTextAttribute(h, 10);											//
				SetConsoleCursorPosition(h, position);									//
				cout << types[1];														//
			}																			//
			else																		//
			{																			//
				SetConsoleTextAttribute(h, 15);											//
				SetConsoleCursorPosition(h, position);									//
				cout << types[0];														//
				position.Y += 2;														//
				SetConsoleTextAttribute(h, 10);											//
				SetConsoleCursorPosition(h, position);									//
				cout << types[1];														//
			}																			//
			break;																		//
		case Keys::Up:																	//
			if (position.Y == 0)														//
			{																			//
				SetConsoleTextAttribute(h, 10);											//
				SetConsoleCursorPosition(h, position);									//
				cout << types[0];														//
			}																			//
			else																		//
			{																			//
				SetConsoleTextAttribute(h, 15);											//
				SetConsoleCursorPosition(h, position);									//
				cout << types[1];														//
				position.Y -= 2;														//
				SetConsoleTextAttribute(h, 10);											//
				SetConsoleCursorPosition(h, position);									//
				cout << types[0];														//
			}																			//
			break;																		//
		case Keys::Enter:																//
			if (position.Y == 2)														//
			{																			//
				type = "Student";														//
				position = { 0,0 };														//
				SetConsoleCursorPosition(h, position);									//
				SetConsoleTextAttribute(h, 15);											//
				return;																	//
			}																			//
			else																		//
			{																			//
				type = "Admin";															//
				position = { 0,0 };														//
				SetConsoleCursorPosition(h, position);									//
				SetConsoleTextAttribute(h, 15);											//
				return;																	//
			}																			//
			break;																		//
		case Keys::Back:																//
			exit(0);																	//
		}																				//
	}																					//
}																						//
																						//