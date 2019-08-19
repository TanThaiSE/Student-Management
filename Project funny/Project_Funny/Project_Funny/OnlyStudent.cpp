#include "OnlyStudent.h"
void OnlyStudent::CheckInAttend()
{
	vector<COURSE>lstc;
	string semester, path;
	cin.ignore(); cout << "\nInput semester:";	getline(cin, semester);
	cin.ignore(); cout << "\nInput class:";		getline(cin, path);
	LoadfiletxtCourse(lstc, semester, path);
	cout << "No" << "- Id Course" << "- Name Course" << "- Class" << "- Lecture" << "- Day start" << "- Day end" << "- Day learn" << "- Time start" << "- Time end" << "- Room\n";
	for (int i = 0; i < lstc.size(); i++)
	{
		lstc[i].OutputCourse();
	}
	vector<CheckAttend_Point> lstcap;
	string idc;
	cin.ignore();	cout << "\nInput Id course:";	getline(cin, idc);
	//system("cls");
	LoadFiletxtListOfCourse(lstcap, semester, idc, path);
	string IDst;
	cin.ignore();	cout << "Input Your ID:";	getline(cin, IDst);
	int pos;
	for (int i = 0; i < lstcap.size(); i++)
	{
		
		if (lstcap[i].get_id() == IDst)
		{
			lstcap[i].Output_Attend_Point();
			pos = i;
		}
	}
	int choose = -1;
	system("cls");
	while (choose != 0)
	{
		cout << "Id" << "- Last name" << "- First name" << "-W01-W02-W03-W04-W05-W06-W07-W08-W09-W10-W11" << "- Mid- Final- Rank" << endl;
		lstcap[pos].Output_Attend_Point();
		cout << "\n//~~ Menu check in attend~~//";
		cout << "\n1.Continue";
		cout << "\n0.Exit";
		cout << "\nYour choose:";	cin >> choose;
		if (choose == 0)
			break;
		int w_edit, choose_w;
		cout << "\nInput week want to check:";	cin >> choose_w;
		cout << "\nWeek want to check:" << choose_w;
		cout << "\nYour check:";	 cin >> w_edit;
		lstcap[pos].set_posattend(choose_w - 1, w_edit);
		system("cls");
	}
	WriteFiletxtListOfCourse(lstcap, semester, idc, path);
	
}

void OnlyStudent::ViewAttend_Score()
{
	vector<COURSE>lstc;
	string semester, path;
	cin.ignore(); cout << "\nInput semester:";	getline(cin, semester);
	cin.ignore(); cout << "\nInput class:";		getline(cin, path);
	LoadfiletxtCourse(lstc, semester, path);
	cout << "No" << "- Id Course" << "- Name Course" << "- Class" << "- Lecture" << "- Day start" << "- Day end" << "- Day learn" << "- Time start" << "- Time end" << "- Room\n";
	for (int i = 0; i < lstc.size(); i++)
	{
		lstc[i].OutputCourse();
	}
	//
	string id_course;
	cin.ignore(); cout << "\nInput id course:";	getline(cin, id_course);
	vector<CheckAttend_Point> lstcap;
	LoadFiletxtListOfCourse(lstcap, semester, id_course, path);
	cout << "Id" << "- Last name" << "- First name" << "-W01-W02-W03-W04-W05-W06-W07-W08-W09-W10-W11" << "- Mid- Final- Rank" << endl;
	for (int i = 0; i < lstcap.size(); i++)
	{
		lstcap[i].Output_Attend_Point();
	}

}

void OnlyStudent::ViewSchedule()
{
	vector<COURSE>lstc;
	string semester, path;
	cin.ignore(); cout << "\nInput semester:";	getline(cin, semester);
	cin.ignore(); cout << "\nInput class:";		getline(cin, path);
	LoadfiletxtCourse(lstc, semester, path);
	cout << "No" << "- Id Course" << "- Name Course" << "- Class" << "- Lecture" << "- Day start" << "- Day end" << "- Day learn" << "- Time start" << "- Time end" << "- Room\n";
	for (int i = 0; i < lstc.size(); i++)
	{
		lstc[i].OutputCourse();
	}
}

void OnlyStudent::Menu_Student()
{
	OnlyStudent x;
	int choose = -1;
	while (choose != 0)
	{
		cout << "1.Check in Attend" << endl;
		cout << "2.View result Attend and Scoreboard" << endl;
		cout << "3.View Schedule" << endl;
		cout << "0.Your choose:";	cin >> choose;
		switch (choose)
		{
		case 1:
			x.CheckInAttend(); //finish
			system("cls");
			break;
		case 2:
			x.ViewAttend_Score();	//finish
			system("pause");
			system("cls");
			break;
		case 3:
			x.ViewSchedule();	//finish
			system("pause");
			system("cls");
			break;
		default:
			system("cls");
			break;
		}

	}
}
OnlyStudent::OnlyStudent()
{
}


OnlyStudent::~OnlyStudent()
{
}
