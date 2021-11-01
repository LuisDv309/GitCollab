// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>


using namespace std;
struct Parents {     //Structure to hold Parents registration data//
    string FullName;
    string Gender;
    string DOB;      //Date of Birth//
    double ContactNumber;
    string ChildFullName;
    float ChildRoomNum;
    float VisaCardNum;
    string VisaCardExpireDate;
    string UserName;
    string Password;

};
vector<Parents>InputParentsRegis(vector<Parents>& inparents);
void RegisPassword(); //Function to register the password//
void Exit() {
    exit(0);
}

int main() {
    vector<Parents>inparents;
    InputParentsRegis(inparents);

}
vector<Parents>InputParentsRegis(vector<Parents>& inparents) {

    Parents p;
    char answer = 'y';
    while (tolower(answer) == 'y') {
        fstream MyFile("ParentsFile.csv", ios::in);

        cout << "Wellcome to Register to The School Lunch Order System" << endl;
        cout << "Please Enter your Full Name :" << endl;
        getline(cin, p.FullName);

        cout << "How do you Identify your Gender :" << endl;
        getline(cin, p.Gender);

        cout << "Date Of Birth :" << endl;
        getline(cin, p.DOB);

        cout << "Phone Number :" << endl;
        cin >> p.ContactNumber;
        cout << "Please Enter Your Child Full Name :" << endl;
        getline(cin, p.ChildFullName);
        cout << "Your Child ClassRoom Number :" << endl;
        cin >> p.ChildRoomNum;
        cout << "Enter Your Credit Card Number :" << endl;
        cin >> p.VisaCardNum;
        cout << "Expire Date: " << endl;

        getline(cin, p.VisaCardExpireDate);

        cout << "User Name :" << endl;
        cin >> p.UserName;
        RegisPassword();





        MyFile << p.FullName << "," << p.Gender << "," << p.DOB << "," << p.ContactNumber << p.ChildFullName << "," << p.ChildRoomNum << "," << p.VisaCardNum << "," << p.VisaCardExpireDate << "," << p.UserName << endl;

        MyFile.close();
        inparents.push_back(p);

    }
    cout << "Do You Wish to Submmit Your Registration Y / N" << endl;
    cin >> answer;

    return (inparents);
}

void RegisPassword() {
    int Choice;
    bool Cinfail;
    int Comfirmation;

    string UserName, Password, Password2;

    cout << "Enter Your Password :";
    cin >> Password;
    cout << "Please Reenter Your Password :";
    cin >> Password2;
    if (Password == Password2) {
        cin.clear();
        cin.ignore(10000, '\n');

        exit(1);
    }
    else; {
        cout << "Sorry Invalid Password" << endl;
        RegisPassword();
    }



}
