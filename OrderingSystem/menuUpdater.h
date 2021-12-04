//  Menu File Manager
//
//  Created by Israel Black

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "screenChange.h"

using namespace std;

//structure definition
struct Item
{
    int ItemNo;
    string ItemName;
    string ItemDescript;
    float ItemPrice;

    //constructor
    Item(int ino = 0, string iname = "", string ides = "", float iprice = 0)
    {
        ItemNo = ino;
        ItemName = iname;
        ItemDescript = ides;
        ItemPrice = iprice;
    }
};
void createMenu();
void readMenu(int itemNumber);
void updateMenu(int itemNumber);

// Initialise and reset menu
void createMenu()
{
    string itemArray[][6] = { {"1.","2.","3.","4.","5.","6."},
                              {"Bento Terryaki", "Salmon Maki Box", "Fruit Salad","Chicken and Cranberry roll", "Curry Laksa", "Bami Goreng"},
                                   {"Terryaki chicken on rice", "Salmon and avacado in rice and seaweed",
                                    "A basic fruit salad with fruits","Chicken and cranberry sauce in a roll", "Seafood in a malaysian style curry","Fried noodle"},
                                   {"$5.00","$5.00","$5.00","$5.00","$5.00","$5.00"}};

    //creating food menu file
    ofstream fout("itemmenu.csv", ios::out | ios::trunc);
    for (int j = 0; j < 6; j++) {
        for (int x = 0; x < 4; x++) {
            fout << itemArray[x][j] << ",";
        }
        fout << endl;
    }
}

// Reads off csv file to display specified item
void readMenu(int itemNumber)
{
    fstream fin;
    fin.open("itemmenu.csv", ios::in);
    int item2 = 0, count = 0;
    vector<string> row;
    string line, word, temp;

    while (!fin.eof()) {
        row.clear();
        getline(fin, line);
        stringstream s(line);
        while (s.good()) {
            getline(s, word, ',');
            row.push_back(word);
        }
        if (row.size() > 1) {
            item2 = stoi(row[0]);
            if (item2 == itemNumber) {
                count = 1;
                break;
            }
        }
    }

    if (item2 == itemNumber) {

        count = 1;
        cout << "Details of Item Number " << row[0] << " : \n";
        cout << "Item Name: " << row[1] << "\n";
        cout << "Item Description: " << row[2] << "\n";
        cout << "Item Price: " << row[3] << "\n";
        cout << "Press any key to go back to continue";
        cin.ignore();
        cin.get();
        clearScreen();
    }
    fin.close();
    if (count == 0) {
        cout << "\nNo record found";
        cout << "Press any key to go back to display menu";
        cin.ignore();
        cin.get();
        clearScreen();
        readMenu(itemNumber);
    }
}

// Update an entry in the manu csv file
void updateMenu(int itemNumber)
{
    int opt, i, item2;
    string newc;
    fstream fin, fout;

    fin.open("itemmenu.csv", ios::in);

    fout.open("itemmenunew.csv", ios::out);

    string line, word;
    vector<string> row;
    readMenu(itemNumber);
    makeLine();
    cout << "\nWhat would you want to modify?";
    cout << "\n1. Item Name"
            "\n2. Item Description"
            "\n3. Item Price"
            "\n4. Return to previous menu\n";
    makeLine();
    cout << "\n";
    cin >> opt;
   
    if (opt == 1) {
        i = 1;
        cout << "\nEnter new Item Name: ";
        cin.ignore();
        getline(cin, newc);
       
    }
    else if (opt == 2) {
        i = 2;
        cout << "\nEnter the new Item Description: ";
        cin.ignore();
        getline(cin, newc);
    }
    else if (opt == 3) {
        i = 3;

        cout << "\nEnter the new Item Price: ";
        cin.ignore();
        getline(cin, newc);
    }
    else if (opt == 4) {
        updateMenu(itemNumber);
    }
    else {
        cout << "\nInvalid Input";
        cout << "\nPress any key to continue:";
        cin.ignore();
        cin.get();
        clearScreen();
        updateMenu(itemNumber);
    }

    item2 = 0;
    int count = 0;

    while (!fin.eof()) {
        row.clear();
        getline(fin, line);
        stringstream s(line);
        while (s.good()) {
            getline(s, word, ',');
            row.push_back(word);
            cout << row[0] << " ";
        }
        
        if (row.size() > 1) {
            item2 = std::stoi(row[0]);
            if (item2 == itemNumber) {
                count = 1;
                row[i] = newc;
                for (int i = 0; i < 4; i++) {
                    fout << row[i] << ",";
                }
                fout << row[4];
                fout << "\n";
            }
            else {
                for (int i = 0; i < 4; i++) {
                    fout << row[i] << ",";
                }
                fout << row[4];
                fout << "\n";
            }

        }
    }

    fin.close();
    fout.close();

    remove("itemmenu.csv");
    int  value;
    value = rename("itemmenunew.csv", "itemmenu.csv");

    
    cout << "\nData modified successfully.";
    cout << "\nPress any key to continue: ";
    cin.ignore();
    cin.get();
    clearScreen();
    readMenu(itemNumber);
}