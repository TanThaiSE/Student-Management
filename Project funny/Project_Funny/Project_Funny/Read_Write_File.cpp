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
			if (x[i].get_Day().size() < 2)
			{
				fout << "0" << x[i].get_Day() << ";";
			}
			else
			{
				fout << x[i].get_Day() << ";";
			}
			if (x[i].get_Month().size() < 2)
			{
				fout << "0" << x[i].get_Month() << ";";
			}
			else
			{
				fout << x[i].get_Month() << ";";
			}

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
			if (x[i].get_day().size() < 2)
			{
				fout << "0" << x[i].get_day() << ";";
			}
			else
			{
				fout << x[i].get_day() << ";";
			}
			if (x[i].get_month().size() < 2)
			{
				fout << "0" << x[i].get_month() << ";";
			}
			else
			{
				fout << x[i].get_month() << ";";
			}
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
void ReadFilecsvtotxtCourse(vector<COURSE>& y, string path)
{
	/*
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
			COURSE a(No, Id_Course, Name_Course, CLASS_, Lecture, Day_start, Month_start, Year_start, Day_end, Month_end, Year_end, Day_learn, Hour_start, Min_start, Hour_end, Min_end, Room);
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
	*/
	string semester;
	cin.ignore();	cout << "\nInput semester:"; getline(cin, semester);
	for (int i = 1; i < 7; i++)
	{
		y.clear();
		path = to_string(i);
		ifstream fin;
		fin.open("Filecourse//" + semester + "//Course18CLC" + path + "-" + semester + ".csv");
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
				COURSE a(No, Id_Course, Name_Course, CLASS_, Lecture, Day_start, Month_start, Year_start, Day_end, Month_end, Year_end, Day_learn, Hour_start, Min_start, Hour_end, Min_end, Room);
				y.push_back(a);
			}
			fin.close();
		}
		ofstream fout;
		fout.open("Filecourse//" + semester + "//Course18CLC" + path + "-" + semester + ".txt");
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
		cout << "Hoan thanh buoc" << i << endl;
	}
	
}

void ReadFiletxtCourseAndLoadSt(vector<Student>&x,vector<COURSE>& y, string semester, string id_course, string path)
{
	x.clear();
	y.clear();
	ifstream fin;
	fin.open("Filecourse//" + semester + "//Course" + path + "-" + semester + ".txt");
	
	ReadFiletxt(x, path);
	if (!fin.is_open())
	{
		cout << "Not open to read semester";
		return;
	}
	else
	{
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
			COURSE a(No, Id_Course, Name_Course, CLASS_, Lecture, Day_start, Month_start, Year_start, Day_end, Month_end, Year_end, Day_learn, Hour_start, Min_start, Hour_end, Min_end, Room);
			y.push_back(a);
		}
		fin.close();
	}
	ofstream fout;
	for (int i = 0; i < y.size(); i++)
	{
		if (id_course == y[i].get_Id_Course())
		{
			cout << "Oke";
			break;
		}
	}
	fout.open("File list of course//" + semester + "//" + id_course + "-" + path + ".txt");
	if (!fout.is_open())
	{
		cout << "Not open to write academy";
		return;
	}
	else
	{
		for (int i = 0; i < x.size(); i++)
		{
			fout << x[i].get_ID() << ";";
			fout << x[i].get_Lastname() << ";";
			fout << x[i].get_Firstname() << ";";
			for (int j = 0; j < 13; j++)
			{
				fout << "0;";
			}
			fout << "0";
			if (i < x.size() - 1)
			{
				fout << '\n';
			}
		}
		fout.close();
	}
	
}

void LoadfiletxtCourse(vector<COURSE>& x, string semester, string path)
{
	x.clear();
	ifstream fin;
	fin.open("Filecourse//" + semester + "//Course" + path + "-" + semester + ".txt");
	if (!fin.is_open())
	{
		cout << "Not open to read semester";
		return;
	}
	else
	{
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
			COURSE a(No, Id_Course, Name_Course, CLASS_, Lecture, Day_start, Month_start, Year_start, Day_end, Month_end, Year_end, Day_learn, Hour_start, Min_start, Hour_end, Min_end, Room);
			x.push_back(a);
		}
		fin.close();
	}

	
}

void WriteFiletxtCourse(vector<COURSE> y, string semester, string path)
{
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
			if (y[i].get_Day_start().size() < 2)
			{
				fout <<"0"<< y[i].get_Day_start() << "/";
			}
			else
			{
				fout << y[i].get_Day_start() << "/";
			}
			if (y[i].get_Month_start().size() < 2)
			{
				fout << "0" << y[i].get_Month_start() << "/";
			}
			else
			{
				fout << y[i].get_Month_start() << "/";
			}
			fout << y[i].get_Year_start() << ";";
			
			if (y[i].get_Day_end().size() < 2)
			{
				fout << "0" << y[i].get_Day_end() << "/";
			}
			else
			{
				fout << y[i].get_Day_end() << "/";
			}
			if (y[i].get_Month_end().size() < 2)
			{
				fout << "0" << y[i].get_Month_end() << "/";
			}
			else
			{
				fout << y[i].get_Month_end() << "/";
			}
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

//Write file and Load file from each of member of Id_Course
void LoadFiletxtListOfCourse(vector<CheckAttend_Point>& x, string semester, string idc, string path)
{
	x.clear();
	ifstream fin;
	fin.open("File list of course//" + semester +"//" +idc + "-" + path + ".txt");
	if (!fin.is_open())
	{
		cout << "Not open file list of course";
		return;
	}
	else
	{
		while (!fin.eof())
		{
			string Id;string LastName;string FirstName;vector<string> attend;string mid;string finals;string Rank;
			attend.clear();
			getline(fin, Id, ';');
			getline(fin, LastName, ';');
			getline(fin, FirstName, ';');
			for (int i = 0; i < 11; i++)
			{
				string y;
				getline(fin, y, ';');
				attend.push_back(y);
			}
			getline(fin,mid, ';');
			getline(fin, finals, ';');
			getline(fin, Rank, '\n');
			CheckAttend_Point a(Id, LastName, FirstName, attend, mid, finals, Rank);
			x.push_back(a);
		}
		cout << "Have loaded\n";
		fin.close();
	}
}

void WriteFiletxtListOfCourse(vector<CheckAttend_Point> x, string semester, string idc, string path)
{
	ofstream fout;
	fout.open("File list of course//" + semester + "//" + idc + "-" + path + ".txt");
	if (!fout.is_open())
	{
		cout << "Not open file list of course to write";
		return;
	}
	else
	{
		for (int i = 0; i < x.size(); i++)
		{
			fout << x[i].get_id() << ";";
			fout<< x[i].get_lastname() << ";";
			fout<< x[i].get_firstname() << ";";
			for (int j = 0; j < x[i].get_sizeattend(); j++)
			{
				fout << x[i].get_posattend(j) << ";";
			}
			fout << x[i].get_mid() << ";";
			fout << x[i].get_finals() << ";";
			fout << x[i].get_Rank();
			if (i < x.size() - 1)
			{
				fout << "\n";
			}
		}
		cout << "Write file list course oke";
		fout.close();
	}
}

//Write file and Load file from Lecture
void LoadFiletxtLecture(vector<COURSE>& x, string semester, string path)
{
	x.clear();
	ifstream fin;
	fin.open("Academy of Lecture//" + semester + "//" +path + ".txt");
	if (!fin.is_open())
	{
		cout << "Not open to read semester";
		return;
	}
	else
	{
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
			COURSE a(No, Id_Course, Name_Course, CLASS_, Lecture, Day_start, Month_start, Year_start, Day_end, Month_end, Year_end, Day_learn, Hour_start, Min_start, Hour_end, Min_end, Room);
			x.push_back(a);
		}
		fin.close();
	}
}

void WriteFiletxtLecture(vector<COURSE> y, string semester, string path)
{
	ofstream fout;
	fout.open("Academy of Lecture//" + semester + "//" + path + ".txt");
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