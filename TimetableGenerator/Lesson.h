#pragma once
#include <iostream>
#include <string>


struct Location
{
	const char* building;
	const char* level;
	const char* room;
};

static unsigned int NextLessonId = 0;

using namespace std;

class Lesson 
{
protected:
	const unsigned int id;
	char* name;
	Location location;
	unsigned int countPerWeek;
	unsigned int heldPerWeek; //count of actual lessons in timetable
	//T* teacher;
	int minQualification;
public:
	Lesson(const char* Name, const char* Building, const char* Level, const char* Room, unsigned int CountPerWeek, int MinQualification);
};

/*
class Lecture : public Lesson<class T> {
	Lecture();
};

class Practice : public Lesson<class T> {

};

class Laboratory : public Lesson<class T> {

};*/