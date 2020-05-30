#include <iostream>
#include "Works.h"

Works::Works()
{
	head = nullptr;
	size = 0;
	sumOfHWs = 0;
	sumOfWorks = 0;
}

Works::~Works()
{
	clear();
}

void Works::push_back(Lessons* lesson)
{
	if (!size)
	{
		head = new Node(lesson);
		sumOfWorks += lesson->get_numOfWorks();
		if (((Home *)lesson)->get_numOfHWs() > 0)
			sumOfHWs += ((Home *)lesson)->get_numOfHWs();
	}
	else
	{
		Node *current = this->head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = new Node(lesson);
		sumOfWorks += lesson->get_numOfWorks();
		if (((Home *)lesson)->get_numOfHWs() > 0)
			sumOfHWs += ((Home *)lesson)->get_numOfHWs();
	}
	this->size++;
}

void Works::erase(int pos)
{
	if (!pos)
		pop_front();
	else
	{
		Node *previous = head;
		for(int i = 0; i < pos-1; i++)
			previous = previous->next;

		Node *temp = previous->next;
		previous->next = temp->next;

		delete temp;
		temp = nullptr;
		size--;
	}
}

void Works::show()
{
	if (this->head == nullptr)
		cout << "\nError (list is empty)\n";
	else
	{
		Node *temp = head;
		int i = 0;
		while (temp != nullptr)
		{
			cout << "\nInfo about lesson #" << ++i << ": " << endl;
			cout << "Subject: " << temp->lesson->get_lessonType() << endl;
			cout << "Lecturer: " << temp->lesson->get_lecturerName() << endl;
			cout << "Audience ID: " << temp->lesson->get_audienceID() << endl;
			cout << "Lesson start time: " << temp->lesson->get_lessonStartTime() << endl;
			cout << "The number of works student wrote for the semester: " << temp->lesson->get_numOfWorks() << endl;
			if (((Home *)temp->lesson)->get_numOfHWs() > 0)
				cout << "The number of hometasks student wrote per semester: " << ((Home *)temp->lesson)->get_numOfHWs() << endl;
			temp = temp->next;
		}
	}
}

void Works::pop_front()
{
	Node *temp = head;
	head = head->next;
	delete temp;
	size--;
}

void Works::clear()
{
	while (size)
	{
		pop_front();
	}
}

Works::Node::Node(Lessons *l, Node *n)
{
	this->lesson = l;
	this->next = n;
}