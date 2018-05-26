#ifndef ManageAccounts_H
#define ManageAccounts_H

#include "Account Node.h"
#include "Account List.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;

class ManageAccounts
{

friend class AccountList;

public:
	//Functions
	//Constructors & Deconstructors
	ManageAccounts();

	//Create, Delete, Update Functions
	void create_account();
	void delete_account();
	void update_account();

	//Search Function
	Account * search_list();

	//Print Functions
	void print_search();
	void print_account(Account *);
	void print_all();

private:
	//Functions
	//Set 'Account' Functions
	void set_firstName(Account *);
	void set_lastName(Account *);
	void set_dateOfBirth(Account *);
	void set_SSN(Account *);
	void set_streetAddress(Account *);
	void set_city(Account *);
	void set_state(Account *);
	void set_zip(Account *);
	void set_telephone(Account *);
	void set_intialBalance(Account *);

	//Modify Account Function
	void modify_account(Account *, int);

	//Collaborative Functions
	void verify_save(Account *, int);

	//Save & Load List Functions
	void save_list();
	void load_list();	

	//Character Conversion & Insertion Functions
	void convert_spaces(string &, int);
	void insert_character(string &, int);
	void captial_case(string &);
	string dateOfBirth_string(int, int, int);

	//Validation Functions
	bool is_empty(ifstream &);
	bool is_digits(string);
	bool invalid_string(string, int, int);
	bool dateOfBirth_validation(int, int, int, int);

	//Variables
	AccountList *accountList;
};

#endif