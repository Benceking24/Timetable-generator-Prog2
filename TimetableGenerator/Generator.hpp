#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <stdexcept>
#include "Lesson.h"
#include "Timetable.h"

using namespace std;

string GenerateHash(const vector<Lesson*>& lessons) {
	stringstream ss;
	for (int i = 0; i < lessons.size(); i++)
	{
		ss << lessons[i]->getId();
	}


	return ss.str();
}

bool operator==(const Location& lhs, const Location& rhs)
{
	
	return (lhs.building.compare(rhs.building) == 0 && lhs.level.compare(rhs.level) == 0 && lhs.room.compare(rhs.room) == 0) ? true : false;
}

void SplitLessonsToStdAndSpec(const vector<Lesson*>& input, vector<Lesson*>& standardLessons, vector<Lesson*>& specialLessons) {
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i]->getSpecificTimes().size() == 0) {
			standardLessons.push_back(input[i]);
		}
		else
		{
			specialLessons.push_back(input[i]);
		}
	}
}


void ReadLessons(const string& file, vector<Lesson*>& lessons, vector<string>& hashes, int& days, int& slots, vector<Lesson*>& standardLessons, vector<Lesson*>& specialLessons) {
	ifstream fs(file);
	if (!fs.is_open())
	{
		throw runtime_error("Can't open file");
	}
	string line;
	int totalLessonsCount= 0;

	getline(fs, line);
	istringstream iss(line);
	bool count = !(iss >> days >> slots);
	if (count)
	{
		throw runtime_error("Bad input on first line of file");
	}

	while (getline(fs, line))
	{
		istringstream iss(line);
		int type, numberPerWeek;
		string name;
		TimeSlot special;
		Location location;
		Lesson* temp = nullptr;

		bool fail = !(iss >> type >> name >> location.building >>location.level >> location.room >> numberPerWeek);
		bool specificTimeDescribed = !(iss >> special.Day >> special.Slot);
		bool alreadyAdded = false;

		if (fail)
		{
			throw runtime_error("Bad input at lesson description");
		}
		if (special.Day<0||special.Day>days-1||special.Slot<0||special.Slot>slots-1)
		{
			throw runtime_error("Bad input at specific time description. Overindexed time");
		}
		for (int i = 0; i < lessons.size(); i++)
		{
			if (lessons[i]->getName().compare(name)==0&&location==lessons[i]->getLocation())
			{
				alreadyAdded = true;
				lessons[i]->addCountPerWeek(numberPerWeek);
				totalLessonsCount += numberPerWeek;
				if (!specificTimeDescribed) { lessons[i]->addSpecificTime(special); }
				break;
			}
		}

		if (!alreadyAdded) {
			totalLessonsCount += numberPerWeek;
			switch (type)
			{
			case practice:
				temp = new Practice(name, location.building, location.level, location.room, numberPerWeek); 
				break;
			case laboratory:
				temp = new Laboratory(name, location.building, location.level, location.room, numberPerWeek); 
				break;
			case lecture:
				temp = new Lecture(name, location.building, location.level, location.room, numberPerWeek);
				break;
			default:
				break;
			}

			if (!specificTimeDescribed) { temp->addSpecificTime(special); }
			lessons.push_back(temp);
		}
	}
	for (int i = 0; i < (days*slots)-totalLessonsCount; i++)
	{
		Lesson* temp = new Lecture("Break", "", "", "", 1);
		lessons.push_back(temp);
	}

	hashes.push_back(GenerateHash(lessons));

	SplitLessonsToStdAndSpec(lessons, standardLessons, specialLessons); 

}

bool GenerateTimetable(const vector<Lesson*>& standard, const vector<Lesson*>& special, Timetable& output, const int days, const int timeslots) {
	for (int i = 0; i < days; i++)
	{
		vector<Lesson*> temp;
		int importantSlot = -1;
		Lesson* importatntlesson = nullptr;
		for (int j = 0; j < special.size(); j++)
		{
			for (int k = 0; k < special[j]->getSpecificTimes().size(); k++)
			{
				if (special[j]->getSpecificTimes()[k].Day == i)
				{
					importantSlot = special[j]->getSpecificTimes()[k].Slot;
					importatntlesson = special[j];
				}
			}
		}
		for (int j = 0; j < timeslots; j++)
		{
			if (importantSlot != j)
			{
				for (int k = 0; k < standard.size(); k++)
				{
					if (standard[k]->getCountPerWeek() > standard[k]->getHeldPerWeek())
					{
						temp.push_back(standard[k]);
						if (!(standard[k]->incrementHeldPerWeek()))
						{
							throw range_error("More lessons held than it should be");
						}
						break;
					}
				}
			}
			else
			{
				if (importatntlesson->getCountPerWeek() > importatntlesson->getHeldPerWeek())
				{
					temp.push_back(importatntlesson);
					importatntlesson->incrementHeldPerWeek();
				}
			}
		}
		output.addDay(temp);
	}

	return true;
}


bool nextVariation(vector<Lesson*>& standard, int& i, int& j) {

	if (j == standard.size()-1)
	{
		swap(standard[i], standard[j]);
		i++;
		return true;
	}
	else
	{
		swap(standard[i], standard[j]);
		i++;
		j++;
		return false;
	}


}

void resetHeldLessons(vector <Lesson*>& lessons){
	for (int i = 0; i < lessons.size(); i++)
	{
		lessons[i]->resetHeldPerWeek();
	}
}