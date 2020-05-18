#pragma once
#include <iostream>
#include <vector>
#include <string>
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
public:
	Timetable(const int Days, const int Lessons);
	~Timetable();
	const unsigned int getId() const;
	const int getDaysPerWeek() const;
	const int getLessonsPerDay() const;
	bool addDay(vector<Lesson*>& day); //TO-DO Exception handling
	void print(ostream& os);
};

