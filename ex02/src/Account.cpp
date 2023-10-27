/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:27:05 by pvong             #+#    #+#             */
/*   Updated: 2023/10/27 14:27:24 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include "Color.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit),  _nbDeposits(0), _nbWithdrawals(0) {
    _nbAccounts += 1;
    _displayTimestamp();
    std::cout << "index:" << CYAN << this->_accountIndex << RESET << ";" << "amount:" << CYAN << this->_amount << RESET << ";created" << std::endl; 
    _totalAmount += initial_deposit;
}

int Account::getNbAccounts(void) {
    return (_nbAccounts);
}

int Account::getTotalAmount(void) {
    return (_totalAmount);
}

int Account::getNbDeposits(void) {
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void) {
    return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << CYAN << Account::_nbAccounts << RESET << ";";
    std::cout << "total:" << CYAN << Account::_totalAmount << RESET << ";";
    std::cout << "deposits:" << CYAN << Account::_totalNbDeposits << RESET << ";";
    std::cout << "withdrawals:" << CYAN << Account::_totalNbWithdrawals << RESET << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << CYAN << this->_accountIndex << RESET << ";";
    std::cout << "p_amount:" << CYAN << this->_amount << RESET << ";";
    std::cout << "deposit:" << CYAN << deposit << RESET << ";";
    this->_amount += deposit;
    _totalAmount += deposit;
    std::cout << "amount:" << CYAN << this->_amount << RESET << ";";
    this->_nbDeposits += 1;
    _totalNbDeposits += 1;
    std::cout << "nb_deposits:" << CYAN << this->_nbDeposits << RESET << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << CYAN << this->_accountIndex << RESET << ";";
    std::cout << "p_amount:" << CYAN << this->_amount << RESET << ";";
    if (this->_amount - withdrawal < 0) {
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    } else {
        std::cout << "withdrawal:" << CYAN << withdrawal << RESET << ";";
        this->_amount -= withdrawal;
        this->_nbWithdrawals += 1;
        _totalNbWithdrawals += 1;
        _totalAmount -= withdrawal;
        std::cout << "amount:" << CYAN << this->_amount << RESET << ";";
        std::cout << "nb_withdrawals:" << CYAN << this->_nbWithdrawals << RESET << std::endl;
    }
    return (true);
}

int Account::checkAmount(void) const {
    return (this->_amount);
}

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "index:" << CYAN << this->_accountIndex << RESET << ";";
    std::cout << "amount:" << CYAN << this->_amount << RESET << ";";
    std::cout << "deposits:" << CYAN << this->_nbDeposits << RESET << ";";
    std::cout << "withdrawals:" << CYAN << this->_nbWithdrawals << RESET << std::endl;
}

void Account::_displayTimestamp(void) {
    std::tm tm; 
    std::time_t t = std::time(nullptr);
    tm = *std::localtime(&t);
    
    char timestamp[20];
    std::strftime(timestamp, sizeof(timestamp), "[%Y%m%d_%H%M%S]", &tm);
    
    std::cout << timestamp << " ";
}

Account::~Account(void) {
    _displayTimestamp();
    std::cout << "index:" << CYAN << this->_accountIndex << RESET << ";" << "amount:" << CYAN << this->_amount << RESET << ";closed" << std::endl; 
}

// int main(void)
// {
//     Account Sample(100); // first created account with 100$ 
//     Account Sample2(500); // second created account with 500$

//     Sample.makeDeposit(100); // first account make a deposit of 100
//     Sample.makeDeposit(300); // first account make a deposit of 300
//     Sample.makeWithdrawal(500); // first account withdraw 500 (possible)
//     Sample.makeWithdrawal(500); // first account withdraw 500 (not possible)
//     Sample.displayStatus(); // Display first account details
//     Sample2.displayStatus(); // Display second account details
//     Account::displayAccountsInfos(); // Display totals
//     return (0);
// }