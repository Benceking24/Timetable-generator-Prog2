#define _CRT_SECURE_NO_WARNINGS 1 
#include "Scholar.h"

Scholar::Scholar(const char* Name, AcademicRank Rank, int Salary):id(NextScholarId),salary(Salary),rank(Rank)
{
	NextScholarId++;
	setName(Name);
}

Scholar::~Scholar()
{
	if (name!=nullptr)
	{
		delete name;
	}
}

unsigned int Scholar::getId() const
{
	return id;
}

int Scholar::getSalary() const
{
	return salary;
}

char* Scholar::getName() const
{
	return name;
}

AcademicRank Scholar::getRank() const
{
	return rank;
}

const char* Scholar::getRankByName() const
{
	switch (rank)
	{
	case AssistantLecturer:
		return "Assistant Lecturer";
		break;
	case Lecturer:
		return "Lecturer";
		break;
	case Professor:
		return "Professor";
		break;
	default:
		break;
	}
}

void Scholar::setSalary(const int Salary) {salary = Salary;}

void Scholar::setName(const char* Name)
{
	if (name!=nullptr)
	{
		delete name;
	}
	name = new char[sizeof(Name)];
	strcpy(name, Name);
}

void Scholar::setRank(AcademicRank Rank) {rank = Rank;}

ostream& operator<<(ostream& os, const Scholar& person)
{
	return os << person.getId() << ";" << person.getRankByName() <<";" << person.getName() << ";" << person.getSalary() << endl;
}
