#pragma once
#include"Course.h"
#include"Read_Write_File.h"
class ListCourse
{
private:
	vector<COURSE> lstc;
public:
	void importcsv();
	void CreateCandImportClass();
	void AddCourse();
	void EditCourse();
	void RemoveCourse();
	void RemoveStOutCourse();
	void AddStIntoCourse();
	void ViewListCourse();
	void ViewListStOfCourse();
	void Menu_Course();
	ListCourse();
	~ListCourse();
};

