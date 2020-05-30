#include "Home.h"

Home::Home() : Lessons()
{
	this->numOfHWs = 0;
}

Home::Home(const int home, const string t, const string name, const string ID, const int time, const int qty)
	: Lessons(t, name, ID, time, qty)
{
	this->numOfHWs = home;
}

Home::Home(const Home & obj) : Lessons(obj)
{
	this->numOfHWs = obj.numOfHWs;
}

Home::~Home()
{
	
}

void Home::generate()
{
	Lessons::generate();
	cout << "Enter a number of homework that student must complete per semester: ";
	cin >> this->numOfHWs;
}
