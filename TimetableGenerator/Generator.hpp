#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include "Lesson.h"
#include "Timetable.h"

using namespace std;
//Ora nev, max ora szam				-standard
//Ora nev, max ora szam, idopont	-special

string GenerateHash(const vector<Lesson*>& lessons) {
	// Hozz�adja karakteresen az ID �rt�k�t egy inthez �s azt pusholja a hashes-be
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
	// Sz�tv�logatni az id� limites �r�kat
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


bool ReadLessons(const string& file, vector<Lesson*>& lessons, vector<string>& hashes, int& days, int& slots, vector<Lesson*>& standardLessons, vector<Lesson*>& specialLessons) {
	// 1. Beolvassa adott streamet v�gjelig
	// 2. Ha m�g nem volt ilyen t�rgy l�trehozza az output-ra
	//	  Ha m�r volt akkor hozz�ad egy countot �s/vagy specific timeot
	// Minta: T�pus(practice, laboratory, lecture) N�v �p�let Emelet Terem Oraszam
	ifstream fs(file);
	string line;
	int totalLessonsCount= 0;

	getline(fs, line); // TO-DO ha tudja
	istringstream iss(line);
	bool count = !(iss >> days >> slots);

	while (getline(fs, line))
	{
		istringstream iss(line);
		int type, numberPerWeek;
		string name;
		TimeSlot special;
		Location location;
		Lesson* temp = nullptr;

		bool fail = !(iss >> type >> name >> location.building >>location.level >> location.room >> numberPerWeek);
		bool extraFail = !(iss >> special.Day >> special.Slot);
		bool alreadyAdded = false;

		if (fail) { break; } // TO-DO: Exception handling

		for (int i = 0; i < lessons.size(); i++)
		{
			if (lessons[i]->getName().compare(name)==0&&location==lessons[i]->getLocation())
			{
				alreadyAdded = true;
				lessons[i]->addCountPerWeek(numberPerWeek);
				totalLessonsCount += numberPerWeek;
				if (!extraFail) { lessons[i]->addSpecificTime(special); } // TO-DO temp=nullptr csere
				break; //TO-DO: While-al ki lehetne v�ltani
			}
		}

		if (!alreadyAdded) {
			totalLessonsCount += numberPerWeek;
			switch (type)
			{
			case practice:
				temp = new Practice(name, location.building, location.level, location.room, numberPerWeek); // TO-DO T�RL�S?
				break;
			case laboratory:
				temp = new Laboratory(name, location.building, location.level, location.room, numberPerWeek); // TO-DO T�RL�S?
				break;
			case lecture:
				temp = new Lecture(name, location.building, location.level, location.room, numberPerWeek); // TO-DO T�RL�S?
				break;
			default:
				break;
			}

			if (!extraFail) { temp->addSpecificTime(special); } // TO-DO temp=nullptr csere
			lessons.push_back(temp);
		}
	}
	for (int i = 0; i < (days*slots)-totalLessonsCount; i++)
	{
		Lesson* temp = new Lecture("Break", "", "", "", 1);
		lessons.push_back(temp);
	}

	hashes.push_back(GenerateHash(lessons));

	SplitLessonsToStdAndSpec(lessons, standardLessons, specialLessons); //TO-DO bele k�ne rakni a beolvas�shoz is

	return true;
}

bool GenerateTimetable(const vector<Lesson*>& standard, const vector<Lesson*>& special, Timetable& output, int days, int timeslots) {
	// 1. Ciklus minden napra egy temp vector<lesson> be
	// 1.1 Megn�zi van-e arra a napra speci�lis, ha igen azt jelzi egy !�J! temp list�ba
	// 1.2 Elkezdi felt�lteni standard elemekkel am�g a temp list�ba nem fut id� szerint bele
	//	   Ha belefut beteszi a sp�ci elemet �s folytatja tov�bb
	// 1.3 V�g�n hozz�adja az outputhoz a temp vector <lesson-t>

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
						standard[k]->incrementHeldPerWeek();
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