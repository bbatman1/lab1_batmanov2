#include "Pipe.h"
#include "Help.h"
using namespace std;

int pipe::MaxID = 0;

pipe::pipe()
{
	ID = ++MaxID;
	name = "";
	in_repair = 0;
};

ostream& operator<<(std::ostream& out, const pipe& p)
{
	cout << "pipe ID = " << p.ID << endl;
	out << "name: " << p.name << endl
		<< "d: " << p.diameter << endl
		<< "l: " << p.length << endl
		<< "in_repair status: " << p.in_repair << endl;

	return out;
}

istream& operator>>(istream& in, pipe& p)
{
	cout << "pipe ID = " << p.ID << endl;
	cout << "name (str) = ";
	p.name = inputString(in);
	cout << "d (int) = ";
	p.diameter = getPositiveNumber<int>(in);
	cout << "l (double) = ";
	p.length = getPositiveNumber<double>(in);
	cout << "in_repair status: 0 (ready for use)" << endl;

	return in;
}

ofstream& operator << (ofstream& fout, const pipe& p) 
{
	fout << p.ID << endl
		<< p.name << endl 
		<< p.diameter << endl
		<< p.length << endl
		<< p.in_repair << endl;;

	return fout;
}

ifstream& operator >> (ifstream& fin, pipe& p)
{
	fin >> p.ID;
	getline(fin >> ws, p.name); 
	fin >> p.diameter;
	fin >> p.length;
	fin >> p.in_repair;

	return fin;
}

pipe pipe::addPipe() 
{
	pipe p;
	cin >> p;
	return p;
}

void pipe::resetMaxID()
{
	MaxID = 0;
}

void pipe::editPipe() 
{
	in_repair = !in_repair;
}
