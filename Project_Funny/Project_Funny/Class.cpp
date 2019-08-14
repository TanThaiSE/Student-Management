#include "Class.h"
void Class::InputList()
{
	string path;
	string path1;
	path1 = "Filelogin//Login.txt";
	cin.ignore(); cout << "\nChoose class want to add :";		 getline(cin, path);
	ReadFiletxt(lst,path);
	vector<Account> y;
	LoadFileLogin(y, "Filelogin//Login.txt");
	Student x;
	x.Input_st();
	x.set_No(lst.size()+1);
	lst.push_back(x);
	WriteFile(lst, path);
	Account z(x.get_ID(), x.get_Day(), x.get_Month(), x.get_Year());
	y.push_back(z);
	WriteFileLogin(y, path1);
}
void Class::OutputList(vector<Student>& x)
{
	for (int i = 0; i < lst.size(); i++)
	{
		cout << "Student " << i + 1 << endl;
		x[i].Output_st();
	}
}
void Class::Importcsv()
{
	vector<Account> lsta;
	string path;
	ReadFilecsvTotxt(lst,lsta, path);
}
void Class::Edit()
{
	int choose=-1;
	int edit;
	string path;
	string path1;
	path1 = "Filelogin//Login.txt";
	cin.ignore(); cout << "Input class:";	getline(cin, path);
	ReadFiletxt(lst, path);
	vector<Account> lsta;
	LoadFileLogin(lsta, "Filelogin//Login.txt");
	cout << "\nNo----ID----LASTNAME----FIRSTNAME----GENDER----DD----MM----YY" << endl;
	for (int i = 0; i < lst.size(); i++)
	{
		lst[i].Output_st();
	}
	cout << "Edit student" << endl;
	cout << "Choose number of student want to edit" << endl;
	cin >> edit;
	int possition = 0;
	for (int j = 0; j < lsta.size(); j++)
	{
		if (lsta[j].get_id() == lst[edit - 1].get_ID())
		{
			possition = j;
			cout << "Have found"<<endl;
			break;
		}
	}
	while (choose != 0)
	{
		lst[edit - 1].Output_st();
		cout << "//~~~Menu edit~~~//" << endl;
		cout << "1.Edit id" << endl;
		cout << "2.Edit Last name" << endl;
		cout << "3.Edit First name" << endl;
		cout << "4.Edit Gender" << endl;
		cout << "5.Edit DoB" << endl;
		cout << "0.Exit" << endl;
		cout << "Your choose:";	cin >> choose;
		string id, last, first, gen, dd, mm, yy;
		switch (choose)
		{
		case 1:
			cin.ignore(); cout << "Input id want to edit:";	getline(cin, id);
			lst[edit - 1].set_ID(id);
			lsta[possition].set_id(id);
			system("cls");
			break;
		case 2:
			cin.ignore(); cout << "Input lastname want to edit:";	getline(cin, last);
			lst[edit - 1].set_Lastname(last);
			system("cls");
			break;
		case 3:
			cin.ignore(); cout << "Input firstname want to edit:";	getline(cin, first);
			lst[edit - 1].set_Firstname(first);
			system("cls");
			break;
		case 4:
			cin.ignore(); cout << "Input gender want to edit;";	getline(cin, first);
			lst[edit - 1].set_Gender(gen);
			system("cls");
			break;
		case 5:
			cout << "Input DoB want to edit" << endl;
			cin.ignore(); cout << "Input day:";	getline(cin, dd);
			cin.ignore(); cout << "Input month:";	getline(cin, mm);
			cin.ignore(); cout << "Input year:";	getline(cin, yy);
			lst[edit - 1].set_Day(dd);
			lst[edit - 1].set_Month(mm);
			lst[edit - 1].set_Year(yy);
			lsta[possition].set_day(dd);
			lsta[possition].set_month(mm);
			lsta[possition].set_year(yy);
			system("cls");
			break;
		default:
			system("cls");
			break;
		}
	}
	WriteFile(lst, path);
	WriteFileLogin(lsta,path1);
}
void Class::Change_st_to_class()
{
	Class x;
	int choose;
	vector<Student> lsc;
	string path, path1;
	cin.ignore(); cout << "\nChoose class old want to change :";		 getline(cin, path);
	ReadFiletxt(lst, path);
	cin.ignore(); cout << "\nChoose class new want to add :";		 getline(cin, path1);
	ReadFiletxt(lsc, path1);
	cout << "List old class:" << path << endl;
	cout << "\nNo----ID----LASTNAME----FIRSTNAME----GENDER----DD----MM----YY" << endl;
	for (int i = 0; i < lst.size(); i++)
	{
		lst[i].Output_st();
	}
	cout << "Choose number of student want to change";	cin >> choose;
	lsc.push_back(lst[choose - 1]);
	lsc[lsc.size() - 1].set_No(lsc.size());

	int pos = lst[choose - 1].get_No();
	lst.erase(lst.begin() + (choose - 1));
	for (int i = choose-1; i < lst.size(); i++)
	{
		lst[i].set_No(pos);
		pos++;
	}
	cout << "List new class:" << path1 << endl;
	cout << "\nNo----ID----LASTNAME----FIRSTNAME----GENDER----DD----MM----YY" << endl;
	for (int i = 0; i < lsc.size(); i++)
	{
		lsc[i].Output_st();
	}
	WriteFile(lst, path);
	WriteFile(lsc, path1);
	system("pause");
}
void Class::Remove()
{
	int remove1;
	string path;
	string path1 = "Filelogin//Login.txt";
	path1 = "Filelogin//Login.txt";
	cin.ignore(); cout << "Input class:";	getline(cin, path);
	ReadFiletxt(lst, path);
	vector<Account> y;
	LoadFileLogin(y, "Filelogin//Login.txt");
	cout << "\nNo----ID----LASTNAME----FIRSTNAME----GENDER----DD----MM----YY" << endl;
	for (int i = 0; i < lst.size(); i++)
	{
		lst[i].Output_st();
	}
	cout << "Remove student" << endl;
	cout << "Choose number of student want to remove:" << endl;
	cin >> remove1;
	for (int i = 0; i < y.size(); i++)
	{
		if (y[i].get_id() == lst[remove1 - 1].get_ID())
		{
			cout << "Have found" << endl;
			y.erase(y.begin() +i);
			WriteFileLogin(y,path1);
			break;
		}
	}
	int pos = lst[remove1 - 1].get_No();
	lst.erase(lst.begin() + (remove1 - 1));
	for (int i = remove1-1; i < lst.size(); i++)
	{
		lst[i].set_No(pos);
		pos++;
	}
	WriteFile(lst, path);
}
void Class::ViewList()
{
	string path;
	cin.ignore(); cout << "\nChoose class want to see :";		 getline(cin, path);
	ReadFiletxt(lst, path);
	cout << "\nNo----ID----LASTNAME----FIRSTNAME----GENDER----DD----MM----YY" << endl;
	for (int i = 0; i < lst.size(); i++)
	{
		lst[i].Output_st();
	}
}
void Class::Menu_Class()
{
	Class x;
	int choose = -1;
	while (choose != 0)
	{
		cout << "1.Add new student" << endl;
		cout << "2.Edit student" << endl;
		cout << "3.Remove student" << endl;
		cout << "4.Change students to class" << endl;
		cout << "5.View list student of class" << endl;
		cout << "0.Your choose:";	cin >> choose;
		switch (choose)
		{
		case 1: //finish
			x.InputList();
			system("cls");
			break;
		case 2: //finish
			x.Edit(); 
			system("cls");
			break;
		case 3: //finish
			x.Remove(); 
			system("cls");
			break;
		case 4: //finish
			x.Change_st_to_class();
			system("cls");
			break;
		case 5: //finish
			x.ViewList();
			system("pause");
			system("cls");
			break;
		default: //finish
			system("cls");
			break;
		}
		
	}
}

Class::Class()
{
}


Class::~Class()
{
}
