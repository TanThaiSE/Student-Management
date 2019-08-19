#pragma once
#include"Student.h"
#include"Read_Write_File.h"
#include"ListAccount.h"
class Class
{
private:
	vector<Student> lst;
public:
	void InputList();
	void OutputList(vector<Student>&);
	void Importcsv();
	void Edit();
	void Remove();
	void Change_st_to_class();
	void ViewList();
	void Menu_Class();
	Class();
	~Class();
};

