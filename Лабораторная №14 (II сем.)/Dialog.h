#pragma once
#include <vector>
#include <set>
#include <list>
#include <map>
#include <algorithm>
#include <iterator>
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
using std::for_each;
using std::count_if;
using std::copy_if;
using std::inserter;
using std::back_inserter;
using std::sort;
using std::cout;
using std::cin;
using std::endl;

template<typename T>
class SortingMinMax
{
public:
	bool operator() (const T &a, const T &b) { return a < b; };
};

template<typename T>
class SortingMaxMin
{
public:
	bool operator() (const T &a, const T &b) { return a > b; };
};

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
	// ������� ��������� �� �������� ��������
	void VectorCount(int ch);
	// ����� ��������� �� �������� ��������
	void VectorFind(int ch);
	// ������� ��������
	void VectorMerge();
	// ���������� ������� �� �������� ��������
	void VectorSort(int ch);
	// ����������� �� ���������� ������ � �������
	bool NoVectorData();
	// ����������� � ������ �������
	void ChoseVector();

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
	// ������� ��������� �� �������� ��������
	void ListCount(int ch);
	// ����� ��������� �� �������� ��������
	void ListFind(int ch);
	// ���������� ������ �� �������� ��������
	void ListSort(int ch);
	// ����������� �� ���������� ������ � ������
	bool NoListData();
	// ����������� � ������ ������
	void ChoseList();

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
	// ������� ��������� �� �������� ��������
	void SetCount(int ch);
	// ����� ��������� �� �������� ��������
	void SetFind(int ch);
	// ����������� �� ���������� ������ � ����
	bool NoSetData();
	// ����������� � ������ ����
	void ChoseSet();

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
	// ������� ��������� �� �������� ��������
	void MapCount(int ch);
	// ����� ��������� �� �������� ��������
	void MapFind(int ch);
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
	cout << "5. ������� ���������� ���������.\n";
	cout << "6. ����� ���������.\n";
	cout << "7. ������� �����������.\n";
	cout << "8. ���������� �� ��������.\n";
	cout << "0. ��������� � ������ ����������.\n";
	cout << "������� ��� ����� ����: ";
	cin >> choice;
	CheckSelect(0, 8, choice);
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

template<typename T>		// ���������� ������
void Print_Pred(const T &elem)
{
	cout << elem << " ";
}

template<typename T>		// ���������� ������ map
void Print_Map(std::pair<int, T> elem)
{
	cout << '[' << elem.first << "] : " << elem.second << endl;
}

#include "Vector.hpp" // ���������� ������� ��� ��������

#include "Set.hpp" // ���������� ������� ��� �����

#include "List.hpp" // ���������� ������� ��� �������

#include "Map.hpp" // ���������� ������� ��� �����