#include "help.h"
using namespace std;

string inputString(istream& in)
{
	string str;
	getline(in >> ws, str);
	
	cerr << str << endl; 
	return str;
}

template <typename T> 
T inputNumber(istream& in) 
{
	T x;
	while ((in >> x).fail()	
		|| in.peek() != '\n')	
	{
		in.clear();
		in.ignore(10000, '\n');
		cout << "ERROR wrong type --> try again: ";
		cerr << x << endl; 
	}
	cerr << x << endl;
	return x;
}
template int inputNumber(istream& in);
template double inputNumber(istream& in);

template <typename T = int>
T getCorrectNumber(T a, T b, bool included, istream& in)
{
	T x = inputNumber<T>(in);
	while ((included && (x<a || x>b))
		|| (!included && (x <= a || x >= b)))
	{
		string str_included = included ? "= " : " ";
		cout << "ERROR wrong number: min >" << str_included << a << " and max <" << str_included << b << " --> try again: ";
		x = inputNumber<T>(in);
	}
	return x;
}
template int getCorrectNumber<int>(int a, int b, bool included, istream& in);
template double getCorrectNumber<double>(double a, double b, bool included, istream& in);

template <typename T>
T getPositiveNumber(istream& in)
{
	return getCorrectNumber<T>(0, std::numeric_limits<T>::max(), false, in);
}
template int getPositiveNumber(istream& in);
template double getPositiveNumber(istream& in);

bool confirm(string message)
{
	cout << message << "\n0.no\n1.yes" << endl;
	return getCorrectNumber(0, 1);
}