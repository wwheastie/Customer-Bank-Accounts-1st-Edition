#include "Manage Accounts.h"
using namespace std;

//Constructors & Deconstructors
ManageAccounts::ManageAccounts()
{
	//Set class variables
	accountList = new AccountList;

	//Load customer information from text file
	load_list();
}

//Create, Delete, Modify Functions
void ManageAccounts::create_account()
{
	//Create new account on the heap
	Account *newAccount = new Account;

	//Run 'set' functions
	set_firstName(newAccount);
	set_lastName(newAccount);
	set_dateOfBirth(newAccount);
	set_SSN(newAccount);
	set_streetAddress(newAccount);
	set_city(newAccount);
	set_state(newAccount);
	set_zip(newAccount);
	set_telephone(newAccount);
	set_intialBalance(newAccount);

	//Verify, add to linked list, and save account information
	verify_save(newAccount, 1);
}
void ManageAccounts::delete_account()
{
	//Local variables
	Account *newAccount = NULL;
	char option;
	string message;

	//Run search function
	newAccount = search_list();

	//If account found
	if (newAccount != NULL)
	{
		//Verify and confirmation account deletion
		do
		{
			try
			{
				cout << "***************************************" << endl;
				cout << "*   Please verify the account below   *" << endl;
				cout << "***************************************" << endl << endl;
				print_account(newAccount);
				cout << "----------------------------------------------------------------------" << endl;
				cout << "Are you sure you want to delete this account? (Y for Yes / N for No): ";
				cin >> option;
				cout << endl;

				if (toupper(option) != 'Y' && toupper(option) != 'N')
				{
					throw message = "Please enter a valid option! (Y or N)";
				}

			}
			catch (string exception){ cout << exception << endl << endl; cout << "Press any key to continue. . . " << endl << endl; system("pause>null"); }

		} while (toupper(option) != 'Y' && toupper(option) != 'N');
		if (toupper(option) == 'Y')
		{
			//Delete account
			accountList->remove_account(newAccount);
		}
		else
		{
			return;
		}
	}
	//If account was not found
	else
	{
		return;
	}
}
void ManageAccounts::update_account()
{
	//Local variables
	Account *newAccount = NULL;

	//Search function
	newAccount = search_list();

	//If account found
	if (newAccount != NULL)
	{
		modify_account(newAccount, 2);
	}
	else
	{
		cout << "Account was not found!" << endl << endl;
		cout << "Press any key to continue. . . " << endl << endl;
		system("pause>null");
	}
}

//Search List Function
Account * ManageAccounts::search_list()
{
	//Local variables
	int option;
	string newString, message;

	//Choose search option
	do
	{
		try
		{
			cout << "Please choose search parameter" << endl;
			cout << "------------------------------" << endl;
			cout << "1. First Name" << endl;
			cout << "2. Last Name" << endl;
			cout << "3. Social Security Number" << endl;
			cout << "4. Display All Accounts" << endl;
			cout << "-------------------------" << endl;
			cout << "Select option (1-4): ";
			cin >> option;
			cout << endl;

			if (option < 1 || option > 4)
			{
				throw message = "Please enter a valid option! (Select 1-4)";
			}

		}
		catch (string exception){ cout << exception << endl << endl; cout << "Press any key to continue. . . " << endl << endl; system("pause>null"); }

	} while (option < 1 || option > 4);

	//Search by first name
	if (option == 1)
	{
		//Get first name
		do
		{
			fflush(stdin);
			cout << "Pleas enter first name: ";
			getline(cin, newString);
			cout << endl;

		} while (invalid_string(newString, 0, 1));

		//Change to correct captial case
		captial_case(newString);
	}
	else if (option == 2)
	{
		//Get last name
		do
		{
			fflush(stdin);
			cout << "Pleas enter last name: ";
			getline(cin, newString);
			cout << endl;

		} while (invalid_string(newString, 0, 1));

		//Change to correct captial case
		captial_case(newString);
	}
	else if (option == 3)
	{
		//Get social security number
		do
		{
			fflush(stdin);
			cout << "Please enter social security number: ";
			getline(cin, newString);
			cout << endl;

		} while (invalid_string(newString, 9, 2));

		//Insert '-'
		insert_character(newString, 2);
	}
	else if (option == 4)
	{
		//Local variables
		Account *tempAccountArray[50];

		//If only one account
		if (accountList->size == 1)
		{
			return accountList->head;
		}
		//If multiple accounts
		else
		{
			//Print all accounts and select one
			return accountList->return_search(tempAccountArray, accountList->size);
		}
	}

	return accountList->search_item(newString, option);
}

//Print Functions
void ManageAccounts::print_search()
{
	//Local variables
	Account *newAccount = NULL;

	//Run search
	newAccount = search_list();

	//If account is found
	if (newAccount != NULL)
	{
		cout << "***************************************" << endl;
		cout << "*   Please verify the account below   *" << endl;
		cout << "***************************************" << endl << endl;
		print_account(newAccount);
		cout << "----------------------------------------------------" << endl;
		cout << "Press any key to continue. . . " << endl << endl; 
		system("pause>null");		
	}
	else
	{
		cout << "Account was not found!" << endl << endl;
		cout << "Press any key to continue. . . " << endl << endl;
		system("pause>null");
	}
}
void ManageAccounts::print_account(Account *newAccount)
{
	//Display account information
	cout << "First Name       : " << newAccount->firstName << endl;
	cout << "Last Name        : " << newAccount->lastName << endl;
	cout << "Date of Birth    : " << newAccount->dateOfBirth << endl;
	cout << "Social Security  : " << newAccount->SSN << endl;
	cout << "Address          : " << newAccount->streetAddress << endl;
	cout << "City, State, Zip : " << newAccount->city << ", " << newAccount->state << " " << newAccount->zip << endl;
	cout << "Telephone Number : " << newAccount->telephone << endl;
	cout << "Account Balance  : $" << fixed << setprecision(2) << newAccount->intialBalance << endl << endl;
}
void ManageAccounts::print_all()
{
	accountList->print_all();
}

//Set 'Account' Functions
void ManageAccounts::set_firstName(Account *newAccount)
{
	//Get first name
	do
	{
		fflush(stdin);
		cout << "Pleas enter first name: ";
		getline(cin, newAccount->firstName);
		cout << endl;

	} while (invalid_string(newAccount->firstName, 0, 1));

	//Change to correct captial case
	captial_case(newAccount->firstName);
}
void ManageAccounts::set_lastName(Account *newAccount)
{
	//Get last name
	do
	{
		fflush(stdin);
		cout << "Pleas enter last name: ";
		getline(cin, newAccount->lastName);
		cout << endl;

	} while (invalid_string(newAccount->lastName, 0, 1));

	//Change to correct captial case
	captial_case(newAccount->lastName);
}
void ManageAccounts::set_dateOfBirth(Account *newAccount)
{
	//Local variables
	int tempDay = 0, tempMonth = 0, tempYear = 0;

	//Get month of birth
	do
	{
		fflush(stdin);
		cout << "Enter MONTH of birth: ";
		cin >> tempMonth;
		cout << endl;

	} while (dateOfBirth_validation(tempDay, tempMonth, tempYear, 1));

	//Get day of birth
	do
	{
		fflush(stdin);
		cout << "Enter DAY of birth: ";
		cin >> tempDay;
		cout << endl;

	} while (dateOfBirth_validation(tempDay, tempMonth, tempYear, 2));

	//Get year of birth
	do
	{
		fflush(stdin);
		cout << "Enter YEAR of birth: ";
		cin >> tempYear;
		cout << endl;

	} while (dateOfBirth_validation(tempDay, tempMonth, tempYear, 3));

	//Set newAccount->dateOfBirth
	newAccount->dateOfBirth = dateOfBirth_string(tempDay, tempMonth, tempYear);
}
void ManageAccounts::set_SSN(Account *newAccount)
{
	//Get social security number
	do
	{
		fflush(stdin);
		cout << "Please enter social security number: ";
		getline(cin, newAccount->SSN);
		cout << endl;

	} while (invalid_string(newAccount->SSN, 9, 2));

	//Insert '-'
	insert_character(newAccount->SSN, 2);
}
void ManageAccounts::set_streetAddress(Account *newAccount)
{
	//Get street address
	do
	{
		fflush(stdin);
		cout << "Please enter street address: ";
		getline(cin, newAccount->streetAddress);
		cout << endl;

	} while (invalid_string(newAccount->streetAddress, 0, 4));

	//Change to correct captial case
	captial_case(newAccount->streetAddress);
}
void ManageAccounts::set_city(Account *newAccount)
{
	//Get city
	do
	{
		fflush(stdin);
		cout << "Please enter city: ";
		getline(cin, newAccount->city);
		cout << endl;

	} while (invalid_string(newAccount->city, 0, 1));

	//Change to correct captial case
	captial_case(newAccount->city);
}
void ManageAccounts::set_state(Account *newAccount)
{
	//Get state
	do
	{
		fflush(stdin);
		cout << "Please enter state (2 characters): ";
		getline(cin, newAccount->state);
		cout << endl;
	} while (invalid_string(newAccount->state, 2, 5));

	//Change to correct captial case
	for (int i = 0; i < newAccount->state.length(); i++)
	{
		newAccount->state.at(i) = toupper(newAccount->state.at(i));
	}
}
void ManageAccounts::set_zip(Account *newAccount)
{
	//Get zip
	do
	{
		fflush(stdin);
		cout << "Please enter zip: ";
		getline(cin, newAccount->zip);
		cout << endl;

	} while (invalid_string(newAccount->zip, 5, 2));
}
void ManageAccounts::set_telephone(Account *newAccount)
{
	//Get telephone
	do
	{
		fflush(stdin);
		cout << "Please enter telephone: ";
		getline(cin, newAccount->telephone);
		cout << endl;

	} while (invalid_string(newAccount->telephone, 10, 2));

	//Insert '-'
	insert_character(newAccount->telephone, 3);
}
void ManageAccounts::set_intialBalance(Account *newAccount)
{
	do
	{
		fflush(stdin);
		cout << "Please enter balance: ";
		cin >> newAccount->intialBalance;
		cout << endl;

	} while (newAccount->intialBalance < 0);
}

//Modify Account Function
void ManageAccounts::modify_account(Account *newAccount, int saveOption)
{
	//Local variables
	int option = 0;
	string message;
	Account tempAccount;

	//Choose what information to modify
	do
	{
		try
		{
			cout << "Please choose the information you would like to modify" << endl;
			cout << "------------------------------------------------------" << endl;
			cout << "1.  First Name" << endl;
			cout << "2.  Last Name" << endl;
			cout << "3.  Date of Birth" << endl;
			cout << "4.  Social Security" << endl;
			cout << "5.  Street Address" << endl;
			cout << "6.  City" << endl;
			cout << "7.  State" << endl;
			cout << "8.  Zip" << endl;
			cout << "9.  Telephone Number" << endl;
			cout << "10. Balance" << endl;
			cout << "11. Exit menu" << endl;
			cout << "---------------------" << endl;
			cout << "Select option (1-10): ";
			cin >> option;
			cout << endl;

			if (option < 1 || option > 11)
			{
				throw message = "Please enter a valid option! (Select 1-10)";
			}

		}
		catch (string exception){ cout << exception << endl << endl; cout << "Press any key to continue. . . " << endl << endl; system("pause>null"); }

	} while (option < 1 || option > 11);

	//Run "set" functions for selected option
	if (option == 1)
	{
		set_firstName(newAccount);
	}
	else if (option == 2)
	{
		set_lastName(newAccount);
	}
	else if (option == 3)
	{
		set_dateOfBirth(newAccount);
	}
	else if (option == 4)
	{
		set_SSN(newAccount);
	}
	else if (option == 5)
	{
		set_streetAddress(newAccount);
	}
	else if (option == 6)
	{
		set_city(newAccount);
	}
	else if (option == 7)
	{
		set_state(newAccount);
	}
	else if (option == 8)
	{
		set_zip(newAccount);
	}
	else if (option == 9)
	{
		set_telephone(newAccount);
	}
	else if (option == 10)
	{
		set_intialBalance(newAccount);
	}
	else if (option == 11)
	{
		return;
	}

	//Verify account information
	verify_save(newAccount, saveOption);
}

//Collaborative Functions
void ManageAccounts::verify_save(Account * newAccount, int saveOption)
{
	//Local variables
	char option;
	string message;

	//Display account information for verification
	do
	{
		try
		{
			cout << "***************************************" << endl;
			cout << "*   Please verify the account below   *" << endl;
			cout << "***************************************" << endl << endl;
			print_account(newAccount);
			cout << "----------------------------------------------------" << endl;
			cout << "Is the information correct? (Y for Yes / N for No): ";
			cin >> option;
			cout << endl;

			if (toupper(option) != 'Y' && toupper(option) != 'N')
			{
				throw message = "Please enter a valid option! (Y or N)";
			}

		}
		catch (string exception){ cout << exception << endl << endl; cout << "Press any key to continue. . . " << endl << endl; system("pause>null"); }

	} while (toupper(option) != 'Y' && toupper(option) != 'N');

	//Modify information
	if (toupper(option) == 'N')
	{
		modify_account(newAccount, saveOption);
	}
	//Add to linked list and save information
	else if (saveOption == 1)
	{
		//Add new account to linked list
		accountList->add_account(newAccount);

		//Save information function
		accountList->save_list();
	}
	else if (saveOption == 2)
	{
		//Sort linked list
		accountList->sort_list(newAccount);

		//Save information function
		accountList->save_list();
	}
}

//Save & Load List Function
void ManageAccounts::save_list()
{
	//Run 'accountList->save_list' function
	accountList->save_list();
}
void ManageAccounts::load_list()
{
	//Local variables
	ifstream accountsFile("Customer Accounts.txt");
	ifstream numberOfAccountsFile("Number.txt");
	int size;

	//Get the number of accounts
	numberOfAccountsFile >> size;

	//Process loading text file information
	if (!is_empty(accountsFile))
	{
		for (int i = 0; i < size; i++)
		{
			//Create pointer variable 'newAccount' on the heap
			Account *newAccount = new Account;

			//Load information from text file
			accountsFile >> newAccount->firstName >> newAccount->lastName >> newAccount->dateOfBirth >> newAccount->SSN >> newAccount->streetAddress >> newAccount->city >> newAccount->state >> newAccount->zip >> newAccount->telephone >> newAccount->intialBalance;

			//Convert '*' to spaces
			convert_spaces(newAccount->firstName, 2);
			convert_spaces(newAccount->lastName, 2);
			convert_spaces(newAccount->streetAddress, 2);
			convert_spaces(newAccount->city, 2);

			//Add loaded information to linked list
			accountList->add_account(newAccount);
		}
	}

	//Close open files
	accountsFile.close();
	numberOfAccountsFile.close();
}

//Character Conversion & Insertion Functions
void ManageAccounts::convert_spaces(string &newString, int option)
{
	//Change spaces to '*'
	if (option == 1)
	{
		for (int i = 0; i < newString.length(); i++)
		{
			if (newString.at(i) == ' ')
			{
				newString.at(i) = '*';
			}
		}
	}
	//Change '*' to spaces
	else if (option == 2)
	{
		for (int i = 0; i < newString.length(); i++)
		{
			if (newString.at(i) == '*')
			{
				newString.at(i) = ' ';
			}
		}
	}
}
void ManageAccounts::insert_character(string &newString, int option)
{
	//Insert '-' for date of birth
	if (option == 1)
	{
		for (int i = 0; i < newString.length(); i++)
		{
			if (i == 2 || i == 5)
			{
				newString.insert(i, 1, '-');
			}
		}
	}
	//Insert '-' for social security number
	if (option == 2)
	{
		for (int i = 0; i < newString.length(); i++)
		{
			if (i == 3 || i == 6)
			{
				newString.insert(i, 1, '-');
			}
		}
	}
	//Insert '-' for telephone number
	if (option == 3)
	{
		for (int i = 0; i < newString.length(); i++)
		{
			if (i == 3 || i == 7)
			{
				newString.insert(i, 1, '-');
			}
		}
	}
}
void ManageAccounts::captial_case(string &newString)
{
	//Change first letter to captial letter
	for (int i = 0; i < newString.length(); i++)
	{
		if (i != 0 && newString.at(i) != ' ')
		{
			newString.at(i) = tolower(newString.at(i));
		}
		else
		{
			if (newString.at(i) != ' ')
			{
				newString.at(i) = toupper(newString.at(i));
			}
			else
			{
				newString.at(i + 1) = toupper(newString.at(i + 1));
				i++;
			}
		}
	}

	//Change 'Mc' to approriate captial case
	for (int i = 0; i < newString.length(); i++)
	{
		if (newString.at(i) == 'M')
		{
			if (newString.at(i + 1) == 'c')
			{
				newString.at(i + 2) = toupper(newString.at(i + 2));
			}
		}
	}

	//Change roman numerals to captial letters
	for (int i = 0; i < newString.length(); i++)
	{
		if (newString.at(i) == ' ')
		{
			if (newString.at(i + 1) == 'i' || newString.at(i + 1) == 'I' || newString.at(i + 1) == 'v' || newString.at(i + 1) == 'V')
			{
				string tempString = newString + ' ';

				if (tempString.at(i + 2) == 'i' || tempString.at(i + 2) == 'I' || tempString.at(i + 2) == 'v' || tempString.at(i + 2) == 'V')
				{
					while (i < newString.length() - 1)
					{
						i++;
						newString.at(i) = toupper(newString.at(i));
					}
				}
			}
		}
	}
}
string ManageAccounts::dateOfBirth_string(int day, int month, int year)
{
	//Local variables
	string dayString, monthString, yearString, dateString;
	stringstream s1, s2, s3;

	//Change month into string
	s1 << month;
	monthString = s1.str();
	if (monthString.length() < 2)
	{
		monthString = "0" + monthString;
	}

	//Change day into string
	s2 << day;
	dayString = s2.str();
	if (dayString.length() < 2)
	{
		dayString = "0" + dayString;
	}

	//Change year into string
	s3 << year;
	yearString = s3.str();

	//Combine month, day, year string and add hypens
	dateString = monthString + dayString + yearString;
	insert_character(dateString, 1);

	return dateString;
}

//Validation Functions
bool ManageAccounts::is_empty(ifstream &file)
{
	return file.peek() == ifstream::traits_type::eof();
}
bool ManageAccounts::is_digits(string newString)
{
	return std::all_of(newString.begin(), newString.end(), ::isdigit);
}
bool ManageAccounts::invalid_string(string newString, int length, int option)
{
	//Set local variables
	bool invalid = false;
	string message = " ";
	
	try
	{
		//Alphabet Only
		if (option == 1)
		{
			if (newString.length() > 25)
			{
				throw message = "Number of characters limit has been exceeded! (No longer than 25)";
			}

			for (int i = 0; i < newString.length(); i++)
			{
				if (newString.at(i) != ' ' && !isalpha(newString.at(i)))
				{
					throw message = "Please enter alphanumeric characters only!";
				}
			}
		}
		//Numbers Only
		else if (option == 2)
		{
			if (newString.length() != length)
			{
				throw message = "Please enter the correct information! (Check the length)";
			}
			else if (!is_digits(newString))
			{
				throw message = "Please enter numbers only!";
			}
		}
		//Integer Only
		else if (option == 3)
		{
			//This option will remain NULL
		}
		//Alphabet and Numbers (no characters)
		else if (option == 4)
		{
			if (newString.length() > 25)
			{
				throw message = "Number of characters limit has been exceeded! (No longer than 25)";
			}

			for (int i = 0; i < newString.length(); i++)
			{
				if (newString.at(i) != ' ' && !isalpha(newString.at(i)) && !isdigit(newString.at(i)))
				{
					throw message = "Please enter alphanumeric characters or digits only!";
				}
			}
		}
		//Alphabet Only (specific length)
		else if (option == 5)
		{
			if (newString.length() != length)
			{
				throw message = "Number of characters limit has been exceeded!";
			}
		}
	}
	catch (string exception){ invalid = true; cout << exception << endl << endl; cout << "Press any key to continue. . . " << endl << endl; system("pause>null"); }

	return invalid;
}
bool ManageAccounts::dateOfBirth_validation(int day, int month, int year, int option)
{
	//Local variables
	bool invalid = false;
	string message = " ";

	try
	{
		//Validate month of birth
		if (option == 1)
		{
			if (month <= 0 || month > 12)
			{
				throw message = "Please enter a valid month! (Choose 01 - 12)";
			}
		}
		//Validate day of birth
		if (option == 2)
		{
			if ((day > 31 || day < 1) || (month == 2 && day > 28))
			{
				throw message = "Please enter a valid day!";
			}
			else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30))
			{
				throw message = "Please enter a valid day!";
			}
		}
		//Validate year of birth
		if (option == 3)
		{
			if (year > 1997 || year < 1915)
			{
				throw message = "Please enter a valid year! (Choose 1915 - 1997)";
			}
		}
	}
	catch (string exception){ invalid = true; cout << exception << endl << endl; cout << "Press any key to continue. . . " << endl << endl; system("pause>null"); }

	return invalid;
}