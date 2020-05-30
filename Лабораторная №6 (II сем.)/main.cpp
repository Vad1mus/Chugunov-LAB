#include <iostream>
#include "Lessons.h"
#include "Works.h"
#include "Home.h"
#include "HomeList.h"
#include "Func.h"

int main()
{
	Lessons lesson;
	Works work;
	Home homework;
	HomeList hws;

	int choose;
	do {
		cout << endl;
		MenuBar();
		cin >> choose;
		if (choose < 1 || choose > 7)
		{
			cout << "\nError (choose 1-7).\n";
			continue;
		}
		switch (choose)
		{
		case 1:
			lesson.generate();
			work.addWork(lesson);
			break;
		case 2:
			homework.generate();
			hws.addHW(homework);
			break;
		case 3:
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
		case 4:
			cout << "Enter a psition of lesson you want to deleting: ";
			int num2;
			while (true)
			{
				cin >> num2;
				if (!hws.get_size())
					break;
				if ((num2 - 1) >= hws.get_size() || (num2 - 1) < 0)
					cout << "Error (pos is higher than qty of subs), try again: ";
				else break;

			}
			hws.removeHW(num2 - 1);
			cout << endl;
			break;
		case 5:
			  work.showAll();
			  break;
		case 6:
			hws.showAllHWs();
			break;
		case 7:
			cout << "\nStudent performs " << work.WorksForSem() + hws.get_sum() << " tasks per semester.";
			cout << "\nStudent performs " << hws.get_sumHW() << " hometasks per semester.";
			cout << "\nStudent performs " << hws.get_sumHW() + work.WorksForSem() + hws.get_sum() << " tasks and hometasks per semester.";
			cout << "\nThank that you using my code!\n";
			break;
		}
	} while (choose != 7);

	system("PAUSE");
	return 0;
}