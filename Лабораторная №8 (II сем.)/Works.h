#pragma once
#include "Lessons.h"
#include "Home.h"

class Works
{
public:
	Works();
	~Works();
	
	//Functions
	void push_back(Lessons* lesson);
	void pop_front();
	void erase(int pos);
	void show();
	void clear();

	//Accesssors
	inline const int& get_works() const { return this->sumOfWorks; };
	inline const int& get_homeworks() const { return this->sumOfHWs; };
	inline const int& get_size() const { return this->size; };

	//Inner classes
	class Node
	{
	public:
		Lessons *lesson;
		Node *next;
		Node(Lessons *l = nullptr, Node *n = nullptr);
	};

	//Operators
	Node* operator[] (const int pos);
	friend ostream& operator<< (ostream& os, Works& w);
	friend ostream& operator<< (ostream& os, Works::Node* w);

private:
	Node *head;
	int size;
	int sumOfHWs;
	int sumOfWorks;
};

ostream& operator<< (ostream& os, Works& w);
ostream& operator<< (ostream& os, Works::Node* w);