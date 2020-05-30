#pragma once
#include "Dialog.h"

// ###################### ОПЕРАЦИИ НАД СПИСКОМ ######################
template<typename T>
inline void ConsoleUI<T>::DoListOperation(int ch)
{
	do {
		ChoseList();
		ch = OperationSelect();
		switch (ch)
		{
		case 1:
			AddToList(ch);
			break;

		case 2:
			DelFromList(ch);
			break;

		case 3:
			ListGet(ch);
			break;

		case 4:
			ListShow();
			break;

		case 5:
			ListCount(ch);
			break;

		case 6:
			ListFind(ch);
			break;
			
		case 7:
			SetColor(12, 0);
			cout << "\nФункция не реализована в данном контейнере.\n";
			SetColor(7, 0);
			system("Pause");
			system("cls");
			break;

		case 8:
			ListSort(ch);
			break;

		case 0:
			return;
		}
	} while (ch);
}
// ###################### ДОБАВЛЕНИЕ В СПИСОЕ #######################
template<typename T>
inline void ConsoleUI<T>::AddToList(int ch)
{
	T value;
	int index;
	auto iterator = List.begin();
	do
	{
		ChoseList();
		cout << "Выберите способ добавления:\n";
		cout << "1. Добавление в начало.\n";
		cout << "2. Вставка.\n";
		cout << "3. Добавление в конец.\n";
		cout << "0. Отмена.\n";
		cout << "Введите ваш ответ сюда: ";
		cin >> ch;
	} while (!CheckSelect(0, 3, ch));
	switch (ch)
	{
	case 1:
		cout << "\nВведите значение для добавления: ";
		cin >> value;
		List.push_front(value);
		OperationPass();
		break;

	case 2:
		cout << "\nВведите значение для добавления: ";
		cin >> value;
		do
		{
			cout << "Введите индекс: ";
			cin >> index;
			if (index > List.size() || index < 0)
			{
				SetColor(12, 0);
				cout << "Вы ошиблись. Введите число от 0 до " << List.size() << endl;
				SetColor(7, 0);
			}
		} while (index > List.size() || index < 0);
		std::advance(iterator, index);
		List.insert(iterator, value);
		OperationPass();
		break;

	case 3:
		cout << "\nВведите значение для добавления: ";
		cin >> value;
		List.push_back(value);
		OperationPass();
		break;
	case 0:
		cout << endl;
		OperationCancel();
	}
}
// ####################### УДАЛЕНИЕ ИЗ СПИСКА #######################
template<typename T>
inline void ConsoleUI<T>::DelFromList(int ch)
{
	if (NoListData())
		return;
	int index;
	auto iterator = List.begin();
	do
	{
		ChoseList();
		cout << "Выберите способ удаления:\n";
		cout << "1. Удаление с начала.\n";
		cout << "2. Удаление по индексу.\n";
		cout << "3. Удаление с конца.\n";
		cout << "0. Отмена.\n";
		cout << "Введите ваш ответ сюда: ";
		cin >> ch;
	} while (!CheckSelect(0, 3, ch));
	switch (ch)
	{
	case 1:
		List.pop_front();
		cout << endl;
		OperationPass();
		break;

	case 2:
		do
		{
			cout << "Введите индекс: ";
			cin >> index;
			if (index >= List.size() || index < 0)
			{
				SetColor(12, 0);
				cout << "Вы ошиблись. Введите число от 0 до " << List.size() - 1 << endl;
				SetColor(7, 0);
			}
		} while (index > List.size() || index < 0);
		std::advance(iterator, index);
		List.erase(iterator);
		OperationPass();
		break;

	case 3:
		List.pop_back();
		cout << endl;
		OperationPass();
		break;

	case 0:
		cout << endl;
		OperationCancel();
	}
}
// ################### ПОЛУЧЕНИЕ ДАННЫХ ИЗ СПИСКА ###################
template<typename T>
inline T ConsoleUI<T>::ListGet(int ch)
{
	if (NoListData())
		return T();
	int index;
	auto iterator = List.begin();
	do
	{
		ChoseList();
		cout << "Выберите вариант получения:\n";
		cout << "1. Вывести первый элемент.\n";
		cout << "2. Вывести элемент по индексу.\n";
		cout << "3. Вывести последний элемент.\n";
		cout << "0. Отмена.\n";
		cout << "Введите ваш ответ сюда: ";
		cin >> ch;
	} while (!CheckSelect(0, 3, ch));
	switch (ch)
	{
	case 1:
		cout << endl << List.front() << endl;
		OperationPass();
		return List.front();
		break;

	case 2:
		do
		{
			cout << "Введите индекс: ";
			cin >> index;
			if (index >= List.size() || index < 0)
			{
				SetColor(12, 0);
				cout << "Вы ошиблись. Введите число от 0 до " << List.size() - 1 << endl;
				SetColor(7, 0);
			}
		} while (index > List.size() || index < 0);
		advance(iterator, index);
		cout << endl << *iterator << endl;
		OperationPass();
		return *iterator;
		break;

	case 3:
		cout << endl << List.back() << endl;
		OperationPass();
		return List.back();
		break;

	case 0:
		cout << endl;
		OperationCancel();
	}
	return T();
}
// ####################### ПОДСЧЕТ ЭЛЕМЕНТОВ ########################
template<typename T>
inline void ConsoleUI<T>::ListCount(int ch)
{
	if (NoListData())
		return;
	T value;
	int count;
	do
	{
		ChoseList();
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
		count = count_if(List.begin(), List.end(), [&value](const T &elem) { return value < elem; });
		cout << "\n\nКоличество элементов, подходящих по критерию: " << count << endl;
		OperationPass();
		break;

	case 2:
		cout << "\nЗадайте значение: ";
		cin >> value;
		count = count_if(List.begin(), List.end(), [&value](const T &elem) { return value > elem; });
		cout << "\n\nКоличество элементов, подходящих по критерию: " << count << endl;
		OperationPass();
		break;

	case 3:
		cout << "\nЗадайте значение: ";
		cin >> value;
		count = count_if(List.begin(), List.end(), [&value](const T &elem) { return value == elem; });
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
inline void ConsoleUI<T>::ListFind(int ch)
{
	if (NoListData())
		return;
	T value;
	list<T> temp;
	do
	{
		ChoseList();
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
		copy_if(List.begin(), List.end(), back_inserter(temp), [&value](const T &elem) { return value < elem; });
		cout << "\n\nСписок элементов, подходящих по критерию:\n";
		for_each(temp.begin(), temp.end(), Print_Pred<T>);
		cout << endl;
		OperationPass();
		break;

	case 2:
		cout << "\nЗадайте значение: ";
		cin >> value;
		copy_if(List.begin(), List.end(), back_inserter(temp), [&value](const T &elem) { return value > elem; });
		cout << "\n\nСписок элементов, подходящих по критерию:\n";
		for_each(temp.begin(), temp.end(), Print_Pred<T>);
		cout << endl;
		OperationPass();
		break;

	case 3:
		cout << "\nЗадайте значение: ";
		cin >> value;
		copy_if(List.begin(), List.end(), back_inserter(temp), [&value](const T &elem) { return value == elem; });
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
// ####################### СОРТИРОВКА СПИСКА ########################
template<typename T>
inline void ConsoleUI<T>::ListSort(int ch)
{
	if (NoListData())
		return;
	SortingMinMax<T> minmax;
	SortingMaxMin<T> maxmin;
	do
	{
		ChoseList();
		cout << "Выберите критерий сортировки:\n";
		cout << "1. Сортировка по возрастанию.\n";
		cout << "2. Сортировка по убыванию.\n";
		cout << "0. Отмена.\n";
		cout << "Введите ваш ответ сюда: ";
		cin >> ch;
	} while (!CheckSelect(0, 2, ch));
	switch (ch)
	{
	case 1:
		List.sort(minmax);
		cout << endl;
		OperationPass();
		break;
	case 2:
		List.sort(maxmin);
		cout << endl;
		OperationPass();
		break;

	case 0:
		cout << endl;
		OperationCancel();
	}
}
// ########################## ВЫВОД СПИСКА ##########################
template<typename T>
inline void ConsoleUI<T>::ListShow()
{
	if (NoListData())
		return;
	cout << endl;
	for_each(List.begin(), List.end(), Print_Pred<T>);
	cout << endl;
	OperationPass();
}
// ####################### НЕТ ДАННЫХ СПИСКА ########################
template<typename T>
inline bool ConsoleUI<T>::NoListData()
{
	if (!List.size())
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
// ########################## ВЫБОР СПИСКА ##########################
template<typename T>
inline void ConsoleUI<T>::ChoseList()
{
	system("cls");
	LabInfo();
	cout << "Выбран контейнер: ";
	SetColor(11, 0);
	cout << "list\n";
	SetColor(7, 0);
}