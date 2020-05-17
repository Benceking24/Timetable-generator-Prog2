#pragma once
#include <sstream>
#include <string>

using namespace std;

enum AcademicRank { AssistantLecturer, Lecturer, Professor };

struct Location
{
	string building;
	string level;
	string room;
};

static const char* AcadaemicRankByName(int rank) {
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

static const char* LocationToString(string& output, Location location){ //TO-DO: Location reference would be better
	stringstream ss;
	ss << "Building: " << location.building << " Level: " << location.level << " Room: " << location.room;
	output = ss.str();
	return output.c_str();
}