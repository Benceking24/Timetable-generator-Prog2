#pragma once
#include <iostream>
#include <string>

static unsigned int NextScholarId= 0;

using namespace std;

enum AcademicRank {AssistantLecturer, Lecturer, Professor};

class Scholar
{
protected:
	const unsigned int id;
	char* name;
	int salary;
	AcademicRank rank;
public:
	Scholar(const char* Name, AcademicRank Rank, int Salary);
	~Scholar();
	unsigned int getId() const;
	int getSalary() const;
	char* getName() const;
	AcademicRank getRank() const;
	const char* getRankByName() const;
	void setSalary(const int Salary);
	void setName(const char* Name);
	void setRank(AcademicRank Rank);
	friend ostream& operator<<(ostream& os, const Scholar& person);
};

ostream& operator<<(ostream& os, const Scholar& person);
