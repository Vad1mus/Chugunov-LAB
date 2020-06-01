#include "Dialog.h"

Dialog::Dialog()
{
	
}

Dialog::~Dialog()
{
}

void Dialog::Run()
{
	int choice;
	do {
		choice = MainMenu();
		switch (choice)
		{
		case 1:
			Cller.AddRGZ();
			system("cls");
			break;

		case 2:
			Cller.AddTest();
			system("cls");
			break;

		case 3:
			Cller.DeleteWork();
			system("cls");
			break;

		case 4:
			Cller.ShowAll();
			system("cls");
			break;

		case 5:
			choice = SortingSelect();
			Cller.Sorting(choice);
			system("cls");
			break;

		case 6:
			choice = SearchSelect();
			Cller.Search(choice);
			system("cls");
			break;

		case 7:
			Cller.Task();
			system("cls");
			break;

		case 0:
			SetColor(13, 0);
			cout << "\n������� �� ������!\n";
			SetColor(7, 0);
		}
	} while (choice);
}

int Dialog::MainMenu()
{
	int choice = 0;
	Info();
	cout << "�������� ���� �� ���������:\n";
	cout << "1. �������� ���.\n";
	cout << "2. �������� ����.\n";
	cout << "3. ������� ������.\n";
	cout << "4. ������� ��� ������ �� �����.\n";
	cout << "5. ���������� ������.\n";
	cout << "6. ����� �����.\n";
	cout << "7. ���������� ���������� ����� �� �������.\n";
	cout << "0. �����.\n";
	cout << "������� ��� ����� ����: ";
	cin >> choice;
	CheckSelect(0, 7, choice);
	return choice;
}

int Dialog::SortingSelect()
{
	int choice = 0;
	Info();
	cout << "�������� ���� �� ���������:\n";
	cout << "1. ���������� �� ��������.\n";
	cout << "2. ���������� �� ����� ������.\n";
	cout << "3. ���������� �� ������.\n";
	cout << "0. �����.\n";
	cout << "������� ��� ����� ����: ";
	cin >> choice;
	CheckSelect(0, 3, choice);
	return choice;
}

int Dialog::SearchSelect()
{
	int choice = 0;
	Info();
	cout << "�������� ���� �� ���������:\n";
	cout << "1. ����� ������ �� ��������.\n";
	cout << "2. ����� ������ �� ����� ������.\n";
	cout << "3. ����� ������ �� ������.\n";
	cout << "0. �����.\n";
	cout << "������� ��� ����� ����: ";
	cin >> choice;
	CheckSelect(0, 3, choice);
	return choice;
}
