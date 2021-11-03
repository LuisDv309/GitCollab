//Admin Login page
//Work to be done: link to admin screen if username/password is true

#include <iostream>

using namespace std;

//Prototype Functions
void title();
void lineHoriz();
bool logInDisplay();
bool loginTrue();

//global Variables
string adminUsernameInput;
string adminPasswordInput;

int main()
{
	title();
	lineHoriz();
	loginTrue();
	
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
	lineHoriz();

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

//if login is successful, will allow user to access main admin landing page (in progress)
bool loginTrue()
{
	bool logInStatus = logInDisplay();
	if (logInStatus)
	{
		char response;
		lineHoriz();
		cout << "\nPick from the following options: \n1.Update menu \n2.Daily Order Report \n3.Weekly sales report \n4.Weekly pending payment report \n5.Weekly complaints \n";
		cin >> response;
		switch (response)
		{
		case '1':

			break;

		default:
			break;
		}

	}
	else
	{
		return 3;
	}
}

//creates horizontal lines for borders
void lineHoriz()
{
	for (int i = 0; i < 45; i++)
	{
		cout << "-";
	}
}


