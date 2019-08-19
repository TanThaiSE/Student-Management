#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<stdlib.h>

using namespace std;
class CheckAttend_Point
{
private:
	string Id;
	string LastName;
	string FirstName;
	vector<string> attend;
	string mid;
	string finals;
	string Rank;
public:
	string get_id() { return Id; }
	string get_lastname() { return LastName; }
	string get_firstname() { return FirstName; }
	int get_sizeattend() { return attend.size(); }
	string get_posattend(int i) { return attend[i]; }
	double get_mid() { return stoi(mid); }
	double get_finals() { return stoi(finals); }
	string get_Rank() { return Rank; }

	void set_id(string a) {  Id=a; }
	void set_lastname(string a) {LastName=a; }
	void set_firstname(string a) { FirstName=a; }
	void set_sizeattend(int a) { 
		attend.clear();
		attend.resize(a);
	}
	void set_posattend(int i, int a) { attend[i] = to_string(a); }
	void set_mid(double a) { mid=to_string(a); }
	void set_finals(double a) { finals=to_string(a); }
	void set_Rank(string a) { Rank=a; }

	void Input_Attend_Point();
	void Output_Attend_Point();
	CheckAttend_Point();
	CheckAttend_Point(string, string, string, vector<string>, string, string, string);
	CheckAttend_Point(string, string,string);
	~CheckAttend_Point();
};

