#include <fstream>
#include <regex>
#include "Lessons.h"

using std::regex;
using std::regex_match;
using std::getline;

Lessons::Lessons()
{
	audienceID = "NULL";
	lecturerName = "NULL";
	lessonType = "NULL";
	lessonStartTime = 0;
	numOfWorks = 0;
}

Lessons::Lessons(const string t, const string name, const string ID, const int time, const int qty)
{
	audienceID = ID;
	lecturerName = name;
	lessonType = t;
	lessonStartTime = time;
	numOfWorks = qty;
}

Lessons::Lessons(const Lessons & copyObject)
{
	this->audienceID = copyObject.audienceID;
	this->lecturerName = copyObject.lecturerName;
	this->lessonStartTime = copyObject.lessonStartTime;
	this->lessonType = copyObject.lessonType;
	this->numOfWorks = copyObject.numOfWorks;
}

Lessons::~Lessons()
{
	
}

void Lessons::generate()
{
	regex allowableStr("([A-Z])""(\\w)*(\\s)?(\.)?");
	cout << "\nEnter the subject name: ";
	cin.ignore(20, '\n');
	do {
		getline(cin, lessonType);
		if (!regex_match(lessonType, allowableStr))
			cout << "Error (invalid syntax)!\nRepeat entering: ";
	} while (!regex_match(lessonType, allowableStr));
	
	cout << "Enter lecturer name: ";
	do {
		getline(cin, lecturerName);
		if (!regex_match(lecturerName, allowableStr))
			cout << "Error (invalid syntax)!\nRepeat entering: ";
	} while (!regex_match(lecturerName, allowableStr));
	
	cout << "Enter an audience ID: ";
	do {
		getline(cin, audienceID);
		if (!(regex_match(audienceID, allowableStr)))
			cout << "Error (invalid syntax)!\nRepeat entering: ";
	} while (!(regex_match(audienceID, allowableStr)));

	cout << "Enter lesson start time: ";
	cin >> lessonStartTime;
	cout << "Enter a number of works student has completed per semester: ";
	cin >> numOfWorks;
}