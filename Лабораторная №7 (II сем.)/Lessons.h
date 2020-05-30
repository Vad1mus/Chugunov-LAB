#pragma once
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Lessons
{
public:
	Lessons();
	Lessons(const string t, const string name, const string ID, const int time, const int qty);
	Lessons(const Lessons & copyObject);

	//Accessors
	void set_audienceID(const string index) { this->audienceID = index; };
	void set_lecturerName(const string name) { this->lecturerName = name; };
	void set_lessonType(const string type) { this->lessonType = type; };
	void set_numOfWorks(const int number) { this->numOfWorks = number; };
	void set_lessonStartTime(const int time) { this->lessonStartTime = time; };
	
	inline const string& get_audienceID() const { return this->audienceID; };
	inline const string& get_lecturerName() const { return this->lecturerName; };
	inline const string& get_lessonType() const { return this->lessonType; };
	inline const int& get_numOfWorks() const { return this->numOfWorks; };
	inline const int& get_lessonStartTime() const { return this->lessonStartTime; };
	
	//Functions
	virtual void generate();

private:
	string audienceID;
	string lecturerName;
	string lessonType;
	int numOfWorks;
	int lessonStartTime;
};