#include "Account List.h"
using namespace std;

//Constructors & Deconstructors
AccountList::AccountList()
{
	head = NULL;
	current = NULL;
	trail = NULL;
}

//Add & Delete Node Functions
void AccountList::add_account(Account *newAccount)
{
	//Case 1 - List is empty
	if (head == NULL)
	{
		//newAccount->next = head;
		head = newAccount;
	}
	else
	{
		current = head;
		

		//Traverse list to locate where to place new node
		while (current != NULL)
		{
			if (newAccount->lastName < current->lastName)
			{
				break;
			}
			else
			{
				trail = current;
				current = current->next;
			}
		}

		//Case 2 - Insert at head (list not empty)
		if (current == head)
		{
			newAccount->next = head;
			head = newAccount;
		}
		//Case 3 - Insert after head (list not empty)
		else
		{
			newAccount->next = current;
			trail->next = newAccount;
		}
	}

	//Increase size of list
	size++;
}
void AccountList::remove_account(Account *newAccount)
{
	//Local variables
	Account *newAccountBefore = NULL;
	Account *newAccountAfter = NULL;
	current = head;
	trail = current;

	//If account to delete is at head
	if (newAccount == head)
	{
		head = newAccount->next;
		delete newAccount;
		size--;
	}
	//If account to delete is after head
	else
	{
		//Find the addresses before and after newAccount
		while (current != NULL)
		{
			trail = current;
			current = current->next;

			if (current == newAccount)
			{
				newAccountBefore = trail;
				newAccountAfter = newAccount->next;
				break;
			}
		}

		//Delete account from the body
		newAccountBefore->next = newAccountAfter;
		delete newAccount;
		size--;
	}

	//Save list
	save_list();
}

//Search Function
Account * AccountList::search_item(string searchItem, int option)
{
	//Local variables
	int count = 0;
	bool found = false;
	Account *itemList[50];

	//Search for item
	found = search_list(itemList, searchItem, count, option);

	//Locate and return 
	if (found)
	{
		return return_search(itemList, count);
	}
	else
	{
		return NULL;
	}
}
bool AccountList::search_list(Account *accountArray[50], string searchItem, int &count, int option)
{
	//Local variables
	bool found = false;
	current = head;

	//Search for first name
	if (option == 1)
	{
		while (current != NULL)
		{
			if (current->firstName == searchItem)
			{
				accountArray[count] = current;
				count++;
				found = true;
			}

			current = current->next;
		}
	}
	//Search for last name
	else if (option == 2)
	{
		while (current != NULL)
		{
			if (current->lastName == searchItem)
			{
				accountArray[count] = current;
				count++;
				found = true;
			}

			current = current->next;
		}
	}
	//Search for social security number
	else if (option == 3)
	{
		while (current != NULL)
		{
			if (current->SSN == searchItem)
			{
				accountArray[count] = current;
				count++;
				found = true;
			}

			current = current->next;
		}
	}

	return found;
}
Account * AccountList::return_search(Account *accountArray[50], int count)
{
	//Local variables
	int option;
	string message;

	if (count == 1 && count != size)
	{
		return accountArray[count - 1];
	}
	else if (count == size)
	{
		//Put linked list into an array
		Account ** tempAccountArray = new Account *[size];
		current = head;
		int i = 0;
		while (current != NULL)
		{
			tempAccountArray[i] = current;
			i++;
			current = current->next;
		}

		//Choose which user to display
		do
		{
			try
			{
				cout << "Below are all accounts. Please select." << endl;
				cout << "--------------------------------------" << endl;
				print_all();
				cout << "------------------------------" << endl;
				cout << "Select option (1 - " << count << "): ";
				cin >> option;
				cout << endl;

				if (option < 1 || option > count)
				{
					throw message = "Please enter a valid option!";
				}

			}
			catch (string exception){ cout << exception << endl << endl; cout << "Press any key to continue. . . " << endl << endl; system("pause>null"); }

		} while (option < 1 || option > count);

		return tempAccountArray[option - 1];
	}
	else
	{
		do
		{
			try
			{
				cout << "Multiple search items have been found. Please choose." << endl;
				cout << "-----------------------------------------------------" << endl;
				for (int i = 0; i < count; i++)
				{
					cout << i + 1 << ". " << accountArray[i]->lastName << ", " << accountArray[i]->firstName << endl;
				}
				cout << "------------------------------" << endl;
				cout << "Select option (1 - " << count << "): ";
				cin >> option;
				cout << endl;

				if (option < 1 || option > count)
				{
					throw message = "Please enter a valid option!";
				}

			}
			catch (string exception){ cout << exception << endl << endl; cout << "Press any key to continue. . . " << endl << endl; system("pause>null"); }

		} while (option < 1 || option > count);

		return accountArray[option - 1];
	}
}

//Sort Function
void AccountList::sort_list(Account *newAccount)
{
	//Local variables
	Account *newAccountBefore = NULL;
	Account *newAccountAfter = NULL;
	current = head;
	trail = current;

	//If updated account was the head
	if (newAccount == head)
	{
		while (current != NULL)
		{
			trail = current;
			current = current->next;

			if (current != NULL)
			{
				if (newAccount->lastName <= current->lastName)
				{
					if (newAccount->next == current)
					{
						break;
					}
					else
					{
						head = newAccount->next;
						newAccount->next = current;
						trail->next = newAccount;
						break;
					}
				}
				else if (current->next == NULL)
				{
					head = newAccount->next;
					newAccount->next = current->next;
					current->next = newAccount;
					break;
				}
			}
		}
	}
	//If updated account was in the body
	else
	{
		//Find the addresses before and after newAccount
		while (current != NULL)
		{
			trail = current;
			current = current->next;

			if (current == newAccount)
			{
				newAccountBefore = trail;
				newAccountAfter = newAccount->next;
				break;
			}
		}

		//Reset current, trail, and counter
		current = head;
		trail = current;

		//If updated account is to be inserted at the head
		if (newAccount->lastName <= head->lastName)
		{
			newAccount->next = head;
			head = newAccount;
			newAccountBefore->next = newAccountAfter;
		}
		//If updated account is to be inserted after head
		else
		{
			//Check to see if account needs to be sorted
			if (newAccount->lastName <= newAccountAfter->lastName)
			{
				return;
			}

			while (current != NULL)
			{
				trail = current;
				current = current->next;

				if (current != NULL)
				{
					if (newAccount->lastName <= current->lastName)
					{
						newAccount->next = current;
						trail->next = newAccount;
						newAccountBefore->next = newAccountAfter;
						break;
					}
					else if (current->next == NULL)
					{
						if (newAccount->lastName >= current->lastName)
						{
							newAccount->next = current->next;
							current->next = newAccount;
							newAccountBefore->next = newAccountAfter;
							break;
						}
					}
				}
			}
		}
	}
}

//Save Function
void AccountList::save_list()//Needs to be updated
{
	//Set variables
	ofstream accountsFile("Customer Accounts.txt");
	ofstream numberOfAccountsFile("Number.txt");
	current = head;

	//Save account information to text file
	while (current != NULL)
	{
		convert_spaces(current->firstName, 1);
		convert_spaces(current->lastName, 1);
		convert_spaces(current->streetAddress, 1);
		convert_spaces(current->city, 1);

		accountsFile << current->firstName << " " << current->lastName << " " << current->dateOfBirth << " " << current->SSN << " " << current->streetAddress << " " << current->city << " " << current->state << " " << current->zip << " " << current->telephone << " " << current->intialBalance << endl;
		current = current->next;
	}

	//Save number of accounts file
	numberOfAccountsFile << size;

	//Close open files
	accountsFile.close();
	numberOfAccountsFile.close();

	//Notify account has been saved
	cout << "Account information has been saved!" << endl << endl;

	//Convert '*' back to spaces
	current = head;

	while (current != NULL)
	{
		convert_spaces(current->firstName, 2);
		convert_spaces(current->lastName, 2);
		convert_spaces(current->streetAddress, 2);
		convert_spaces(current->city, 2);

		current = current->next;
	}
}

//Print Function
void AccountList::print_all()
{
	recursive_print(head, 1);
}
void AccountList::recursive_print(Account *currentPointer, int number)
{
	//Call recursive function to print all accounts
	if (currentPointer != NULL)
	{
		cout << number << ". " << currentPointer->lastName << ", " << currentPointer->firstName << endl;
		recursive_print(currentPointer->next, number + 1);
	}
}

//Character Conversion & Insertion Functions
void AccountList::convert_spaces(string &newString, int option)
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