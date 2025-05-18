#include <iostream>
#include "Transactions.h"

using namespace std;

double Deposit(double balance) {
    double depositAmount;
    // Deposit option
    cout << "Enter the deposit amount: $";
    cin >> depositAmount;

    // Validate the deposit amount
    if (depositAmount > 0) {
        balance += depositAmount;  // Update balance
        cout << "Deposit amount: $" << depositAmount << endl;
        cout << "New balance: $" << balance << endl;
    }
    else {
        cout << "Invalid deposit amount. It must be positive." << endl;
    }
    return balance;
}

double Withdrawal(double balance) {
    double withdrawalAmount;
    // Withdrawal option
    cout << "Enter the withdrawal amount: $";
    cin >> withdrawalAmount;

    // Validate the withdrawal amount
    if (withdrawalAmount > 0 && withdrawalAmount <= balance) {
        balance -= withdrawalAmount;  // Update balance
        cout << "Withdrawal amount: $" << withdrawalAmount << endl;
        cout << "New balance: $" << balance << endl;
    }
    else if (withdrawalAmount > balance) {
        cout << "Insufficient balance. Your balance is only $" << balance << endl;
    }
    else {
        cout << "Invalid withdrawal amount. It must be positive." << endl;
    }
    return balance;
}
