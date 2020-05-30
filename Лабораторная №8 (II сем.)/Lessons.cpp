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

void Lessons::operator=(const Lessons & obj)
{
	this->set_audienceID(obj.get_audienceID());
	this->set_lecturerName(obj.get_lessonType());
	this->set_lessonStartTime(obj.get_lessonStartTime());
	this->set_lessonType(obj.get_lessonType());
	this->set_numOfWorks(obj.get_numOfWorks());
}

bool Lessons::operator==(const Lessons & obj)
{
	bool expr = this->audienceID == obj.audienceID
		&& this->lecturerName == obj.lecturerName
		&& this->lessonType == obj.lessonType
		&& this->numOfWorks == obj.numOfWorks
		&& this->lessonStartTime == obj.lessonStartTime;
	return expr;
}

ostream & operator<<(ostream & os, const Lessons & obj)
{
	os << "Subject: " << obj.get_lessonType() << endl
		<< "Lecturer: " << obj.get_lecturerName() << endl
		<< "Audience ID: " << obj.get_audienceID() << endl
		<< "Lesson start time: " << obj.get_lessonStartTime() << endl
		<< "The number of works student wrote for the semester: " << obj.get_numOfWorks() << endl;
	return os;
}

istream & operator>>(istream & is, Lessons & obj)
{
	regex allowableStr("([A-Z])""(\\w)*(\\s)?(\.)?");
	cout << "\nEnter the subject name: ";
	do {
		getline(is, obj.lessonType);
		if (!regex_match(obj.lessonType, allowableStr))
			cout << "Error (invalid syntax)!\nRepeat entering: ";
	} while (!regex_match(obj.lessonType, allowableStr));

	cout << "Enter lecturer name: ";
	do {
		getline(is, obj.lecturerName);
		if (!regex_match(obj.lecturerName, allowableStr))
			cout << "Error (invalid syntax)!\nRepeat entering: ";
	} while (!regex_match(obj.lecturerName, allowableStr));

	cout << "Enter an audience ID: ";
	do {
		getline(is, obj.audienceID);
		if (!(regex_match(obj.audienceID, allowableStr)))
			cout << "Error (invalid syntax)!\nRepeat entering: ";
	} while (!(regex_match(obj.audienceID, allowableStr)));

	cout << "Enter lesson start time: ";
	is >> obj.lessonStartTime;
	cout << "Enter a number of works student has completed per semester: ";
	is >> obj.numOfWorks;
	return is;
}

