#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "Helper.hpp"
#include "Generator.hpp"
#include "Scholar.h"
#include "Lesson.h"
#include "Timetable.h"

//TO-DO: Intelisense comments
//Kikötések: - egy konkrét bejegyzés csak egyszer lehet fix idõpontos
//			 - egy nap csak egy fix idõpontos elem lehet
//TO-DO: Üres elemek
//TO-DO: ha nincs fájl, ha üres a fájl, ha sok az adat, ha kevés az adat, ha rossz az adat

using namespace std;

int main() {
	{
		
		int days, slots;
		vector<Lesson*> Lessons, standardLessons, specialLessons;
		vector<string> hashes;
		ReadLessons("demo.txt", Lessons, hashes, days, slots, standardLessons, specialLessons);
		vector<Timetable*> timetables;
		bool variations = false;
		bool first = true;
		bool over10VaritaonContinue = false;
		int i = 0;
		int j = 1;
		do
		{
			vector<Lesson*> tempStandardLessons = standardLessons;
			if (first)
			{
				first = false;
			}
			else
			{
				if (i == 0 && j > tempStandardLessons.size()-1)
				{
					break;
				}
				variations = nextVariation(tempStandardLessons, i, j);
			}
			Timetable* variation = new Timetable(days, slots);
			GenerateTimetable(tempStandardLessons, specialLessons, *variation, days, slots);
			variation->setHash(GenerateHash(tempStandardLessons));
			timetables.push_back(variation);
			resetHeldLessons(Lessons);
		} while (!variations); 
			
		if (timetables.size()>=10)
		{
			cout << "The number of variations is over 10. Do you want to print all " << timetables.size() << " version? (Y/n)" << endl;
			char input;
			cin >> input;
			switch (input)
			{
			case 'Y':
				over10VaritaonContinue = true;
				break;
			case 'y':
				over10VaritaonContinue = true;
				break;
			case 'N':
				over10VaritaonContinue = false;
				break;
			case 'n':
				over10VaritaonContinue = false;
				break;
			default:
				over10VaritaonContinue = false;
				break;
			}
		}

		if (over10VaritaonContinue)
		{
			cout << "Number of variations: " << timetables.size() << endl;
			for (int i = 0; i < timetables.size(); i++)
			{
				cout << "ID of timetable: " << timetables[i]->getHash() << endl;
				timetables[i]->print(cout, 30);
				cout << endl;
			}
		}
		for (int i = 0; i < timetables.size(); i++)
		{
			delete timetables[i];
		}
		timetables.clear();
		for (int i = 0; i < standardLessons.size(); i++)
		{
			delete standardLessons[i];
		}
		standardLessons.clear();
		for (int i = 0; i < specialLessons.size(); i++)
		{
			delete specialLessons[i];
		}
		specialLessons.clear();
		Lessons.clear();
	}
	_CrtDumpMemoryLeaks(); //Memory leak
	return 0;
}