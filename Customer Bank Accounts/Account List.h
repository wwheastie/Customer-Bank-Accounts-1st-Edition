#ifndef AccountList_H
#define AccountList_H

#include "Account Node.h"
#include <iostream>
#include <fstream>
#include <iomanip>

class AccountList
{

friend class ManageAccounts;

public:
	//Functions
	//Constructors & Deconstructors
	AccountList();

private:
	//Functions
	//Add & Remove Node Functions
	void add_account(Account *);
	void remove_account(Account *);

	//Search Function
	Account * search_item(string, int);
	bool search_list(Account *[50], string, int &, int);
	Account * return_search(Account *[50], int);

	//Sort Function
	void sort_list(Account *);

	//Save Function
	void save_list();

	//Print Function
	void print_all();
	void recursive_print(Account *, int);

	//Character Conversion & Insertion Functions
	void convert_spaces(string &, int);

	//Variables
	int size;
	Account *current, *trail, *head;
};

#endif