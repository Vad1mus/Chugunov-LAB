#pragma once
#include "Dialog.h"

// ####################### ОПЕРАЦИИ НАД МАПОМ #######################
template<typename T>
inline void ConsoleUI<T>::DoMapOperation(int ch)
{
	do {
		ChoseMap();
		ch = OperationSelect();
		switch (ch)
		{
		case 1:
			AddToMap();
			break;

		case 2:
			DelFromMap();
			break;

		case 3:
			MapGet();
			break;

		case 4:
			MapShow();
			break;

		case 0:
			return;
		}
	} while (ch);
}
// ######################## ДОБАВЛЕНИЕ В МАП ########################
template<typename T>
inline void ConsoleUI<T>::AddToMap()
{
	T value;
	int key;
	cout << "\nВведите ключ: ";
	cin >> key;
	cout << "Введите значение для добавления: ";
	cin >> value;
	Map.emplace(key, value);
	OperationPass();
}
// ######################## УДАЛЕНИЕ ИЗ МАПА ########################
template<typename T>
inline void ConsoleUI<T>::DelFromMap()
{
	if (NoMapData())
		return;
	int key;
	cout << "\nВведите ключ для удаления: ";
	cin >> key;
	auto iterator = Map.find(key);
	if (iterator == Map.end())
	{
		SetColor(12, 0);
		cout << "Данных с таким ключом нет в контейнере.\n";
		SetColor(7, 0);
		system("PAUSE");
		system("cls");
		return;
	}
	Map.erase(iterator);
	OperationPass();
}
// #################### ПОЛУЧЕНИЕ ДАННЫХ ИЗ МАПА ####################
template<typename T>
inline T ConsoleUI<T>::MapGet()
{
	if (NoMapData())
		return T();
	int key;
	cout << "\nВведите ключ для поиска: ";
	cin >> key;
	auto iterator = Map.find(key);
	if (iterator == Map.end())
	{
		SetColor(12, 0);
		cout << "Данных с таким ключом нет в контейнере.\n";
		SetColor(7, 0);
		system("PAUSE");
		system("cls");
		return T();
	}
	cout << "Данные по ключу: " << Map[key] << endl;
	OperationPass();
	return Map[key];
}
// ########################### ВЫВОД МАПА ###########################
template<typename T>
inline void ConsoleUI<T>::MapShow()
{
	if (NoMapData())
		return;
	cout << endl;
	for (auto &i : Map)
		cout << '[' << i.first << "] : " << i.second << endl;
	OperationPass();
}
// ######################## НЕТ ДАННЫХ МАПА #########################
template<typename T>
inline bool ConsoleUI<T>::NoMapData()
{
	if (!Map.size())
	{
		SetColor(12, 0);
		cout << "\nДанные отсутствуют!\n";
		SetColor(7, 0);
		system("PAUSE");
		system("cls");
		return true;
	}
	return false;
}
// ########################### ВЫБОР МАПА ###########################
template<typename T>
inline void ConsoleUI<T>::ChoseMap()
{
	system("cls");
	LabInfo();
	cout << "Выбран контейнер: ";
	SetColor(11, 0);
	cout << "map\n";
	SetColor(7, 0);
}
