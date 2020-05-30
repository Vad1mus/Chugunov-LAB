#pragma once
#include "Lessons.h"

class Works : public Lessons
{
public:
	void addWork(Lessons& lesson);
	void removeWork(int pos);
	void showAll();
	void endOfProgramm();
	const int get_size() const;

private:
	Lessons* lessons;
	int size = 0;
};