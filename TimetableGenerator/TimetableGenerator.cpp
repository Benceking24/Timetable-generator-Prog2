  //Memory leak
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


#include "Helper.hpp" // Includes Academic ranks enum and backward conversion (AssistantLecturer, Lecturer, Professor)
#include "Scholar.h"
#include "Lesson.h"
#include "Timetable.h"
#include "Generator.hpp"

//TO-DO: Intelisense comments
//TO-DO: El kéne tárolni az aktuális hash-t hogy kétszer ugyanazt ne generálja le?

using namespace std;

int main() {
	{
		/*int numberOfVariations = 0;
		Timetable v1 = Timetable(1, 3);
		vector<Lesson*> dayOne;
		dayOne.push_back(new Lecture("Fizika", "F", "1", "201", 5));
		dayOne.push_back(new Practice("Fizika", "F", "1", "201", 5));
		dayOne.push_back(new Laboratory("Fizika", "F", "1", "201", 5));
		v1.addDay(dayOne);
		v1.print(cout);
		*/

		vector<Lesson*> temp;
		vector<int> hashes;
		ReadLessons("demo.txt", temp, hashes);
		vector<Lesson*> standard;
		vector<Lesson*> special;
		SplitLessonsToStdAndSpec(temp, standard, special); //TO-DO bele kéne rakni a beolvasáshoz is
		
		Timetable v2 = Timetable(2, 3);
		GenerateTimetable(standard, special, v2, 2, 3);
		v2.print(cout);

		standard[0]->print(cout);
		standard[1]->print(cout);
		swap(standard[0], standard[1]);
		standard[0]->print(cout);
		standard[1]->print(cout);

		for (int i = 0; i < standard.size(); i++)
		{
			delete standard[i];
		}
		standard.clear();
		for (int i = 0; i < special.size(); i++)
		{
			delete special[i];
		}
		special.clear();
		temp.clear();
		/*{

		//Setting the size of matrix
		const int daysPerWeek = 1;
		const int lessonsPerDay = 3;

		vector<vector<Lesson*>> Lessons;

		vector<Lesson*> dayOne;
		dayOne.push_back(new Lecture("Fizika", "F", "1", "201", 5));
		dayOne.push_back(new Practice("Fizika", "F", "1", "201", 5));
		dayOne.push_back(new Laboratory("Fizika", "F", "1", "201", 5));
		Lessons.push_back(dayOne);

		for (int i = 0; i < Lessons[0].size(); i++)
		{
			Lessons[0][i]->print(cout);
			delete Lessons[0][i];
		}
		Lessons.clear();

		Scholar teacher = Scholar("Kis", Professor, 20);
		cout << teacher;
		}*/
	}
	_CrtDumpMemoryLeaks(); //Memory leak
	return 0;
}