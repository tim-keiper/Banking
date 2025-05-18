#pragma once
#include <vector>
#include <string>

double Deposit(double balance, std::vector<std::string>& depositHistory);
double Withdrawal(double balance, std::vector<std::string>& withdrawalHistory);

// Now returns the calculated starting balance
double LoadHistory(std::vector<std::string>& deposits, std::vector<std::string>& withdrawals);

void SaveHistory(const std::vector<std::string>& deposits, const std::vector<std::string>& withdrawals);
void DisplayHistory(const std::vector<std::string>& history, const std::string& type);
void DisplayAllHistory(const std::vector<std::string>& deposits, const std::vector<std::string>& withdrawals);
