/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:27:05 by pvong             #+#    #+#             */
/*   Updated: 2023/10/25 17:14:44 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include "Color.hpp"
#include <iostream>

#define MSG_SEP "================================"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) _nbDeposits(0), _nbWithdrawals(0) {
    // std::cout << BOLDGREEN << "Constructor called " << RESET << __func__ << std::endl;
    makeDeposit(initial_deposit);
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

void    Account::makeDeposit(int deposit)
{
    this->_amount += deposit;
    _totalAmount += this->_amount;
    this->_nbDeposits += 1;
    _totalNbDeposits += this->_nbDeposits;
}



Account::~Account(void) {
    // std::cout << BOLDRED << "Destructor called " << RESET << __func__ << std::endl;
}

int main(void)
{
    Account Sample(100);
    Account Sample2(500);

    std::cout << BLACK << MSG_SEP << RESET << std::endl;
    std::cout << "getNbAccounts:\t\t" << Sample.getNbAccounts() << std::endl;
    std::cout << "getTotalAmount:\t\t" << Sample.getTotalAmount() << std::endl;
    std::cout << "getNbDeposits:\t\t" << Sample.getNbDeposits() << std::endl;
    std::cout << "getNbWithdrawals:\t" << Sample.getNbWithdrawals() << std::endl;
    std::cout << BLACK << MSG_SEP << RESET << std::endl;
    std::cout << BLACK << MSG_SEP << RESET << std::endl;
    std::cout << "2. getNbAccounts:\t" << Sample2.getNbAccounts() << std::endl;
    std::cout << "2. getTotalAmount:\t" << Sample2.getTotalAmount() << std::endl;
    std::cout << "2. getNbDeposits:\t" << Sample2.getNbDeposits() << std::endl;
    std::cout << "2. getNbWithdrawals:\t" << Sample2.getNbWithdrawals() << std::endl;
    std::cout << BLACK << MSG_SEP << RESET << std::endl;
    return (0);
}