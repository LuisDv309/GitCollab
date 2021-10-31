
//Admin log in page
#include <iostream>
using namespace std;
//structures

//prototype functions
void display();
void displayLinesHoriz();
void displayUpdateMenu();
void diplayDailyOrders();
void displayWeeklySalesReport();
void displayWeeklyPendingPayments();
void displayUpdateMenu();


int main(){
    display();
}

//display output
void display() {
    cout << "                               Admin Page\n";
    displayLinesHoriz();
    displayUpdateMenu();
    diplayDailyOrders();
    displayWeeklySalesReport();
    displayWeeklyPendingPayments();
    displayUpdateMenu();


   
}
  
void displayUpdateMenu() {
    cout << "\n              | 1. Update Menu" << "                |"<<endl;
    displayLinesHoriz();
}

void diplayDailyOrders() {
    cout << "\n              | 2. Daily Orders" << "                |" << endl;
    displayLinesHoriz();
}

void displaySalesReport() {
    cout << "\n              | 3. Weekly sales report" << "                |" << endl;
    displayLinesHoriz();
}

void displayPendingPayments() {
    cout << "\n              | 4. Weekly Pending Payments" << "                |" << endl;
    displayLinesHoriz();
}

void displayComplaints() {
    cout << "\n              | 5. Weekly complaints" << "                |" << endl;
    displayLinesHoriz();
}

//builds horizontral lines for the display
void displayLinesHoriz() {
    cout << "              ";
    for (int i = 0; i < 33; i++ ) {
        cout << "_";
    }
}




