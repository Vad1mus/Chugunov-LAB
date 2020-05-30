#pragma once
#include "Lessons.h"

class Home : public Lessons
{
public:
	Home();
	Home(const int home, const string t, const string name, const string ID, const int time, const int qty);
	Home(const Home &obj);

	//Accessors
	inline const int& get_numOfHWs() const { return this->numOfHWs; };
	
	//Functions
	void generate() override;

private:
	int numOfHWs;
};