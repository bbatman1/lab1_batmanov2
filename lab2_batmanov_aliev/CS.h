#pragma once
#include <iostream>
#include <string>
#include <fstream>

class CS
{
private:
	static int top_id;
	int ID;
	std::string name;
	int workstations;
	int workstations_work;
	double efficienty;

public:
	CS();

	static CS appendCS();
	static void resetMaxID();

	friend std::ostream& operator << (std::ostream& out, const CS& cs);
	friend std::istream& operator >> (std::istream& in, CS& cs);
	friend std::ofstream& operator << (std::ofstream& fout, const CS& cs);
	friend std::ifstream& operator >> (std::ifstream& fin, CS& cs);

	bool runWS();
	bool stopWS();

	int getID()
	{
		return ID;
	}
	std::string getName()
	{
		return name;
	}
	double getPercentWsInUse()
	{
		return (double)workstations_work / workstations * 100;
	}
};
