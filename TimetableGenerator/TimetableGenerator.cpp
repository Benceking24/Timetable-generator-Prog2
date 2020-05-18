/*  //Memory leak
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
*/

#include <iostream>
#include "Helper.hpp" // Includes Academic ranks enum and backward conversion (AssistantLecturer, Lecturer, Professor)
#include "Scholar.h"
#include "Lesson.h"
#include <vector>

//TO-DO: Intelisense comments

using namespace std;

int main() {
	{
	Scholar teacher = Scholar("Kis", Professor, 20);
	vector<Lesson*> Lessons;
	Lessons.push_back(new Lecture("Fizika", "F", "1", "201", 5));
	Lessons.push_back(new Practice("Fizika", "F", "1", "201", 5));
	Lessons.push_back(new Laboratory("Fizika", "F", "1", "201", 5));
	for (int i = 0; i < Lessons.size(); i++)
	{
		Lessons[i]->print(cout);
		delete Lessons[i];
	}
	Lessons.clear();
	cout << teacher;
	}
	//_CrtDumpMemoryLeaks(); //Memory leak
	return 0;
}