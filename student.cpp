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

void Student::input()
{
	cout << "First name: "; fflush(stdin); getline(cin, First_Name);
	cout << "Last name: "; fflush(stdin); getline(cin, Last_Name);
	cout << endl;
	cout << "Student ID: "; fflush(stdin); getline(cin, Id_Code);
	cout << "Date of Birth"; Date_Of_Birth.input();
	// adding date
	cout << endl;
	cout << "Linear Algebra grade: "; cin >> Linear_Algebra_Grade;
	cout << "Calculus grade: "; cin >> Calculus_Grade;
	cout << "Data Struct grade: "; cin >> DataStruct_Grade;
	Avg_Grade = (Linear_Algebra_Grade + Calculus_Grade + DataStruct_Grade) / 3;
}
void Student::output_all()
{
	cout << "|"<< left << setw(15) << First_Name << setw(10) << Last_Name << "|" << left << setw(8) << Id_Code << "|" << left << setw(8) << Linear_Algebra_Grade << left << setw(8) << Calculus_Grade << left << setw(8) << DataStruct_Grade << left << setw(8) << Avg_Grade << endl;
}
