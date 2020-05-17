#include <iostream>
#include "Scholar.h"
#include "Lesson.h"

//mindkettõ .h ba is benne van! enum AcademicRank { AssistantLecturer, Lecturer, Professor };

using namespace std;

int main() {
	Scholar asd("Kis", Professor, 20);
	Scholar bsd("Közepes", AssistantLecturer, 30);
	Scholar csd("Nagy",Lecturer, 40);
	cout << asd;
	cout << bsd;
	cout << csd;
	Lesson ora("Fizika", "F", "1", "201", 5, Lecturer);
	return 0;
}