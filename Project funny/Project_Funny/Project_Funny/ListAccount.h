#pragma once
#include"Account.h"
#include"Read_Write_File.h"
class ListAccount
{
private:
	vector<Account> acc;
public:
	void CheckLogin(string username, string password);
	ListAccount();
	~ListAccount();
};

