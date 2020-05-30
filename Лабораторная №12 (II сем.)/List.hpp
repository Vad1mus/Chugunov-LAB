#pragma once
#include "Dialog.h"

// ###################### �������� ��� ������� ######################
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

		case 0:
			return;
		}
	} while (ch);
}
// ###################### ���������� � ������ #######################
template<typename T>
inline void ConsoleUI<T>::AddToList(int ch)
{
	T value;
	int index;
	auto iterator = List.begin();
	do
	{
		ChoseList();
		cout << "�������� ������ ����������:\n";
		cout << "1. ���������� � ������.\n";
		cout << "2. �������.\n";
		cout << "3. ���������� � �����.\n";
		cout << "0. ������.\n";
		cout << "������� ��� ����� ����: ";
		cin >> ch;
	} while (!CheckSelect(0, 3, ch));
	switch (ch)
	{
	case 1:
		cout << "\n������� �������� ��� ����������: ";
		cin >> value;
		List.push_front(value);
		OperationPass();
		break;

	case 2:
		cout << "\n������� �������� ��� ����������: ";
		cin >> value;
		do
		{
			cout << "������� ������: ";
			cin >> index;
			if (index > List.size() || index < 0)
			{
				SetColor(12, 0);
				cout << "�� ��������. ������� ����� �� 0 �� " << List.size() << endl;
				SetColor(7, 0);
			}
		} while (index > List.size() || index < 0);
		std::advance(iterator, index);
		List.insert(iterator, value);
		OperationPass();
		break;

	case 3:
		cout << "\n������� �������� ��� ����������: ";
		cin >> value;
		List.push_back(value);
		OperationPass();
		break;
	case 0:
		cout << endl;
		OperationCancel();
	}
}
// ####################### �������� �� ������ #######################
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
		cout << "�������� ������ ��������:\n";
		cout << "1. �������� � ������.\n";
		cout << "2. �������� �� �������.\n";
		cout << "3. �������� � �����.\n";
		cout << "0. ������.\n";
		cout << "������� ��� ����� ����: ";
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
			cout << "������� ������: ";
			cin >> index;
			if (index >= List.size() || index < 0)
			{
				SetColor(12, 0);
				cout << "�� ��������. ������� ����� �� 0 �� " << List.size() - 1 << endl;
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
// ################### ��������� ������ �� ������ ###################
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
		cout << "�������� ������� ���������:\n";
		cout << "1. ������� ������ �������.\n";
		cout << "2. ������� ������� �� �������.\n";
		cout << "3. ������� ��������� �������.\n";
		cout << "0. ������.\n";
		cout << "������� ��� ����� ����: ";
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
			cout << "������� ������: ";
			cin >> index;
			if (index >= List.size() || index < 0)
			{
				SetColor(12, 0);
				cout << "�� ��������. ������� ����� �� 0 �� " << List.size() - 1 << endl;
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
// ########################## ����� ������ ##########################
template<typename T>
inline void ConsoleUI<T>::ListShow()
{
	if (NoListData())
		return;
	cout << endl;
	for (auto &i : List)
		cout << i << " ";
	cout << endl;
	OperationPass();
}
// ####################### ��� ������ ������ ########################
template<typename T>
inline bool ConsoleUI<T>::NoListData()
{
	if (!List.size())
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
// ########################## ����� ������ ##########################
template<typename T>
inline void ConsoleUI<T>::ChoseList()
{
	system("cls");
	LabInfo();
	cout << "������ ���������: ";
	SetColor(11, 0);
	cout << "list\n";
	SetColor(7, 0);
}
