#include"Class.h"
#include"ListAccount.h"
#include"ListCourse.h"
#include"Read_Write_File.h"

int main() {
	Class x;
	/*
	int a = -1;
	while (a!=0)
	{
		cout << "in:";	cin >> a;
		if (a == 0)
		{
			break;
		}
		else
			x.Importcsv();

	}
	*/
	//x.Menu_Class();
	
	ListCourse y;
	/*
	int a = -1;
	vector<COURSE> z;
	string path;
	while (a != 0)
	{
		cout << "in:";	cin >> a;
		if (a == 0)
		{
			break;
		}
		else
		{
		//	y.importcsv();
			y.CreateCandImportClass();
		}

	}
	*/
	//y.Menu_Course();
	Lecture z;
	//z.Menu_Lecture();
	OnlyStudent t;
	//t.Menu_Student();
	ListAccount a;
	string b, c;
	a.CheckLogin(b, c);
	
	int choose = -1;
	while (choose != 0)
	{
		cout << "1.Admin manage Class" << endl;
		cout << "2.Admin manage Course" << endl;
		cout << "3.Lecture" << endl;
		cout << "4.Student" << endl;
		cout << "0.Your choose:";	cin >> choose;
		switch (choose)
		{
		case 1: 
			system("cls");
			x.Menu_Class();
			system("pause");
			system("cls");
			break;
		case 2: 
			system("cls");
			y.Menu_Course();
			system("pause");
			system("cls");
			break;
		case 3:
			z.Menu_Lecture();
			system("pause");
			system("cls");
			break;
		case 4: 
			system("cls");
			t.Menu_Student();
			system("pause");
			system("cls");
			break;
		default: 

			break;
		}
	}
	
	
	return 0;
}

