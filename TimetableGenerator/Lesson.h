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
	unsigned int heldPerWeek; //count of actual lessons in timetable
	int minQualification;
	vector<TimeSlot> specificTimes;
	//T* teacher;
public:
	Lesson(const string& Name, const string& Building, const string& Level, const string& Room, const unsigned int CountPerWeek, const int MinQualification); //TO-DO: default values
	~Lesson();
	const unsigned int getId() const;
	string getName() const;
	Location getLocation() const;
	unsigned int getCountPerWeek() const;
	unsigned int getHeldPerWeek() const;
	void addCountPerWeek(int);
	bool incrementHeldPerWeek();
	int getMinQualification() const;
	vector<TimeSlot> getSpecificTimes() const;
	bool addSpecificTime(const TimeSlot& time);
	virtual void print(ostream& os)=0;
};


class Lecture : public Lesson {
public:
	Lecture(const string& Name, const string& Building, const string& Level, const string& Room, const unsigned int CountPerWeek, const int MinQualification = Professor); //TO-DO: default values
	void print(ostream& os); //TO-DO: Nem jobb az hogy van egy print függvény Lesson-re és ilyenkor azt hívja meg elejére odaírva az altípust?
};

class Practice : public Lesson {

public:
	Practice(const string& Name, const string& Building, const string& Level, const string& Room, const unsigned int CountPerWeek, const int MinQualification = AssistantLecturer); //TO-DO: default values
	void print(ostream& os);
};

class Laboratory : public Lesson {

public:
	Laboratory(const string& Name, const string& Building, const string& Level, const string& Room, const unsigned int CountPerWeek, const int MinQualification = Lecturer); //TO-DO: default values
	void print(ostream& os);
};