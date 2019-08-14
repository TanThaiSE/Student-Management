#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<stdlib.h>
using namespace std;
class Student
{
private:
	string No;
	string ID;
	string Lastname;
	string Firstname;
	string Gender;
	string Day;
	string Month;
	string Year;
public:
	int get_No() { return stoi(No); }
	string get_ID() { return ID; }
	string get_Lastname() { return Lastname; }
	string get_Firstname() { return Firstname; }
	string get_Gender() { return Gender; }
	string get_Day() { return Day; }
	string get_Month() { return Month; }
	string get_Year() { return Year; }

	void set_No(int a) { No = To_String(a); }
	void set_ID(string a) { ID = a; }
	void set_Lastname(string a) { Lastname = a; }
	void set_Firstname(string a) { Firstname=a; }
	void set_Gender(string a) { Gender=a; }
	void set_Day(string a) { Day=a; }
	void set_Month(string a) {Month=a; }
	void set_Year(string a) { Year=a; }

	void Input_st();
	void Output_st();

	
	string To_String(int a) {
		stringstream write;
		write << a;
		return write.str();
	}
	Student();
	Student(string, string, string, string, string, string, string, string);
	~Student();
};

