#include "Course.h"
Course::Course(string a, string b, string c, string d, string e, string f, string g, string h, string i, string j, string k, string l, string m,
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


Course::Course()
{
}


Course::~Course()
{
}
