#include <iostream>
#include <iomanip>
#include <string>
#include "Transactions.h"

using namespace std;

int main() {
    string name;
    double balance = 500.00;  // Initial balance

    // Ask for user's name
    cout << "What is your name?" << endl;
    getline(cin, name);  // Get the name of the user

    // Display welcome message and initial balance
    cout << name << " Welcome to your account" << endl;
    cout << fixed << setprecision(2);  // Set precision for monetary values
    cout << "Balance: $" << balance << endl;

    // Display menu options
    cout << "1) Make a Deposit" << endl;
    cout << "2) Make a Withdrawal" << endl;

    int choice;
    cout << "Please select an option (1 or 2): ";
    cin >> choice;

    // Process user choice
    if (choice == 1) {
        Deposit(balance);
    }
    else if (choice == 2) {
        Withdrawal(balance);
    }
    else {
        cout << "Invalid choice. Please select either 1 or 2." << endl;
    }

    return 0;
}