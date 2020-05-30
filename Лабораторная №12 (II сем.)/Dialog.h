#pragma once
#include <vector>
#include <set>
#include <list>
#include <map>
#include <Windows.h>
#include"Point.h"

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

using std::vector;
using std::set;
using std::list;
using std::map;
using std::cout;
using std::cin;
using std::endl;

template<typename T>
class ConsoleUI
{
public:
	/* Меню - отвечает за работу диалогового окна */
	void RunExe();

private:
	// Используемые контейнеры
	vector<T> Vector;
	set<T> Set;
	list<T> List;
	map<int, T> Map;

	// Выбор контейнера
	int ContainerSelect();
	// Выбор операции
	int OperationSelect();

	// Выполнение операции над Вектором
	void DoVectorOperation(int ch);
	// Добавление элемента в Вектор	
	void AddToVector(int ch);
	// Удаление элемента из вектора
	void DelFromVector(int ch);
	// Получение данных из вектора
	T VectorGet(int ch);
	// Вывод содержимого Вектора на экран
	void VectorShow();
	// Уведомление об отсутствии данных в Векторе
	bool NoVectorData();
	// Уведомление о выборе Вектора
	void ChoseVector();

	// Выполнение операции над Сетом
	void DoSetOperation(int ch);
	// Добавление элемента в Сет
	void AddToSet();
	// Удаление элемента из Сета
	void DelFromSet();
	// Получение данных из Сета
	T SetGet();
	// Вывод содержимого Сета на экран
	void SetShow();
	// Уведомление об отсутствии данных в Сете
	bool NoSetData();
	// Уведомление о выборе Сета
	void ChoseSet();

	// Выполнение операции над Списком
	void DoListOperation(int ch);
	// Добавление элемента в Список
	void AddToList(int ch);
	// Удаление элемента из Списка
	void DelFromList(int ch);
	// Получение данных из Списка
	T ListGet(int ch);
	// Вывод содержимого Списка на экран
	void ListShow();
	// Уведомление об отсутствии данных в Списке
	bool NoListData();
	// Уведомление о выборе Списка
	void ChoseList();

	// Выпонение операции над Мапом
	void DoMapOperation(int ch);
	// Добавление элемента в Мап
	void AddToMap();
	// Удаление элемента из Мапа
	void DelFromMap();
	// Получение данных из Мапа
	T MapGet();
	// Вывод содержимого Мапа на экран
	void MapShow();
	// Уведомление об отсутствии данных в Мапе
	bool NoMapData();
	// Уведомление о выборе Мапа
	void ChoseMap();

	// Уведомление об успешной операции
	void OperationPass();
	// Уведомление об отмене операции
	void OperationCancel();
	// Информация о лабораторной работе
	void LabInfo();
	// Проверка выбора варианта
	bool CheckSelect(int b, int e, int i);
};
// ########################## ГЛАВНОЕ МЕНЮ ##########################
template<typename T>
inline void ConsoleUI<T>::RunExe()
{
	int choice;
	do {
		choice = ContainerSelect();
		switch (choice)
		{
		case 1:
			DoVectorOperation(choice);
			system("cls");
			break;

		case 2:
			DoListOperation(choice);
			system("cls");
			break;

		case 3:
			DoSetOperation(choice);
			system("cls");
			break;

		case 4:
			DoMapOperation(choice);
			system("cls");
			break;

		case 0:
			SetColor(13, 0);
			cout << "\nСпасибо за работу!\n";
			SetColor(7, 0);
		}
	} while (choice);
}
// ######################## ВЫБОР КОНТЕЙНЕРА ########################
template<typename T>
inline int ConsoleUI<T>::ContainerSelect()
{
	int choice;
	LabInfo();
	cout << "Выберите контейнер:\n";
	cout << "1. Vector.\n";
	cout << "2. List.\n";
	cout << "3. Set.\n";
	cout << "4. Map.\n";
	cout << "0. Выход.\n";
	cout << "Введите ваш ответ сюда: ";
	cin >> choice;
	CheckSelect(0, 4, choice);
	return choice;
}
// ######################### ВЫБОР ОПЕРАЦИЙ #########################
template<typename T>
inline int ConsoleUI<T>::OperationSelect()
{
	int choice;
	cout << "Список доступных операций:\n";
	cout << "1. Добавление элемента.\n";
	cout << "2. Удаление элемента.\n";
	cout << "3. Получение данных.\n";
	cout << "4. Вывод содержимого на экран.\n";
	cout << "0. Вернуться к выбору контейнера.\n";
	cout << "Введите ваш ответ сюда: ";
	cin >> choice;
	CheckSelect(0, 4, choice);
	return choice;
}
// ######################## ОПЕРАЦИЯ УСПЕШНА ########################
template<typename T>
inline void ConsoleUI<T>::OperationPass()
{
	SetColor(10, 0);
	cout << "Операция прошла успешно!\n";
	SetColor(7, 0);
	system("PAUSE");
	system("cls");
}
// ######################### ОТМЕНА ОПЕРАЦИИ ########################
template<typename T>
inline void ConsoleUI<T>::OperationCancel()
{
	SetColor(12, 0);
	cout << "Операция отменена.\n";
	SetColor(7, 0);
	system("PAUSE");
	system("cls");
}
// ########################### ИНФО О ЛАБЕ ##########################
template<typename T>
inline void ConsoleUI<T>::LabInfo()
{
	SetColor(9, 0);
	cout << "  Лабораторная работа №12: \"STL контейнеры\"  *Выполнил: Пумня Александр\n";
	SetColor(7, 0);
}
// ################## ПРОВЕРКА ПРАВИЛЬНОСТИ ВЫБОРА ##################
template<typename T>
inline bool ConsoleUI<T>::CheckSelect(int b, int e, int i)
{
	if (i < b || i > e)
	{
		SetColor(12, 0);
		cout << "\nВы ошиблись. Введите число от " << b << " до " << e << endl;
		SetColor(7, 0);
		system("PAUSE");
		system("cls");
		return false;
	}
	return true;
}

#include "Vector.hpp" // Реализация функций над Вектором

#include "Set.hpp" // Реализация функций над Сетом

#include "List.hpp" // Реализация функций над Списком

#include "Map.hpp" // Реализация функций над Мапом