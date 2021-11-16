//
//  main.cpp
//  Testproject
//
//  Created by Luis Perez on 17/10/21

#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;
//structure//

struct Parents {     //Structure to hold Parents registration data//
    string FullName;
    string DOB;      //Date of Birth//
    double ContactNumber;
    string ChildFullName;
    int ChildRoomNum;
    long int VisaCardNum;
    string VisaCardExpireDate;
    string UserName;
    string Password;

};
vector<Parents>InputParentsRegis(vector<Parents>& inparents); //Declaration of Vector and structure with pointer//

void Exit() {
    exit(0);
}
void Line(int n);
//Functions to read from Files//
vector<Parents>ReadFromParentsFile();
vector<Parents>ReadFromLoginParentsFile();
//Function to Show Menu//
void IntroMenu();
vector<Parents>LoginParents(vector<Parents>& LoginInfo);

void FoodMenu();
int main() {

    IntroMenu();

    
}

//Functions //
vector<Parents>InputParentsRegis(vector<Parents>& inparents) {

    Parents p;
    char answer = 'y';
    fstream  MyFile("ParentsFile.csv", ios::app);// Adding to existing file
    while (tolower(answer) == 'y') {

        cin.ignore();
        Line(45);
        cout << "\tRegister For The School Lunch Order System " << endl;
        Line(45);
        cout << "\tPlease Enter your Full Name :" << endl;
        getline(cin, p.FullName);

        cout << "\tDate Of Birth :" << endl;
        getline(cin, p.DOB);

        cout << "\tPhone Number :" << endl;
        cin >> p.ContactNumber;
        cin.ignore();
        cout << "\tPlease Enter Your Child Full Name :" << endl;
        getline(cin, p.ChildFullName);
        cout << "\tYour Child ClassRoom Number :" << endl;
        cin >> p.ChildRoomNum;
        cout << "\tEnter Your Credit Card Number :" << endl;
        cin >> p.VisaCardNum;
        cin.ignore();
        cout << "\tExpire Date: " << endl;
        getline(cin, p.VisaCardExpireDate);
        cout << "\tEnter the Username :" << endl;
        getline(cin, p.UserName);
        cout << "\tEnter Your Password :" << endl;
        getline(cin, p.Password);
        
        if (p.Password.size() >= 8) {
            int PasswordIndex, DigitFlag = 0, LowerFlag = 0, UpperFlag = 0, SpecialCharacterFlag = 0;
            for (PasswordIndex = 0; PasswordIndex < p.Password.size(); PasswordIndex++) {
                if (isdigit(p.Password[PasswordIndex])) {
                    DigitFlag = 1;
                }


            }
            if (DigitFlag == 0)
                cout << "\tNumber is Missing" << endl;

            //Checking if the Password contains a lower case//
            for (PasswordIndex = 0; PasswordIndex < p.Password.size(); PasswordIndex++) {
                if (islower(p.Password[PasswordIndex])) {
                    LowerFlag = 1;
                }
            }
            if (LowerFlag == 0)
                cout << "\tLower Case is Missing" << endl;


            for (PasswordIndex = 0; PasswordIndex < p.Password.size(); PasswordIndex++) {
                if (isupper(p.Password[PasswordIndex])) {
                    UpperFlag = 1;
                }
            }
            if (UpperFlag == 0)
                cout << "\tUpper Case is Missing" << endl;
            //Checking if the password has a special Character//

            for (PasswordIndex = 0; PasswordIndex < p.Password.size(); PasswordIndex++) {
                if (!(isupper(p.Password[PasswordIndex])) && !(islower(p.Password[PasswordIndex])) && !(isdigit(p.Password[PasswordIndex]))) {
                    SpecialCharacterFlag = 1;
                }
            }
            if (SpecialCharacterFlag == 0)
                cout << "\tSpecial Character is Missing" << endl;

            if ((DigitFlag == 1) && (LowerFlag == 1) && (UpperFlag == 1) && (SpecialCharacterFlag == 1)) {
                cout << "\tCongratulation You have been Registered" << endl;
                
                
            }
            else {
                cout << "The password must contain alteast a number, a special character, a lower case and an upper case. It is an invalid password " << endl;

            }
        }
        else {
            cout << "Password must contain 8 or more character" << endl;
        
        }
        
        MyFile << p.FullName << "," << p.DOB << "," << p.ContactNumber << p.ChildFullName << "," << p.ChildRoomNum << "," << p.VisaCardNum << "," << p.VisaCardExpireDate << p.UserName << "," << p.Password << "," << endl;
        
        MyFile.close();
            
        cout << "\tWould you like to Login y/n" << endl;
        cin >> answer;
        if (tolower(answer) == 'y'){
            
            vector<Parents>LoginInfo;
            LoginParents(LoginInfo);
        }
       
        
    }

    vector<Parents> InfoFromParentsFile = ReadFromParentsFile();

    return (InfoFromParentsFile);
}


void Line(int n) {

    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << "*";
    }

    cout << endl;
}

vector<Parents>ReadFromParentsFile() {

   // cout << "FromReadFrom File Function" << endl;
    Line(66);
    fstream MyFile("ParentsFile.csv", ios::in);
    vector <Parents>TempParents;
    Parents p;
    string line;
    while (getline(MyFile, line)) {
        cout << line << endl;
        istringstream linestream(line);
        string RegisteredParent;
        getline(linestream, RegisteredParent, ',');
        p.FullName = RegisteredParent;

        getline(linestream, RegisteredParent, ',');
        p.DOB = RegisteredParent;

        getline(linestream, RegisteredParent, ',');

        stringstream ss(RegisteredParent);
        ss >> p.ContactNumber;
        
        getline(linestream, RegisteredParent, ',');
        p.UserName = RegisteredParent;
        
        getline(linestream, RegisteredParent, ',');
        p.UserName = RegisteredParent;
        
        
        TempParents.push_back(p);
    }
    MyFile.close();
    return(TempParents);

}
void IntroMenu() {
    Line(40);
    cout << "         Lunch Ordering System  " << endl;
    Line(40);

    cout << "         Available Options Are: " << endl;
    cout << "         Parent Registration(1)" << endl;
    cout << "         Parent Login       (2)" << endl;
    cout << "         Weeekly Menu       (3)" << endl;
    cout << "         Admin Login        (4)" << endl;
    cout << "         Exit               (5)" << endl;
    Line(40);
    Line(40);
    cout << endl << endl;
    int Option;
    //Input Options//
    cin >> Option;
    //Calling the functions on the bases of the above options//
    if (Option == 1) {
        vector<Parents>InfoParentsFromFile;
        InputParentsRegis(InfoParentsFromFile);
    }
    else if (Option == 2) {
        vector<Parents>LoginInfo;
        LoginParents(LoginInfo);
        

    }
    else if (Option == 3) {

    }
    else if (Option == 4) {

    }
    else if (Option == 5) {
        exit(0);

    }
    else {
        cout << "\tInvalid Option Please Try Again" << endl << endl;
        IntroMenu();
    }
}
vector<Parents>LoginParents(vector<Parents>& LoginInfo) {

    Parents p;
    
    char answer = 'y';
    fstream MyFlie1("ParentsLogin.csv", ios::app); //adding to existing file//
    while (tolower(answer) == 'y') {
        cin.ignore();
        Line(40);
        cout << "     Parent Login  " << endl;
        Line(40);
        cout << "Enter the Username :" << endl;
        getline(cin, p.UserName);
        cout << "Enter Your Password :" << endl;
        getline(cin, p.Password);
        if (p.Password == )
    }
        vector<Parents> InfoLoginParents = ReadFromLoginParentsFile();
    
        return (InfoLoginParents);
        
    }
        

vector<Parents>ReadFromLoginParentsFile(){

     cout << "ReadFromLogin File Function" << endl;
    Line(66);
    fstream MyFile2("ParentsLogin.csv", ios::in);
    vector <Parents>TempLoginParents;
    Parents p;
    string line;
    while (getline(MyFile2, line)) {
        cout << line << endl;
        istringstream linestream(line);
        string LoggedParent;
        getline(linestream, LoggedParent, ',');
        p.UserName = LoggedParent;

        getline(linestream, LoggedParent, ',');
        p.Password = LoggedParent;

        TempLoginParents.push_back(p);
    }
    MyFile2.close();

    return(TempLoginParents);

}

