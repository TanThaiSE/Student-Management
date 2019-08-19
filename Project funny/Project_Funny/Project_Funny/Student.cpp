#include "Student.h"
void Student::Input_st() {
	
	cin.ignore();	cout << "\nInput your ID:";			 getline(cin, ID);
	cin.ignore(); cout << "\nInput your lastname:";	 getline(cin, Lastname);
	cin.ignore(); cout << "\nInput your firstname:";	 getline(cin, Firstname);
	cin.ignore(); cout << "\nInput your gender:";		 getline(cin, Gender);
	cin.ignore(); cout << "\nInput your date of birthday:";		getline(cin, Day);
	cin.ignore();	cout << "\nInput your month of birthday:";	getline(cin, Month);
	cin.ignore(); cout << "\nInput your year of birthday:";		getline(cin, Year);
}
void Student::Output_st() {
	
	cout << No << "," << ID << "," << Lastname << "," << Firstname << "," << Gender << "," << Day << "/" << Month << "/" << Year << endl;
}

Student::Student(string a, string b, string c, string d, string e, string f, string g, string h) {
	No = a;
	ID = b;
	Lastname = c;
	Firstname = d;
	Gender = e;
	Day = f;
	Month = g;
	Year = h;
}

Student::Student()
{
	No = '0';
	ID = '0';
	Lastname = '0';
	Firstname = '0';
	Gender = '0';
	Day = '0';
	Month = '0';
	Year = '0';
}


Student::~Student()
{
}
