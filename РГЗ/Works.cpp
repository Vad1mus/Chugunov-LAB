#include "Works.h"

Work::Work()
{
	this->subjec = '\0';
	this->author = '\0';
	this->teachName = '\0';
	this->mark = 0;
	this->id_gen++;
}

Work::Work(string sub, string a, string tName, int m)
{
	this->subjec = sub;
	this->author = a;
	this->mark = m;
	this->id_gen++;
}

Work::~Work()
{
}