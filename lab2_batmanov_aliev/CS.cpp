#include "CS.h"
#include "Help.h"
using namespace std;

int CS::top_id = 0;

CS::CS()
{
	ID = ++top_id;
	name = "";
	ws_work = 0;
};

ostream& operator << (ostream& out, const CS& cs) 
{
	cout << "CS ID = " << cs.ID << endl;
	out << "name: " << cs.name << endl
		<< "ws: " << cs.ws << endl
		<< "ws in work: " << cs.ws_work << endl
		<< "eff: " << cs.eff << endl;

	return out;
}

istream& operator >> (istream& in, CS& cs) 
{
	cout << "CS ID = " << cs.ID << endl;
	cout << "name (str): ";
	cs.name = inputString(in);
	cout << "ws (int) = ";
	cs.ws = getPositiveNumber<int>(in);
	cout << "ws in work (int) = ";
	cs.ws_work = getCorrectNumber<int>(0, cs.ws, true, in);
	cout << "eff (double) >=0 and <=1 = ";
	cs.eff = getPositiveNumber<double>(in);

	return in;
}

ofstream& operator << (ofstream& fout, const CS& cs) 
{
	fout << cs.ID << endl
		<< cs.name << endl
		<< cs.ws << endl
		<< cs.ws_work << endl
		<< cs.eff << endl;

	return fout;
}

ifstream& operator >> (ifstream& fin, CS& cs)
{
	fin >> cs.ID;
	getline(fin >> ws, cs.name);
	fin >> cs.ws;
	fin >> cs.ws_work;
	fin >> cs.eff;

	return fin;
}

CS CS::addCS()
{
	CS cs;
	cin >> cs;
	return cs;
}

void CS::resetMaxID()
{
	top_id = 0;
}

bool CS::runWS() 
{
	if (ws_work < ws)
	{
		ws_work++;
		return 1;
	}
	else
		return 0;
}

bool CS::stopWS()
{
	if (ws_work > 0)
	{
		ws_work--;
		return 1;
	}
	else
		return 0;
}
