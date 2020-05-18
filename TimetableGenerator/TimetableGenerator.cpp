/*  //Memory leak
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
*/

#include "Helper.hpp" // Includes Academic ranks enum and backward conversion (AssistantLecturer, Lecturer, Professor)
#include "Scholar.h"
#include "Lesson.h"
#include "Timetable.h"

//TO-DO: Intelisense comments

using namespace std;

int main() {
	Timetable v1 = Timetable(5, 3);
	vector<Lesson*> dayOne;
	dayOne.push_back(new Lecture("Fizika", "F", "1", "201", 5));
	dayOne.push_back(new Practice("Fizika", "F", "1", "201", 5));
	dayOne.push_back(new Laboratory("Fizika", "F", "1", "201", 5));
	v1.addDay(dayOne);
	v1.addDay(dayOne);
	v1.addDay(dayOne);
	v1.addDay(dayOne);
	v1.addDay(dayOne);
	v1.addDay(dayOne);
	v1.print(cout);
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
	//_CrtDumpMemoryLeaks(); //Memory leak
	return 0;
}