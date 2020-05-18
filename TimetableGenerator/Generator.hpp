#pragma once
#include <iostream>
#include <vector>
#include "Lesson.h"
#include "Timetable.h"

using namespace std;
//Ora nev, max ora szam				-standard
//Ora nev, max ora szam, idopont	-special

bool ReadStandardLessons(static istream& input, vector<Lesson>& output) {
	// 1. Beolvassa adott streamet v�gjelig
	// 2. Ha m�g nem volt ilyen t�rgy l�trehozza az output-ra
	//	  Ha m�r volt akkor hozz�ad egy countot
}

bool ReadSpecialLessons(static istream& input, vector<Lesson>& output) {
	// 1. Beolvassa adott streamet v�gjelig
	// 2. Ha m�g nem volt ilyen t�rgy l�trehozza az output-ra
	//	  Ha m�r volt akkor hozz�ad egy countot �s/vagy specific timeot
	//
}

bool GenerateTimetable(static vector<Lesson>& standard, static vector<Lesson>& special, Timetable output) {
	// 1. Ciklus minden napra egy temp vector<lesson> be
	// 1.1 Megn�zi van-e arra a napra speci�lis, ha igen azt jelzi egy !�J! temp list�ba
	// 1.2 Elkezdi felt�lteni standard elemekkel am�g a temp list�ba nem fut id� szerint bele
	//	   Ha belefut beteszi a sp�ci elemet �s folytatja tov�bb
	// 1.3 V�g�n hozz�adja az outputhoz a temp vector <lesson-t>
}

void GenerateHash(static vector<Lesson>& standard, vector<int>& hashes) {
	// Hozz�adja karakteresen az ID �rt�k�t egy inthez �s azt pusholja a hashes-be
}

void RandomizeOrder(static vector<Lesson>& standard, static vector<Lesson>& special, vector<int>& hashes) {
	// Megcser�l egy tetsz�leges elemet egy tetsz�legssel ami nem �namaga
	// Megn�zi hogy van-e ilyen a hashes-be ha igen ism�tli am�g nem tal�l �j hash-t
}
