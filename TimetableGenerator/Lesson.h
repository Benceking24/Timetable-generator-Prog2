#pragma once
#include <iostream>
#include <string>
#include <vector>
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
	unsigned int heldPerWeek;
	int minQualification;
	vector<TimeSlot> specificTimes;
public:
	Lesson(const string& Name, const string& Building, const string& Level, const string& Room, const unsigned int CountPerWeek, const int MinQualification);
	~Lesson();
	const unsigned int getId() const;
	string getName() const;
	string getLongName() const;
	Location getLocation() const;
	unsigned int getCountPerWeek() const;
	unsigned int getHeldPerWeek() const;
	void addCountPerWeek(const int);
	bool incrementHeldPerWeek();
	void resetHeldPerWeek();
	int getMinQualification() const;
	vector<TimeSlot> getSpecificTimes() const;
	void addSpecificTime(const TimeSlot& time);
	virtual void print(ostream& os)=0;
};


class Lecture : public Lesson {
public:
	Lecture(const string& Name, const string& Building, const string& Level, const string& Room, const unsigned int CountPerWeek, const int MinQualification = Professor);
	void print(ostream& os);
};

class Practice : public Lesson {

public:
	Practice(const string& Name, const string& Building, const string& Level, const string& Room, const unsigned int CountPerWeek, const int MinQualification = AssistantLecturer);
	void print(ostream& os);
};

class Laboratory : public Lesson {

public:
	Laboratory(const string& Name, const string& Building, const string& Level, const string& Room, const unsigned int CountPerWeek, const int MinQualification = Lecturer);
	void print(ostream& os);
};