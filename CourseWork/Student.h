#include <iostream>																//
#include "User.h"																//
																				//
using namespace std;															//
																				//
class Student : public User														// Студент - класс наследник от юзера
{																				//
private:																		//
	int countOfFinishedTests;													// Приватное поле для количества пройденных тестов конкретного студента
public:																			//
	Student() = delete;															// Запрещаем создавать пустые объекты класса
	Student(string type);														// 
	void Input();																// Метод ввода студента
	void Output();																// Метод вывода
	void LogReg(string &choose);												// Выбор между логином и регистрация
	void StudentMenu();															// Меню студента,которого мы регистрируем
	void StudentMenu(string fileName);											// Метод студента,в которого мы входим
	void SetCountOfFinishedTests(int countOfFinishedTests);						// Метод СЕТ для кол-ва пройденных тестов
	void PassTheTest();															// Прохождение теста
	int GetCountOfFinishedTests();												// Метод ГЕТ для кол - ва пройденных тестов
	~Student();																	// Деструктор
};																				//