#pragma once
#include "Home.h"

class HomeList
{
public:
	~HomeList();
	void addHW(Home& hw);
	void removeHW(int pos);
	void showAllHWs();
	inline const int& get_size() const { return this->size; };
	inline const int& get_sumHW() const { return this->sumHW; }
	inline const int& get_sum() const { return this->sum; }

private:
	Home *hws;
	int size = 0;
	int sum = 0;
	int sumHW = 0;
};