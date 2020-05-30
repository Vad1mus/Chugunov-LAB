#include <iostream>
#include "Works.h"

Works::Works()
{
	head = nullptr;
	size = 0;
	sumOfHWs = 0;
	sumOfWorks = 0;
}

Works::Node::Node(Lessons *l, Node *n)
{
	this->lesson = l;
	this->next = n;
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
		while (temp)
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

Works::Node* Works::operator[](const int pos)
{
	if (pos >= size)
	{
		cout << "Error (out of range)";
		return nullptr;
	}
	if (!pos)
	{
		return head;
	}
	Node *out = head;
	for (int i = 0; i < pos; i++)
		out = out->next;
	return out;
}

ostream& operator<<(ostream & os, Works& w)
{
	if (!w.head)
	{
		os << "\nError (list is empty)\n";
		return os;
	}
	Works::Node *temp = w.head;
	int i = 0;
	while (temp)
	{
		os << "\nInfo about lesson #" << ++i << ": " << endl
			<< "Subject: " << temp->lesson->get_lessonType() << endl
			<< "Lecturer: " << temp->lesson->get_lecturerName() << endl
			<< "Audience ID: " << temp->lesson->get_audienceID() << endl
			<< "Lesson start time: " << temp->lesson->get_lessonStartTime() << endl
			<< "The number of works student wrote for the semester: " << temp->lesson->get_numOfWorks() << endl;
		if (((Home *)temp->lesson)->get_numOfHWs() > 0)
			os << "The number of hometasks student wrote per semester: " << ((Home *)temp->lesson)->get_numOfHWs() << endl;
		temp = temp->next;
	}
	return os;
}

ostream & operator<<(ostream & os, Works::Node * w)
{
	if (!w->lesson)
	{
		os << "Error (Bad Index)";
		return os;
	}
	os << "\nSubject: " << w->lesson->get_lessonType() << endl
		<< "Lecturer: " << w->lesson->get_lecturerName() << endl
		<< "Audience ID: " << w->lesson->get_audienceID() << endl
		<< "Lesson start time: " << w->lesson->get_lessonStartTime() << endl
		<< "The number of works student wrote for the semester: " << w->lesson->get_numOfWorks() << endl;
	if (((Home *)w->lesson)->get_numOfHWs() > 0)
		os << "The number of hometasks student wrote per semester: " << ((Home *)w->lesson)->get_numOfHWs() << endl;
	return os;
}