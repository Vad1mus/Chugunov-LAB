#pragma once
#include "Controller.h"

// ����� "���������� ����"
class Dialog
{
public:
	/* ������������, ���������� */
	// ����������� ��-���������
	Dialog();
	// ����������
	~Dialog();

	// ������ ����������� ����
	void Run();

private:
	/* �������� */
	// ����������, ����������� �������� ��� ��������� �������
	Controller Cller;

	// ������� ����
	int MainMenu();
	// ����� �������� ����������
	int SortingSelect();
	// ����� �������� ������
	int SearchSelect();
};