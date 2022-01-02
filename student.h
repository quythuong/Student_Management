#include<string>
using namespace std;
class Date
{
	int Day, Month, Year;
public:
	Date(int day, int month, int year): Day(day), Month(month), Year(year) {}
	bool is_LeapYear();
	bool checkDate();
	void input();
	void output();
};

class Student
{
	string First_Name;
	string Last_Name;

	string Id_Code;
	Date Date_Of_Birth;
	Date Adding_Date;

	float Linear_Algebra_Grade;
	float DataStruct_Grade;
	float Calculus_Grade;
	float Avg_Grade;

public:
	void input();
	void output_all();
	void output_in4();
	void output_grade();
};
class List
{
	Student* Head;
	int Numb_Of_Student;
public:
	List(): Head(nullptr), Numb_Of_Student(0) {}
	void add(Student A);
	void del(string Id);
	void search_by_name(string Name);
	void save();
};
