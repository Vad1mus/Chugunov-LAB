#include <iostream>
#include "Lessons.h"
#include "Works.h"
#include "Func.h"

int main()
{
	Lessons lesson;
	Works work;

	int choose;
	do {
		cout << endl;
		MenuBar();
		cin >> choose;
		if (choose < 1 || choose > 4)
		{
			cout << "\nError (choose 1-4).\n";
			continue;
		}
		switch (choose)
		{
		case 1:
			lesson.generateLesson();
			work.addWork(lesson);
			break;
		case 2:
			cout << "Enter a psition of lesson you want to deleting: ";
			int num;
			while (true)
			{
				cin >> num;
				if ((work.get_size() == 0))
					break;
				if ((num - 1) >= work.get_size() || (num - 1) < 0)
					cout << "Error (pos is higher than qty of subs), try again: ";
				else break;
				
			}
			work.removeWork(num-1);
			cout << endl;
			break;
		case 3:
			work.showAll();
			break;
		case 4:
			work.endOfProgramm();
			cout << "\nThank that you using my code!\n";
			break;
		}
	} while (choose != 4);
	system("PAUSE");
	return 0;
}