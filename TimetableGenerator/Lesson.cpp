#define _CRT_SECURE_NO_WARNINGS 1 
#include "Lesson.h"

Lesson::Lesson(const char* Name, const char* Building, const char* Level, const char* Room, unsigned int CountPerWeek, int MinQualification) :id(NextLessonId), countPerWeek(CountPerWeek), minQualification(MinQualification), heldPerWeek(0)
{
	NextLessonId++;
	Location Tlocation = {Building, Level, Room};
	location = Tlocation;
	name = new char[sizeof(Name)];
	strcpy(name, Name);
}

//return os << lesson.id << ";" << lesson.name <<";" << lesson.location <<";"<< lesson.minQualification<< ";" << lesson.countPerWeek <<";" <<lesson.heldPerWeek << ";" << lesson.teacher << endl;
