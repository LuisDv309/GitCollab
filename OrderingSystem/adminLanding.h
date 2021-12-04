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
			"\n1. Display Menu"
			"\n2. Update Menu"
			"\n3. Reset menu\n";
		makeLine();
	}

	void options() {
		int itemNo;
		cout << "\nWhich option would you like? ";
		cin >> response;

		switch (response)
		{
		case '1':
			clearScreen();
			cout << "Enter item number to display: ";
			cin >> itemNo;
			readMenu(itemNo);
			adminLanding();
			

		case '2':
			clearScreen();
			cout << "Enter item number to update: ";
			cin >> itemNo;
			updateMenu(itemNo);
			adminLanding();

		case '3':
			createMenu();
			adminLanding();
		default:
			cout << "\nPlease enter 1-2 for the corresponding option";
			break;
		}
		makeLine();
	}


