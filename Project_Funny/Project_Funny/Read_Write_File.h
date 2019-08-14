#pragma once
#include"Class.h"
#include"ListAccount.h"
#include"Academy.h"
//Write file and Load file from Class
void ReadFilecsvTotxt(vector<Student>& x,vector<Account>&y,string path);
void WriteFile(vector<Student> x,string path);
void ReadFiletxt(vector<Student>& x,string path);

void WriteFileLogin(vector<Account> x,string path);
void LoadFileLogin(vector<Account>& x,string path);

//Write file and Load file from Course

//void ReadFilecsvtotxtCourse(vector<Course>& y,string path);
//void ReadFilecsvtotxtCourse(vector<Course>& y);
//void ReadFileCourse(vector<Course>x, string path);
/*
void ReadFiletxtCourse(vector<Course>& x, string path);
void WriteFiletxtCourse(vector<Course> x, string path);
*/