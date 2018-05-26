#include "Main Menu.h"
using namespace std;

//Run Program
void MainMenu::run()
{
	//Local variables
	int menuOption;
	char runAgain;
	string message;

	//Display menu
	do
	{
		do
		{
			try
			{
				cout << "                    **************************" << endl;
				cout << "                    | Customer Bank Accounts |" << endl;
				cout << "                    **************************" << endl;
				cout << " This program is designed to create, update, and delete customer accounts " << endl << endl;
				cout << "From the menu below, please choose which function you would like to perform" << endl;
				cout << "___________________________________________________________________________" << endl << endl;
				cout << "1. Create Account" << endl;
				cout << "2. Update Account" << endl;
				cout << "3. Delete Account" << endl;
				cout << "4. Search Account" << endl;
				cout << "5. Exit Program" << endl;
				cout << "------------------------" << endl;
				cout << "Select option (1-5): ";
				cin >> menuOption;
				cout << endl;

				if (menuOption < 1 || menuOption > 5)
				{
					throw message = "Please enter a valid option! (Select 1 - 5)";
				}

			}
			catch (string exception){ cout << exception << endl << endl; cout << "Press any key to continue. . . " << endl << endl; system("pause>null"); }

		} while (menuOption < 1 || menuOption > 5);

		//Process menuOption
		if (menuOption == 1)
		{
			manageAccounts.create_account();
		}
		else if (menuOption == 2)
		{
			manageAccounts.update_account();
		}
		else if (menuOption == 3)
		{
			manageAccounts.delete_account();
		}
		else if (menuOption == 4)
		{
			manageAccounts.print_search();
		}
		else if (menuOption == 5)
		{
			return;
		}

		//Ask user to run program again
		do
		{
			try
			{
				cout << "Would you like to run this program again?" << endl;
				cout << "('Y' for Yes or 'N' for No): ";
				cin >> runAgain;
				cout << endl << endl;

				if (toupper(runAgain) == !'Y' || toupper(runAgain) == !'N')
				{
					throw message = "Please enter a valid option! (Y or N)";
				}
			}
			catch (string exception){ cout << exception << endl << endl; cout << "Press any key to continue. . . " << endl << endl; system("pause>null"); }

		} while (toupper(runAgain) == !'Y' || toupper(runAgain) == !'N');

		//Clear screen
		system("cls");

	} while (toupper(runAgain) == 'Y');
}