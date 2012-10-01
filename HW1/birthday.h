/* 
birthday.h
Nicole Wade
24 Sept. 2012
Header for class Birthday
*/

#ifndef BIRTHDAY_H
#define BIRTHDAY_H

#include <string>
using std::string;
#include <iostream>
using std::ostream;

class Birthday
{
	// class invariants 
	// 1 <= _month <= 12, 1<= _day <= 31	

	friend bool operator==(const Birthday& lhs, const Birthday& rhs);

public:
	// default constructor
	Birthday();

	//constructor- takes parameters
	Birthday(string name, int month, int day);

	// Birthday class uses silently written copy constructor, copy assignment, and destructor

	string getName() const;

	int getMonth() const;

	int getDay() const;

	void setName(string name);

	void setMonth(int);

	void setDay(int);

	// returns info as "name (Jan 1)"
	string toString() const; 

private:
	string _name;
	int _month; // range 1-12
	int _day; // range 1-31	
};

bool operator!=(const Birthday& lhs, const Birthday& rhs);

ostream & operator<<(ostream &os, const Birthday &m);

#endif 

