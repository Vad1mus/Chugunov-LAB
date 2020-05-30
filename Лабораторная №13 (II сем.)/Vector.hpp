#pragma once
#include "Dialog.h"

// ##################### ОПЕРАЦИИ НАД ВЕКТОРОМ ######################
template<typename T>
inline void ConsoleUI<T>::DoVectorOperation(int ch)
{
	do {
		ChoseVector();
		ch = OperationSelect();
		switch (ch)
		{
		case 1:
			AddToVector(ch);
			break;

		case 2:
			DelFromVector(ch);
			break;

		case 3:
			VectorGet(ch);
			break;

		case 4:
			VectorShow();
			break;

		case 5:
			VectorCount(ch);
			break;

		case 6:
			VectorFind(ch);
			break;

		case 0:
			return;
		}
	} while (ch);
}
// ###################### ДАБАВЛЕНИЕ В ВЕКТОР #######################
template<typename T>
inline void ConsoleUI<T>::AddToVector(int ch)
{
	T value;
	int index;
	auto iterator = Vector.begin();
	do
	{
		ChoseVector();
		cout << "Выберите способ добавления:\n";
		cout << "1. Добавление в конец.\n";
		cout << "2. Вставка.\n";
		cout << "0. Отмена.\n";
		cout << "Введите ваш ответ сюда: ";
		cin >> ch;
	} while (!CheckSelect(0, 2, ch));
	switch (ch)
	{
	case 1:
		cout << "\nВведите значение для добавления: ";
		cin >> value;
		Vector.push_back(value);
		OperationPass();
		break;

	case 2:
		cout << "\nВведите значение для добавления: ";
		cin >> value;
		do
		{
			cout << "Введите индекс: ";
			cin >> index;
			if (index > Vector.size() || index < 0)
			{
				SetColor(12, 0);
				cout << "Вы ошиблись. Введите число от 0 до " << Vector.size() << endl;
				SetColor(7, 0);
			}
		} while (index > Vector.size() || index < 0);
		std::advance(iterator, index);
		Vector.insert(iterator, value);
		OperationPass();
		break;

	case 0:
		cout << endl;
		OperationCancel();
	}
}
// ###################### УДАЛЕНИЕ ИЗ ВЕКТОРА #######################
template<typename T>
inline void ConsoleUI<T>::DelFromVector(int ch)
{
	if (NoVectorData())
		return;
	int index;
	auto iterator = Vector.begin();
	do
	{
		ChoseVector();
		cout << "Выберите способ удаления:\n";
		cout << "1. Удаление с конца.\n";
		cout << "2. Удаление по индексу.\n";
		cout << "0. Отмена.\n";
		cout << "Введите ваш ответ сюда: ";
		cin >> ch;
	} while (!CheckSelect(0, 2, ch));
	switch (ch)
	{
	case 1:
		Vector.pop_back();
		cout << endl;
		OperationPass();
		break;

	case 2:
		do
		{
			cout << "Введите индекс: ";
			cin >> index;
			if (index >= Vector.size() || index < 0)
			{
				SetColor(12, 0);
				cout << "Вы ошиблись. Введите число от 0 до " << Vector.size() - 1 << endl;
				SetColor(7, 0);
			}
		} while (index > Vector.size() || index < 0);
		std::advance(iterator, index);
		Vector.erase(iterator);
		OperationPass();
		break;

	case 0:
		cout << endl;
		OperationCancel();
	}
}
// ################## ПОЛУЧЕНИЕ ДАННЫХ ИЗ ВЕКТОРА ###################
template<typename T>
inline T ConsoleUI<T>::VectorGet(int ch)
{
	if (NoVectorData())
		return T();
	int index;
	auto iterator = Vector.begin();
	do
	{
		ChoseVector();
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
		cout << endl << Vector.front() << endl;
		OperationPass();
		return Vector.front();
		break;

	case 2:
		do
		{
			cout << "Введите индекс: ";
			cin >> index;
			if (index >= Vector.size() || index < 0)
			{
				SetColor(12, 0);
				cout << "Вы ошиблись. Введите число от 0 до " << Vector.size() - 1 << endl;
				SetColor(7, 0);
			}
		} while (index > Vector.size() || index < 0);
		cout << endl << Vector[index] << endl;
		OperationPass();
		return Vector[index];
		break;

	case 3:
		cout << endl << Vector.back() << endl;
		OperationPass();
		return Vector.back();
		break;

	case 0:
		cout << endl;
		OperationCancel();
	}
	return T();
}
// ####################### ПОДСЧЕТ ЭЛЕМЕНТОВ ########################
template<typename T>
inline void ConsoleUI<T>::VectorCount(int ch)
{
	if (NoVectorData())
		return;
	T value;
	int count;
	do
	{
		ChoseVector();
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
		count = count_if(Vector.begin(), Vector.end(), [&value](const T &elem) { return value < elem; });
		cout << "\n\nКоличество элементов, подходящих по критерию: " << count << endl;
		OperationPass();
		break;

	case 2:
		cout << "\nЗадайте значение: ";
		cin >> value;
		count = count_if(Vector.begin(), Vector.end(), [&value](const T &elem) { return value > elem; });
		cout << "\n\nКоличество элементов, подходящих по критерию: " << count << endl;
		OperationPass();
		break;

	case 3:
		cout << "\nЗадайте значение: ";
		cin >> value;
		count = count_if(Vector.begin(), Vector.end(), [&value](const T &elem) { return value == elem; });
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
inline void ConsoleUI<T>::VectorFind(int ch)
{
	if (NoVectorData())
		return;
	T value;
	vector<T> temp;
	do
	{
		ChoseVector();
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
		copy_if(Vector.begin(), Vector.end(), back_inserter(temp) , [&value](const T &elem) { return value < elem; });
		cout << "\n\nСписок элементов, подходящих по критерию:\n";
		for_each(temp.begin(), temp.end(), Print_Pred<T>);
		cout << endl;
		OperationPass();
		break;

	case 2:
		cout << "\nЗадайте значение: ";
		cin >> value;
		copy_if(Vector.begin(), Vector.end(), back_inserter(temp), [&value](const T &elem) { return value > elem; });
		cout << "\n\nСписок элементов, подходящих по критерию:\n";
		for_each(temp.begin(), temp.end(), Print_Pred<T>);
		cout << endl;
		OperationPass();
		break;

	case 3:
		cout << "\nЗадайте значение: ";
		cin >> value;
		copy_if(Vector.begin(), Vector.end(), back_inserter(temp), [&value](const T &elem) { return value == elem; });
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
// ######################### ВЫВОД ВЕКТОРА ##########################
template<typename T>
inline void ConsoleUI<T>::VectorShow()
{
	if (NoVectorData())
		return;
	cout << endl;
	for_each(Vector.begin(), Vector.end(), Print_Pred<T>);
	cout << endl;
	OperationPass();
}
// ####################### НЕТ ДАННЫХ ВЕКТОРА #######################
template<typename T>
inline bool ConsoleUI<T>::NoVectorData()
{
	if (!Vector.size())
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
// ######################### ВЫБОР ВЕКТОРА ##########################
template<typename T>
inline void ConsoleUI<T>::ChoseVector()
{
	system("cls");
	LabInfo();
	cout << "Выбран контейнер: ";
	SetColor(11, 0);
	cout << "vector\n";
	SetColor(7, 0);
}