#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<iomanip>
#include<conio.h>
#include<stdlib.h>
#include<ctime>
#include<fstream>
#include"student.h"

using namespace std;

List L;

void read_file();
void add_Student();
void del_Student();
void print_List();
void init_program();
int main() {
	init_program();
	return 0;
}

void init_program()
{
	read_file();
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
		
		cout << "\n";
		system("pause");
	}
}
void add_Student()
{
	int Q;
	Student *Temp_St;
	cout << "\nType quantity: "; cin >> Q;
	Temp_St = new Student[Q];
	cout << "\n=================================================================\n";
	for(int i = 0 ; i < Q; i++)
	{
		string tstr;
		cout << "First Name: "; fflush(stdin); getline(cin, tstr); Temp_St[i].set_FirstName(tstr);
		cout << "Last Name: "; fflush(stdin); cin >> tstr; Temp_St[i].set_LastName(tstr);
		cout << "Gender: "; fflush(stdin); cin >> tstr; Temp_St[i].set_Gender(((tstr == "male")? 1 : 0));
		cout << "ID code: "; fflush(stdin); cin >> tstr; Temp_St[i].set_Id(tstr);
		
		Date temp_Date;
		int D, M, Y;
		do
		{
			cout << "Date of Birth(separate with space): "; cin >> Y >> M >> D; 
			temp_Date.set_Day(D);
			temp_Date.set_Month(M);
			temp_Date.set_Year(Y);
		} while(!temp_Date.checkDate());
		Temp_St[i].set_DateOfBirth(temp_Date);

		//get the current date
		time_t t = time(0); // get time now
		tm* now = localtime(&t);
		temp_Date.set_Day(now->tm_mday);
		temp_Date.set_Month(now->tm_mon);
		temp_Date.set_Year(now->tm_year);
		Temp_St[i].set_Adding_Date(temp_Date);

		cout << "=================================================================\n";
	}

	L.add(Temp_St, Q);
	delete[] Temp_St;
}

void read_file()
{
	fstream Student_Data_FileIn;
	Student_Data_FileIn.open("student_data.csv", ios_base::in);
	
	string line;
	getline(Student_Data_FileIn, line);

	int Q = stoi(line);
	Student* Temp_St = new Student[Q];

	getline(Student_Data_FileIn, line);
	
	for(int i = 0; i < Q; i++)
	{
		string temp;
		getline(Student_Data_FileIn, line);
		int p1 = 0, p2 = 0;
		// get first name
		while(line[p2] != ',')
			p2++;
		temp = line.substr(p1, p2 - p1);
		Temp_St[i].set_FirstName(temp);
		// get last name
		p1 = p2 + 1;
		p2 = p1;
		while(line[p2] != ',')
			p2++;
		temp = line.substr(p1, p2 - p1);
		Temp_St[i].set_LastName(temp);
		// get gender
		p1 = p2 + 1;
		p2 = p1;
		p2++;
		temp = line.substr(p1, 1);
		Temp_St[i].set_Gender(bool(temp[0] - '0'));
		// get Id code
		p1 = p2 + 1;
		p2 = p1;
		while(line[p2] != ',')
			p2++;
		temp = line.substr(p1, p2 - p1);
		Temp_St[i].set_Id(temp);

		// get Birthday
		Date Temp_Date;
		p1 = p2 + 1;
		p2 = p1;
		while(line[p2] != '-')
			p2++;
		temp = line.substr(p1, p2 - p1);
		Temp_Date.set_Day(stoi(temp));
		p1 = p2 + 1;
		p2 = p1;
		while(line[p2] != '-')
			p2++;
		temp = line.substr(p1, p2 - p1);
		Temp_Date.set_Month(stoi(temp));
		p1 = p2 + 1;
		p2 = p1;
		while(line[p2] != ',')
			p2++;
		temp = line.substr(p1, p2 - p1);
		Temp_Date.set_Year(stoi(temp));
		Temp_St[i].set_DateOfBirth(Temp_Date);
		// get Adding day
		p1 = p2 + 1;
		p2 = p1;
		while(line[p2] != '-')
			p2++;
		temp = line.substr(p1, p2 - p1);
		Temp_Date.set_Day(stoi(temp));
		p1 = p2 + 1;
		p2 = p1;
		while(line[p2] != '-')
			p2++;
		temp = line.substr(p1, p2 - p1);
		Temp_Date.set_Month(stoi(temp));
		p1 = p2 + 1;
		p2 = p1;
		while(line[p2] != ',')
			p2++;
		temp = line.substr(p1, p2 - p1);
		Temp_Date.set_Year(stoi(temp));
		Temp_St[i].set_Adding_Date(Temp_Date);
		// get Linear_Algebra_Grade
		p1 = p2 + 1;
		p2 = p1;
		while(line[p2] != ',')
			p2++;
		temp = line.substr(p1, p2 - p1);
		Temp_St[i].set_LA_Grade(stof(temp));
		// get Calculus_Grade
		p1 = p2 + 1;
		p2 = p1;
		while(line[p2] != ',')
			p2++;
		temp = line.substr(p1, p2 - p1);
		Temp_St[i].set_Calculus_Grade(stof(temp));
		// get DataStruct_Grade
		p1 = p2 + 1;
		p2 = p1;
		while(line[p2] != ',')
			p2++;
		temp = line.substr(p1, p2 - p1);
		Temp_St[i].set_DS_Grade(stof(temp));
	}

	L.add(Temp_St, Q);
	
	Student_Data_FileIn.close();
}

void print_List()
{	
	int q = L.get_Numb_Of_Student();
	cout << "\nNumber of students: " << q;
	cout << "\n|" << setw(15) << left << "First name " << "|" << setw(10) << left << "Last name " << "|"
		<< setw(7) << left << "Gender " << "|" << setw(11) << left << "Birthday " << "|" << endl;
	cout << "+" << "---------------" << "+" << "----------" << "+" << "-------" << "+" << "-----------" << "+" << endl;
	Student* Temp_St = L.get_Head();
	for(int i = 0; i < q; i++)
	{
		cout << "|" << setw(15) << left << Temp_St[i].get_FirstName()<< "|" << setw(10) << left << Temp_St[i].get_LastName() << "|"
			<< setw(7) << left << Temp_St[i].get_Gender() << "|" << Temp_St[i].get_DateOfBirth().get_Year() 
			<< "/";
		int M = Temp_St[i].get_DateOfBirth().get_Month(); 
		int D = Temp_St[i].get_DateOfBirth().get_Day();
		if(M < 10 && D < 10)
			cout << 0 << M << "/" << 0 << setw(2) << left << D << "|" << endl;
		else if(M >= 10 && D < 10)
			cout << M << "/" << 0 << setw(2) << left << D << "|" << endl;
		else if(M < 10 && D >= 10)
			cout << 0 << M << "/" << setw(3) << left << D << "|" << endl;
		else
			cout << M << "/" << setw(3) << left << D << "|" << endl;
	}
	delete[] Temp_St;
}
//void del_Student();
