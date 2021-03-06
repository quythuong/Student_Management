#include<iostream>
#include<math.h>
#include<string>
#include<iomanip>
#include"student.h"

using namespace std;
// test
//=============================================================Date class definition=============================================================

Date::Date()
{
	Day = 0;
	Month = 0;
	Year = 0;
}
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
	int DaysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if(Month == 2 && Day > 0 && Day <= DaysInMonth[Month] + is_LeapYear())
		return true;
	if(Day > 0 && Day <= DaysInMonth[Month])
		return true;
	return false;
}
void Date::set_Day(int Day) {this->Day = Day; }
void Date::set_Month(int  Month) { this->Month = Month; }
void Date::set_Year(int Year) { this->Year = Year; }

int Date::get_Day() { return this->Day; }
int Date::get_Month() { return this->Month; }
int Date::get_Year() { return this->Year; }
string Date::get_Date()
{
	string date = ((this->Day < 10)? "0" : "") + to_string(this->Day) + "/";
	date += ((this->Month < 10)? "0" : "") + to_string(this->Month) + "/";
	date += to_string(this->Year);
	return date;
}
//=============================================================Student class definition=============================================================
Student::Student()
{
	First_Name = "";
	Last_Name = "";
	Id_Code = "N/A";
	Date_Of_Birth = Date(1, 1, 1900);
	Adding_Date = Date(1, 1, 1900);
	Linear_Algebra_Grade = -1;
	DataStruct_Grade = -1;
	Calculus_Grade = -1;
	Avg_Grade = 0; }
void Student::set_FirstName(string First_Name) { this->First_Name = First_Name; }
void Student::set_LastName(string Last_Name) { this->Last_Name = Last_Name; }
void Student::set_Gender(bool Gender) { this->Gender = Gender; }
void Student::set_Id(string Id) { this->Id_Code = Id; }
void Student::set_DateOfBirth(Date Date_Of_Birth) { this->Date_Of_Birth = Date_Of_Birth; }
void Student::set_Adding_Date(Date Adding_Date) { this->Adding_Date = Adding_Date; }
void Student::set_LA_Grade(float Linear_Algebra_Grade) { this->Linear_Algebra_Grade = Linear_Algebra_Grade; }
void Student::set_Calculus_Grade(float Calculus_Grade) { this->Calculus_Grade = Calculus_Grade; }
void Student::set_DS_Grade(float DataStruct_Grade) { this->DataStruct_Grade = DataStruct_Grade; }
void Student::set_Avg()
{
	float Avg = (this->Linear_Algebra_Grade + this->Calculus_Grade + this->DataStruct_Grade) / 3;
	Avg = roundf(Avg * 100) / 100;
	this->Avg_Grade = Avg;
}
string Student::get_FirstName() { return First_Name; }
string Student::get_LastName() { return Last_Name; }
bool Student::get_Gender() { return Gender; }
string Student::get_Id() { return Id_Code; }
Date Student::get_DateOfBirth() { return Date_Of_Birth; }
Date Student::get_Adding_Date() { return Adding_Date; }
float Student::get_LA_Grade() { return Linear_Algebra_Grade; }
float Student::get_DS_Grade() { return DataStruct_Grade; }
float Student::get_Calculus_Grade() { return Calculus_Grade; }
float Student::get_Avg() { return Avg_Grade; }

//=============================================================List class definition=============================================================
void List::add(Student* A, int Q)
{
	if(Head == nullptr) // if the List is empty
	{
		Head = new Student[Q];
		for(int i = 0; i < Q; i++)
			Head[i] = A[i];

		Numb_Of_Student = Q;
	}
	else
	{
		reallocate(Head, Numb_Of_Student + Q, Numb_Of_Student);
		for(int i = 0; i < Q; i++)
			Head[Numb_Of_Student + i] = A[i];

		Numb_Of_Student += Q;
	}
}
void List::del_by_Id(string Id)
{
	if(Head == nullptr)
	{
		cout << "The List is empty";
	}
	else
	{
		for(int i = 0; i < Numb_Of_Student; i++)
			if(Head[i].get_Id() == Id)
			{
				for(int k = i; k < Numb_Of_Student - 1; k++)
					Head[k] = Head[k + 1];
				reallocate(Head, Numb_Of_Student - 1, Numb_Of_Student);
				Numb_Of_Student--;
				break;
			}
		if(Numb_Of_Student == 0)
			Head = nullptr;
	}
}

int List::get_Numb_Of_Student() { return this->Numb_Of_Student; }
Student* List::get_Head() { return this->Head; }
List::~List()
{
	delete[] Head;
}
//=============================================================Other definitions=============================================================
void reallocate(Student *&St, int new_memory_area, int old_memory_area)
{
	Student *temp = new Student[old_memory_area];

	for(int i = 0; i < old_memory_area; i++)
		temp[i] = St[i];
	delete[] St;

	St = new Student[new_memory_area];
	for(int i = 0; i < ((new_memory_area < old_memory_area)? new_memory_area : old_memory_area); i++)
		St[i] = temp[i];
	delete[] temp;
}
