#include "Timetable.h"

Timetable::Timetable(const int Days, const int Lessons):id(NextTimetableId), daysPerWeek(Days), lessonsPerDay(Lessons), hash("") {NextTimetableId++;}

Timetable::~Timetable()
{

}

const unsigned int Timetable::getId() const {return id;}

const int Timetable::getDaysPerWeek() const {return daysPerWeek;}

const int Timetable::getLessonsPerDay() const {return lessonsPerDay;}

string Timetable::getHash() const
{
	return hash;
}

bool Timetable::addDay(vector<Lesson*>& day)
{
	Lessons.push_back(day);
	return true;
}

bool Timetable::setHash(const string& Hash)
{
	hash = Hash;
	return true;
}

void Timetable::print(ostream& os, const int width)
{
	//Header
	os << "\t";
	for (int day = 0; day < daysPerWeek; day++)
	{
		os << setw(width);
		os << DaysOfWeek(day) << "\t";
	}
	os << endl;

	//Body
	for (int slot = 0; slot < lessonsPerDay; slot++)
	{
		os << slot+1 << ".\t";
		for (int day = 0; day < daysPerWeek; day++)
		{
			if (Lessons[day][slot]->getName().compare("Break")==0)
			{
				os << setw(width);
				os << Lessons[day][slot]->getName() << "\t";

			}
			else
			{
				os << setw(width);
				os << Lessons[day][slot]->getLongName() << "\t";
			}
		}
		os << endl;
	}
}
