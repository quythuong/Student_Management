#include<iostream>
#include<iomanip>
#include"student.h"


bool Date::is_LeapYear()
{
	if(Year % 4 == 0 && Year % 100 != 0)
		return true;
	if(Year % 400 == 0)
		return true;
	return false;
}
bool Date::checkDate()
{
	if(Day < 0 || Month < 0 || Year < 0)
		return false;
	if(Day > 31 || Month > 12)
		return false;
	switch(Month)
	{
		case 2:
			if(is_LeapYear())
			{
				if(Day > 29)
					return false;
			}
			else
			{
				if(Day > 28)
					return false;
			}
			break;
		case 4:
			if(Day > 30)
				return false;
			break;
		case 6:
			if(Day > 30)
				return false;
			break;
		case 9:
			if(Day > 30)
				return false;
			break;
		case 11:
			if(Day > 30)
				return false;
			break;
		default:
			break;
	}
	return true;
}
void Date::input()
{
	cout << "Day/Month/Year(separate by space): "; cin >> Day >> Month >> Year;
	while(!checkDate())
	{
		cout << "Wrong date! Please try again!";
		cout << "Day/Month/Year(separate by space): "; cin >> Day >> Month >> Year;
	}
}
void Date::output()
{
	cout << Day << "/" << Month << "/" << Year;
}


