  //Memory leak
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


#include "Helper.hpp" // (AssistantLecturer, Lecturer, Professor), 
#include "Scholar.h"
#include "Lesson.h"
#include "Timetable.h"
#include "Generator.hpp"

//TO-DO: Intelisense comments
//TO-DO: El k�ne t�rolni az aktu�lis hash-t hogy k�tszer ugyanazt ne gener�lja le?
//TO-DO: Mi van akkor ha csak 1 fajta bemenet van
//Kik�t�sek: - egy konkr�t bejegyz�s csak egyszer lehet fix id�pontos
//			 - egy nap csak egy fix id�pontos elem lehet
//TO-DO: �res elemek

using namespace std;

int main() {
	{
		int i = 0;
		int j = 1;
		vector<Lesson*> Lessons;
		vector<string> hashes;
		ReadLessons("demo.txt", Lessons, hashes);
		vector<Lesson*> standardLessons;
		vector<Lesson*> specialLessons;
		SplitLessonsToStdAndSpec(Lessons, standardLessons, specialLessons); //TO-DO bele k�ne rakni a beolvas�shoz is


		bool variations = false;
		bool first = true;
		do
		{
			vector<Lesson*> tempStandardLessons = standardLessons;
			if (first)
			{
				first = false;
			}
			else
			{
				variations = nextVariation(tempStandardLessons, i, j);
			}
			Timetable variation = Timetable(5, 5);
			GenerateTimetable(tempStandardLessons, specialLessons, variation, 5, 5);
			cout << "ID of timetable: "<<GenerateHash(tempStandardLessons) <<endl;
			variation.print(cout);
			cout << endl;
			resetHeldLessons(Lessons);
		} while (!variations);


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