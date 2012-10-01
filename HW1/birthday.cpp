/*
Birthday.cpp
Nicole Wade 
24 Sept. 2012
Source code for Birthday class
CS311
*/

#include "birthday.h"

#include <sstream>
using std::ostringstream; //review this guy!

//******write pre and post conditions

bool operator==(const Birthday& lhs, const Birthday& rhs)
{
	//Pre-condition: none
	return (lhs._name == rhs._name && lhs._month == rhs._month && lhs._day == rhs._day);
	//Post-condition: returns true if lhs==rhs for all instance variables
}

// default constructor
Birthday::Birthday():_name(""), _month(1), _day(1)
{
	//Pre-condition: none
	//Post-condition: set _name to an empty string, _month to 1, and _day to 1
}

//constructor
// If month or day are not in appropriate range, they are set to 1
Birthday::Birthday(string name, int month, int day)
{
	//Pre-condition: 1 <= month <=12, 1<= day <=31
	_name = name; 

	if(1<= month && month <=12)
	{
		_month = month;
	}
	else
	{
		_month = 1;
	}

	if(1<= day && day <=31)
	{
		_day = day;
	}
	else
	{
		_day = 1;
	}

	//Post-condition: _name = name, if in appropriate range _month=month and _day=day
	// if not in appropriate ranges, _month=1, _day=1
}

string Birthday::getName() const
{
	//Pre-condition: none
	return _name;
	//Post-condition: _name is returned
}

int Birthday::getMonth() const
{
	//Pre-condition: none
	return _month;
	//Post-condition: _month is returned
}

int Birthday::getDay() const
{	
	//Pre-condition: none
	return _day;
	//Post-condition: _day is returned
}

void Birthday::setName(string name)
{
	//Pre-condition: none
	_name = name;
	//Post-condition: _name=name
}

//if month not in appropriate range, _month is set to 1
void Birthday::setMonth(int month)
{
	//Pre-condition: 1<= month <=12
	if (1<= month && month <= 12)
	{
		_month = month;
	}
	else
	{
		_month = 1;
	}	
	//Post-condition: if pre-condition holds, _month=month else _month=1
}

//if day not in appropriate range, _day is set to 1
void Birthday::setDay(int day)
{
	//Pre-condition: 1<= day <=31
	if (1<= day && day<= 31)
	{
		_day = day;
	}
	else
	{
		_day = 1;
	}
	//Post-condition: if pre-condition holds, _day=day, else _day=1
}

// toString 
	// takes no parameters and returns a string representation of info as Fred Smith (Jan 5)
string Birthday::toString() const
{
	//Pre-condition: none
	string theMonth;

	switch (_month)
	{
		case 1: theMonth = "Jan";
			break;
		case 2: theMonth = "Feb";
			break;
		case 3: theMonth = "Mar";
			break;
		case 4: theMonth = "Apr";
			break;
		case 5: theMonth = "May";
			break;
		case 6: theMonth = "Jun";
			break;
		case 7: theMonth = "Jul";
			break;
		case 8: theMonth = "Aug";
			break;
		case 9: theMonth = "Sep";
			break;
		case 10: theMonth = "Oct";
			break;
		case 11: theMonth = "Nov"; 
			break;
		case 12: theMonth = "Dec";
	}

	ostringstream os;
	os << _name << " (" << theMonth << " " << _day << ")"; 

	return os.str(); 
	//Post-condition: returns the data in the following form:"name (Jan 1)"
} 

bool operator!=(const Birthday& lhs, const Birthday& rhs)
{
	//Pre-condition: none
	return ! (lhs==rhs);
	//Post-condition: returns true when the instance variables are not equal 
}

ostream & operator<<(ostream &os, const Birthday &m)
{
	//pre-condition: os is not in an error state
	return os << m.toString();
	//Post-condition: m has been printed to os in the format "name (Jan 1)"
}