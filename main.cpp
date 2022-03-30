#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<iomanip>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<ctime>
#include<fstream>
#include"student.h"

using namespace std;

List L;

void read_file();
void add_Student();
void del_Student();
void print_List(Student* l);
void detail_info();
void sort_Student_byName();
void sort_Student_byAvgGrade();
void search_by_Name();
void init_program();
void save_data();

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
		cout <<"\n\t4. See and edit detail infomation";
		cout <<"\n\t5. Search by name";
		cout <<"\n\t6. Sort";
		cout <<"\n\t0. Close program";
	
		cout << "\n\nChoose: "; cin >> Choice;
		if(Choice == 0)
			break;
		else if(Choice == 1)
			add_Student();
		else if(Choice == 2)
			del_Student();
		else if(Choice == 3)
			print_List(L.get_Head());
		else if(Choice == 4)
			detail_info();
		else if(Choice == 5)
			search_by_Name();
		else if(Choice == 6)
		{
			system("cls");
			cout << "1. Sort by name" << "\t2. Sort by average grade";
			cout << "\nChoose: "; cin >> Choice;
			if(Choice == 1)
				sort_Student_byName();
			else if(Choice == 2)
				sort_Student_byAvgGrade();
		}
		cout << "\n";
		system("pause");
	}
	//  file here
	save_data();
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
			cout << "Date of Birth(separated with space): "; cin >> Y >> M >> D; 
			temp_Date.set_Day(D);
			temp_Date.set_Month(M);
			temp_Date.set_Year(Y);
		} while(!temp_Date.checkDate());
		Temp_St[i].set_DateOfBirth(temp_Date);

		//get the current date
		time_t t = time(0); // get time now
		tm* now = localtime(&t);
		temp_Date.set_Day(now->tm_mday);
		temp_Date.set_Month(now->tm_mon + 1);
		temp_Date.set_Year(now->tm_year + 1900);
		Temp_St[i].set_Adding_Date(temp_Date);

		cout << "=================================================================\n";
	}

	L.add(Temp_St, Q);
	delete[] Temp_St;
}
// Last name,First name,Gender,Id code,Birthday,Adding day,Linear Algebra grade,Calculus grade,Database grade,Average grade
void read_file()
{
	fstream Student_Data_FileIn;
	Student_Data_FileIn.open("student_data.csv", ios_base::in);
	if(Student_Data_FileIn.fail())
	{
		cout << "student_data.cvs doesn't exist";
		return;
	}
	
	string line;
	getline(Student_Data_FileIn, line);

	int Q = stoi(line);
	Student* Temp_St = new Student[Q];
	
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
		float t = stof(temp);
		Temp_St[i].set_LA_Grade(t);
		// get Calculus_Grade
		p1 = p2 + 1;
		p2 = p1;
		while(line[p2] != ',')
			p2++;
		temp = line.substr(p1, p2 - p1);
		t = stof(temp);
		Temp_St[i].set_Calculus_Grade(t);
		// get DataStruct_Grade
		p1 = p2 + 1;
		p2 = p1;
		while(line[p2] != ',')
			p2++;
		temp = line.substr(p1, p2 - p1);
		t = stof(temp);
		Temp_St[i].set_DS_Grade(t);
		Temp_St[i].set_Avg();
	}
	L.add(Temp_St, Q);
	delete[] Temp_St;
	Student_Data_FileIn.close();
}
// Last name,First name,Gender,Id code,Birthday,Adding day,Linear Algebra grade,Calculus grade,Database grade,Average grade
void save_data()
{
	ofstream Student_Data_FileOut;
	Student_Data_FileOut.open("student_data.csv", ios_base::out);
	
	int Q = L.get_Numb_Of_Student();
	Student_Data_FileOut << Q << ",,,,,,,,,\n";
	
	string temp = "";
	for(int i = 0; i < Q; i++)
	{
		//First name and last name
		temp += L.get_Head()[i].get_FirstName() + "," + L.get_Head()[i].get_LastName() + ",";
		//Gender
		temp.push_back(char(L.get_Head()[i].get_Gender() + '0')); temp += ",";
		//Id code
		temp += L.get_Head()[i].get_Id() + ",";
		//Date of birth
		temp += to_string(L.get_Head()[i].get_DateOfBirth().get_Day()) + "-";
		temp += to_string(L.get_Head()[i].get_DateOfBirth().get_Month()) + "-";
		temp += to_string(L.get_Head()[i].get_DateOfBirth().get_Year()) + ",";
		//Adding day
		temp += to_string(L.get_Head()[i].get_Adding_Date().get_Day()) + "-";
		temp += to_string(L.get_Head()[i].get_Adding_Date().get_Month()) + "-";
		temp += to_string(L.get_Head()[i].get_Adding_Date().get_Year()) + ",";
		//LA grade
		temp += to_string(L.get_Head()[i].get_LA_Grade()) + ",";
		//Calculus grade
		temp += to_string(L.get_Head()[i].get_Calculus_Grade()) + ",";
		//DS grade
		temp += to_string(L.get_Head()[i].get_DS_Grade()) + ",";
		//Avg grade
		temp += to_string(L.get_Head()[i].get_Avg());
		Student_Data_FileOut << temp;
		Student_Data_FileOut << "\n";

		temp.clear();
	}
	Student_Data_FileOut.close();
}

void print_List(Student* l)
{	
	int q = L.get_Numb_Of_Student();
	cout << "\nNumber of students: " << q;
	cout << "\n|" << setw(15) << left << "First name " << "|" << setw(10) << left << "Last name " << "|" << setw(10) << left << "ID" << "|"
		<< setw(7) << left << "Gender " << "|" << setw(11) << left << "Birthday " << "|" << setw(14) << left << "Linear Algebra" << "|" << setw(8) << left << "Calculus" << "|"
		<< setw(11) << left << "Data Struct" << "|" << setw(10) << left << "Average" << "|" << endl;
	cout << "+---------------+" << "----------+"  << "----------+" << "-------+"  << "-----------+" << "--------------+" << "--------+" << "-----------+" << "----------+" << endl;
	for(int i = 0; i < q; i++)
	{
		cout << "|" << setw(15) << left << l[i].get_FirstName()<< "|" << setw(10) << left << l[i].get_LastName() << "|" 
			<< setw(10) << left << l[i].get_Id() << "|" << setw(7) << left << l[i].get_Gender() 
			<< "|" << setw(11) << left << l[i].get_DateOfBirth().get_Date() << "|" << setw(14) << left << l[i].get_LA_Grade() << "|" << setw(8) << left << l[i].get_Calculus_Grade() << "|"
		<< setw(11) << left << l[i].get_DS_Grade() << "|" << setw(10) << left << l[i].get_Avg() << "|" << endl;
	}
}
void del_Student()
{
	string ID;
	cout << "Type student's ID code(to delete): "; fflush(stdin); cin >> ID;
	L.del_by_Id(ID);
}
void detail_info()
{
	string ID;
	int Cur_Student_Pos;
	cout << "Type student's ID code(to see details): "; fflush(stdin); cin >> ID;
	// search
	int Q = L.get_Numb_Of_Student();
	for(int i = 0; i < Q; i++)
		if(L.get_Head()[i].get_Id() == ID)
		{
			string t;
			cout << "\n=================================================================\n";
			cout << setw(18) << left << "1. ID: " << setw(20) << left << L.get_Head()[i].get_Id() 
				<< "7. Linear Algebra grade: " << L.get_Head()[i].get_LA_Grade() << endl;
			cout << setw(18) << left << "2. First name: " << setw(20) << left << L.get_Head()[i].get_FirstName() 
				<< "8. Data Struct grade: " << L.get_Head()[i].get_DS_Grade() << endl;
			cout << setw(18) << left << "3. Last name: " << setw(20) << left << L.get_Head()[i].get_LastName() 
				<< "9. Calculus grade: " << L.get_Head()[i].get_Calculus_Grade() << endl;
			cout << setw(18) << "4. Gender: " << L.get_Head()[i].get_Gender() << endl;
			cout << setw(18) << left << "5. Date of birth: " << setw(20) << left << L.get_Head()[i].get_DateOfBirth().get_Date() 
				<< "10. Average grade: " << L.get_Head()[i].get_Avg() << endl;
			cout << setw(18) << "6. Adding date: " << L.get_Head()[i].get_Adding_Date().get_Date() << endl;
			Cur_Student_Pos = i;
			break;
		}

	if(Cur_Student_Pos == -1)
		return;
	//edit inf	

	int Choice_Int;
	cout << "\n\n1. Edit\t\t" << "2. Back";
	cout << "\nChoose: "; cin >> Choice_Int;
	if(Choice_Int == 1)
	{
		while(true)
		{
			cout << "\nChoose field(separated by space): "; cin >> Choice_Int;
			switch(Choice_Int)
			{
				case 0:
					return;
					break;
				case 1:
					{
						string ID;
						cout << "\nType ID: "; fflush(stdin); getline(cin, ID);
						L.get_Head()[Cur_Student_Pos].set_Id(ID);
					}
					break;
				case 2:
					{
						string First_Name;
						cout << "\nType first name: "; fflush(stdin); getline(cin, First_Name);
						L.get_Head()[Cur_Student_Pos].set_FirstName(First_Name);
					}
					break;
				case 3:
					{
						string Last_Name;
						cout << "\nType last name: "; fflush(stdin); getline(cin, Last_Name);
						L.get_Head()[Cur_Student_Pos].set_LastName(Last_Name);
					}
					break;
				case 4:
					{
						string Gender;
						cout << "\nType gender: "; fflush(stdin); getline(cin, Gender);
						L.get_Head()[Cur_Student_Pos].set_Gender(((Gender == "male")? 1 : 0));
					}
					break;
				case 5:
					{
						do
						{
							int Y, M, D;
							cout << "\nType date of Birth(separated by space): "; cin >> Y >> M >> D;
							L.get_Head()[Cur_Student_Pos].get_DateOfBirth().set_Year(Y);
							L.get_Head()[Cur_Student_Pos].get_DateOfBirth().set_Month(M);
							L.get_Head()[Cur_Student_Pos].get_DateOfBirth().set_Day(D);
						} while(L.get_Head()->get_DateOfBirth().checkDate());
					}
					break;
				case 7:
					{
						float LA_Grade;
						cout << "\nType Linear Algebra grade"; cin >> LA_Grade;
						L.get_Head()[Cur_Student_Pos].set_LA_Grade(LA_Grade);
					}
					break;
				case 8:
					{
						float DS_Grade;
						cout << "\nType Linear Algebra grade"; cin >> DS_Grade;
						L.get_Head()[Cur_Student_Pos].set_DS_Grade(DS_Grade);
					}
					break;
				case 9:
					{
						float Calculus_Grade;
						cout << "\nType Linear Algebra grade"; cin >> Calculus_Grade;
						L.get_Head()[Cur_Student_Pos].set_Calculus_Grade(Calculus_Grade);
					}
					break;
				default:
					return;
					break;
			}
			cout << "\n=================================================================\n";
			cout << setw(18) << left << "1. ID: " << setw(20) << left << L.get_Head()[Cur_Student_Pos].get_Id() 
				<< "7. Linear Algebra grade: " << L.get_Head()[Cur_Student_Pos].get_LA_Grade() << endl;
			cout << setw(18) << left << "2. First name: " << setw(20) << left << L.get_Head()[Cur_Student_Pos].get_FirstName() 
				<< "8. Data Struct grade: " << L.get_Head()[Cur_Student_Pos].get_DS_Grade() << endl;
			cout << setw(18) << left << "3. Last name: " << setw(20) << left << L.get_Head()[Cur_Student_Pos].get_LastName() 
				<< "9. Calculus grade: " << L.get_Head()[Cur_Student_Pos].get_Calculus_Grade() << endl;
			cout << setw(18) << "4. Gender: " << L.get_Head()[Cur_Student_Pos].get_Gender() << endl;
			cout << setw(18) << left << "5. Date of birth: " << setw(20) << left << L.get_Head()[Cur_Student_Pos].get_DateOfBirth().get_Date() 
				<< "10. Average grade: " << L.get_Head()[Cur_Student_Pos].get_Avg() << endl;
			cout << setw(18) << "6. Adding date: " << L.get_Head()[Cur_Student_Pos].get_Adding_Date().get_Date() << endl;
			cout << "\n0. Back\n";
			system("pause");
		}
	}
	else
		return;
}
void search_by_Name()
{
	string Name;
	cout << "Type student's last name: "; fflush(stdin); cin >> Name;
	//string Full_Name;
	int Q = L.get_Numb_Of_Student();

	cout << "\n|" << setw(15) << left << "First name " << "|" << setw(10) << left << "Last name " << "|" << setw(10) << left << "ID" << "|"
		<< setw(7) << left << "Gender " << "|" << setw(11) << left << "Birthday " << "|" << endl;
	cout << "+" << "---------------" << "+" << "----------" << "+" << "----------" << "+" << "-------" << "+" << "-----------" << "+" << endl;
	for(int i = 0; i < Q; i++)
	{
		if(L.get_Head()[i].get_FirstName().find(Name) != -1)
		{
			cout << "|" << setw(15) << left << L.get_Head()[i].get_FirstName()<< "|" << setw(10) << left << L.get_Head()[i].get_LastName() << "|" 
				<< setw(10) << left << L.get_Head()[i].get_Id() << "|" << setw(7) << left << L.get_Head()[i].get_Gender() 
				<< "|" << setw(11) << left << L.get_Head()[i].get_DateOfBirth().get_Date() << "|" << endl;
			continue;
		}
		if(L.get_Head()[i].get_LastName().find(Name) != -1)
		{
			cout << "|" << setw(15) << left << L.get_Head()[i].get_FirstName()<< "|" << setw(10) << left << L.get_Head()[i].get_LastName() << "|" 
				<< setw(10) << left << L.get_Head()[i].get_Id() << "|" << setw(7) << left << L.get_Head()[i].get_Gender() 
				<< "|" << setw(11) << left << L.get_Head()[i].get_DateOfBirth().get_Date() << "|" << endl;
			continue;
		}
	}
}
void sort_Student_byName()
{	
	int Q = L.get_Numb_Of_Student();
	Student *Temp = new Student[Q];
	// copy from Student list
	for(int i = 0; i < Q; i++)
		Temp[i] = L.get_Head()[i];

	for(int i = 0; i < Q - 1; i++)
		for(int k = i + 1; k < Q; k++)
			if(Temp[i].get_LastName()[0] > Temp[k].get_LastName()[0])
				swap(Temp[i], Temp[k]);
	print_List(Temp);
	delete[] Temp;
}
void sort_Student_byAvgGrade()
{
	int Q = L.get_Numb_Of_Student();
	Student *Temp = new Student[Q];
	// copy from Student list
	for(int i = 0; i < Q; i++)
		Temp[i] = L.get_Head()[i];

	for(int i = 0; i < Q - 1; i++)
		for(int k = i + 1; k < Q; k++)
			if(Temp[i].get_Avg() < Temp[k].get_Avg())
				swap(Temp[i], Temp[k]);
	print_List(Temp);
	delete[] Temp;
}
