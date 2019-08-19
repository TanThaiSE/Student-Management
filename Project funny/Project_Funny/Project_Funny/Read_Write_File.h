#pragma once
#include"Class.h"
#include"ListAccount.h"
#include"ListCourse.h"
#include"List_CheckAttend_Point.h"
#include"Lecture.h"
#include"OnlyStudent.h"
//Write file and Load file from Class
void ReadFilecsvTotxt(vector<Student>& x,vector<Account>&y,string path);
void WriteFile(vector<Student> x,string path);
void ReadFiletxt(vector<Student>& x,string path);

void WriteFileLogin(vector<Account> x,string path);
void LoadFileLogin(vector<Account>& x,string path);

//Write file and Load file from Course
void ReadFilecsvtotxtCourse(vector<COURSE>& y, string path);
void ReadFiletxtCourseAndLoadSt(vector<Student>& x, vector<COURSE>& y, string semester, string id_course, string path);

void LoadfiletxtCourse(vector<COURSE>& x, string semester, string path);
void WriteFiletxtCourse(vector<COURSE> y, string semester, string path);

//Write file and Load file from each of member of Id_Course
void LoadFiletxtListOfCourse(vector<CheckAttend_Point>& x, string semester, string idc, string path);
void WriteFiletxtListOfCourse(vector<CheckAttend_Point> x, string semester, string idc, string path);

//Write file and Load file from Lecture
void LoadFiletxtLecture(vector<COURSE>& x, string semester, string path);
void WriteFiletxtLecture(vector<COURSE> y, string semester, string path);