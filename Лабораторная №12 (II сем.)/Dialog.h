#pragma once
#include <vector>
#include <set>
#include <list>
#include <map>
#include <Windows.h>
#include"Point.h"

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

using std::vector;
using std::set;
using std::list;
using std::map;
using std::cout;
using std::cin;
using std::endl;

template<typename T>
class ConsoleUI
{
public:
	/* ���� - �������� �� ������ ����������� ���� */
	void RunExe();

private:
	// ������������ ����������
	vector<T> Vector;
	set<T> Set;
	list<T> List;
	map<int, T> Map;

	// ����� ����������
	int ContainerSelect();
	// ����� ��������
	int OperationSelect();

	// ���������� �������� ��� ��������
	void DoVectorOperation(int ch);
	// ���������� �������� � ������	
	void AddToVector(int ch);
	// �������� �������� �� �������
	void DelFromVector(int ch);
	// ��������� ������ �� �������
	T VectorGet(int ch);
	// ����� ����������� ������� �� �����
	void VectorShow();
	// ����������� �� ���������� ������ � �������
	bool NoVectorData();
	// ����������� � ������ �������
	void ChoseVector();

	// ���������� �������� ��� �����
	void DoSetOperation(int ch);
	// ���������� �������� � ���
	void AddToSet();
	// �������� �������� �� ����
	void DelFromSet();
	// ��������� ������ �� ����
	T SetGet();
	// ����� ����������� ���� �� �����
	void SetShow();
	// ����������� �� ���������� ������ � ����
	bool NoSetData();
	// ����������� � ������ ����
	void ChoseSet();

	// ���������� �������� ��� �������
	void DoListOperation(int ch);
	// ���������� �������� � ������
	void AddToList(int ch);
	// �������� �������� �� ������
	void DelFromList(int ch);
	// ��������� ������ �� ������
	T ListGet(int ch);
	// ����� ����������� ������ �� �����
	void ListShow();
	// ����������� �� ���������� ������ � ������
	bool NoListData();
	// ����������� � ������ ������
	void ChoseList();

	// ��������� �������� ��� �����
	void DoMapOperation(int ch);
	// ���������� �������� � ���
	void AddToMap();
	// �������� �������� �� ����
	void DelFromMap();
	// ��������� ������ �� ����
	T MapGet();
	// ����� ����������� ���� �� �����
	void MapShow();
	// ����������� �� ���������� ������ � ����
	bool NoMapData();
	// ����������� � ������ ����
	void ChoseMap();

	// ����������� �� �������� ��������
	void OperationPass();
	// ����������� �� ������ ��������
	void OperationCancel();
	// ���������� � ������������ ������
	void LabInfo();
	// �������� ������ ��������
	bool CheckSelect(int b, int e, int i);
};
// ########################## ������� ���� ##########################
template<typename T>
inline void ConsoleUI<T>::RunExe()
{
	int choice;
	do {
		choice = ContainerSelect();
		switch (choice)
		{
		case 1:
			DoVectorOperation(choice);
			system("cls");
			break;

		case 2:
			DoListOperation(choice);
			system("cls");
			break;

		case 3:
			DoSetOperation(choice);
			system("cls");
			break;

		case 4:
			DoMapOperation(choice);
			system("cls");
			break;

		case 0:
			SetColor(13, 0);
			cout << "\n������� �� ������!\n";
			SetColor(7, 0);
		}
	} while (choice);
}
// ######################## ����� ���������� ########################
template<typename T>
inline int ConsoleUI<T>::ContainerSelect()
{
	int choice;
	LabInfo();
	cout << "�������� ���������:\n";
	cout << "1. Vector.\n";
	cout << "2. List.\n";
	cout << "3. Set.\n";
	cout << "4. Map.\n";
	cout << "0. �����.\n";
	cout << "������� ��� ����� ����: ";
	cin >> choice;
	CheckSelect(0, 4, choice);
	return choice;
}
// ######################### ����� �������� #########################
template<typename T>
inline int ConsoleUI<T>::OperationSelect()
{
	int choice;
	cout << "������ ��������� ��������:\n";
	cout << "1. ���������� ��������.\n";
	cout << "2. �������� ��������.\n";
	cout << "3. ��������� ������.\n";
	cout << "4. ����� ����������� �� �����.\n";
	cout << "0. ��������� � ������ ����������.\n";
	cout << "������� ��� ����� ����: ";
	cin >> choice;
	CheckSelect(0, 4, choice);
	return choice;
}
// ######################## �������� ������� ########################
template<typename T>
inline void ConsoleUI<T>::OperationPass()
{
	SetColor(10, 0);
	cout << "�������� ������ �������!\n";
	SetColor(7, 0);
	system("PAUSE");
	system("cls");
}
// ######################### ������ �������� ########################
template<typename T>
inline void ConsoleUI<T>::OperationCancel()
{
	SetColor(12, 0);
	cout << "�������� ��������.\n";
	SetColor(7, 0);
	system("PAUSE");
	system("cls");
}
// ########################### ���� � ���� ##########################
template<typename T>
inline void ConsoleUI<T>::LabInfo()
{
	SetColor(9, 0);
	cout << "  ������������ ������ �12: \"STL ����������\"  *��������: ����� ���������\n";
	SetColor(7, 0);
}
// ################## �������� ������������ ������ ##################
template<typename T>
inline bool ConsoleUI<T>::CheckSelect(int b, int e, int i)
{
	if (i < b || i > e)
	{
		SetColor(12, 0);
		cout << "\n�� ��������. ������� ����� �� " << b << " �� " << e << endl;
		SetColor(7, 0);
		system("PAUSE");
		system("cls");
		return false;
	}
	return true;
}

#include "Vector.hpp" // ���������� ������� ��� ��������

#include "Set.hpp" // ���������� ������� ��� �����

#include "List.hpp" // ���������� ������� ��� �������

#include "Map.hpp" // ���������� ������� ��� �����