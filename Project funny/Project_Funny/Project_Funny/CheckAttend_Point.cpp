#include "CheckAttend_Point.h"
void CheckAttend_Point::Input_Attend_Point()
{
	cin.ignore(); cout << "Input your Id:"; getline(cin, Id);
	cin.ignore(); cout << "Input your LastName:";	getline(cin, LastName);
	cin.ignore(); cout << "Input your FirstName:";	getline(cin, FirstName);
	for (int i = 0; i < 11; i++)
	{
		attend.push_back("0");
	}
	mid = "0";
	finals = "0";
	Rank = "0";
}
void CheckAttend_Point::Output_Attend_Point()
{
	cout << Id << ";" << LastName << ";" << FirstName << ";";
	for (int i = 0; i < attend.size(); i++)
	{
		cout << attend[i] << ";";
	}
	cout << mid << ";" << finals << ";" << Rank << endl;
}


CheckAttend_Point::CheckAttend_Point()
{
	Id = "0";
	LastName = "0";
	FirstName= "0";
	for (int i = 0; i < 11; i++)
	{
		attend.push_back("0");
	}
	mid = "0";
	finals = "0";
	Rank = "0";
}
CheckAttend_Point::CheckAttend_Point(string a, string b,string c)
{
	Id = a;
	LastName = b;
	FirstName = c;
	attend.clear();
	for (int i = 0; i < 11; i++)
	{
		attend.push_back("0");
	}
	mid = "0";
	finals = "0";
	Rank = "0";
}
CheckAttend_Point::CheckAttend_Point(string a, string b, string c, vector<string> d, string e, string f, string g)
{
	Id = a;
	LastName = b;
	FirstName = c;
	attend.clear();
	attend.resize(d.size());
	for (int i = 0; i < attend.size(); i++)
	{
		attend[i] = d[i];
	}
	mid = e;
	finals = f;
	Rank = g;
}

CheckAttend_Point::~CheckAttend_Point()
{
}
