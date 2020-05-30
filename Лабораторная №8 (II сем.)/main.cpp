#include <iostream>
#include "Lessons.h"
#include "Works.h"
#include "Home.h"
#include "Func.h"

int main()
{
	/*Lessons lesson;
	Home homework;
	Works work;

	int choose;
	do {
		cout << endl;
		MenuBar();
		cin >> choose;
		if (choose < 1 || choose > 5)
		{
			cout << "\nError (choose 1-5).\n";
			continue;
		}
		switch (choose)
		{
		case 1:
			lesson.generate();
			work.push_back(&lesson);
			break;
		case 2:
			homework.generate();
			work.push_back(&homework);
			break;
		case 3:
			if ((work.get_size() == 0))
			{
				cout << "\nError (list is empty.)\n";
				break;
			}
			cout << "Enter a psition of lesson you want to deleting: ";
			int num;
			while (true)
			{
				cin >> num;
				if ((num - 1) >= work.get_size() || (num - 1) < 0)
					cout << "Error (pos is higher than qty of subs), try again: ";
				else break;
			}
			work.erase(num-1);
			cout << endl;
			break;
		case 4:
			  work.show();
			  break;
		case 5:
			cout << "\nStudent performs " << work.get_works() << " tasks per semester.";
			cout << "\nStudent performs " << work.get_homeworks() << " hometasks per semester.";
			cout << "\nStudent performs " << work.get_works() + work.get_homeworks() << " tasks and hometasks per semester.";
			cout << "\nThank that you using my code!\n";
			break;
		}
	} while (choose != 5);*/

	cout << "Lesson 1:";
	Lessons s1;
	cin >> s1;

	cout << "\nLesson 2:";
	cin.ignore(20, '\n');
	Lessons s2;
	cin >> s2;

	Works w;
	w.push_back(&s1);
	w.push_back(&s2);

	cout << "\nList:" << w << endl;
	cout << "\nList[0]:" << w[1];

	system("PAUSE");
	return 0;
}