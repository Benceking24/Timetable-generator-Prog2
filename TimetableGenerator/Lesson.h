#pragma once
#include <iostream>
#include <string>
#include "Helper.hpp"

using namespace std;
static unsigned int NextLessonId = 0;

class Lesson 
{
protected:
	const unsigned int id;
	string name;
	Location location;
	unsigned int countPerWeek;
	unsigned int heldPerWeek; //count of actual lessons in timetable
	//T* teacher;
	int minQualification;
public:
	Lesson(const string& Name, const string& Building, const string& Level, const string& Room, const unsigned int CountPerWeek, const int MinQualification);
	const unsigned int getId() const;
	string getName() const;
	Location getLocation() const;
	unsigned int getCountPerWeek() const;
	unsigned int getHeldPerWeek() const;
	int getMinQualification() const;
	bool incrementHeldPerWeek();
	friend ostream& operator<< (ostream& os, Lesson& leacher);
};


class Lecture : public Lesson {
	Lecture();
};

class Practice : public Lesson {

};

class Laboratory : public Lesson {

};