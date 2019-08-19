#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<stdlib.h>
using namespace std;
#include"Read_Write_File.h"
class OnlyStudent
{
public:
	void CheckInAttend();
	void ViewAttend_Score();
	void ViewSchedule();
	void Menu_Student();
	OnlyStudent();
	~OnlyStudent();
};

