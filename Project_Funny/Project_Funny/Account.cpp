#include "Account.h"

Account::Account(string a, string b, string c, string d)
{
	id = a;
	day = b;
	month = c;
	year = d;
}

Account::Account()
{
	id = "0";
	day = "0";
	month = "0";
	year = "0";
}


Account::~Account()
{
}
