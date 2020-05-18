#pragma once
#include <iostream>
#include <vector>
#include "Lesson.h"
#include "Timetable.h"

using namespace std;
//Ora nev, max ora szam				-standard
//Ora nev, max ora szam, idopont	-special

bool ReadStandardLessons(static istream& input, vector<Lesson>& output) {
	// 1. Beolvassa adott streamet végjelig
	// 2. Ha még nem volt ilyen tárgy létrehozza az output-ra
	//	  Ha már volt akkor hozzáad egy countot
}

bool ReadSpecialLessons(static istream& input, vector<Lesson>& output) {
	// 1. Beolvassa adott streamet végjelig
	// 2. Ha még nem volt ilyen tárgy létrehozza az output-ra
	//	  Ha már volt akkor hozzáad egy countot és/vagy specific timeot
	//
}

bool GenerateTimetable(static vector<Lesson>& standard, static vector<Lesson>& special, Timetable output) {
	// 1. Ciklus minden napra egy temp vector<lesson> be
	// 1.1 Megnézi van-e arra a napra speciális, ha igen azt jelzi egy !ÚJ! temp listába
	// 1.2 Elkezdi feltölteni standard elemekkel amíg a temp listába nem fut idõ szerint bele
	//	   Ha belefut beteszi a spéci elemet és folytatja tovább
	// 1.3 Végén hozzáadja az outputhoz a temp vector <lesson-t>
}

void GenerateHash(static vector<Lesson>& standard, vector<int>& hashes) {
	// Hozzáadja karakteresen az ID értékét egy inthez és azt pusholja a hashes-be
}

void RandomizeOrder(static vector<Lesson>& standard, static vector<Lesson>& special, vector<int>& hashes) {
	// Megcserél egy tetszõleges elemet egy tetszõlegssel ami nem önamaga
	// Megnézi hogy van-e ilyen a hashes-be ha igen ismétli amíg nem talál új hash-t
}
