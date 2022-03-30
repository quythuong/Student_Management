#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class Student;

//=============================================================Functions declaration=============================================================
void reallocate(Student *&St, int new_memory_area, int old_memory_area);

//=============================================================Date class declaration=============================================================
class Date
{
	int Day, Month, Year;
public:
	Date();
	Date(int day, int month, int year): Day(day), Month(month), Year(year) {}
	bool is_LeapYear();
	bool checkDate();

	void set_Day(int Day);
	void set_Month(int Month);
	void set_Year(int Year);

	int get_Day();
	int get_Month();
	int get_Year();
	string get_Date();
};

//=============================================================Student class declaration=============================================================
class Student
{
private:
	string First_Name;
	string Last_Name;
	bool Gender;

	string Id_Code;
	Date Date_Of_Birth;
	Date Adding_Date;


	float Linear_Algebra_Grade;
	float DataStruct_Grade;
	float Calculus_Grade;
	float Avg_Grade;

public:
	Student();

	void set_FirstName(string FirstName);
	void set_LastName(string LastName);
	void set_Gender(bool Gender);
	void set_Id(string Id);
	void set_DateOfBirth(Date Date_Of_Birth);
	void set_Adding_Date(Date Adding_Date);
	void set_LA_Grade(float Linear_Algebra_Grade);
	void set_DS_Grade(float DataStruct_Grade);
	void set_Calculus_Grade(float Calculus_Grade);
	void set_Avg();

	string get_FirstName();
	string get_LastName();
	bool get_Gender();
	string get_Id();
	Date get_DateOfBirth();
	Date get_Adding_Date();
	float get_LA_Grade();
	float get_DS_Grade();
	float get_Calculus_Grade();
	float get_Avg();
};
//=============================================================List class declaration=============================================================
class List
{
	Student *Head;
	int Numb_Of_Student;
public:
	List(): Head(nullptr), Numb_Of_Student(0) {}
	void add(Student* A, int Q);
	void del_by_Id(string Id);
	void search_by_name(string Name);

	int get_Numb_Of_Student();
	Student* get_Head();

	void save();
	~List();
};
#endif
