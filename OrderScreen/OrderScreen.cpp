#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <time.h>

using namespace std;

//***********************
//Definition of structure
//***********************
struct Order //parent order
{
    string OrderNum;
    string Date;
    string ItemNum;
    int ItemQuant;
    string ChildName;
    string ChildRoomNum;
    float Price;

    //constructor
    Order(string on = "000", string d = "00/00/0000", string in ="1", int iq= 0, string cn="John Doe", string crn="00", float p =0.0)
    {
        OrderNum = on;
        Date = d;
        ItemNum = in;
        ItemQuant = iq;
        ChildName = cn;
        ChildName = crn;
        Price = p;
    }
};//POrder

//***********************
//Function prototypes
//***********************

int OrderNum();


int main()
{
    OrderNum();
}//main



//***********************
//Definition of functions
//***********************

//generates random order number
int OrderNum()
{
    srand((unsigned)time(0));
    int RandomNum;

    for (int i = 0; i < 1; i++)
    {
        RandomNum = (rand() % 999) + 100;
    }//for
    return 0;
}//OrderNum

vector <Order> InputPOrder(vector<Order>& parker)
{
    cout << "\nFrom InputMarker Function";
    cout << "\n***************************";
    Order m;
    char Answer = 'y';
    while (tolower(Answer) == 'y')
    {
        cout << "\nYour Order Number is: " << OrderNum;
        cout << "\nEnter the today's date (dd/mm/yyyy): ";
        getline(cin, m.Date);
        cout << "\nEnter Item Number: ";
        getline(cin,m.)

        
    }

}