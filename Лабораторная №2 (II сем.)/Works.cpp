#include <iostream>
#include <sstream>
#include "Works.h"

Works::~Works()
{
	delete[]lessons;
	lessons = nullptr;
}

void Works::addWork(Lessons& lesson)
{
	if (!size)
	{
		lessons = new Lessons[size + 1];
		lessons[size] = lesson;
		sum += lessons[size].get_numOfWorks();
		size++;
	}
	else {
		Lessons *newLessons = new Lessons[size + 1];
		for (auto i = 0; i < size; i++) {
			newLessons[i] = lessons[i];
		}
		newLessons[size] = lesson;
		delete[]lessons;
		lessons = newLessons;
		sum += lessons[size].get_numOfWorks();
		size++;
	}
}

void Works::removeWork(int pos)
{	
	if (!size)
		cout << "\nError (list is empty)\n";
	else {
		Lessons *newLessons = new Lessons[size - 1];
		for (auto i = 0, j = 0; i < size; i++, j++)
		{
			if (i == pos) {
				j--;
				continue;
			}
			newLessons[j] = lessons[i];
		}
		delete[](lessons);
		lessons = newLessons;
		size--;
	}
}

void Works::showAll()
{
	if (!size)
		cout << "\nError (the list is empty)\n";
	else {
		for (auto i = 0; i < size; i++)
		{
			cout << "\nInfo about lesson #" << i + 1 << ": " << endl;
			cout << "Subject: " << lessons[i].get_lessonType() << endl;
			cout << "Lecturer: " << lessons[i].get_lecturerName() << endl;
			cout << "Audience ID: " << lessons[i].get_audienceID() << endl;
			cout << "Lesson start time: " << lessons[i].get_lessonStartTime() << endl;
			cout << "The number of works student wrote for the semester: " << lessons[i].get_numOfWorks() << endl;
		}
	}
}