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
public:
	Lesson(const string& Name, const string& Building, const string& Level, const string& Room, const unsigned int CountPerWeek); //TO-DO: default values
	const unsigned int getId() const;
	string getName() const;
	Location getLocation() const;
	unsigned int getCountPerWeek() const;
	unsigned int getHeldPerWeek() const;
	bool incrementHeldPerWeek();
	//virtual int getMinQualification() const = 0;
};


class Lecture : public Lesson {
private:
	int minQualification;
public:
	Lecture(const string& Name, const string& Building, const string& Level, const string& Room, const unsigned int CountPerWeek, const int MinQualification); //TO-DO: default values
	int getMinQualification() const;
	friend ostream& operator<< (ostream& os, Lecture& lesson); //TO-DO: Nem jobb az hogy van egy print függvény Lesson-re és ilyenkor azt hívja meg elejére odaírva az altípust?
};

class Practice : public Lesson {
private:
	int minQualification;
public:
	Practice(const string& Name, const string& Building, const string& Level, const string& Room, const unsigned int CountPerWeek, const int MinQualification); //TO-DO: default values
	int getMinQualification() const;
	friend ostream& operator<< (ostream& os, Practice& lesson);
};

class Laboratory : public Lesson {
private:
	int minQualification;
public:
	Laboratory(const string& Name, const string& Building, const string& Level, const string& Room, const unsigned int CountPerWeek, const int MinQualification); //TO-DO: default values
	int getMinQualification() const;
	friend ostream& operator<< (ostream& os, Laboratory& lesson);
};