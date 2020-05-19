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

static string AcadaemicRankByName(int rank) {
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

static string DaysOfWeek(int nthDay) {
	switch (nthDay)
	{
	case Monday:
		return "Mond";
		break;
	case Tuesday:
		return "Tues";
		break;
	case Wednesday:
		return "Wedn";
		break;
	case Thursday:
		return "Thur";
		break;
	case Friday:
		return "Frid";
		break;
	case Saturday:
		return "Satu";
		break;
	case Sunday:
		return "Sund";
		break;
	default:
		break;
	}
	return nullptr;
}

static const char* LocationToString(string& output, Location location){ //TO-DO: Location reference would be better
	stringstream ss;
	ss << "Building: " << location.building << " Level: " << location.level << " Room: " << location.room;
	output = ss.str();
	return output.c_str();
}