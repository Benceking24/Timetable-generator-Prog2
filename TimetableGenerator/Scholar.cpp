#include "Scholar.h"

Scholar::Scholar(string Name, int Rank, int Salary):id(NextScholarId),salary(Salary),rank(Rank),name(Name)
{
	NextScholarId++;
}

unsigned int Scholar::getId() const {return id;}

int Scholar::getSalary() const {return salary;}

string Scholar::getName() const {return name;}

int Scholar::getRank() const {return rank;}

void Scholar::setSalary(const int Salary) {salary = Salary;} //TO-DO: Exception handling

void Scholar::setName(string Name) {name = Name;} //TO-DO: Exception handling

void Scholar::setRank(int Rank) {rank = Rank;} //TO-DO: Exception handling

ostream& operator<< (ostream& os, Scholar& teacher)
{
	return os <<"Teacher: "<< "Id: "<< teacher.getId() << "\t Name: " << teacher.getName() << "\t Rank: " << AcadaemicRankByName(teacher.getRank()) << "\t Salary: " << teacher.getSalary() << endl;
}