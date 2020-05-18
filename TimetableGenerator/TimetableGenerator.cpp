#include <iostream>
#include "Helper.hpp" // Includes Academic ranks enum and backward conversion (AssistantLecturer, Lecturer, Professor)
#include "Scholar.h"
#include "Lesson.h"
#include <vector>

using namespace std;

int main() {
	Lecture ora1 = Lecture("Fizika", "F", "1", "201", 5, Professor);
	Practice ora2 = Practice("Fizika", "F", "1", "201", 5, Professor);
	Laboratory ora3 = Laboratory("Fizika", "F", "1", "201", 5, Professor);
	Scholar teacher = Scholar("Kis", Professor, 20);
	cout << ora1;
	cout << ora2;
	cout << ora3;
	cout << teacher;
	/*
	vector<unique_ptr<Scholar>> teachers;
	vector<Lesson> lessons;

	lessons.push_back(Lecture("Fizika", "F", "1", "201", 5, Professor));
	cout << AcadaemicRankByName(lessons[0].getMinQualification());
	
	teachers.push_back(new Scholar("Kis", Professor, 20));
	teachers.push_back(new Scholar("Közepes", AssistantLecturer, 30));
	teachers.push_back(new Scholar("Nagy", Lecturer, 40));
	*/
	return 0;
}