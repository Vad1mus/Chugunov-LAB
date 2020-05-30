#include <iostream>
#include "Lessons.h"

void Lessons::set_audienceID(const string index) {
	this->audienceID = index;
}

void Lessons::set_lecturerName(const string name) {
	this->lecturerName = name;
}

void Lessons::set_lessonType(const string type) {
	this->lessonType = type;
}

void Lessons::set_studAmount(const int number) {
	this->studAmount = number;
}

void Lessons::set_lessonStartTime(const int time) {
	this->lessonStartTime = time;
}

const string Lessons::get_audienceID() const {
	return audienceID;
}

const string Lessons::get_lecturerName() const {
	return lecturerName;
}

const string Lessons::get_lessonType() const {
	return lessonType;
}

const int Lessons::get_studAmount() const {
	return studAmount;
}

const int Lessons::get_lessonStartTime() const {
	return lessonStartTime;
}

void Lessons::generateLesson()
{
	cout << "\nEnter the subject name: ";
	cin >> lessonType;
	cout << "Enter lecturer name: ";
	cin >> lecturerName;
	cout << "Enter an audience ID: ";
	cin >> audienceID;
	cout << "Enter lesson start time: ";
	cin >> lessonStartTime;
	cout << "Enter a number of students in audience: ";
	cin >> studAmount;
}