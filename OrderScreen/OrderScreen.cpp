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
        cout << "Your order number is being generated, please continue.";
        cout << "\nEnter the today's date (dd/mm/yyyy): ";
        getline(cin, m.Date);
        cout << "\nEnter Item Number: ";
        getline(cin, m.ItemNum);
        cout << "\nEnter Quantity: ";
        cin >> m.ItemQuant;
        parker.push_back(m);
        cout << "\nEnter your Child's Name (First Last):  ";
        getline(cin, m.ChildName);
        cout << "\nEnter your Child's Room Number (e.g 12): ";
        getline(cin, m.ChildRoomNum);
       
        cout << "\nDo you Wish to Make Another Order? (y/n) ";
        cin >> Answer;

    }
    return (parker);
}

void OutputOrder(vector<Order>& order)
{
    cout << "\nFrom OutputMarker Function";
    cout << "\n***************************";
    int i;
    for (i = 0; i < order.size(); i++)
    {
        cout << "\nYour Order Number is " << order[i].OrderNum;
        cout << "\nThe Date of your order is: " << order[i].Date;
        cout << "\nThe item is: " << order[i].ItemNum; //also display item name from menu.csv, to bi imlemented
        cout << "\nThe Quantity of this item is: " << order[i].ItemQuant;
        cout << "\nYour Child is: " << order[i].ChildName;
        cout << "\nYour Child's Name is" << order[i].ChildName;
        cout << "\nThe Price is: ";//Pulls from menu.csv
    }
}

void WriteToFile(vector<Order>& order)
{
    cout << "\nWriting to file ";
    cout << "\n***************************";
    int i;
    fstream myFile("OrderFile.csv", ios::app);
    for (i = 0; i < order.size(); i++)
    {
        myFile << order[i].OrderNum << "," << order[i].Date << "," << order[i].ItemNum;
    }

}