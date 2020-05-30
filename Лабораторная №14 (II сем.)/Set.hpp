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

		case 5:
			SetCount(ch);
			break;

		case 6:
			SetFind(ch);
			break;

		case 7:
			SetColor(12, 0);
			cout << "\nФункция не реализована в данном контейнере.\n";
			SetColor(7, 0);
			system("Pause");
			system("cls");
			break;

		case 8:
			SetColor(12, 0);
			cout << "\nКонтейнер не поддрерживает сортировки.\n";
			SetColor(7, 0);
			system("Pause");
			system("cls");
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
// ####################### ПОДСЧЕТ ЭЛЕМЕНТОВ ########################
template<typename T>
inline void ConsoleUI<T>::SetCount(int ch)
{
	if (NoSetData())
		return;
	T value;
	int count;
	do
	{
		ChoseSet();
		cout << "Выберите критерий подсчета:\n";
		cout << "1. Посчитать все элементы, которые больше заданого.\n";
		cout << "2. Посчитать все элементы, которые меньше заданого.\n";
		cout << "3. Посчитать все элементы, которые равны заданому.\n";
		cout << "0. Отмена.\n";
		cout << "Введите ваш ответ сюда: ";
		cin >> ch;
	} while (!CheckSelect(0, 3, ch));
	switch (ch)
	{
	case 1:
		cout << "\nЗадайте значение: ";
		cin >> value;
		count = count_if(Set.begin(), Set.end(), [&value](const T &elem) { return value < elem; });
		cout << "\n\nКоличество элементов, подходящих по критерию: " << count << endl;
		OperationPass();
		break;

	case 2:
		cout << "\nЗадайте значение: ";
		cin >> value;
		count = count_if(Set.begin(), Set.end(), [&value](const T &elem) { return value > elem; });
		cout << "\n\nКоличество элементов, подходящих по критерию: " << count << endl;
		OperationPass();
		break;

	case 3:
		cout << "\nЗадайте значение: ";
		cin >> value;
		count = count_if(Set.begin(), Set.end(), [&value](const T &elem) { return value == elem; });
		cout << "\n\nКоличество элементов, подходящих по критерию: " << count << endl;
		OperationPass();
		break;

	case 0:
		cout << endl;
		OperationCancel();
	}
}
// ######################## ПОИСК ЭЛЕМЕНТОВ #########################
template<typename T>
inline void ConsoleUI<T>::SetFind(int ch)
{
	if (NoSetData())
		return;
	T value;
	set<T> temp;
	do
	{
		ChoseSet();
		cout << "Выберите критерий подсчета:\n";
		cout << "1. Найти все элементы, которые больше заданого.\n";
		cout << "2. Найти все элементы, которые меньше заданого.\n";
		cout << "3. Найти все элементы, которые равны заданому.\n";
		cout << "0. Отмена.\n";
		cout << "Введите ваш ответ сюда: ";
		cin >> ch;
	} while (!CheckSelect(0, 3, ch));
	switch (ch)
	{
	case 1:
		cout << "\nЗадайте значение: ";
		cin >> value;
		copy_if(Set.begin(), Set.end(), inserter(temp, temp.end()), [&value](const T &elem) { return value < elem; });
		cout << "\n\nСписок элементов, подходящих по критерию:\n";
		for_each(temp.begin(), temp.end(), Print_Pred<T>);
		cout << endl;
		OperationPass();
		break;

	case 2:
		cout << "\nЗадайте значение: ";
		cin >> value;
		copy_if(Set.begin(), Set.end(), inserter(temp, temp.end()), [&value](const T &elem) { return value > elem; });
		cout << "\n\nСписок элементов, подходящих по критерию:\n";
		for_each(temp.begin(), temp.end(), Print_Pred<T>);
		cout << endl;
		OperationPass();
		break;

	case 3:
		cout << "\nЗадайте значение: ";
		cin >> value;
		copy_if(Set.begin(), Set.end(), inserter(temp, temp.end()), [&value](const T &elem) { return value == elem; });
		cout << "\n\nСписок элементов, подходящих по критерию:\n";
		for_each(temp.begin(), temp.end(), Print_Pred<T>);
		cout << endl;
		OperationPass();
		break;

	case 0:
		cout << endl;
		OperationCancel();
	}
}
// ########################### ВЫВОД СЕТА ###########################
template<typename T>
inline void ConsoleUI<T>::SetShow()
{
	if (NoSetData())
		return;
	cout << endl;
	for_each(Set.begin(), Set.end(), Print_Pred<T>);
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