#pragma once
#include <iostream>
#include <string>

enum AcademicRank { AssistantLecturer, Lecturer, Professor };

static unsigned int NextScholarId= 0;

using namespace std;

class Scholar
{
protected:
	const unsigned int id;
	char* name;
	int salary;
	int rank;
public:
	Scholar(const char* Name, int Rank, int Salary);
	~Scholar();
	unsigned int getId() const;
	int getSalary() const;
	char* getName() const;
	int getRank() const;
	const char* getRankByName() const;
	void setSalary(const int Salary);
	void setName(const char* Name);
	void setRank(int Rank);
	friend ostream& operator<<(ostream& os, const Scholar& person);
};

ostream& operator<<(ostream& os, const Scholar& person);
