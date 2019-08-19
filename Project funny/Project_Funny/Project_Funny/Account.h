#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<stdlib.h>
using namespace std;
class Account
{
	string id, day, month, year;
public:
	void set_id(string a) { id = a; }
	void set_day(string a) { day = a; }
	void set_month(string a) { month = a; }
	void set_year(string a) { year = a; }

	string get_id() { return id; }
	string get_day() { return day; }
	string get_month() { return month; }
	string get_year() { return year; }
	
	Account();
	Account(string, string, string, string);
	~Account();
};

