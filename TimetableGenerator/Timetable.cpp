#include "Timetable.h"

Timetable::Timetable(const int Days, const int Lessons):id(NextTimetableId), daysPerWeek(Days), lessonsPerDay(Lessons) {NextTimetableId++;}

Timetable::~Timetable()
{

}

const unsigned int Timetable::getId() const {return id;}

const int Timetable::getDaysPerWeek() const {return daysPerWeek;}

const int Timetable::getLessonsPerDay() const {return lessonsPerDay;}

bool Timetable::addDay(vector<Lesson*>& day)
{
	Lessons.push_back(day);
	return true;
}

void Timetable::print(ostream& os)
{
	//Header
	os << "\t";
	for (int day = 0; day < daysPerWeek; day++)
	{
		os << DaysOfWeek(day) << "\t";
	}
	os << endl;

	//Body
	for (int slot = 0; slot < lessonsPerDay; slot++)
	{
		os << slot+1 << ".\t";
		for (int day = 0; day < daysPerWeek; day++)
		{
			os << Lessons[day][slot]->getName() <<"\t";
		}
		os << endl;
	}
}
