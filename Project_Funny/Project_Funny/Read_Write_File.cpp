#include "Read_Write_File.h"

//Write file and Load file from Class
void ReadFilecsvTotxt(vector<Student>& x, vector<Account>& y, string path)
{
	x.clear();
	y.clear();
	ifstream fin;
	cin.ignore(); cout << "\nInput File to read:";		 getline(cin, path);
	fin.open("Filecsv//"+path+".csv");

	if (!fin.is_open())
	{
		cout << "Not read";
		return;
	}
	else
	{
		string temp;
		getline(fin, temp, '\n');
		while (!fin.eof())
		{
			string no, id, last, first, gen, dd, mm, yy;
			getline(fin, no, ';');
			getline(fin, id, ';');
			getline(fin, last, ';');
			getline(fin, first, ';');
			getline(fin, gen, ';');
			getline(fin, dd, '/');
			getline(fin, mm, '/');
			getline(fin, yy, '\n');
			Student a(no, id, last, first, gen, dd, mm, yy);
			x.push_back(a);
			Account b(id, dd, mm, yy);
			y.push_back(b);
		}
	}
	cout << "Read success";
	fin.close();
	
	ofstream fout;
	ofstream fout1;
	fout.open("Filecsv//"+path+".txt");
	fout1.open("Filelogin//Login.txt", ios::app);
	if (!fout.is_open())
	{
		cout << "Not write";
		return;
	}
	else if (!fout1.is_open())
	{
		cout << "Not write file login";
		return;
	}
	else
	{
		
		ifstream fin1;
		fin1.open("Filelogin//Login.txt");
		if (!fin1.is_open())
		{
			cout << "Not read file login";
			return;
		}
		else
		{
			fin1.seekg(ios::beg);
			string temp1;
			getline(fin1, temp1, '\n');
			if (temp1 != "")
			{
				fout1.seekp(0, ios::end);
				fout1 << "\n";
			}
		}
		for (int i = 0; i < x.size(); i++)
		{
			fout << x[i].get_No() << ";";
			fout << x[i].get_ID() << ";";
			fout << x[i].get_Lastname() << ";";
			fout << x[i].get_Firstname() << ";";
			fout << x[i].get_Gender() << ";";
			fout << x[i].get_Day() << ";";
			fout << x[i].get_Month() << ";";
			fout << x[i].get_Year();
			if (i < x.size() - 1)
			{
				fout << "\n";
			}
			
			fout1 << y[i].get_id() << ";";
			fout1 << y[i].get_day() << ";";
			fout1 << y[i].get_month() << ";";
			fout1 << y[i].get_year();
			if (i < y.size() - 1)
			{
				fout1 << "\n";
			}
		}
		fout.close();
		fout1.close();
	}

}

void ReadFiletxt(vector<Student>& x,string path)
{
	x.clear();
	ifstream fin;
	//cin.ignore(); cout << "\nChoose class want to add :";		 getline(cin, path);
	fin.open("Filecsv//" + path + ".txt");
	if (!fin.is_open())
	{
		cout << "Not read";
		return;
	}
	else
	{
		string temp;
		//getline(fin, temp, '\n');
		while (!fin.eof())
		{
			string no, id, last, first, gen, dd, mm, yy;
			getline(fin, no, ';');
			getline(fin, id, ';');
			getline(fin, last, ';');
			getline(fin, first, ';');
			getline(fin, gen, ';');
			getline(fin, dd, ';');
			getline(fin, mm, ';');
			getline(fin, yy, '\n');
			Student a(no, id, last, first, gen, dd, mm, yy);
			x.push_back(a);
		}
	}
	cout << "Read success";
	fin.close();
}

void WriteFile(vector<Student> x,string path)
{
	ofstream fout;
	fout.open("Filecsv//" + path + ".txt");
	if (!fout.is_open())
	{
		cout << "Not write";
		return;
	}
	else
	{
		for (int i = 0; i < x.size(); i++)
		{
			fout << x[i].get_No() << ";";
			fout << x[i].get_ID() << ";";
			fout << x[i].get_Lastname() << ";";
			fout << x[i].get_Firstname() << ";";
			fout << x[i].get_Gender() << ";";
			fout << x[i].get_Day() << ";";
			fout << x[i].get_Month() << ";";
			fout << x[i].get_Year();
			if (i < x.size() - 1)
			{
				fout << "\n";
			}
		}
		fout.close();
	}
}

void WriteFileLogin(vector<Account> x,string path)
{
	ofstream fout;
	fout.open("Filelogin//Login.txt");
	if (!fout.is_open())
	{
		cout << "Not open file";
		return;
	}
	else
	{
		for (int i = 0; i < x.size(); i++)
		{
			fout << x[i].get_id() << ";";
			fout << x[i].get_day() << ";";
			fout << x[i].get_month() << ";";
			fout << x[i].get_year();
			if (i < x.size() - 1)
			{
				fout << "\n";
			}
		}
	}
	cout << "Write login success";
	fout.close();
}

void LoadFileLogin(vector<Account>& x,string path)
{
	x.clear();
	ifstream fin;
	fin.open("Filelogin//Login.txt");
	if (!fin.is_open())
	{
		cout << "\nNot read file login" <<endl;;
		return;
	}
	else
	{
		while (!fin.eof())
		{
			string id, dd, mm, yy;
			getline(fin, id, ';');
			getline(fin, dd, ';');
			getline(fin, mm, ';');
			getline(fin, yy, '\n');
			Account a(id, dd, mm, yy);
			x.push_back(a);
		}
	}
	cout << "Read all login success";
	fin.close();
}

//Write file and Load file from Course
//void ReadFileCourse(vector<Course>x, string path)
//{
	
//}
/*
void ReadFilecsvtotxtCourse(vector<Course>& y,string path)
{
	y.clear();
	string semester;
	cin.ignore();	cout << "\nInput semester:"; getline(cin, semester);
	cin.ignore();	cout << "\nInput class want to import:";	getline(cin, path);
	ifstream fin;
	fin.open("Filecourse//" + semester + "//Course" + path + "-" + semester + ".csv");
	if (!fin.is_open())
	{
		cout << "Not open to read semester";
		return;
	}
	else
	{
		string temp;
		getline(fin, temp, '\n');
		while (!fin.eof())
		{
			string No, Id_Course, Name_Course, CLASS_, Lecture, Day_start, Month_start, Year_start, Day_end, Month_end, Year_end, Day_learn
				, Hour_start, Min_start, Hour_end, Min_end, Room;
			getline(fin, No, ';');
			getline(fin, Id_Course, ';');
			getline(fin, Name_Course, ';');
			getline(fin, CLASS_, ';');
			getline(fin, Lecture, ';');
			getline(fin, Day_start, '/');
			getline(fin, Month_start, '/');
			getline(fin, Year_start, ';');
			getline(fin, Day_end, '/');
			getline(fin, Month_end, '/');
			getline(fin, Year_end, ';');
			getline(fin, Day_learn, ';');
			getline(fin, Hour_start, ':');
			getline(fin, Min_start, ';');
			getline(fin, Hour_end, ':');
			getline(fin, Min_end, ';');
			getline(fin, Room, '\n');
			Course a(No, Id_Course, Name_Course, CLASS_, Lecture, Day_start, Month_start, Year_start, Day_end, Month_end, Year_end, Day_learn, Hour_start, Min_start, Hour_end, Min_end, Room);
			y.push_back(a);
		}
		fin.close();
	}
	ofstream fout;
	fout.open("Filecourse//" + semester + "//Course" + path + "-" + semester + ".txt");
	if (!fout.is_open())
	{
		cout << "Not open to write semester";
		return;
	}
	else
	{
		for (int i = 0; i < y.size(); i++)
		{
			fout << y[i].get_No() << ";";
			fout << y[i].get_Id_Course() << ";";
			fout << y[i].get_Name_Course() << ";";
			fout << y[i].get_CLASS_() << ";";
			fout << y[i].get_Lecture() << ";";
			fout << y[i].get_Day_start() << "/";
			fout << y[i].get_Month_start() << "/";
			fout << y[i].get_Year_start() << ";";
			fout << y[i].get_Day_end() << "/";
			fout << y[i].get_Month_end() << "/";
			fout << y[i].get_Year_end() << ";";
			fout << y[i].get_Day_learn() << ";";
			fout << y[i].get_Hour_start() << ":";
			fout << y[i].get_Min_start() << ";";
			fout << y[i].get_Hour_end() << ":";
			fout << y[i].get_Min_end() << ";";
			fout << y[i].get_Room();
			if (i < y.size() - 1)
			{
				fout << "\n";
			}
		}
		fout.close();
	}
}
*/
/*
void ReadFiletxtCourse(vector<Course>& x, string path)
{

}
void WriteFiletxtCourse(vector<Course> x, string path)
{

}
*/