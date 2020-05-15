#include <iostream>
#include "Scholar.h"
#include "Lesson.h"

using namespace std;

int main() {
	Scholar asd("Kis",Professor, 20);
	Scholar bsd("Közepes",AssistantLecturer, 30);
	Scholar csd("Nagy",Lecturer, 40);
	cout << asd;
	cout << bsd;
	cout << csd;

	return 0;
}