#include<string>
using namespace std;
class Date
{
	int Day, Month, Year;
public:
	Date(int day, int month, int year): Day(day), Month(month), Year(year) {}
	void setDate(int day, int month, int year);
	void input();
	void output();
};

class Student
{
	string Name;

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
};
