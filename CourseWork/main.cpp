#include <iostream>																							//
#include <fstream>																							//
#include "Admin.h"																							// Подключение библиотек и
#include "Student.h"																						// наших классов
#include "Menu.h"																							//
#include <string>																							//
																											//
using namespace std;																						//
																											//
int main()																									//
{																											//
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);                                                        // Дескриптор окна
	CONSOLE_CURSOR_INFO structCursorInfo;																	// Метод скрытия курсора
	GetConsoleCursorInfo(handle, &structCursorInfo);														//
	structCursorInfo.bVisible = FALSE;																		//
	SetConsoleCursorInfo(handle, &structCursorInfo);														//
	string type;																							// Инициализация типа(студент,или админ)
	Menu obj;																								// Вызов объекта класса Меню
	obj.PrintLogin();																						//
	system("cls");																							//
	obj.ChooseYourType(type);																				// Выбор между студентом или админом
	system("cls");																							//
	if (type == "Student")																					// Условный оператор для студента
	{																										//
		Student student(type);																				// Инициализация объекта класса студент
		string choose;																						// Выбор залогиниться или зарегестрироваться
		student.LogReg(choose);																				//
		if (choose == "Login")																				// Условный оператор для входа
		{																									//
			string name;																					// Даём логин
			system("cls");																					//
			SetConsoleTextAttribute(handle, 15);															//
			cout << "Enter your name: ";																	//
			cin >> name;																					//
			while (name == "Admin")																			// Если решили войти под админом - заставляем поменять имя
			{																								//
				cout << "\nEnter your name: ";																//
				cin >> name;																				//
			}																								//
			name += ".txt";																					//
			ifstream in(name);																				// Открываем файл с логином пользователя
			if (in.is_open() == true)																		//
			{																								//
				string temp;																				//
				in >> temp;																					// 
				string password;																			//
				system("cls");																				//
				cout << "\nEnter your password: ";															// Задаём пароль
				cin >> temp;																				//
				do																							//
				{																							//
					if (in.is_open() == true)																// Если есть такой юзер - проверяем пароль
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
					system("cls");																			// Пароли совпадают - вызываем меню студента
					in.close();																				//
					student.StudentMenu(name);																//
					system("cls");																			//
				}																							//
				else																						//
				{																							//
					cout << "\nWrong password\n";															// Пароли не совпадают - закрываем программу
					in.close();																				//
					return 0;																				//
				}																							//
			}																								//
			else																							//
			{																								//
				cout << "\nUser doesn't exist";																// Если нет такого студента - закрываем программу
				in.close();																					//
				return 0;																					//
			}																								//
		}																									//
		else																								// Если мы решили зарегистрировать пользователя,
		{																									// то мы вызываем специальные методы класса студент
			SetConsoleTextAttribute(handle, 15);															//
			system("cls");																					//
			student.Input();																				//
			system("cls");																					//
			student.StudentMenu();																			//
		}																									//
	}																										//
	else																									// Если мы заходим под админом
	{																										//
		Admin admin(type);																					// Создаём объект класса админ
		ifstream in("Admin.txt");																			// Открываем для чтения
		if (in.is_open() == true)																			// Если админ уже есть - запускаем процесс входа
		{																									// Процесс входа точно такой же,как и у студента
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
		else																								// Если под админом мы заходим первый раз,
		{																									// то вызываются специальные методы класса админ
			in.close();																						//
			system("cls");																					//
			admin.Input();																					//
			system("cls");																					//
			admin.AdminMenu();																				//
		}																									//
	}																										//
}																											//