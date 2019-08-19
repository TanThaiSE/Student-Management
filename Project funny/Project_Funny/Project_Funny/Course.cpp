#include "Course.h"
COURSE::COURSE(string a, string b, string c, string d, string e, string f, string g, string h, string i, string j, string k, string l, string m,
	string n, string o, string p, string q)
{
	No = a;
	Id_Course = b;
	Name_Course = c;
	CLASS_ = d;
	Lecture = e;
	Day_start = f;
	Month_start = g;
	Year_start = h;
	Day_end = i;
	Month_end = j;
	Year_end = k;
	Day_learn = l;
	Hour_start = m;
	Min_start = n;
	Hour_end = o;
	Min_end = p;
	Room = q;
}


COURSE::COURSE()
{
	No = "0";
	Id_Course = "0";
	Name_Course = "0";
	CLASS_ = "0";
	Lecture = "0";
	Day_start = "0";
	Month_start = "0";
	Year_start = "0";
	Day_end = "0";
	Month_end = "0";
	Year_end = "0";
	Day_learn = "0";
	Hour_start = "0";
	Min_start = "0";
	Hour_end = "0";
	Min_end = "0";
	Room = "0";
}
void COURSE::InputCourse()
{
	cin.ignore(); cout << "\nInput ID course:";	getline(cin, Id_Course);
	cin.ignore(); cout << "\nInput Name course:";	getline(cin, Name_Course);
	cin.ignore(); cout << "\nInput Class:";	getline(cin, CLASS_);
	cin.ignore(); cout << "\nInput Lecture:";	getline(cin, Lecture);
	cin.ignore(); cout << "\nInput Day start:";	getline(cin, Day_start);
	cin.ignore(); cout << "\nInput Month start:"; getline(cin, Month_start);
	cin.ignore(); cout << "\nInput Year start:";	getline(cin, Year_start);
	cin.ignore(); cout << "\nInput Day end:";	getline(cin, Day_end);
	cin.ignore(); cout << "\nInput Month end:"; getline(cin, Month_end);
	cin.ignore(); cout << "\nInput Year end:";	getline(cin, Year_end);
	cin.ignore(); cout << "\nInput Day learn:";	getline(cin, Day_learn);
	cin.ignore(); cout << "\nInput Hour start:";	getline(cin, Hour_start);
	cin.ignore(); cout << "\nInput Min start:";	getline(cin, Min_start);
	cin.ignore(); cout << "\nInput Hour end:";	getline(cin, Hour_end);
	cin.ignore(); cout << "\nInput Min end:";	getline(cin, Min_end);
	cin.ignore(); cout << "\nInput Room:";	getline(cin, Room);
}
void COURSE::OutputCourse()
{
	cout << No << "," << Id_Course << "," << Name_Course << "," << CLASS_ << "," << Lecture << "," << Day_start << "/" << Month_start << "/" << Year_start << ","
		<< Day_end << "/" << Month_end << "/" << Year_end << "," << Day_learn << "," << Hour_start << ":" << Min_start << "," << Hour_end << ":" << Min_end << "," << Room << endl;
}

COURSE::~COURSE()
{
}
