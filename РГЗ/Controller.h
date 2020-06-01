#pragma once
#include <algorithm>
#include <vector>
#include <Windows.h>
#include "RGZ.h"
#include "Test.h"

using std::vector;
using std::sort;
using std::copy_if;
using std::back_inserter;

// ����� "����������"
class Controller
{
public:
	/* ������������, ���������� */
	// ����������� ��-���������
	Controller();
	// ����������
	~Controller();

	/* ������ */
	// ���������� ���
	void AddRGZ();
	// ���������� �����
	void AddTest();
	// �������� ������
	void DeleteWork();
	// ����� ����� �� �����
	void ShowAll();
	// ���������� ������
	void Sorting(int ch);
	// ����� �����
	void Search(int ch);
	// ���������� �������
	void Task();

private:
	/* �������� */
	// ������, ��������� �� �����
	vector<Work*> works;
};

// ���������� ���������� �� �������� ���-���� 
class SortingMinMaxSubject
{
public:
	bool operator() (const Work *a, const Work *b) { return a->get_subject() < b->get_subject(); };
};

// ���������� ���������� �� �������� ����-���
class SortingMaxMinSubject
{
public:
	bool operator() (const Work *a, const Work *b) { return a->get_subject() > b->get_subject(); };
};

// ���������� ���������� �� ������ ���-���� 
class SortingMinMaxAutor
{
public:
	bool operator() (const Work *a, const Work *b) { return a->get_autor() < b->get_autor(); };
};

// ���������� ���������� �� ������ ����-���
class SortingMaxMinAutor
{
public:
	bool operator() (const Work *a, const Work *b) { return a->get_autor() > b->get_autor(); };
};

// ���������� ���������� �� ������ ���-���� 
class SortingMinMaxMark
{
public:
	bool operator() (const Work *a, const Work *b) { return a->get_mark() < b->get_mark(); };
};

// ���������� ���������� �� ������ ����-���
class SortingMaxMinMark
{
public:
	bool operator() (const Work *a, const Work *b) { return a->get_mark() > b->get_mark(); };
};

// ������� ����� ����� �������
void SetColor(int text, int background);
// �������� ������ ��������
bool CheckSelect(int b, int e, int i);
// ����������� �� �������� ��������
void OperationPass();
// ����������� �� ������ ��������
void OperationCancel();
// ���������� � ������
void Info();