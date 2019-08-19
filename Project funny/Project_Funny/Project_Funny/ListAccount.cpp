#include "ListAccount.h"

void ListAccount::CheckLogin(string username,string password)
{
	string path;
	LoadFileLogin(acc, path);
	int choose = -1;
	while (choose!=0)
	{
		cin.ignore();	cout << "\nUsername:";	getline(cin, username);
		cin.ignore();	cout << "\nPassWord:";	getline(cin, password);
		for (int i = 0; i < acc.size(); i++)
		{
			if (acc[i].get_id() == username)
			{
				string pass = acc[i].get_day() + acc[i].get_month() + acc[i].get_year();
				if (pass == password)
				{
					cout << "\nLogin access!";
					choose = 0;
					return;
				}
				else
				{
					cout << "\nPassword or Login not correct!!";
					cout << "\n1.Continue----0.Exit";
					cout << "\nYour choose:";	cin >> choose;
					if (choose == 0)
					{
						return;
					}
				}
			}
		}

	}
	
}

ListAccount::ListAccount()
{
}


ListAccount::~ListAccount()
{
}
