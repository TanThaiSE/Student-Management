#include "ListCourse.h"

void ListCourse::importcsv()
{
	string path;
	ReadFilecsvtotxtCourse(lstc, path);
}

void ListCourse::CreateCandImportClass()
{
	string path, semester, id_course;
	vector<Student> x;
	cin.ignore();	cout << "\nInput semester:"; getline(cin, semester);
	cin.ignore();	cout << "\nImport Id coure want to create:";	getline(cin, id_course);
	cin.ignore();	cout << "\nInput your class:";	getline(cin, path);
	ReadFiletxtCourseAndLoadSt(x, lstc, semester, id_course, path);
}

void ListCourse::AddCourse()
{
	string semester, path;
	cin.ignore();	cout << "\nInput semester:"; getline(cin, semester);
	cin.ignore();	cout << "\nInput class want to load:";	getline(cin, path);
	LoadfiletxtCourse(lstc, semester, path);
	COURSE x;
	x.InputCourse();
	x.set_No(lstc.size()+1);
	lstc.push_back(x);
	string id_course = x.get_Id_Course();
	WriteFiletxtCourse(lstc, semester, path);
	vector<Student> y;
	//cin.ignore();	cout << "\nImport Id coure want to create:";	getline(cin, id_course);
	ReadFiletxtCourseAndLoadSt(y, lstc, semester, id_course, path);

}

void ListCourse::EditCourse()
{
	string semester, path;
	cin.ignore();	cout << "\nChoose semester:";	getline(cin, semester);
	cin.ignore();	cout << "\nChoose class:";	getline(cin, path);
	LoadfiletxtCourse(lstc, semester, path);
	for (int i = 0; i < lstc.size(); i++)
	{
		lstc[i].OutputCourse();
	}
	string edit;
	cin.ignore();	 cout << "\nInput your ID_Course want to choose:";		getline(cin, edit);
	int pos;
	for (int i = 0; i < lstc.size(); i++)
	{
		if (lstc[i].get_Id_Course() == edit)
		{
			pos = i;
			break;
		}
	}
	int choose = -1;
	system("cls");
	while (choose!=0)
	{
		lstc[pos].OutputCourse();
		cout << "\n//~~ Menu edit course~~//";
		cout << "\n1.Edit Name of leacture";
		cout << "\n2.Edit Day of week start";
		cout << "\n3.Edit Start Hour";
		cout << "\n4.Edit End Hour";
		cout << "\n5.Edit Room";
		cout << "\n6.Edit Day-Month-Year Start";
		cout << "\n7.Edit Day-Month-Year End";
		cout << "\n0.Exit";
		cout << "\nYour choose:";	cin >> choose;
		string name_lecture, day_st, h_b, m_b, h_e, m_e, r, dd, mm, yy;
		switch (choose)
		{
		case 1:
			cin.ignore();	cout << "Input name of lecture:";	getline(cin, name_lecture);
			lstc[pos].set_Lecture(name_lecture);
			system("cls");
			break;
		case 2:
			cin.ignore();	cout << "Input day start:";	getline(cin, day_st);
			lstc[pos].set_Day_learn(day_st);
			system("cls");
			break;
		case 3:
			cin.ignore();	cout << "Input hour start:";	getline(cin, h_b);
			cin.ignore();	cout << "Input minute start:";	getline(cin, m_b);
			lstc[pos].set_Hour_start(h_b);
			lstc[pos].set_Min_start(m_b);
			system("cls");
			break;
		case 4:
			cin.ignore();	cout << "Input hour end:";	getline(cin, h_e);
			cin.ignore();	cout << "Input minute end:";	getline(cin, m_e);
			lstc[pos].set_Hour_end(h_e);
			lstc[pos].set_Min_end(m_e);
			system("cls");
			break;
		case 5:
			cin.ignore();	cout << "Input room:";	getline(cin, r);
			lstc[pos].set_Room(r);
			system("cls");
			break;
		case 6:
			cin.ignore(); cout << "Input day start:";	getline(cin, dd);
			cin.ignore(); cout << "Input month start:";	getline(cin, mm);
			cin.ignore(); cout << "Input year start:";	getline(cin, yy);
			lstc[pos].set_Day_start(dd);
			lstc[pos].set_Month_start(mm);
			lstc[pos].set_Year_start(yy);
			system("cls");
			break;
		case 7:
			cin.ignore(); cout << "Input day end:";	getline(cin, dd);
			cin.ignore(); cout << "Input month end:";	getline(cin, mm);
			cin.ignore(); cout << "Input year end:";	getline(cin, yy);
			lstc[pos].set_Day_end(dd);
			lstc[pos].set_Month_end(mm);
			lstc[pos].set_Year_end(yy);
			system("cls");
			break;
		default:
			cout << "Input not right";
			system("cls");
			break;
		}
	}
	WriteFiletxtCourse(lstc, semester, path);
}

void ListCourse::RemoveCourse()
{
	string semester, path;
	cin.ignore();	cout << "\nInput semester:"; getline(cin, semester);
	cin.ignore();	cout << "\nInput class want to choose:";	getline(cin, path);
	LoadfiletxtCourse(lstc, semester, path);
	for (int i = 0; i < lstc.size(); i++)
	{
		lstc[i].OutputCourse();
	}
	string Remove;
	cin.ignore();	 cout << "\nInput your ID_Course want to choose:";		getline(cin, Remove);
	int pos;
	for (int i = 0; i < lstc.size(); i++)
	{
		if (lstc[i].get_Id_Course() == Remove)
		{
			cout << "\nHave found" << endl;
			lstc.erase(lstc.begin() + i);
			pos = i;
			break;
		}
	}
	for (int i = pos; i < lstc.size(); i++)
	{
		lstc[i].set_No(i + 1);
	}
	WriteFiletxtCourse(lstc, semester, path);
	string name_remove = "File list of course//" + semester + "//"+Remove + "-" + path + ".txt";
	if (remove(name_remove.c_str()) == 0)
	{
		cout << "Delete file" << Remove << " Success" << endl;
	}
	else
	{
		cout << "Delete not find!!";
	}
	
}

void ListCourse::RemoveStOutCourse()
{
	string semester, path, id_course;
	cin.ignore(); cout << "\nInput semester:";	getline(cin, semester);
	cin.ignore(); cout << "\nInput class:";		getline(cin, path);
	cin.ignore(); cout << "\nInput id course:";	getline(cin, id_course);
	vector<CheckAttend_Point> lstcap;
	LoadFiletxtListOfCourse(lstcap, semester, id_course, path);
	for (int i = 0; i < lstcap.size(); i++)
	{
		lstcap[i].Output_Attend_Point();
	}
	string id;
	cin.ignore();	cout << "\nInput Id want to remove:";	getline(cin, id);
	for (int i = 0; i < lstcap.size(); i++)
	{
		if (lstcap[i].get_id() == id)
		{
			lstcap.erase(lstcap.begin()+i);
			WriteFiletxtListOfCourse(lstcap, semester, id_course, path);
			cout << "\nRemove oke";
			break;
		}
	}
}

void ListCourse::AddStIntoCourse()
{
	string semester, path, id_course;
	cin.ignore(); cout << "\nInput semester:";	getline(cin, semester);
	cin.ignore(); cout << "\nInput class:";		getline(cin, path);
	cin.ignore(); cout << "\nInput id course:";	getline(cin, id_course);
	vector<CheckAttend_Point> lstcap;
	LoadFiletxtListOfCourse(lstcap, semester, id_course, path);
	CheckAttend_Point x;
	x.Input_Attend_Point();
	lstcap.push_back(x);
	WriteFiletxtListOfCourse(lstcap, semester, id_course, path);
}

void ListCourse::ViewListCourse()
{
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

void ListCourse::ViewListStOfCourse()
{
	string semester, path, id_course;
	cin.ignore(); cout << "\nInput semester:";	getline(cin, semester);
	cin.ignore(); cout << "\nInput class:";		getline(cin, path);
	cin.ignore(); cout << "\nInput id course:";	getline(cin, id_course);
	vector<CheckAttend_Point> lstcap;
	LoadFiletxtListOfCourse(lstcap, semester, id_course, path);
	cout << "Id" << "- Last name" << "- First name" << "-W01-W02-W03-W04-W05-W06-W07-W08-W09-W10-W11" << "- Mid- Final- Rank" << endl;
	for (int i = 0; i<lstcap.size(); i++)
	{
		lstcap[i].Output_Attend_Point();
	}
	
}

void ListCourse::Menu_Course()
{
	ListCourse x;
	int choose = -1;
	while (choose != 0)
	{
		cout << "1.Add new course" << endl;
		cout << "2.Edit course" << endl;
		cout << "3.Remove course" << endl;
		cout << "4.Remove student from course" << endl;
		cout << "5.Add student from course" << endl;
		cout << "6.View list of courses" << endl;
		cout << "7.View list student of courses (attend and score)" << endl;
		cout << "0.Your choose:";	cin >> choose;
		switch (choose)
		{
		case 1: 
			x.AddCourse(); //finish
			system("cls");
			break;
		case 2: 
			x.EditCourse(); //finish
			system("cls");
			break;
		case 3: 
			x.RemoveCourse(); //finish
			system("cls");
			break;
		case 4: 
			x.RemoveStOutCourse(); //finish
			system("cls");
			break;
		case 5: 
			x.AddStIntoCourse(); //finish
			system("pause");
			system("cls");
			break;
		case 6:
			x.ViewListCourse(); //finish
			system("pause");
			system("cls");
			break;
		case 7:
			x.ViewListStOfCourse();
			system("pause");
			system("cls");
			break;
		default:  //finish
			system("cls");
			break;
		}

	}
}

ListCourse::ListCourse()
{
}


ListCourse::~ListCourse()
{
}
