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

		case 5:
			SetCount(ch);
			break;

		case 6:
			SetFind(ch);
			break;

		case 7:
			SetColor(12, 0);
			cout << "\n������� �� ����������� � ������ ����������.\n";
			SetColor(7, 0);
			system("Pause");
			system("cls");
			break;

		case 8:
			SetColor(12, 0);
			cout << "\n��������� �� ������������� ����������.\n";
			SetColor(7, 0);
			system("Pause");
			system("cls");
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
// ####################### ������� ��������� ########################
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
		cout << "�������� �������� ��������:\n";
		cout << "1. ��������� ��� ��������, ������� ������ ��������.\n";
		cout << "2. ��������� ��� ��������, ������� ������ ��������.\n";
		cout << "3. ��������� ��� ��������, ������� ����� ��������.\n";
		cout << "0. ������.\n";
		cout << "������� ��� ����� ����: ";
		cin >> ch;
	} while (!CheckSelect(0, 3, ch));
	switch (ch)
	{
	case 1:
		cout << "\n������� ��������: ";
		cin >> value;
		count = count_if(Set.begin(), Set.end(), [&value](const T &elem) { return value < elem; });
		cout << "\n\n���������� ���������, ���������� �� ��������: " << count << endl;
		OperationPass();
		break;

	case 2:
		cout << "\n������� ��������: ";
		cin >> value;
		count = count_if(Set.begin(), Set.end(), [&value](const T &elem) { return value > elem; });
		cout << "\n\n���������� ���������, ���������� �� ��������: " << count << endl;
		OperationPass();
		break;

	case 3:
		cout << "\n������� ��������: ";
		cin >> value;
		count = count_if(Set.begin(), Set.end(), [&value](const T &elem) { return value == elem; });
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
inline void ConsoleUI<T>::SetFind(int ch)
{
	if (NoSetData())
		return;
	T value;
	set<T> temp;
	do
	{
		ChoseSet();
		cout << "�������� �������� ��������:\n";
		cout << "1. ����� ��� ��������, ������� ������ ��������.\n";
		cout << "2. ����� ��� ��������, ������� ������ ��������.\n";
		cout << "3. ����� ��� ��������, ������� ����� ��������.\n";
		cout << "0. ������.\n";
		cout << "������� ��� ����� ����: ";
		cin >> ch;
	} while (!CheckSelect(0, 3, ch));
	switch (ch)
	{
	case 1:
		cout << "\n������� ��������: ";
		cin >> value;
		copy_if(Set.begin(), Set.end(), inserter(temp, temp.end()), [&value](const T &elem) { return value < elem; });
		cout << "\n\n������ ���������, ���������� �� ��������:\n";
		for_each(temp.begin(), temp.end(), Print_Pred<T>);
		cout << endl;
		OperationPass();
		break;

	case 2:
		cout << "\n������� ��������: ";
		cin >> value;
		copy_if(Set.begin(), Set.end(), inserter(temp, temp.end()), [&value](const T &elem) { return value > elem; });
		cout << "\n\n������ ���������, ���������� �� ��������:\n";
		for_each(temp.begin(), temp.end(), Print_Pred<T>);
		cout << endl;
		OperationPass();
		break;

	case 3:
		cout << "\n������� ��������: ";
		cin >> value;
		copy_if(Set.begin(), Set.end(), inserter(temp, temp.end()), [&value](const T &elem) { return value == elem; });
		cout << "\n\n������ ���������, ���������� �� ��������:\n";
		for_each(temp.begin(), temp.end(), Print_Pred<T>);
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
inline void ConsoleUI<T>::SetShow()
{
	if (NoSetData())
		return;
	cout << endl;
	for_each(Set.begin(), Set.end(), Print_Pred<T>);
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