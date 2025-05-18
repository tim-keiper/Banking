#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "Transactions.h"

using namespace std;

int main() {
    string name;
    vector<string> depositHistory, withdrawalHistory;

    // Get user's name
    cout << "What is your name?" << endl;
    getline(cin, name);

    // Load transaction history from file and calculate starting balance
    double startingBalance = LoadHistory(depositHistory, withdrawalHistory);
    double balance = startingBalance;

    // Welcome and starting balance
    cout << "\n" << name << ", welcome to your account!" << endl;
    cout << fixed << setprecision(2);
    cout << "Starting Balance (from history): $" << balance << endl;

    int choice;
    do {
        // Display menu
        cout << "\nMenu Options:" << endl;
        cout << "1) Balance" << endl;
        cout << "2) Make a Deposit" << endl;
        cout << "3) Make a Withdrawal" << endl;
        cout << "4) Deposit History" << endl;
        cout << "5) Withdrawal History" << endl;
        cout << "6) All Deposits and Withdrawals" << endl;
        cout << "7) Exit" << endl;

        cout << "\nSelect an option (1-7): ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Current Balance: $" << balance << endl;
            break;
        case 2:
            balance = Deposit(balance, depositHistory);
            break;
        case 3:
            balance = Withdrawal(balance, withdrawalHistory);
            break;
        case 4:
            DisplayHistory(depositHistory, "Deposit");
            break;
        case 5:
            DisplayHistory(withdrawalHistory, "Withdrawal");
            break;
        case 6:
            DisplayAllHistory(depositHistory, withdrawalHistory);
            break;
        case 7:
            SaveHistory(depositHistory, withdrawalHistory);
            cout << "\nSession Summary:" << endl;
            cout << "Starting Balance: $" << startingBalance << endl;
            cout << "Final Balance: $" << balance << endl;
            cout << "Thank you for banking with us!\n";
            break;
        default:
            cout << "Invalid choice. Please select 1–7." << endl;
        }
    } while (choice != 7);

    return 0;
}
