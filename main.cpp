#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<iomanip>
#include<conio.h>
#include<ctime>
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
			add_Student();
		else if(Choice == 2)
			break;
		else if(Choice == 3)
			print_List();

		_getch();
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
		cout << "First Name: "; fflush(stdin); getline(cin, tstr); Temp->set_FirstName(tstr);
		cout << "Last Name: "; fflush(stdin); cin >> tstr; Temp->set_LastName(tstr);
		cout << "Gender: "; fflush(stdin); cin >> tstr; Temp->set_Gender(((tstr == "male")? 1 : 0));
		cout << "ID code: "; fflush(stdin); cin >> tstr; Temp->set_Id(tstr);
		
		Date temp_Date;
		int D, M, Y;
		do
		{
			cout << "Date of Birth(separate with space): "; cin >> Y >> M >> D; 
			temp_Date.set_Day(D);
			temp_Date.set_Month(M);
			temp_Date.set_Year(Y);
		} while(!temp_Date.checkDate());
		Temp->set_DateOfBirth(temp_Date);

		//get the current date
		time_t t = time(0); // get time now
		tm* now = localtime(&t);
		temp_Date.set_Day(now->tm_mday);
		temp_Date.set_Month(now->tm_mon);
		temp_Date.set_Year(now->tm_year);
		Temp->set_Adding_Date(temp_Date);
	}

	L.add(Temp, Q);
	delete[] Temp;
}
void print_List()
{
	int n = L.get_Numb_Of_Student();

	cout << "\n|" << setw(15) << left << "First name " << "|" << setw(10) << left << "Last name " << "|"
		<< setw(7) << left << "Gender " << "|" << setw(11) << left << "Birthday " << "|" << endl;
	cout << "+" << "---------------" << "+" << "----------" << "+" << "-------" << "+" << "-----------" << "+" << endl;
	
	for(int i = 0; i < n; i++)
	{
		cout << "|" << setw(15) << left << L.get_Head()->get_FirstName()<< "|" << setw(10) << left << L.get_Head()->get_LastName() << "|"
			<< setw(7) << left << L.get_Head()->get_Gender() << "|" << L.get_Head()->get_DateOfBirth().get_Year() 
			<< "/" << L.get_Head()->get_DateOfBirth().get_Month() << "/" << setw(4) << left << L.get_Head()->get_DateOfBirth().get_Day() << "|" << endl;
	}
}
//void del_Student();
