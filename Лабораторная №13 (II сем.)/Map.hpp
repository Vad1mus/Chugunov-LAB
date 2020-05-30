#pragma once
#include "Dialog.h"

// ####################### �������� ��� ����� #######################
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
// ######################## ���������� � ��� ########################
template<typename T>
inline void ConsoleUI<T>::AddToMap()
{
	T value;
	int key;
	cout << "\n������� ����: ";
	cin >> key;
	cout << "������� �������� ��� ����������: ";
	cin >> value;
	Map.emplace(key, value);
	OperationPass();
}
// ######################## �������� �� ���� ########################
template<typename T>
inline void ConsoleUI<T>::DelFromMap()
{
	if (NoMapData())
		return;
	int key;
	cout << "\n������� ���� ��� ��������: ";
	cin >> key;
	auto iterator = Map.find(key);
	if (iterator == Map.end())
	{
		SetColor(12, 0);
		cout << "������ � ����� ������ ��� � ����������.\n";
		SetColor(7, 0);
		system("PAUSE");
		system("cls");
		return;
	}
	Map.erase(iterator);
	OperationPass();
}
// #################### ��������� ������ �� ���� ####################
template<typename T>
inline T ConsoleUI<T>::MapGet()
{
	if (NoMapData())
		return T();
	int key;
	cout << "\n������� ���� ��� ������: ";
	cin >> key;
	auto iterator = Map.find(key);
	if (iterator == Map.end())
	{
		SetColor(12, 0);
		cout << "������ � ����� ������ ��� � ����������.\n";
		SetColor(7, 0);
		system("PAUSE");
		system("cls");
		return T();
	}
	cout << "������ �� �����: " << Map[key] << endl;
	OperationPass();
	return Map[key];
}
// ####################### ������� ��������� ########################
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
		cout << "�������� �������� ��������:\n";
		cout << "1. ��������� ��� ��������, ������� ������ �������� �� ��������.\n";
		cout << "2. ��������� ��� ��������, ������� ������ �������� �� ��������.\n";
		cout << "3. ��������� ��� ��������, ������� ����� ���������� ��������.\n";
		cout << "4. ��������� ��� ��������, ������� ������ �������� �� �����.\n";
		cout << "5. ��������� ��� ��������, ������� ������ �������� �� �����.\n";
		cout << "6. ��������� ��� ��������, ������� ����� ���������� �����.\n";
		cout << "7. ��������� ��� ��������, ������� ������ �������� �� ����� � ��������.\n";
		cout << "8. ��������� ��� ��������, ������� ������ �������� �� ����� � ��������.\n";
		cout << "9. ��������� ��� ��������, ������� ����� ���������� ����� � ��������.\n";
		cout << "0. ������.\n";
		cout << "������� ��� ����� ����: ";
		cin >> ch;
	} while (!CheckSelect(0, 9, ch));
	switch (ch)
	{
	case 1:
		cout << "\n������� ��������: ";
		cin >> value;
		count = count_if(Map.begin(), Map.end(), [&value](std::pair<int, T > elem) { return value < elem.second; });
		cout << "\n\n���������� ���������, ���������� �� ��������: " << count << endl;
		OperationPass();
		break;

	case 2:
		cout << "\n������� ��������: ";
		cin >> value;
		count = count_if(Map.begin(), Map.end(), [&value](std::pair<int, T > elem) { return value > elem.second; });
		cout << "\n\n���������� ���������, ���������� �� ��������: " << count << endl;
		OperationPass();
		break;

	case 3:
		cout << "\n������� ��������: ";
		cin >> value;
		count = count_if(Map.begin(), Map.end(), [&value](std::pair<int, T > elem) { return value == elem.second; });
		cout << "\n\n���������� ���������, ���������� �� ��������: " << count << endl;
		OperationPass();
		break;

	case 4:
		cout << "\n������� ����: ";
		cin >> key;
		count = count_if(Map.begin(), Map.end(), [&key](std::pair<int, T > elem) { return key < elem.first; });
		cout << "\n\n���������� ���������, ���������� �� ��������: " << count << endl;
		OperationPass();
		break;

	case 5:
		cout << "\n������� ����: ";
		cin >> key;
		count = count_if(Map.begin(), Map.end(), [&key](std::pair<int, T > elem) { return key > elem.first; });
		cout << "\n\n���������� ���������, ���������� �� ��������: " << count << endl;
		OperationPass();
		break;

	case 6:
		cout << "\n������� ����: ";
		cin >> key;
		count = count_if(Map.begin(), Map.end(), [&key](std::pair<int, T > elem) { return key == elem.first; });
		cout << "\n\n���������� ���������, ���������� �� ��������: " << count << endl;
		OperationPass();
		break;
	case 7:
		cout << "\n������� ����: ";
		cin >> key;
		cout << "\n������� ��������: ";
		cin >> value;
		count = count_if(Map.begin(), Map.end(), [&value, &key](std::pair<int, T > elem) { return value < elem.second && key < elem.first; });
		cout << "\n\n���������� ���������, ���������� �� ��������: " << count << endl;
		OperationPass();
		break;

	case 8:
		cout << "\n������� ����: ";
		cin >> key;
		cout << "\n������� ��������: ";
		cin >> value;
		count = count_if(Map.begin(), Map.end(), [&value, &key](std::pair<int, T > elem) { return value > elem.second && key > elem.first; });
		cout << "\n\n���������� ���������, ���������� �� ��������: " << count << endl;
		OperationPass();
		break;

	case 9:
		cout << "\n������� ����: ";
		cin >> key;
		cout << "\n������� ��������: ";
		cin >> value;
		count = count_if(Map.begin(), Map.end(), [&value, &key](std::pair<int, T > elem) { return value == elem.second && key == elem.first; });
		cout << "\n\n���������� ���������, ���������� �� ��������: " << count << endl;
		OperationPass();
		break;

	case 0:
		cout << endl;
		OperationCancel();
	}
}
// ######################## ����� ��������� #########################
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
		cout << "�������� �������� ��������:\n";
		cout << "1. ����� ��� ��������, ������� ������ �������� �� ��������.\n";
		cout << "2. ����� ��� ��������, ������� ������ �������� �� ��������.\n";
		cout << "3. ����� ��� ��������, ������� ����� ���������� ��������.\n";
		cout << "4. ����� ��� ��������, ������� ������ �������� �� �����.\n";
		cout << "5. ����� ��� ��������, ������� ������ �������� �� �����.\n";
		cout << "6. ����� ��� ��������, ������� ����� ���������� �����.\n";
		cout << "7. ����� ��� ��������, ������� ������ �������� �� ����� � ��������.\n";
		cout << "8. ����� ��� ��������, ������� ������ �������� �� ����� � ��������.\n";
		cout << "9. ����� ��� ��������, ������� ����� ���������� ����� � ��������.\n";
		cout << "0. ������.\n";
		cout << "������� ��� ����� ����: ";
		cin >> ch;
	} while (!CheckSelect(0, 9, ch));
	switch (ch)
	{
	case 1:
		cout << "\n������� ��������: ";
		cin >> value;
		copy_if(Map.begin(), Map.end(), inserter(temp, temp.end()), [&value](std::pair<int, T > elem) { return value < elem.second; });
		cout << "\n\n������ ���������, ���������� �� ��������:\n";
		for_each(temp.begin(), temp.end(), Print_Map<T>);
		cout << endl;
		OperationPass();
		break;

	case 2:
		cout << "\n������� ��������: ";
		cin >> value;
		copy_if(Map.begin(), Map.end(), inserter(temp, temp.end()), [&value](std::pair<int, T > elem) { return value > elem.second; });
		cout << "\n\n������ ���������, ���������� �� ��������:\n";
		for_each(temp.begin(), temp.end(), Print_Map<T>);
		cout << endl;
		OperationPass();
		break;

	case 3:
		cout << "\n������� ��������: ";
		cin >> value;
		copy_if(Map.begin(), Map.end(), inserter(temp, temp.end()), [&value](std::pair<int, T > elem) { return value == elem.second; });
		cout << "\n\n������ ���������, ���������� �� ��������:\n";
		for_each(temp.begin(), temp.end(), Print_Map<T>);
		cout << endl;
		OperationPass();
		break;

	case 4:
		cout << "\n������� ����: ";
		cin >> key;
		copy_if(Map.begin(), Map.end(), inserter(temp, temp.end()), [&key](std::pair<int, T > elem) { return key < elem.first; });
		cout << "\n\n������ ���������, ���������� �� ��������:\n";
		for_each(temp.begin(), temp.end(), Print_Map<T>);
		cout << endl;
		OperationPass();
		break;

	case 5:
		cout << "\n������� ����: ";
		cin >> key;
		copy_if(Map.begin(), Map.end(), inserter(temp, temp.end()), [&key](std::pair<int, T > elem) { return key > elem.first; });
		cout << "\n\n������ ���������, ���������� �� ��������:\n";
		for_each(temp.begin(), temp.end(), Print_Map<T>);
		cout << endl;
		OperationPass();
		break;

	case 6:
		cout << "\n������� ����: ";
		cin >> key;
		copy_if(Map.begin(), Map.end(), inserter(temp, temp.end()), [&key](std::pair<int, T > elem) { return key == elem.first; });
		cout << "\n\n������ ���������, ���������� �� ��������:\n";
		for_each(temp.begin(), temp.end(), Print_Map<T>);
		cout << endl;
		OperationPass();
		break;

	case 7:
		cout << "\n������� ����: ";
		cin >> key;
		cout << "\n������� ��������: ";
		cin >> value;
		copy_if(Map.begin(), Map.end(), inserter(temp, temp.end()), [&value, &key](std::pair<int, T > elem) { return value < elem.second && key < elem.first; });
		cout << "\n\n������ ���������, ���������� �� ��������:\n";
		for_each(temp.begin(), temp.end(), Print_Map<T>);
		cout << endl;
		OperationPass();
		break;

	case 8:
		cout << "\n������� ����: ";
		cin >> key;
		cout << "\n������� ��������: ";
		cin >> value;
		copy_if(Map.begin(), Map.end(), inserter(temp, temp.end()), [&value, &key](std::pair<int, T > elem) { return value > elem.second && key > elem.first; });
		cout << "\n\n������ ���������, ���������� �� ��������:\n";
		for_each(temp.begin(), temp.end(), Print_Map<T>);
		cout << endl;
		OperationPass();
		break;

	case 9:
		cout << "\n������� ����: ";
		cin >> key;
		cout << "\n������� ��������: ";
		cin >> value;
		copy_if(Map.begin(), Map.end(), inserter(temp, temp.end()), [&value, &key](std::pair<int, T > elem) { return value == elem.second && key == elem.first; });
		cout << "\n\n������ ���������, ���������� �� ��������:\n";
		for_each(temp.begin(), temp.end(), Print_Map<T>);
		cout << endl;
		OperationPass();
		break;

	case 0:
		cout << endl;
		OperationCancel();
	}
}
// ########################### ����� ���� ###########################
template<typename T>
inline void ConsoleUI<T>::MapShow()
{
	if (NoMapData())
		return;
	cout << endl;
	for_each(Map.begin(), Map.end(), Print_Map<T>);
	OperationPass();
}
// ######################## ��� ������ ���� #########################
template<typename T>
inline bool ConsoleUI<T>::NoMapData()
{
	if (!Map.size())
	{
		SetColor(12, 0);
		cout << "\n������ �����������!\n";
		SetColor(7, 0);
		system("PAUSE");
		system("cls");
		return true;
	}
	return false;
}
// ########################### ����� ���� ###########################
template<typename T>
inline void ConsoleUI<T>::ChoseMap()
{
	system("cls");
	LabInfo();
	cout << "������ ���������: ";
	SetColor(11, 0);
	cout << "map\n";
	SetColor(7, 0);
}