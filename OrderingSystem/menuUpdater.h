#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

//structure definition
struct MenuUpdater
{
    string ItemNo;
    string ItemName;
    string ItemDescript;
    float ItemPrice;

    //constructor
    MenuUpdater(string ino = "", string iname = "", string ides = "", float iprice = 0)
    {
        ItemNo = ino;
        ItemName = iname;
        ItemDescript = ides;
        ItemPrice = iprice;
    }
};




void updater()
{
    MenuUpdater mu[5], menuupdater;

    fstream appFile("menuupdater.csv", ios::app);
    int i;
    for (i = 0; i < 5; i++)
    {
        cin.ignore();

        cout << "\nEnter the item number: ";
        getline(cin, mu[i].ItemNo);

        cout << "\nEnter the item name: ";
        getline(cin, mu[i].ItemName);

        cout << "\nEnter the item description: ";
        getline(cin, mu[i].ItemDescript);

        cout << "\nEnter the item price: ";
        cin >> mu[i].ItemPrice;
    }//for loop

    appFile.close();

    ifstream inFile("menuupdater.csv", ios::in);

    string line;
    int linenum = 0;
    MenuUpdater mupdater[5];
    i = 0;
    while (getline(inFile, line)) {
        cout << line;
        istringstream linestream(line);
        string Item;
        getline(linestream, Item, ',');
        menuupdater.ItemNo = Item;

        getline(linestream, Item, ',');
        menuupdater.ItemName = Item;

        getline(linestream, Item, ',');
        menuupdater.ItemDescript = Item;

        getline(linestream, Item, ',');
        stringstream ss(Item);
        ss >> menuupdater.ItemPrice;

        mupdater[linenum] = menuupdater;
        linenum++;
    }//while loop

    int j;
    for (j = 0; j < 5; j++)
    {
        cout << "\nMenu item id: " << mupdater[j].ItemNo;
        cout << "\nMenu item name: " << mupdater[j].ItemName;
        cout << "\nMenu item description: " << mupdater[j].ItemDescript;
        cout << "\nMenu item price: " << mupdater[j].ItemPrice;
    }//for loop

    inFile.close();

}
