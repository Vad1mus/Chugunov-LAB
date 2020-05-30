#pragma once
#include "Dialog.h"

// ####################### �������� ��� ����� #######################
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
// ######################## ���������� � ��� ########################
template<typename T>
inline void ConsoleUI<T>::AddToSet()
{
	T value;
	cout << "\n������� ������ ��� ����������: ";
	cin >> value;
	Set.insert(value);
	OperationPass();
}
// ######################## �������� �� ���� ########################
template<typename T>
inline void ConsoleUI<T>::DelFromSet()
{
	if (NoSetData())
		return;
	T value;
	cout << "\n������� ��������� ������: ";
	cin >> value;
	auto iterator = Set.find(value);
	if (iterator == Set.end())
	{
		SetColor(12, 0);
		cout << "������ � ����� ��������� ��� � ����������.\n";
		SetColor(7, 0);
		system("PAUSE");
		system("cls");
		return;
	}
	Set.erase(iterator);
	OperationPass();
}
// #################### ��������� ������ �� ���� ####################
template<typename T>
inline T ConsoleUI<T>::SetGet()
{
	if (NoSetData())
		return T();
	T value;
	cout << "\n������� ������� ������: ";
	cin >> value;
	auto iterator = Set.find(value);
	if (iterator == Set.end())
	{
		SetColor(12, 0);
		cout << "������ � ����� ��������� ��� � ����������.\n";
		SetColor(7, 0);
		system("PAUSE");
		system("cls");
		return T();
	}
	cout << "������ � ����� ��������� ���� � ���������� � ������� ����������!\n";
	OperationPass();
	return *iterator;
}
// ########################### ����� ���� ###########################
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
// ######################## ��� ������ ���� #########################
template<typename T>
inline bool ConsoleUI<T>::NoSetData()
{
	if (!Set.size())
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
inline void ConsoleUI<T>::ChoseSet()
{
	system("cls");
	LabInfo();
	cout << "������ ���������: ";
	SetColor(11, 0);
	cout << "set\n";
	SetColor(7, 0);
}