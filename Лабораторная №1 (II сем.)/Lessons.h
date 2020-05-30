#include <string>
using namespace std;

#pragma once
class Lessons
{
public:
	void set_audienceID(const string index);
	void set_lecturerName(const string name);
	void set_lessonType(const string type);
	void set_studAmount(const int number);
	void set_lessonStartTime(const int time);
	const string get_audienceID() const;
	const string get_lecturerName() const;
	const string get_lessonType() const;
	const int get_studAmount() const;
	const int get_lessonStartTime() const;
	void generateLesson();

private:
	string audienceID;
	string lecturerName;
	string lessonType;
	int studAmount;
	int lessonStartTime;
};