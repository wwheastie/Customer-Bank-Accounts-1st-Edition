#ifndef AccountNode_H
#define AccountNode_H

#include <string>
using namespace std;

class Account
{

friend class AccountList;
friend class ManageAccounts;

public:
	//Functions
	//Constructors & Deconstructors
	Account();

private:
	//Variables
	string firstName, lastName, streetAddress, city, state, zip, dateOfBirth, SSN, telephone;
	long double intialBalance;
	Account *next;
};

#endif