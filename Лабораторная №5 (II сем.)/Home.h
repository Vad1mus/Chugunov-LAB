#pragma once
#include "Lessons.h"
#include "Works.h"

class Home : public Lessons
{
public:
	Home();
	Home(const int home, const string t, const string name, const string ID, const int time, const int qty);
	Home(const Home &obj);
	~Home();

	void setNumOfHW(int number) { this->numOfHWs = number; };
	inline const int& getNumOfHWs() const { return this->numOfHWs; };
	void generate() override;

private:
	Works work;
	int numOfHWs;
};