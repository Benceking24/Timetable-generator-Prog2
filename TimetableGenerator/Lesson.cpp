#include "Lesson.h"

Lesson::Lesson(const string& Name, const string& Building, const string& Level, const string& Room, unsigned int CountPerWeek) :id(NextLessonId), countPerWeek(CountPerWeek), heldPerWeek(0),name(Name),location({Building,Level,Room})
{ NextLessonId++; }

const unsigned int Lesson::getId() const {return id;}

string Lesson::getName() const {return name;}

Location Lesson::getLocation() const {return location;}

unsigned int Lesson::getCountPerWeek() const { return countPerWeek; }

unsigned int Lesson::getHeldPerWeek() const { return heldPerWeek; }

bool Lesson::incrementHeldPerWeek() { //TO-DO Exception handling 
	if (heldPerWeek < countPerWeek) {
		heldPerWeek++;
		return true;
	}
	return false;
}

Lecture::Lecture(const string& Name, const string& Building, const string& Level, const string& Room, const unsigned int CountPerWeek, const int MinQualification) :Lesson(Name, Building, Level, Room, CountPerWeek), minQualification(MinQualification) {}

int Lecture::getMinQualification() const { return minQualification; }

ostream& operator<<(ostream& os, Lecture& lesson)
{
	string temp;
	return os << "Lecture:\tId: " << lesson.getId() << "\t Name: " << lesson.getName() << "\t Location: " << LocationToString(temp, lesson.getLocation()) << "\t Minimum Qualification: " << AcadaemicRankByName(lesson.getMinQualification())  << "\t Count per week: " << lesson.getCountPerWeek() << "\t Held per week: " << lesson.getHeldPerWeek() << endl;
}

ostream& operator<<(ostream& os, Practice& lesson)
{
	string temp;
	return os << "Practice:\tId: " << lesson.getId() << "\t Name: " << lesson.getName() << "\t Location: " << LocationToString(temp, lesson.getLocation()) << "\t Minimum Qualification: " << AcadaemicRankByName(lesson.getMinQualification()) << "\t Count per week: " << lesson.getCountPerWeek() << "\t Held per week: " << lesson.getHeldPerWeek() << endl;
}


ostream& operator<<(ostream& os, Laboratory& lesson)
{
	string temp;
	return os << "Laboratory:\tId: " << lesson.getId() << "\t Name: " << lesson.getName() << "\t Location: " << LocationToString(temp, lesson.getLocation()) << "\t Minimum Qualification: " << AcadaemicRankByName(lesson.getMinQualification()) << "\t Count per week: " << lesson.getCountPerWeek() << "\t Held per week: " << lesson.getHeldPerWeek() << endl;
}


Practice::Practice(const string& Name, const string& Building, const string& Level, const string& Room, const unsigned int CountPerWeek, const int MinQualification) :Lesson(Name, Building, Level, Room, CountPerWeek), minQualification(MinQualification) {}


int Practice::getMinQualification() const { return minQualification; }

Laboratory::Laboratory(const string& Name, const string& Building, const string& Level, const string& Room, const unsigned int CountPerWeek, const int MinQualification) :Lesson(Name, Building, Level, Room, CountPerWeek), minQualification(MinQualification) {}


int Laboratory::getMinQualification() const { return minQualification; }
