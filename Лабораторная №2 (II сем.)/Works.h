#pragma once
#include "Lessons.h"

class Works
{
public:
	~Works();
	void addWork(Lessons& lesson);
	void removeWork(int pos);
	void showAll();
	inline const int& WorksForSem() const { return this->sum; };
	inline const int& get_size() const { return this->size; };

private:
	Lessons* lessons;
	int size = 0;
	int sum = 0;
};