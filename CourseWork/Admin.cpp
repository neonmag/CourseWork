#include "Admin.h"																																															//		
#include "Student.h"																																														//
#include <conio.h>																																															//
#include <Windows.h>																																														//
#include <fstream>																																															//
#include <vector>																																															//
#include <string>																																															//
																																																			//
int Admin::counter = 0;																																														// Админа не может быть больше 
																																																			// чем 1
Admin::Admin(string type) : User(type)																																										//
{																																																			//
	this->counter++;																																														//
}																																																			//
																																																			//
void Admin::Input()																																															// Метод создания админа
{																																																			//
	ofstream out("Admin.txt");																																												//
	string login;																																															//
	string password;																																														//
	cout << "\nEnter your login: ";																																											//
	cin >> login;																																															//
	cout << "\nEnter your password: ";																																										//
	cin >> password;																																														//
	SetLogin(login);																																														//
	SetPassword(password);																																													//
	out << login << "\n" << password;																																										//
	out.close();																																															//
}																																																			//
																																																			//
void Admin::Output()																																														//
{																																																			//
	cout << "\nLogin: " << GetLogin();																																										//
	cout << "\nPassword: " << GetPassword();																																								//
}																																																			//
																																																			//
void Admin::AdminMenu()																																														// Админское меню
{																																																			//
	COORD position{ 0,0 };																																													//
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);																																								//
	string puncts[5] = { "Change password","Make test","Edit test", "Make new user" , "Check answers" };																									//
	for (int i = 0; i < 5; i++)																																												//
	{																																																		//
		SetConsoleCursorPosition(h, position);																																								//
		cout << puncts[i];																																													//
		position.Y += 2;																																													//
	}																																																		//
	int key = 0;																																															//
	int counter = 0;																																														//
	position.Y = 0;																																															//
	while (key != Keys::Back)																																												// Выбор пунктов меню
	{																																																		//
		key = _getch();																																														//
		switch (key)																																														//
		{																																																	//
		case Keys::Up:																																														//
			if (position.Y == 0)																																											//
			{																																																//
				continue;																																													//
			}																																																//
			else																																															//
			{																																																//
				SetConsoleTextAttribute(h, 15);																																								//
				SetConsoleCursorPosition(h, position);																																						//
				cout << puncts[counter];																																									//
				position.Y -= 2;																																											//
				counter--;																																													//
				SetConsoleTextAttribute(h, 10);																																								//
				SetConsoleCursorPosition(h, position);																																						//
				cout << puncts[counter];																																									//
																																																			//
			}																																																//
			break;																																															//
		case Keys::Down:																																													//
			if (position.Y == 8)																																											//
			{																																																//
				continue;																																													//
			}																																																//
			else																																															//
			{																																																//
				SetConsoleTextAttribute(h, 15);																																								//
				SetConsoleCursorPosition(h, position);																																						//
				cout << puncts[counter];																																									//
				counter++;																																													//
				position.Y += 2;																																											//
				SetConsoleTextAttribute(h, 10);																																								//
				SetConsoleCursorPosition(h, position);																																						//
				cout << puncts[counter];																																									//
			}																																																//
			break;																																															//
		case Keys::Back:																																													//
			return;																																															//
		case Keys::Enter:																																													//
			if (position.Y == 0)																																											// Смена пароля
			{																																																//
				SetConsoleTextAttribute(h, 15);																																								//
				string newPassword;																																											//
				system("cls");																																												//
				cout << "Enter new password: ";																																								//
				cin >> newPassword;																																											//
				SetPassword(newPassword);																																									//
				system("cls");																																												//
				cout << GetPassword();																																										//
				system("pause");																																											//
				ifstream in("Admin.txt");																																									//
				string tmp;																																													//
				in >> tmp;																																													//
				SetLogin(tmp);																																												//
				in.close();																																													//
				ofstream on("Admin.txt");																																									//
				on << GetLogin() << "\n" << GetPassword();																																					//
				on.close();																																													//
				system("cls");																																												//
				for (int i = 0; i < 5; i++)																																									//
				{																																															//
					SetConsoleCursorPosition(h, position);																																					//
					cout << puncts[i];																																										//
					position.Y += 2;																																										//
				}																																															//
				position.Y = 0;																																												//
				SetConsoleCursorPosition(h, position);																																						//
				break;																																														//
			}																																																//
			else if (position.Y == 2)																																										// Создание теста
			{																																																//
				SetConsoleTextAttribute(h, 15);																																								//
				system("cls");																																												//
				cout << "Every test included his name, and 12 asks with 12 answer,no more,no less.\nEvery right answer give you 1 point.\nSo,lets start making the test";									//
				string nameOfTest;																																											//
				cout << "\nEnter name of test: ";																																							//
				cin >> nameOfTest;																																											//
				cin.ignore();																																												//
				ofstream outNames("Name of tests.txt", ios::app);																																			//
				outNames << nameOfTest << "\n";																																								//
				outNames.close();																																											//
				string nameOfTestAnswers = nameOfTest + " answers.txt";																																		//
				nameOfTest = nameOfTest + ".txt";																																							//
				ofstream out(nameOfTest, ios::app);																																							//
				char* ask = new char[50];																																									//
				char* answer = new char[50];																																								//
				for (int i = 0; i < 12; i++)																																								//
				{																																															//
					cout << "\nEnter ask: ";																																								//
					cin.getline(ask, 49);																																									//
					out << ask << "\n";																																										//
				}																																															//
				out.close();																																												//
				ofstream answers(nameOfTestAnswers);																																						//
				for (int i = 0; i < 12; i++)																																								//
				{																																															//
					cout << "\nEnter answer: ";																																								//
					cin.getline(answer, 49);																																								//
					answers << answer << "\n";																																								//
				}																																															//
				delete[]ask;																																												//
				delete[]answer;																																												//
				ask = nullptr;																																												//
				answer = nullptr;																																											//
				answers.close();																																											//
				system("cls");																																												//
				position.Y = 0;																																												//
				for (int i = 0; i < 5; i++)																																									//
				{																																															//
					SetConsoleCursorPosition(h, position);																																					//
					cout << puncts[i];																																										//
					position.Y += 2;																																										//
				}																																															//
				counter = 0;																																												//
				position.Y = 0;																																												//
				SetConsoleCursorPosition(h, position);																																						//
				break;																																														//
			}																																																//
			else if (position.Y == 4)																																										// Редактирование теста
			{																																																//
				string nameOfTest;																																											//
				cout << "\nEnter name of test: ";																																							//
				cin >> nameOfTest;																																											//
				nameOfTest = nameOfTest + ".txt";																																							//
				string nameOfTestAnswers = nameOfTest + " answers.txt";																																		//
				nameOfTest = nameOfTest + ".txt";																																							//
				ofstream out(nameOfTest, ios::app);																																							//
				char* ask = new char[50];																																									//
				char* answer = new char[50];																																								//
				for (int i = 0; i < 12; i++)																																								//
				{																																															//
					cout << "\nEnter ask: ";																																								//
					cin.getline(ask, 49);																																									//
					out << ask << "\n";																																										//
				}																																															//
				out.close();																																												//
				ofstream answers(nameOfTestAnswers);																																						//
				for (int i = 0; i < 12; i++)																																								//
				{																																															//
					cout << "\nEnter answer: ";																																								//
					cin.getline(answer, 49);																																								//
					answers << answer << "\n";																																								//
				}																																															//
				delete[]ask;																																												//
				delete[]answer;																																												//
				ask = nullptr;																																												//
				answer = nullptr;																																											//
				answers.close();																																											//
				system("cls");																																												//
				position.Y = 0;																																												//
				for (int i = 0; i < 5; i++)																																									//
				{																																															//
					SetConsoleCursorPosition(h, position);																																					//
					cout << puncts[i];																																										//
					position.Y += 2;																																										//
				}																																															//
				counter = 0;																																												//
				position.Y = 0;																																												//
				SetConsoleCursorPosition(h, position);																																						//
				break;																																														//
			}																																																//
			else if (position.Y == 6)																																										// Создание нового студента
			{																																																//
				system("cls");																																												//
				Student student("Student");																																									//
				SetConsoleTextAttribute(h, 15);																																								//
				student.Input();																																											//
				system("cls");																																												//
				position.Y = 0;																																												//
				for (int i = 0; i < 5; i++)																																									//
				{																																															//
					SetConsoleCursorPosition(h, position);																																					//
					cout << puncts[i];																																										//
					position.Y += 2;																																										//
				}																																															//
				counter = 0;																																												//
				position.Y = 0;																																												//
				SetConsoleCursorPosition(h, position);																																						//
				break;																																														//
			}																																																//
			else																																															// Проверка статистики студентов
			{																																																//
				system("cls");																																												//
				SetConsoleTextAttribute(h, 15);																																								//
				ifstream in("Name of tests.txt");																																							//
				int count = 0;																																												//
				string ptr;																																													//
				if (in.is_open() == true)																																									//
				{																																															//
					do																																														//
					{																																														//
						count++;																																											//
						getline(in, ptr);																																									//
					} while (!in.eof());																																									//
					in.close();																																												//
				}																																															//
				in.open("Name of tests.txt",ios::beg);																																						//
				string* nameOfTests = new string[count];																																					//
				count = 0;																																													//
				if (in.is_open() == true)																																									//
				{																																															//
					do																																														//
					{																																														//
						getline(in, nameOfTests[count]);																																					//
						count++;																																											//
					} while (!in.eof());																																									//
					in.close();																																												//
				}																																															//
				ifstream inUsers("Name of users.txt");																																						//
				int countOfUsers = 0;																																										//
				if (inUsers.is_open() == true)																																								//
				{																																															//
					do																																														//
					{																																														//
						countOfUsers++;																																										//
						getline(inUsers, ptr);																																								//
					} while (!inUsers.eof());																																								//
					inUsers.close();																																										//
				}																																															//
				string* namesOfUsers = new string[countOfUsers];																																			//
				inUsers.open("Name of users.txt",ios::beg);																																					//
				countOfUsers = 0;																																											//
				if (inUsers.is_open() == true)																																								//
				{																																															//
					do																																														//
					{																																														//
						getline(inUsers, namesOfUsers[countOfUsers]);																																		//
						countOfUsers++;																																										//
					} while (!inUsers.eof());																																								//
					inUsers.close();																																										//
				}																																															//
				for (int i = 0; i < count; i++)																																								//
				{																																															//
					cout << nameOfTests[i] << "\n";																																							//
				}																																															//
				cout << "Enter name of test: ";																																								//
				string test;																																												//
				bool check = false;																																											//
				cin >> test;																																												//
				for (int i = 0; i < count; i++)																																								//
				{																																															//
					if (test == nameOfTests[i])																																								//
					{																																														//
						check = true;																																										//
						break;																																												//
					}																																														//
				}																																															//
				if (check == true)																																											//
				{																																															//
					check = false;																																											//
					system("cls");																																											//
					for (int i = 0; i < countOfUsers; i++)																																					//
					{																																														//
						cout << namesOfUsers[i] << "\n";																																					//
					}																																														//
					cout << "\nEnter name of user: ";																																						//
					string testUser;																																										//
					cin >> testUser;																																										//
					for (int i = 0; i < count; i++)																																							//
					{																																														//
						if (testUser == namesOfUsers[i])																																					//
						{																																													//
							check = true;																																									//
							break;																																											//
						}																																													//
					}																																														//
					if (check == true)																																										//
					{																																														//
						ifstream checkAnswers(testUser + test + " answers.txt");																															//
						string checkAns;																																									//
						if (checkAnswers.is_open() == true)																																					//
						{																																													//
							do																																												//
							{																																												//
								getline(checkAnswers, checkAns);																																			//
								cout << checkAns << endl;																																					//
							} while (!checkAnswers.eof());																																					//
						}																																													//
						checkAnswers.close();																																								//
					}																																														//
				}																																															//
				system("pause");																																											//
				system("cls");																																												//
				position.Y = 0;																																												//
				for (int i = 0; i < 5; i++)																																									//
				{																																															//
					SetConsoleCursorPosition(h, position);																																					//
					cout << puncts[i];																																										//
					position.Y += 2;																																										//
				}																																															//
				counter = 0;																																												//
				position.Y = 0;																																												//
				SetConsoleCursorPosition(h, position);																																						//
				break;																																														//
			}																																																//
		}																																																	//
	}																																																		//
																																																			//
}																																																			//
																																																			//
Admin::~Admin()																																																//
{																																																			//
}																																																			//
																																																			//