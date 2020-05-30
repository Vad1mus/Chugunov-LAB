#include <iostream>
#include "Works.h"

void Works::addWork(Lessons& lesson)
{
	if (size == 0)
	{
		lessons = new Lessons[size + 1];
		lessons[size] = lesson;
		size++;
	}
	else {
		Lessons *newLessons = new Lessons[size + 1];
		for (int i = 0; i < size; i++) {
			newLessons[i] = lessons[i];
		}
		newLessons[size] = lesson;
		delete[]lessons;
		lessons = newLessons;
		size++;
	}
}

void Works::removeWork(int pos)
{
	if (size == 0)
		cout << "\nError (list is empty)\n";
	else {
		Lessons *newLessons = new Lessons[size - 1];
		for (int i = 0, j = 0; i < size; i++, j++) 
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
	if (size == 0)
		cout << "\nError (the list is empty)\n";
	else {
		for (int i = 0; i < size; i++)
		{
			printf("\nInfo about lesson #%d: \n", i+1);
			cout << "Subject: " << lessons[i].get_lessonType() << endl;
			cout << "Lecturer: " << lessons[i].get_lecturerName() << endl;
			cout << "Audience ID: " << lessons[i].get_audienceID() << endl;
			cout << "Lesson start time: " << lessons[i].get_lessonStartTime() << endl;
			cout << "Number of students in audience: " << lessons[i].get_studAmount() << endl;
		}
	}
}

void Works::endOfProgramm()
{
	delete[]lessons;
	lessons = nullptr;
}

const int Works::get_size() const {
	return size;
}