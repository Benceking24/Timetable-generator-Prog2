#include "Lesson.h"

Lesson::Lesson(const string& Name, const string& Building, const string& Level, const string& Room, unsigned int CountPerWeek, int MinQualification) :id(NextLessonId), countPerWeek(CountPerWeek), minQualification(MinQualification), heldPerWeek(0),name(Name),location({Building,Level,Room})
{
	NextLessonId++;
}

const unsigned int Lesson::getId() const {return id;}

string Lesson::getName() const {return name;}

Location Lesson::getLocation() const {return location;}

unsigned int Lesson::getCountPerWeek() const { return countPerWeek; }

unsigned int Lesson::getHeldPerWeek() const { return heldPerWeek; }

int Lesson::getMinQualification() const { return minQualification; }

bool Lesson::incrementHeldPerWeek() { //TO-DO Exception handling 
	if (heldPerWeek < countPerWeek) {
		heldPerWeek++;
		return true;
	}
	return false;
}

ostream& operator<< (ostream& os, Lesson& lesson)
{
	string temp; //used for location
				 //TO-DO better solution?
	return os << "Lesson: "<< "Id: " << lesson.getId() << "\t Name: " << lesson.getName() <<"\t Location: " << LocationToString(temp, lesson.getLocation()) <<"\t Minimum Qualification: "<< AcadaemicRankByName(lesson.getMinQualification()) << "\t Count per week: " << lesson.getCountPerWeek() <<"\t Held per week: " <<lesson.getHeldPerWeek() << endl;
}

