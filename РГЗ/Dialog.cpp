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
			cout << "\nСпасибо за работу!\n";
			SetColor(7, 0);
		}
	} while (choice);
}

int Dialog::MainMenu()
{
	int choice = 0;
	Info();
	cout << "Выберите один из вариантов:\n";
	cout << "1. Добавить РГЗ.\n";
	cout << "2. Добавить Тест.\n";
	cout << "3. Удалить работу.\n";
	cout << "4. Вывести все работы на экран.\n";
	cout << "5. Сортировка списка.\n";
	cout << "6. Поиск работ.\n";
	cout << "7. Определить количество работ за семестр.\n";
	cout << "0. Выход.\n";
	cout << "Введите ваш ответ сюда: ";
	cin >> choice;
	CheckSelect(0, 7, choice);
	return choice;
}

int Dialog::SortingSelect()
{
	int choice = 0;
	Info();
	cout << "Выберите один из критериев:\n";
	cout << "1. Сотрировка по предмету.\n";
	cout << "2. Сотрировка по имени автора.\n";
	cout << "3. Сотрировка по оценке.\n";
	cout << "0. Выход.\n";
	cout << "Введите ваш ответ сюда: ";
	cin >> choice;
	CheckSelect(0, 3, choice);
	return choice;
}

int Dialog::SearchSelect()
{
	int choice = 0;
	Info();
	cout << "Выберите один из критериев:\n";
	cout << "1. Поиск работы по предмету.\n";
	cout << "2. Поиск работы по имени автора.\n";
	cout << "3. Поиск работы по оценке.\n";
	cout << "0. Выход.\n";
	cout << "Введите ваш ответ сюда: ";
	cin >> choice;
	CheckSelect(0, 3, choice);
	return choice;
}
