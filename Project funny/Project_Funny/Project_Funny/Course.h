#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<stdlib.h>

using namespace std;
class COURSE
{
private:

	string No;
	string Id_Course;
	string Name_Course;
	string CLASS_;
	string Lecture;
	string Day_start;
	string Month_start;
	string Year_start;
	string Day_end;
	string Month_end;
	string Year_end;
	string Day_learn;
	string Hour_start;
	string Min_start;
	string Hour_end;
	string Min_end;
	string Room;
public:
	int get_No() { return stoi(No); }
	string get_Id_Course() { return Id_Course; }
	string get_Name_Course() { return Name_Course; }
	string get_CLASS_() { return CLASS_; }
	string get_Lecture() { return Lecture; }
	string get_Day_start() { return Day_start; }
	string get_Month_start() { return Month_start; }
	string get_Year_start() { return Year_start; }
	string get_Day_end() { return Day_end; }
	string get_Month_end() { return Month_end; }
	string get_Year_end() { return Year_end; }
	string get_Day_learn() { return Day_learn; }
	string get_Hour_start() { return Hour_start; }
	string get_Min_start() { return Min_start; }
	string get_Hour_end() { return Hour_end; }
	string get_Min_end() { return Min_end; }
	string get_Room() { return Room; }

	void set_No(int a) { No = to_string(a); }
	void set_Id_Course(string a) { Id_Course = a; }
	void set_Name_Course(string a) { Name_Course = a; }
	void set_CLASS_(string a) { CLASS_ = a; }
	void set_Lecture(string a) { Lecture = a; }
	void set_Day_start(string a) { Day_start = a; }
	void set_Month_start(string a) { Month_start = a; }
	void set_Year_start(string a) { Year_start = a; }
	void set_Day_end(string a) { Day_end = a; }
	void set_Month_end(string a) { Month_end = a; }
	void set_Year_end(string a) { Year_end = a; }
	void set_Day_learn(string a) { Day_learn = a; }
	void set_Hour_start(string a) { Hour_start = a; }
	void set_Min_start(string a) { Min_start = a; }
	void set_Hour_end(string a) { Hour_end = a; }
	void set_Min_end(string a) { Min_end = a; }
	void set_Room(string a) { Room = a; }

	void InputCourse();
	void OutputCourse();
	
	COURSE(string, string, string, string, string, string, string, string, string, string, string, string, string,string, string, string, string);
	COURSE();
	~COURSE();
};

