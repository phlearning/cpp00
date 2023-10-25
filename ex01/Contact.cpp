/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:31:49 by pvong             #+#    #+#             */
/*   Updated: 2023/10/25 15:45:17 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>

Contact::Contact(void) {
    std::cout << BOLDGREEN << "Constructor called " << RESET << __func__ << std::endl;
    return ;
}

Contact::Contact(std::string s1, std::string s2, std::string s3, std::string s4,
                 std::string s5) : _firstName(s1), _lastName(s2),
                                   _nickname(s3), _phoneNumber(s4), _darkestSecret(s5) {

    std::cout << BOLDGREEN << "Constructor called " << RESET << __func__ << std::endl;
    std::cout << "=================================================" << std::endl;
    std::cout << "this->_firstName: " << this->_firstName << std::endl;
    std::cout << "this->_lastName: " << this->_lastName << std::endl;
    std::cout << "this->_nickname: " << this->_nickname << std::endl;
    std::cout << "this->_phoneNumber: " << this->_phoneNumber << std::endl;
    std::cout << "this->_darkestSecret: " << this->_darkestSecret << std::endl;
    std::cout << "=================================================" << std::endl;
    return ;
}

void    Contact::display(void) {
    std::string truncatedFirstName = this->_firstName.substr(0, 10);
    std::string truncatedLastName = this->_lastName.substr(0, 10);
    std::string truncatedNickname = this->_nickname.substr(0, 10);

    if (this->_firstName.length() > 10) {
        truncatedFirstName[9] = '.';
    }
    if (this->_lastName.length() > 10) {
        truncatedLastName[9] = '.';
    }
    if (this->_nickname.length() > 10) {
        truncatedNickname[9] = '.';
    }
    std::cout << std::right << std::setw(10) << truncatedFirstName << " | " << std::setw(10) << truncatedLastName << " | " << std::setw(10) << truncatedNickname << std::endl;
}

std::string Contact::getFirstName() const {
    return _firstName;
}

std::string Contact::getLastName() const {
    return _lastName;
}

std::string Contact::getNickname() const {
    return _nickname;
}

std::string Contact::getPhoneNumber() const {
    return _phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return _darkestSecret;
}

Contact::~Contact() {
    std::cout << BOLDRED << "Destructor called " << RESET << __func__ << std::endl;
}

// int main() {
//     Contact Sample("hello", "hello", "hello", "hello", "hello");
//     Contact Test;

//     std::cout << BOLDWHITE << "Constructor Test: " << Test.getFirstName() << RESET << std::endl;
//     return 0;
// }