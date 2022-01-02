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
	int Numerical_Order;
	Date BirthDay;
	float Linear_Algebra_Grade;
	float DataStruct_Grade;
	float DataBase_Grade;
	float Avg_Grade;

public:
	void input();
	void output();
};

class List
{
	struct Nodes
	{
		Student St;
		Student* Next;
	};
public:
	void add(Student A);
	void del(string Id);
	void search_by_name(string Name);
	void save();
};

