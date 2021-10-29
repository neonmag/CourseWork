#include "Student.h"																					//
#include <Windows.h>																					//
#include <conio.h>																						//
#include "Keys.h"																						//
#include <fstream>																						//
#include <string>																						//
																										//
using namespace std;																					//
																										//
Student::Student(string type) : User(type)																// Делигирование в базовый класс
{																										//
	this->countOfFinishedTests = 0;																		//
}																										//
																										//
void Student::Input()																					// Метод для регистрации нового студента
{																										//
	string login;																						//
	string password;																					//
	cout << "Enter your login: ";																		//
	cin >> login;																						//
	cout << "\nEnter your password: ";																	//
	cin >> password;																					//
	SetLogin(login);																					//
	SetPassword(password);																				//
	string temp = login;																				//
	login += ".txt";																					//
	ofstream on(login);																					//
	on << temp << "\n" << password << "\n" << GetCountOfFinishedTests();								//
	on.close();																							//
	ofstream inNames("Name of users.txt",ios::app);														// Запись студента в файл
	inNames << temp << "\n";																			//
	inNames.close();																					//
}																										//
																										//
void Student::Output()																					// Метод вывода студента
{																										//
	cout << "\nLogin: " << GetLogin();																	//
	cout << "\nPassword: " << GetPassword();															//
	cout << endl;																						//
}																										//
																										//
void Student::LogReg(string &choose)																	// Выбор между входом и регистрацией
{																										//
	COORD position{ 0,0 };																				//
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);															//
	string puncts[2] = { "Sign in","Sign up" };															//
	for (int i = 0; i < 2; i++)																			//
	{																									//
		SetConsoleCursorPosition(h,position);															//
		cout << puncts[i];																				//
		position.Y += 2;																				//
	}																									//
	position.Y = 0;																						//
	SetConsoleCursorPosition(h, position);																//
	int key = 0;																						//
	int counter = 0;																					//
	while (key != Keys::Back)																			//
	{																									// Конструкция для выборов пунктов меню
		key = _getch();																					//
		switch (key)																					//
		{																								//
		case Keys::Up:																					//
			if (position.Y == 0)																		//
			{																							//
				continue;																				//
			}																							//
			else																						//
			{																							//
				SetConsoleCursorPosition(h, position);													//
				SetConsoleTextAttribute(h, 15);															//
				cout << puncts[counter];																//
				counter--;																				//
				position.Y -= 2;																		//
				SetConsoleCursorPosition(h, position);													//
				SetConsoleTextAttribute(h, 10);															//
				cout << puncts[counter];																//
			}																							//
			break;																						//
		case Keys::Down:																				//
			if (position.Y == 2)																		//
			{																							//
				continue;																				//
			}																							//
			else																						//
			{																							//
				SetConsoleCursorPosition(h, position);													//
				SetConsoleTextAttribute(h, 15);															//
				cout << puncts[counter];																//
				counter++;																				//
				position.Y += 2;																		//
				SetConsoleCursorPosition(h, position);													//
				SetConsoleTextAttribute(h, 10);															//
				cout << puncts[counter];																//
			}																							//
			break;																						//
		case Keys::Back:																				//
			exit(0);																					//
		case Keys::Enter:																				//
			if (position.Y == 0)																		//
			{																							//
				choose = "Login";																		//
			}																							//
			else																						//
			{																							//
				choose = "Registration";																//
			}																							//
			return;																						//
		}																								//
	}																									//
}																										//
																										//
void Student::StudentMenu()																				// Меню нового студента
{																										//
	COORD position{ 0,0 };																				//
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);															//
	string puncts[3] = { "Show my info","Pass the test","Exit the programm" };							// Пункты меню студента
	for (int i = 0; i < 3; i++)																			//
	{																									//
		SetConsoleCursorPosition(h, position);															//
		cout << puncts[i];																				//
		position.Y += 2;																				//
	}																									//
	position.Y = 0;																						//
	int counter = 0;																					//
	int key = 0;																						//
	while (key != Keys::Back)																			//
	{																									// Конструкция выбора пунктов меню
		key = _getch();																					//
		switch (key)																					//
		{																								//
		case Keys::Up:																					//
			if (position.Y == 0)																		//
			{																							//
				continue;																				//
			}																							//
			else																						//
			{																							//
				SetConsoleCursorPosition(h, position);													//
				SetConsoleTextAttribute(h, 15);															//
				cout << puncts[counter];																//
				counter--;																				//
				position.Y -= 2;																		//
				SetConsoleCursorPosition(h, position);													//
				SetConsoleTextAttribute(h, 10);															//
				cout << puncts[counter];																//
			}																							//
			break;																						//
		case Keys::Down:																				//
			if (position.Y == 4)																		//
			{																							//
				continue;																				//
			}																							//
			else																						//
			{																							//
				SetConsoleCursorPosition(h, position);													//
				SetConsoleTextAttribute(h, 15);															//
				cout << puncts[counter];																//
				counter++;																				//
				position.Y += 2;																		//
				SetConsoleCursorPosition(h, position);													//
				SetConsoleTextAttribute(h, 10);															//
				cout << puncts[counter];																//
			}																							//
			break;																						//
		case Keys::Back:																				//
			exit(0);																					//
		case Keys::Enter:																				//
			if (position.Y == 0)																		//
			{																							//
				system("cls");																			//
				SetConsoleTextAttribute(h, 15);															//
				cout << "Name: " << GetLogin();															//
				cout << "\nPassword: " << GetPassword();												//
				cout << "\nAmount of passed tests: " << GetCountOfFinishedTests();						//
				system("pause");																		//
				system("cls");																			//
				for (int i = 0; i < 3; i++)																//
				{																						//
					SetConsoleCursorPosition(h, position);												//
					cout << puncts[i];																	//
					position.Y += 2;																	//
				}																						//
				position.Y = 0;																			//
				SetConsoleCursorPosition(h, position);													//
			}																							//
			else if (position.Y == 2)																	//
			{																							//
				SetConsoleTextAttribute(h, 15);															//
				PassTheTest();																			//
				system("cls");																			//
				position.Y = 0;																			//
				SetConsoleCursorPosition(h, position);													//
				for (int i = 0; i < 3; i++)																//
				{																						//
					SetConsoleCursorPosition(h, position);												//
					cout << puncts[i];																	//
					position.Y += 2;																	//
				}																						//
				position.Y = 0;																			//
				counter = 0;																			//
				SetConsoleCursorPosition(h, position);													//
			}																							//
			else																						//
			{																							//
				return;																					//
			}																							//
			break;																						//
		}																								//
	}																									//
}																										//
																										//
void Student::StudentMenu(string fileName)																// Меню студента уже существующего
{																										//
	if (fileName != "\0")																				// Проверка на наличие студента
	{																									//
		ifstream GetLog(fileName);																		//
		string temp;																					//
		getline(GetLog, temp);																			//
		SetLogin(temp);																					//
		getline(GetLog, temp);																			//
		SetPassword(temp);																				//
		getline(GetLog, temp);																			//
		int mark = stoi(temp);																			//
		SetCountOfFinishedTests(mark);																	//
	}																									//
	COORD position{ 0,0 };																				//
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);															//
	string puncts[3] = { "Show my info","Pass the test","Exit the programm" };							//
	for (int i = 0; i < 3; i++)																			//
	{																									//
		SetConsoleCursorPosition(h, position);															//
		cout << puncts[i];																				//
		position.Y += 2;																				//
	}																									//
	position.Y = 0;																						//
	int counter = 0;																					//
	int key = 0;																						//
	while (key != Keys::Back)																			//
	{																									//
		key = _getch();																					//
		switch (key)																					//
		{																								//
		case Keys::Up:																					//
			if (position.Y == 0)																		//
			{																							//
				continue;																				//
			}																							//
			else																						//
			{																							//
				SetConsoleCursorPosition(h, position);													//
				SetConsoleTextAttribute(h, 15);															//
				cout << puncts[counter];																//
				counter--;																				//
				position.Y -= 2;																		//
				SetConsoleCursorPosition(h, position);													//
				SetConsoleTextAttribute(h, 10);															//
				cout << puncts[counter];																//
			}																							//
			break;																						//
		case Keys::Down:																				//
			if (position.Y == 4)																		//
			{																							//
				continue;																				//
			}																							//
			else																						//
			{																							//
				SetConsoleCursorPosition(h, position);													//
				SetConsoleTextAttribute(h, 15);															//
				cout << puncts[counter];																//
				counter++;																				//
				position.Y += 2;																		//
				SetConsoleCursorPosition(h, position);													//
				SetConsoleTextAttribute(h, 10);															//
				cout << puncts[counter];																//
			}																							//
			break;																						//
		case Keys::Back:																				//
			exit(0);																					//
		case Keys::Enter:																				//
			if (position.Y == 0)																		//
			{																							//
				system("cls");																			//
				SetConsoleTextAttribute(h, 15);															//
				cout << "Name: " << GetLogin();															//
				cout << "\nPassword: " << GetPassword();												//
				cout << "\nAmount of passed tests: " << GetCountOfFinishedTests();						//
				system("pause");																		//
				system("cls");																			//
				for (int i = 0; i < 3; i++)																//
				{																						//
					SetConsoleCursorPosition(h, position);												//
					cout << puncts[i];																	//
					position.Y += 2;																	//
				}																						//
				position.Y = 0;																			//
				SetConsoleCursorPosition(h, position);													//
			}																							//
			else if (position.Y == 2)																	//
			{																							//
				SetConsoleTextAttribute(h, 15);															//
				PassTheTest();																			//
				system("cls");																			//
				position.Y = 0;																			//
				SetConsoleCursorPosition(h, position);													//
				for (int i = 0; i < 3; i++)																//
				{																						//
					SetConsoleCursorPosition(h, position);												//
					cout << puncts[i];																	//
					position.Y += 2;																	//
				}																						//
				position.Y = 0;																			//
				counter = 0;																			//
				SetConsoleCursorPosition(h, position);													//
			}																							//
			else																						//
			{																							//
				return;																					//
			}																							//
			break;																						//
		}																								//
	}																									//
}																										//
																										//
void Student::SetCountOfFinishedTests(int countOfFinishedTests)											//
{																										//
	this->countOfFinishedTests = countOfFinishedTests;													//
}																										//
																										//
void Student::PassTheTest()																				// Метод прохождения теста
{																										//
	system("cls");																						//
	ifstream in("Name of tests.txt");																	//
	string names[100];																					//
	int count = 0;																						//
	if (in.is_open() == true)																			//
	{																									//
		do																								//
		{																								//
			count++;																					//
			getline(in, names[count]);																	//
			cout << names[count] << "\n";																//
		} while (!in.eof());																			//
	}																									//
	in.close();																							//
	string temp;																						//
	cout << "\nEnter name of test: ";																	//
	cin >> temp;																						//
	int check;																							//
	for (int i = 0; i < count; i++)																		//
	{																									//
		if (temp == names[i])																			//
		{																								//
			check = i;																					//
			break;																						//
		}																								//
	}																									//
	ifstream inTest((names[check] + ".txt"));															//
	string newSmth;																						//
	if (inTest.is_open() == true)																		//
	{																									//
		do																								//
		{																								//
			getline(inTest, newSmth);																	//
			cout << newSmth << "\n";																	//
		} while (!inTest.eof());																		//
	}																									//
	inTest.close();																						//
	string answ[12];																					//
	for (int i = 0; i < 12; i++)																		//
	{																									//
		cout << "\nEnter: " << i + 1 << " answer: ";													//
		cin >> answ[i];																					//
		cout << endl;																					//
	}																									//
	int countOfAnswers = 0;																				//
	int points = 0;																						//
	ifstream answer((names[check] + " answers.txt"));
	ofstream onAnswers(GetLogin() + temp + " answers.txt", ios::beg);
	onAnswers.close();
	if (answer.is_open() == true)																		//
	{																									//
		do																								//
		{																								//
			getline(answer, newSmth);																	//
			if (newSmth == answ[countOfAnswers])														//
			{																							//
				points++;																				//
				onAnswers.open(GetLogin() + temp + " answers.txt", ios::app);						//
				onAnswers << answ[countOfAnswers] << " +\n";											//
				onAnswers.close();																		//
			}																							//
			else																						//
			{																							//
				onAnswers.open(GetLogin() + temp + " answers.txt", ios::app);						//
				onAnswers << answ[countOfAnswers] << " -\n";											//
				onAnswers.close();																		//
			}																							//
			countOfAnswers++;																			//
		} while (!answer.eof());																		//
	}																									//
	answer.close();																						//
	if (points >= 6)																					//
	{																									//
		string FileName = GetLogin() + ".txt";															//
		ifstream Login(FileName);																		//
		string tempTests;																				//
		do																								//
		{																								//
			getline(Login, tempTests);																	//
		} while (!Login.eof());																			//
		int mark = stoi(tempTests) + 1;																	//
		SetCountOfFinishedTests(mark);																	//
	}																									//
	string tempLogin = GetLogin() + ".txt";																//
	ofstream onName(GetLogin() + ".txt");																//
	onName << GetLogin() << "\n" << GetPassword() << "\n" << GetCountOfFinishedTests();					//
	onName.close();																						//
	system("pause");																					//
}																										//
																										//
int Student::GetCountOfFinishedTests()																	//
{																										//
	return this->countOfFinishedTests;																	//
}																										//
																										//
Student::~Student()																						//
{																										//
}																										//
																										//