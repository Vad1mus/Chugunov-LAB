#include "Controller.h"

Controller::Controller()
{
	
}

Controller::~Controller()
{
}

void Controller::AddRGZ()
{
	Info();
	cout << "Информация об РГЗ:\n\n";
	RGZ *work = new RGZ;
	cin >> *work;
	works.push_back(work);
	OperationPass();
}

void Controller::AddTest()
{
	Info();
	cout << "Информация о Тесте:\n\n";
	Test *work = new Test;
	cin >> *work;
	works.push_back(work);
	OperationPass();
}

void Controller::DeleteWork()
{
	Info();
	string name;
	cout << "Удаление работы:\n\n";
	cout << "Введите имя студента: ";
	cin >> name;
	int i = 0;
	auto iter = works.begin();
	for (auto &work : works)
	{
		if (work->get_autor() == name)
		{
			std::advance(iter, i);
			works.erase(iter);
		}
		i++;
	}
	if (i == works.size())
	{
		SetColor(12, 0);
		cout << "Студент с таким именем не писал работу.\n";
		SetColor(7, 0);
		system("pause");
		return;
	}
	OperationPass();
}

void Controller::ShowAll()
{
	Info();
	if (works.empty())
	{
		SetColor(12, 0);
		cout << "\nНет информации. Сначала добавте что-либо.\n";
		SetColor(7, 0);
		system("pause");
		return;
	}
	for (auto &work : works)
	{
		work->operator<<(work);
		cout << endl;
	}
	OperationPass();
}

void Controller::Sorting(int ch)
{
	Info();
	if (works.empty())
	{
		SetColor(12, 0);
		cout << "\nНет информации. Сначала добавте что-либо.\n";
		SetColor(7, 0);
		system("pause");
		return;
	}
	int choice;
	SortingMinMaxSubject minmaxS;
	SortingMaxMinSubject maxminS;
	SortingMinMaxAutor minmaxA;
	SortingMaxMinAutor maxminA;
	SortingMinMaxMark minmaxM;
	SortingMaxMinMark maxminM;
	
	do {
		cout << "Выберите направление сортировки:\n";
		cout << "1. Сортировать по возрастанию.\n";
		cout << "2. Сортировать по убыванию.\n";
		cout << "0. Выход.\n";
		cout << "Введите ваш ответ сюда: ";
		cin >> choice;
	} while (!CheckSelect(0, 2, choice));
	switch (ch)
	{
	case 1:
		switch (choice)
		{
		case 1:
			sort(works.begin(), works.end(), minmaxS);
			OperationPass();
			return;
		case 2:
			sort(works.begin(), works.end(), maxminS);
			OperationPass();
			return;
		case 0:
			OperationCancel();
			return;
		}
		break;

	case 2:
		switch (choice)
		{
		case 1:
			sort(works.begin(), works.end(), minmaxA);
			OperationPass();
			return;
		case 2:
			sort(works.begin(), works.end(), maxminA);
			OperationPass();
			return;
		case 0:
			OperationCancel();
			return;
		}
		break;

	case 3:
		switch (choice)
		{
		case 1:
			sort(works.begin(), works.end(), minmaxM);
			OperationPass();
			return;
		case 2:
			sort(works.begin(), works.end(), maxminM);
			OperationPass();
			return;
		case 0:
			OperationCancel();
			return;
		}
		break;

	case 0:
		cout << endl;
		OperationCancel();
	}
}

void Controller::Search(int ch)
{
	Info();
	if (works.empty())
	{
		SetColor(12, 0);
		cout << "\nНет информации. Сначала добавте что-либо.\n";
		SetColor(7, 0);
		system("pause");
		return;
	}
	vector<Work *> elements;
	string checkStr;
	int checkInt;
	cout << "\nВведите искомое значение значение: ";
	switch (ch)
	{
	case 1:
		cin >> checkStr;
		copy_if(works.begin(), works.end(), back_inserter(elements), [&checkStr](Work *a) {
			return a->get_subject() == checkStr;
		});
		for (auto &work : elements)
		{
			work->operator<<(work);
			cout << endl;
		}
		OperationPass();
		break;

	case 2:
		cin >> checkStr;
		copy_if(works.begin(), works.end(), back_inserter(elements), [&checkStr](Work *a) {
			return a->get_autor() == checkStr;
		});
		for (auto &work : elements)
		{
			work->operator<<(work);
			cout << endl;
		}
		OperationPass();
		break;

	case 3:
		cin >> checkInt;
		copy_if(works.begin(), works.end(), back_inserter(elements), [&checkInt](Work *a) {
			return a->get_mark() == checkInt;
		});
		for (auto &work : elements)
		{
			work->operator<<(work);
			cout << endl;
		}
		OperationPass();
		break;

	case 0:
		cout << endl;
		OperationCancel();
	}

}

void Controller::Task()
{
	Info();
	int worksPerSemester = works.size() * 8 - 7;
	cout << "\nСтудент выполнил " << worksPerSemester << " работ за семестр.\n";
	OperationPass();
}

bool CheckSelect(int b, int e, int i)
{
	if (i < b || i > e)
	{
		SetColor(12, 0);
		cout << "\nВы ошиблись. Введите число от " << b << " до " << e << endl;
		SetColor(7, 0);
		system("PAUSE");
		system("cls");
		return false;
	}
	return true;
}

void OperationPass()
{
	SetColor(10, 0);
	cout << "Операция прошла успешно!\n";
	SetColor(7, 0);
	system("PAUSE");
	system("cls");
}

void OperationCancel()
{
	SetColor(12, 0);
	cout << "Операция отменена.\n";
	SetColor(7, 0);
	system("PAUSE");
	system("cls");
}

void Info()
{
	system("cls");
	SetColor(9, 0);
	cout << "  РГЗ по дисциплине \"Программрование\"  *Выполнил: Чугунов Вадим\n";
	SetColor(7, 0);
}

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
