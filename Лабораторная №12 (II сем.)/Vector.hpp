#pragma once
#include "Dialog.h"

// ##################### �������� ��� �������� ######################
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

		case 0:
			return;
		}
	} while (ch);
}
// ###################### ���������� � ������ #######################
template<typename T>
inline void ConsoleUI<T>::AddToVector(int ch)
{
	T value;
	int index;
	auto iterator = Vector.begin();
	do
	{
		ChoseVector();
		cout << "�������� ������ ����������:\n";
		cout << "1. ���������� � �����.\n";
		cout << "2. �������.\n";
		cout << "0. ������.\n";
		cout << "������� ��� ����� ����: ";
		cin >> ch;
	} while (!CheckSelect(0, 2, ch));
	switch (ch)
	{
	case 1:
		cout << "\n������� �������� ��� ����������: ";
		cin >> value;
		Vector.push_back(value);
		OperationPass();
		break;

	case 2:
		cout << "\n������� �������� ��� ����������: ";
		cin >> value;
		do
		{
			cout << "������� ������: ";
			cin >> index;
			if (index > Vector.size() || index < 0)
			{
				SetColor(12, 0);
				cout << "�� ��������. ������� ����� �� 0 �� " << Vector.size() << endl;
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
// ###################### �������� �� ������� #######################
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
		cout << "�������� ������ ��������:\n";
		cout << "1. �������� � �����.\n";
		cout << "2. �������� �� �������.\n";
		cout << "0. ������.\n";
		cout << "������� ��� ����� ����: ";
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
			cout << "������� ������: ";
			cin >> index;
			if (index >= Vector.size() || index < 0)
			{
				SetColor(12, 0);
				cout << "�� ��������. ������� ����� �� 0 �� " << Vector.size() - 1 << endl;
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
// ################## ��������� ������ �� ������� ###################
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
		cout << endl << Vector.front() << endl;
		OperationPass();
		return Vector.front();
		break;

	case 2:
		do
		{
			cout << "������� ������: ";
			cin >> index;
			if (index >= Vector.size() || index < 0)
			{
				SetColor(12, 0);
				cout << "�� ��������. ������� ����� �� 0 �� " << Vector.size() - 1 << endl;
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
// ######################### ����� ������� ##########################
template<typename T>
inline void ConsoleUI<T>::VectorShow()
{
	if (NoVectorData())
		return;
	cout << endl;
	for (auto &i : Vector)
		cout << i << " ";
	cout << endl;
	OperationPass();
}
// ####################### ��� ������ ������� #######################
template<typename T>
inline bool ConsoleUI<T>::NoVectorData()
{
	if (!Vector.size())
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
// ######################### ����� ������� ##########################
template<typename T>
inline void ConsoleUI<T>::ChoseVector()
{
	system("cls");
	LabInfo();
	cout << "������ ���������: ";
	SetColor(11, 0);
	cout << "vector\n";
	SetColor(7, 0);
}