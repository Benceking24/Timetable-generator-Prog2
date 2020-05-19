#include "Lesson.h"

Lesson::Lesson(const string& Name, const string& Building, const string& Level, const string& Room, unsigned int CountPerWeek, const int MinQualification) :id(NextLessonId), countPerWeek(CountPerWeek), heldPerWeek(0),name(Name),location({Building,Level,Room}), minQualification(MinQualification)
{ 	NextLessonId++; }

Lesson::~Lesson()
{
	specificTimes.clear();
}

const unsigned int Lesson::getId() const {return id;}

string Lesson::getName() const {return name;}

string Lesson::getLongName() const
{
	stringstream ss;
	string temp = typeid(*this).name();
	ss << name<<" "<< temp.substr(6, temp.length());
	return ss.str();
}

Location Lesson::getLocation() const {return location;}

unsigned int Lesson::getCountPerWeek() const { return countPerWeek; }

unsigned int Lesson::getHeldPerWeek() const { return heldPerWeek; }

int Lesson::getMinQualification() const { return minQualification; }

vector<TimeSlot> Lesson::getSpecificTimes() const
{
	return specificTimes;
}

bool Lesson::addSpecificTime(const TimeSlot& time)
{
	specificTimes.push_back(time);
	return true; //TO-DO Exception handling
}

void Lesson::addCountPerWeek(int amount) { countPerWeek += amount; }

bool Lesson::incrementHeldPerWeek() { //TO-DO Exception handling 
	if (heldPerWeek < countPerWeek) {
		heldPerWeek ++;
		return true;
	}
	return false;
}

void Lesson::resetHeldPerWeek()
{
	heldPerWeek = 0;
}

Lecture::Lecture(const string& Name, const string& Building, const string& Level, const string& Room, const unsigned int CountPerWeek, const int MinQualification) :Lesson(Name, Building, Level, Room, CountPerWeek, MinQualification) {}

void Lecture::print(ostream& os)
{
	string temp;
	 os << "Lecture:\tId: " << getId() << "\t Name: " << getName() << "\t Location: " << LocationToString(temp, getLocation()) << "\t Minimum Qualification: " << AcadaemicRankByName(getMinQualification())  << "\t\t Count per week: " << getCountPerWeek() << "\t Held per week: " << getHeldPerWeek() << endl;
}

Practice::Practice(const string& Name, const string& Building, const string& Level, const string& Room, const unsigned int CountPerWeek, const int MinQualification) :Lesson(Name, Building, Level, Room, CountPerWeek, MinQualification) {}

void Practice::print(ostream& os)
{
	string temp;
	os << "Practice:\tId: " << getId() << "\t Name: " << getName() << "\t Location: " << LocationToString(temp, getLocation()) << "\t Minimum Qualification: " << AcadaemicRankByName(getMinQualification()) << "\t Count per week: " << getCountPerWeek() << "\t Held per week: " << getHeldPerWeek() << endl;
}

Laboratory::Laboratory(const string& Name, const string& Building, const string& Level, const string& Room, const unsigned int CountPerWeek, const int MinQualification) :Lesson(Name, Building, Level, Room, CountPerWeek, MinQualification) {}

void Laboratory::print(ostream& os)
{
	string temp;
	os << "Laboratory:\tId: " << getId() << "\t Name: " << getName() << "\t Location: " << LocationToString(temp, getLocation()) << "\t Minimum Qualification: " << AcadaemicRankByName(getMinQualification()) << "\t\t Count per week: " << getCountPerWeek() << "\t Held per week: " << getHeldPerWeek() << endl;
}



