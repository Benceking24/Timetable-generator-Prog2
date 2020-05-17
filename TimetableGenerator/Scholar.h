#pragma once
#include <iostream>
#include <string>
#include "Helper.hpp"

static unsigned int NextScholarId= 0;

using namespace std;

class Scholar
{
protected:
	const unsigned int id;
	string name;
	int salary;
	int rank;
public:
	Scholar(string Name, int Rank, int Salary);
	unsigned int getId() const;
	int getSalary() const;
	string getName() const;
	int getRank() const;
	void setSalary(const int Salary);
	void setName(string Name);
	void setRank(int Rank);
	friend ostream& operator<< (ostream& os, Scholar& teacher);
};