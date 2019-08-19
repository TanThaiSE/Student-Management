#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<stdlib.h>
using namespace std;
#include"Read_Write_File.h"
class Lecture
{
public:
	void ViewListCourse();
	void ViewListStInCourse();
	void EditAttend_Score();
	string Rank(double, double);
	void ViewAttend_Score();
	void Menu_Lecture();
	Lecture();
	~Lecture();
};

