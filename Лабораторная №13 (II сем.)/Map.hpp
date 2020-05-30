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

		case 5:
			MapCount(ch);
			break;

		case 6:
			MapFind(ch);
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
// ####################### ПОДСЧЕТ ЭЛЕМЕНТОВ ########################
template<typename T>
inline void ConsoleUI<T>::MapCount(int ch)
{
	if (NoMapData())
		return;
	T value;
	int key;
	int count;
	do
	{
		ChoseMap();
		cout << "Выберите критерий подсчета:\n";
		cout << "1. Посчитать все элементы, которые больше заданого по ЗНАЧЕНИЮ.\n";
		cout << "2. Посчитать все элементы, которые меньше заданого по ЗНАЧЕНИЮ.\n";
		cout << "3. Посчитать все элементы, которые равны заданомупо ЗНАЧЕНИЮ.\n";
		cout << "4. Посчитать все элементы, которые больше заданого по КЛЮЧУ.\n";
		cout << "5. Посчитать все элементы, которые меньше заданого по КЛЮЧУ.\n";
		cout << "6. Посчитать все элементы, которые равны заданомупо КЛЮЧУ.\n";
		cout << "7. Посчитать все элементы, которые больше заданого по КЛЮЧУ и ЗНАЧЕНИЮ.\n";
		cout << "8. Посчитать все элементы, которые меньше заданого по КЛЮЧУ и ЗНАЧЕНИЮ.\n";
		cout << "9. Посчитать все элементы, которые равны заданомупо КЛЮЧУ и ЗНАЧЕНИЮ.\n";
		cout << "0. Отмена.\n";
		cout << "Введите ваш ответ сюда: ";
		cin >> ch;
	} while (!CheckSelect(0, 9, ch));
	switch (ch)
	{
	case 1:
		cout << "\nЗадайте значение: ";
		cin >> value;
		count = count_if(Map.begin(), Map.end(), [&value](std::pair<int, T > elem) { return value < elem.second; });
		cout << "\n\nКоличество элементов, подходящих по критерию: " << count << endl;
		OperationPass();
		break;

	case 2:
		cout << "\nЗадайте значение: ";
		cin >> value;
		count = count_if(Map.begin(), Map.end(), [&value](std::pair<int, T > elem) { return value > elem.second; });
		cout << "\n\nКоличество элементов, подходящих по критерию: " << count << endl;
		OperationPass();
		break;

	case 3:
		cout << "\nЗадайте значение: ";
		cin >> value;
		count = count_if(Map.begin(), Map.end(), [&value](std::pair<int, T > elem) { return value == elem.second; });
		cout << "\n\nКоличество элементов, подходящих по критерию: " << count << endl;
		OperationPass();
		break;

	case 4:
		cout << "\nВведите ключ: ";
		cin >> key;
		count = count_if(Map.begin(), Map.end(), [&key](std::pair<int, T > elem) { return key < elem.first; });
		cout << "\n\nКоличество элементов, подходящих по критерию: " << count << endl;
		OperationPass();
		break;

	case 5:
		cout << "\nВведите ключ: ";
		cin >> key;
		count = count_if(Map.begin(), Map.end(), [&key](std::pair<int, T > elem) { return key > elem.first; });
		cout << "\n\nКоличество элементов, подходящих по критерию: " << count << endl;
		OperationPass();
		break;

	case 6:
		cout << "\nВведите ключ: ";
		cin >> key;
		count = count_if(Map.begin(), Map.end(), [&key](std::pair<int, T > elem) { return key == elem.first; });
		cout << "\n\nКоличество элементов, подходящих по критерию: " << count << endl;
		OperationPass();
		break;
	case 7:
		cout << "\nВведите ключ: ";
		cin >> key;
		cout << "\nЗадайте значение: ";
		cin >> value;
		count = count_if(Map.begin(), Map.end(), [&value, &key](std::pair<int, T > elem) { return value < elem.second && key < elem.first; });
		cout << "\n\nКоличество элементов, подходящих по критерию: " << count << endl;
		OperationPass();
		break;

	case 8:
		cout << "\nВведите ключ: ";
		cin >> key;
		cout << "\nЗадайте значение: ";
		cin >> value;
		count = count_if(Map.begin(), Map.end(), [&value, &key](std::pair<int, T > elem) { return value > elem.second && key > elem.first; });
		cout << "\n\nКоличество элементов, подходящих по критерию: " << count << endl;
		OperationPass();
		break;

	case 9:
		cout << "\nВведите ключ: ";
		cin >> key;
		cout << "\nЗадайте значение: ";
		cin >> value;
		count = count_if(Map.begin(), Map.end(), [&value, &key](std::pair<int, T > elem) { return value == elem.second && key == elem.first; });
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
inline void ConsoleUI<T>::MapFind(int ch)
{
	if (NoMapData())
		return;
	map<int, T> temp;
	T value;
	int key;

	int count;
	do
	{
		ChoseMap();
		cout << "Выберите критерий подсчета:\n";
		cout << "1. Найти все элементы, которые больше заданого по ЗНАЧЕНИЮ.\n";
		cout << "2. Найти все элементы, которые меньше заданого по ЗНАЧЕНИЮ.\n";
		cout << "3. Найти все элементы, которые равны заданомупо ЗНАЧЕНИЮ.\n";
		cout << "4. Найти все элементы, которые больше заданого по КЛЮЧУ.\n";
		cout << "5. Найти все элементы, которые меньше заданого по КЛЮЧУ.\n";
		cout << "6. Найти все элементы, которые равны заданомупо КЛЮЧУ.\n";
		cout << "7. Найти все элементы, которые больше заданого по КЛЮЧУ и ЗНАЧЕНИЮ.\n";
		cout << "8. Найти все элементы, которые меньше заданого по КЛЮЧУ и ЗНАЧЕНИЮ.\n";
		cout << "9. Найти все элементы, которые равны заданомупо КЛЮЧУ и ЗНАЧЕНИЮ.\n";
		cout << "0. Отмена.\n";
		cout << "Введите ваш ответ сюда: ";
		cin >> ch;
	} while (!CheckSelect(0, 9, ch));
	switch (ch)
	{
	case 1:
		cout << "\nЗадайте значение: ";
		cin >> value;
		copy_if(Map.begin(), Map.end(), inserter(temp, temp.end()), [&value](std::pair<int, T > elem) { return value < elem.second; });
		cout << "\n\nСписок элементов, подходящих по критерию:\n";
		for_each(temp.begin(), temp.end(), Print_Map<T>);
		cout << endl;
		OperationPass();
		break;

	case 2:
		cout << "\nЗадайте значение: ";
		cin >> value;
		copy_if(Map.begin(), Map.end(), inserter(temp, temp.end()), [&value](std::pair<int, T > elem) { return value > elem.second; });
		cout << "\n\nСписок элементов, подходящих по критерию:\n";
		for_each(temp.begin(), temp.end(), Print_Map<T>);
		cout << endl;
		OperationPass();
		break;

	case 3:
		cout << "\nЗадайте значение: ";
		cin >> value;
		copy_if(Map.begin(), Map.end(), inserter(temp, temp.end()), [&value](std::pair<int, T > elem) { return value == elem.second; });
		cout << "\n\nСписок элементов, подходящих по критерию:\n";
		for_each(temp.begin(), temp.end(), Print_Map<T>);
		cout << endl;
		OperationPass();
		break;

	case 4:
		cout << "\nВведите ключ: ";
		cin >> key;
		copy_if(Map.begin(), Map.end(), inserter(temp, temp.end()), [&key](std::pair<int, T > elem) { return key < elem.first; });
		cout << "\n\nСписок элементов, подходящих по критерию:\n";
		for_each(temp.begin(), temp.end(), Print_Map<T>);
		cout << endl;
		OperationPass();
		break;

	case 5:
		cout << "\nВведите ключ: ";
		cin >> key;
		copy_if(Map.begin(), Map.end(), inserter(temp, temp.end()), [&key](std::pair<int, T > elem) { return key > elem.first; });
		cout << "\n\nСписок элементов, подходящих по критерию:\n";
		for_each(temp.begin(), temp.end(), Print_Map<T>);
		cout << endl;
		OperationPass();
		break;

	case 6:
		cout << "\nВведите ключ: ";
		cin >> key;
		copy_if(Map.begin(), Map.end(), inserter(temp, temp.end()), [&key](std::pair<int, T > elem) { return key == elem.first; });
		cout << "\n\nСписок элементов, подходящих по критерию:\n";
		for_each(temp.begin(), temp.end(), Print_Map<T>);
		cout << endl;
		OperationPass();
		break;

	case 7:
		cout << "\nВведите ключ: ";
		cin >> key;
		cout << "\nЗадайте значение: ";
		cin >> value;
		copy_if(Map.begin(), Map.end(), inserter(temp, temp.end()), [&value, &key](std::pair<int, T > elem) { return value < elem.second && key < elem.first; });
		cout << "\n\nСписок элементов, подходящих по критерию:\n";
		for_each(temp.begin(), temp.end(), Print_Map<T>);
		cout << endl;
		OperationPass();
		break;

	case 8:
		cout << "\nВведите ключ: ";
		cin >> key;
		cout << "\nЗадайте значение: ";
		cin >> value;
		copy_if(Map.begin(), Map.end(), inserter(temp, temp.end()), [&value, &key](std::pair<int, T > elem) { return value > elem.second && key > elem.first; });
		cout << "\n\nСписок элементов, подходящих по критерию:\n";
		for_each(temp.begin(), temp.end(), Print_Map<T>);
		cout << endl;
		OperationPass();
		break;

	case 9:
		cout << "\nВведите ключ: ";
		cin >> key;
		cout << "\nЗадайте значение: ";
		cin >> value;
		copy_if(Map.begin(), Map.end(), inserter(temp, temp.end()), [&value, &key](std::pair<int, T > elem) { return value == elem.second && key == elem.first; });
		cout << "\n\nСписок элементов, подходящих по критерию:\n";
		for_each(temp.begin(), temp.end(), Print_Map<T>);
		cout << endl;
		OperationPass();
		break;

	case 0:
		cout << endl;
		OperationCancel();
	}
}
// ########################### ВЫВОД МАПА ###########################
template<typename T>
inline void ConsoleUI<T>::MapShow()
{
	if (NoMapData())
		return;
	cout << endl;
	for_each(Map.begin(), Map.end(), Print_Map<T>);
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