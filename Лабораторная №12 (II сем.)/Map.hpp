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
// ########################### ����� ���� ###########################
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
