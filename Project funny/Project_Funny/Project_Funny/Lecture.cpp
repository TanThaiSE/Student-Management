#include "Lecture.h"
void Lecture::ViewListCourse()
{
	string name_lecture;
	cin.ignore();	cout << "Input name of lecture:";	getline(cin, name_lecture);
	string semester;
	cin.ignore();	cout << "Input semester:";	getline(cin, semester);
	vector<COURSE> write;
	vector<COURSE> lstc;
	for (int i = 0; i < 6; i++)
	{
		string path = "18CLC" + to_string(i);
		LoadfiletxtCourse(lstc, semester, path);
		for (int j = 0; j < lstc.size(); j++)
		{
			if (name_lecture == lstc[j].get_Lecture())
			{
				write.push_back(lstc[j]);
			}
		}
	}
	WriteFiletxtLecture(write, semester, name_lecture);
	for (int i = 0; i < write.size(); i++)
	{
		write[i].OutputCourse();
	}
}

void Lecture::ViewListStInCourse()
{
	vector<COURSE> lstc;
	string name_lecture;
	cin.ignore();	cout << "\nInput name of lecture:";	getline(cin, name_lecture);
	string semester;
	cin.ignore();	cout << "\nInput semester:";	getline(cin, semester);
	LoadFiletxtLecture(lstc, semester, name_lecture);
	string idc;
	for (int i = 0; i < lstc.size(); i++)
	{
		cout << "Lecture:" << name_lecture << " teach:" << lstc[i].get_CLASS_() << endl;
		idc = lstc[i].get_Id_Course();
	}
	string name_class;
	cin.ignore();	cout << "Input name of class want to see:";	getline(cin, name_class);

	vector<CheckAttend_Point> lstcap;
	LoadFiletxtListOfCourse(lstcap, semester, idc, name_class);
	cout << "Id" << "- Last name" << "- First name" << "-W01-W02-W03-W04-W05-W06-W07-W08-W09-W10-W11" << "- Mid- Final- Rank" << endl;
	for (int i = 0; i < lstcap.size(); i++)
	{
		lstcap[i].Output_Attend_Point();
	}
}

void Lecture::EditAttend_Score()
{
	vector<COURSE> lstc;
	string name_lecture, semester;
	cin.ignore();	cout << "\nInput name of lecture:";	getline(cin, name_lecture);
	cin.ignore();	cout << "\nInput semester:";	getline(cin, semester);
	LoadFiletxtLecture(lstc, semester, name_lecture);
	string idc;
	for (int i = 0; i < lstc.size(); i++)
	{
		cout << "Lecture:" << name_lecture << " teach:" << lstc[i].get_CLASS_() << endl;
		idc = lstc[i].get_Id_Course();
	}
	string name_class;
	cin.ignore();	cout << "Input name of class want to see:";	getline(cin, name_class);
	vector<CheckAttend_Point> lstcap;
	LoadFiletxtListOfCourse(lstcap, semester, idc, name_class);
	cout << "Id" << "- Last name" << "- First name" << "-W01-W02-W03-W04-W05-W06-W07-W08-W09-W10-W11" << "- Mid- Final- Rank" << endl;
	for (int i = 0; i < lstcap.size(); i++)
	{
		lstcap[i].Output_Attend_Point();
	}

	string edit;
	cin.ignore();	 cout << "\nInput your ID student want to choose:";		getline(cin, edit);
	int pos;
	for (int i = 0; i < lstcap.size(); i++)
	{
		if (lstcap[i].get_id() == edit)
		{
			pos = i;
			break;
		}
	}
	int choose = -1;
	system("cls");
	while (choose != 0)
	{
		cout << "Id" << "- Last name" << "- First name" << "-W01-W02-W03-W04-W05-W06-W07-W08-W09-W10-W11" << "- Mid- Final- Rank" << endl;
		lstcap[pos].Output_Attend_Point();
		cout << "\n//~~ Menu edit attend and score~~//";
		cout << "\n1.Edit Attend";
		cout << "\n2.Edit Score";
		cout << "\n0.Exit";
		cout << "\nYour choose:";	cin >> choose;
		int w_edit,choose_w;
		double m, f;
		string r;
		Lecture x;
		switch (choose)
		{
		case 1:
			cout << "\nInput week want to check:";	cin >> choose_w;
			cout << "\nWeek want to check:" << choose_w;
			cout << "\nYour check:";	 cin >> w_edit;
			lstcap[pos].set_posattend(choose_w-1, w_edit);
			system("cls");
			break;
		case 2:
			cin.ignore();	cout << "\nInput midterm:";	cin >> m;
			cin.ignore(); cout << "\nInput final:";		cin >> f;
			r = x.Rank(m, f);
			lstcap[pos].set_mid(m);
			lstcap[pos].set_finals(f);
			lstcap[pos].set_Rank(r);
			system("cls");
			break;
		default:
			cout << "Input not right";
			system("cls");
			break;
		}
	}
	WriteFiletxtListOfCourse(lstcap, semester, idc, name_class);
}

string Lecture::Rank(double a, double b)
{
	double total = (b * 2 + a) * 1.0 / 3;
	if (total > 9)
	{
		return "A";
	}
	else if (total > 8)
	{
		return "B";
	}
	else if (total > 7)
	{
		return "C";
	}
	else if (total > 6)
	{
		return "D";
	}
	else if (total > 5)
	{
		return "E";
	}
	else
	{
		return "F";
	}
}

void Lecture::ViewAttend_Score()
{
	vector<COURSE> lstc;
	string name_lecture, semester;
	cin.ignore();	cout << "\nInput name of lecture:";	getline(cin, name_lecture);
	cin.ignore();	cout << "\nInput semester:";	getline(cin, semester);
	LoadFiletxtLecture(lstc, semester, name_lecture);
	string idc;
	for (int i = 0; i < lstc.size(); i++)
	{
		cout << "Lecture:" << name_lecture << " teach:" << lstc[i].get_CLASS_() << endl;
		idc = lstc[i].get_Id_Course();
	}
	string name_class;
	cin.ignore();	cout << "Input name of class want to see:";	getline(cin, name_class);
	vector<CheckAttend_Point> lstcap;
	LoadFiletxtListOfCourse(lstcap, semester, idc, name_class);
	cout << "Id" << "- Last name" << "- First name" << "-W01-W02-W03-W04-W05-W06-W07-W08-W09-W10-W11" << "- Mid- Final- Rank" << endl;
	for (int i = 0; i < lstcap.size(); i++)
	{
		lstcap[i].Output_Attend_Point();
	}
}

void Lecture::Menu_Lecture()
{
	Lecture x;
	int choose = -1;
	while (choose != 0)
	{
		cout << "1.View list of course" << endl;
		cout << "2.View list student in course" << endl;
		cout << "3.Edit/Import Attend and Scoreboard" << endl;
		cout << "4.View Attend and Scoreboard" << endl;
		cout << "0.Your choose:";	cin >> choose;
		switch (choose)
		{
		case 1:
			x.ViewListCourse();
			system("cls");
			break;
		case 2:
			x.ViewListStInCourse();
			system("pause");
			system("cls");
			break;
		case 3:
			x.EditAttend_Score();
			system("cls");
			break;
		case 4:
			x.ViewAttend_Score();
			system("pause");
			system("cls");
			break;
		default: 
			system("cls");
			break;
		}

	}
}

Lecture::Lecture()
{
}


Lecture::~Lecture()
{
}
