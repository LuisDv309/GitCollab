//Admin screen
#include <iostream>

using namespace std;

//Prototype functions
void makeLine();
void display();
void options();

//global variables
char response;

int main()
{
	display();
	options();
}

void display()
{
	cout << "Admin menu\n";
	makeLine();
	cout << "\nPlease select from the following options: \n1.Update Menu \n2.Daily Orders \n3.Weekly complaint report \n4.Weekly Pending Payments \n5.Weekly sales report\n";
	makeLine();
}

void makeLine() {
	for (int i = 0; i < 45; i++)
	{
		cout << "-";
	}
}

void options(){
	cout << "\nWhich option would you like? ";
	cin >> response;
	switch (response)
	{
	case '1':

		break;

	case '2':

		break;

	case '3':

		break;

	case '4':

		break;

	case '5':

		break;
	default:
		cout << "\nPlease enter 1-5 for the corresponding option";
		break;
	}
	makeLine;
}
	
	
