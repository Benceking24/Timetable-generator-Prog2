#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Helper.hpp"
#include "Lesson.h"

using namespace std;
static unsigned int NextTimetableId = 0;

class Timetable
{
private:
	const unsigned int id;
	const int daysPerWeek;
	const int lessonsPerDay;
	vector<vector<Lesson*>> Lessons;
	string hash;
public:
	Timetable(const int Days, const int Lessons);
	~Timetable();
	const unsigned int getId() const;
	const int getDaysPerWeek() const;
	const int getLessonsPerDay() const;
	string getHash() const;
	void addDay(const vector<Lesson*>& day);
	bool setHash(const string& Hash);
	void print(ostream& os, const int width = 20) const;
};

