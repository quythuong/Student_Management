#include<iostream>
#include<string>
#include<iomanip>
#include"student.h"

using namespace std;

List L;

void add_Student();
void del_Student();
void print_List();

int main() {
	int Choice;
	while(true)
	{
		// Menu
		system("cls");
		cout << "\t\tSTUDENT MANAGEMENT PROGRAM";
		cout <<"\n\n\t1. Adding students";
		cout <<"\n\t2. Delete student";
		cout <<"\n\t3. Print student list";
		cout <<"\n\t0. Close program";
	
		cout << "\n\nChoose: "; cin >> Choice;
		if(Choice == 0)
			break;
		else if(Choice == 1)
		{
			
		}
		else if(Choice == 2)
		{

		}
		else if(Choice == 3)
		{

		}
		system("pause");
	}
	return 0;
}


void add_Student()
{
	int Q;
	Student *Temp;
	cout << "\nType quantity: "; cin >> Q;
	Temp = new Student[Q];
	for(int i = 0 ; i < Q; i++)
	{
		string tstr;
		cout << "First Name: "; fflush(stdin); cin >> tstr; Temp->set_FirstName(tstr);
		cout << "Last Name: "; fflush(stdin); cin >> tstr; Temp->set_LastName(tstr);
		cout << "Gender: "; fflush(stdin); cin >> tstr; Temp->set_Gender(((tstr == "male")? 1 : 0));
		cout << "ID code: "; fflush(stdin); cin >> tstr; Temp->set_Id(tstr);
		
		Date temp_Date;
		int D, M, Y;
		do
		{
			cout << "Date of Birth(separate with space): "; cin >> D >> M >> Y; 
			temp_Date.set_Day(D);
			temp_Date.set_Month(M);
			temp_Date.set_Year(Y);
		} while(temp_Date.checkDate());
		Temp->set_DateOfBirth(temp_Date);
		//get the current date


	}
}
void del_Student();
void print_List();
