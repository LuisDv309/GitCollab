#include <iostream>
#include "menuUpdater.h"
#include "orderScreen.h"
#include "screenChange.h"
using namespace std;

	//Prototype functions
	void display();
	void options();
	void adminLanding();

	//global variables
	char response;

	void adminLanding()
	{
		display();
		options();
	}

	void display()
	{
		cout << "\nAdmin menu\n";
		makeLine();
		cout << "\nPlease select from the following options:"
			"\n1.Update Menu"
			"\n2.Weekly sales report\n";
		makeLine();
	}

	void options() {
		cout << "\nWhich option would you like? ";
		cin >> response;

		switch (response)
		{
		case '1':
			clearScreen();
			updater();
			break;

		case '2':
			//OrderScreen();
			break;
		default:
			cout << "\nPlease enter 1-2 for the corresponding option";
			break;
		}
		makeLine();
	}


