#pragma once
#include "Dialog.h"

// ####################### ОПЕРАЦИИ НАД СЕТОМ #######################
template<typename T>
inline void ConsoleUI<T>::DoSetOperation(int ch)
{
	do {
		ChoseSet();
		ch = OperationSelect();
		switch (ch)
		{
		case 1:
			AddToSet();
			break;

		case 2:
			DelFromSet();
			break;

		case 3:
			SetGet();
			break;

		case 4:
			SetShow();
			break;

		case 0:
			return;
		}
	} while (ch);
}
// ######################## ДОБАВЛЕНИЕ В СЕТ ########################
template<typename T>
inline void ConsoleUI<T>::AddToSet()
{
	T value;
	cout << "\nВведите данные для добавления: ";
	cin >> value;
	Set.insert(value);
	OperationPass();
}
// ######################## УДАЛЕНИЕ ИЗ СЕТА ########################
template<typename T>
inline void ConsoleUI<T>::DelFromSet()
{
	if (NoSetData())
		return;
	T value;
	cout << "\nВведите удаляемые данные: ";
	cin >> value;
	auto iterator = Set.find(value);
	if (iterator == Set.end())
	{
		SetColor(12, 0);
		cout << "Данных с таким значением нет в контейнере.\n";
		SetColor(7, 0);
		system("PAUSE");
		system("cls");
		return;
	}
	Set.erase(iterator);
	OperationPass();
}
// #################### ПОЛУЧЕНИЕ ДАННЫХ ИЗ СЕТА ####################
template<typename T>
inline T ConsoleUI<T>::SetGet()
{
	if (NoSetData())
		return T();
	T value;
	cout << "\nВведите искомые данные: ";
	cin >> value;
	auto iterator = Set.find(value);
	if (iterator == Set.end())
	{
		SetColor(12, 0);
		cout << "Данных с таким значением нет в контейнере.\n";
		SetColor(7, 0);
		system("PAUSE");
		system("cls");
		return T();
	}
	cout << "Данные с таким значением есть в контейнере и успешно возвращены!\n";
	OperationPass();
	return *iterator;
}
// ########################### ВЫВОД СЕТА ###########################
template<typename T>
inline void ConsoleUI<T>::SetShow()
{
	if (NoSetData())
		return;
	cout << endl;
	for (auto &i : Set)
		cout << i << " ";
	cout << endl;
	OperationPass();
}
// ######################## НЕТ ДАННЫХ СЕТА #########################
template<typename T>
inline bool ConsoleUI<T>::NoSetData()
{
	if (!Set.size())
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
// ########################### ВЫБОР СЕТА ###########################
template<typename T>
inline void ConsoleUI<T>::ChoseSet()
{
	system("cls");
	LabInfo();
	cout << "Выбран контейнер: ";
	SetColor(11, 0);
	cout << "set\n";
	SetColor(7, 0);
}