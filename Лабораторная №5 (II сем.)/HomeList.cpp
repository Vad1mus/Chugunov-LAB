#include "HomeList.h"

HomeList::~HomeList()
{
	delete[]hws;
	hws = nullptr;
}

void HomeList::addHW(Home & hw)
{
	if (!size)
	{
		hws = new Home[size + 1];
		hws[size] = hw;
		sumHW += hws[size].getNumOfHWs();
		sum += hws[size].get_numOfWorks();
		size++;
	}
	else {
		Home *newHws = new Home[size + 1];
		for (auto i = 0; i < size; i++) {
			newHws[i] = hws[i];
		}
		newHws[size] = hw;
		delete[] hws;
		hws = newHws;
		sumHW += hws[size].getNumOfHWs();
		sum += hws[size].get_numOfWorks();
		size++;
	}
}

void HomeList::removeHW(int pos)
{
	if (!size)
		cout << "\nError(list is empty)\n";
	else {
		Home *newHws = new Home[size - 1];
		for (auto i = 0, j = 0; i < size; i++, j++)
		{
			if (i == pos) {
				j--;
				continue;
			}
			newHws[j] = hws[i];
		}
		delete[] hws;
		hws = newHws;
		size--;
	}
}

void HomeList::showAllHWs()
{
	if (!size)
		cout << "\nError (the list is empty)\n";
	else {
		for (auto i = 0; i < size; i++)
		{
			cout << "\nInfo about lesson #" << i + 1 << ": " << endl;
			cout << "Subject: " << hws[i].get_lessonType() << endl;
			cout << "Lecturer: " << hws[i].get_lecturerName() << endl;
			cout << "Audience ID: " << hws[i].get_audienceID() << endl;
			cout << "Lesson start time: " << hws[i].get_lessonStartTime() << endl;
			cout << "The number of works student wrote for the semester: " << hws[i].get_numOfWorks() << endl;
			cout << "The number of hometasks student wrote per semester: " << hws[i].getNumOfHWs() << endl;
		}
	}
}
