#pragma once
#include <sstream>
#include <string>

using namespace std;

enum LessonTypes {practice, laboratory, lecture};

enum AcademicRank { AssistantLecturer, Lecturer, Professor };

enum DaysOfWeek { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };

struct Location
{
	string building;
	string level;
	string room;
};


struct TimeSlot {
	int Day;
	int Slot;
};

static string AcadaemicRankByName(const int rank) {
	switch (rank)
	{
	case AssistantLecturer:
		return "Assistant Lecturer";
		break;
	case Lecturer:
		return "Lecturer";
		break;
	case Professor:
		return "Professor";
		break;
	default:
		break;
	}
	return nullptr;
}

static string DaysOfWeek(const int nthDay) {
	switch (nthDay)
	{
	case Monday:
		return "Monday";
		break;
	case Tuesday:
		return "Tuesday";
		break;
	case Wednesday:
		return "Wednesday";
		break;
	case Thursday:
		return "Thursday";
		break;
	case Friday:
		return "Friday";
		break;
	case Saturday:
		return "Saturday";
		break;
	case Sunday:
		return "Sunday";
		break;
	default:
		break;
	}
	return nullptr;
}

static const char* LocationToString(string& output, const Location& location){
	stringstream ss;
	ss << "Building: " << location.building << " Level: " << location.level << " Room: " << location.room;
	output = ss.str();
	return output.c_str();
}