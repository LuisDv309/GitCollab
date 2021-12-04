//Admin Login page
//
//  Created by Israel Black

#include <iostream>

using namespace std;

//Prototype Functions
void title();
void makeLine();
bool logInDisplay();
bool loginTrue();

//global Variables
string adminUsernameInput;
string adminPasswordInput;
bool login();

bool login()
{
	title();
	makeLine();
	return (logInDisplay());

}

//adds title of page
void title()
{
	cout << "Admin Login" << endl;
}

//allows user to log in with admin username and password. Times out if username or password incorrect
bool logInDisplay()
{
	int counter = 2;
	makeLine();

	while (counter >= 0)
	{
		cout << "\nAdmin Username: ";
		cin >> adminUsernameInput;
		cout << "\nAdmin Password: ";
		cin >> adminPasswordInput;

		if ((adminUsernameInput == "IBlack" || adminUsernameInput == "LPerez") && adminPasswordInput == "Admincs103")
		{
			return true;
		}
		else
		{
			if (counter != 0)
			{
				cout << "\nIncorrect Username or Password. " << endl;
				cout << counter << " attempts left.";

			}
			counter--;
		}

	}
	cout << "Exceeded 3 attempts. Please close and try again in 5 seconds";
	return false;

}



