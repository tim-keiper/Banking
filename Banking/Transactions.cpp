#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>
#include "Transactions.h"

using namespace std;

string GetTimeStamp() {
    time_t now = time(nullptr);
    struct tm timeInfo;
    char buf[80];
    localtime_s(&timeInfo, &now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &timeInfo);
    return string(buf);
}

double Deposit(double balance, vector<string>& depositHistory) {
    double amount;
    cout << "Enter deposit amount: $";
    cin >> amount;

    if (amount > 0) {
        balance += amount;
        string entry = "$" + to_string(amount) + " on " + GetTimeStamp();
        depositHistory.push_back(entry);
        cout << "Deposited: " << entry << endl;
    }
    else {
        cout << "Invalid deposit amount. Must be positive." << endl;
    }
    return balance;
}

double Withdrawal(double balance, vector<string>& withdrawalHistory) {
    double amount;
    cout << "Enter withdrawal amount: $";
    cin >> amount;

    if (amount > 0 && amount <= balance) {
        balance -= amount;
        string entry = "$" + to_string(amount) + " on " + GetTimeStamp();
        withdrawalHistory.push_back(entry);
        cout << "Withdrawn: " << entry << endl;
    }
    else if (amount > balance) {
        cout << "Insufficient balance. Your balance is only $" << balance << endl;
    }
    else {
        cout << "Invalid withdrawal amount. Must be positive." << endl;
    }
    return balance;
}

double LoadHistory(vector<string>& deposits, vector<string>& withdrawals) {
    ifstream inFile("transactions.txt");
    string line;
    double totalDeposits = 0.0;
    double totalWithdrawals = 0.0;

    while (getline(inFile, line)) {
        if (line.find("Deposit:") == 0) {
            string record = line.substr(8);
            deposits.push_back(record);

            // Parse deposit amount
            size_t pos = record.find(" on ");
            if (pos != string::npos) {
                string amountStr = record.substr(1, pos - 1); // skip $
                totalDeposits += stod(amountStr);
            }
        }
        else if (line.find("Withdrawal:") == 0) {
            string record = line.substr(11);
            withdrawals.push_back(record);

            // Parse withdrawal amount
            size_t pos = record.find(" on ");
            if (pos != string::npos) {
                string amountStr = record.substr(1, pos - 1); // skip $
                totalWithdrawals += stod(amountStr);
            }
        }
    }

    inFile.close();
    return 500.00 + totalDeposits - totalWithdrawals;  // Base balance + net transactions
}

void SaveHistory(const vector<string>& deposits, const vector<string>& withdrawals) {
    ofstream outFile("transactions.txt");
    for (const string& d : deposits) {
        outFile << "Deposit:" << d << endl;
    }
    for (const string& w : withdrawals) {
        outFile << "Withdrawal:" << w << endl;
    }
    outFile.close();
}

void DisplayHistory(const vector<string>& history, const string& type) {
    cout << "\n" << type << " History:\n";
    if (history.empty()) {
        cout << "No " << type << "s recorded.\n";
    }
    else {
        for (const string& entry : history) {
            cout << type << ": " << entry << endl;
        }
    }
}

void DisplayAllHistory(const vector<string>& deposits, const vector<string>& withdrawals) {
    cout << "\nAll Transaction History:\n";
    DisplayHistory(deposits, "Deposit");
    DisplayHistory(withdrawals, "Withdrawal");
}
