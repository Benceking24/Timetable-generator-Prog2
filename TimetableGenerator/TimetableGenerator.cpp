#include <iostream>
#include "Helper.hpp" // Includes Academic ranks enum and backward conversion (AssistantLecturer, Lecturer, Professor)
#include "Scholar.h"
#include "Lesson.h"

using namespace std;

int main() {
	Scholar asd("Kis", Professor, 20);
	Scholar bsd("Közepes", AssistantLecturer, 30);
	Scholar csd("Nagy",Lecturer, 40);
	Lesson ora("Fizika", "F", "1", "201", 5, Lecturer);
	cout << ora;
	cout << asd;
	return 0;
}