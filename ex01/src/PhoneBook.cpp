/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:27:17 by pvong             #+#    #+#             */
/*   Updated: 2023/10/25 15:45:57 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctype.h>

PhoneBook::PhoneBook(void) : _numContacts(0), _oldestIndex(0) {

    std::cout << BOLDGREEN << "Constructor called " << RESET << __func__ << std::endl;
}

void    PhoneBook::handleCtrlD(void) {
    
    if (std::cin.eof()) {
        std::cout << "End of input. Exiting phonebook." << std::endl;
        exit(0);
    }
}

void PhoneBook::addContact(std::string firstName, std::string lastName,
                           std::string nickname, std::string phoneNumber, std::string darkestSecret) {

    if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty()) {
        std::cout << "Contact details cannot be empty. Please provide valid information." << std::endl;
        return;
    }
    
    if (this->_numContacts < MAX_CONTACT) {
        this->_contacts[this->_numContacts] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
        this->_numContacts++;
        std::cout << BLACK << MSG_SEP << RESET << std::endl;
        std::cout << "Contact added successfully!" << std::endl;
    } else {
        this->_contacts[this->_oldestIndex] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
        this->_oldestIndex = (this->_oldestIndex + 1) % MAX_CONTACT;
        std::cout << "PhoneBook is full. Replaced the oldest contact." << std::endl;
    }
}

void    PhoneBook::displayContacts(void) {
    
    if (this->_numContacts == 0) {
        std::cout << BLACK << MSG_SEP << RESET << std::endl;
        std::cout << "Phonebook is empty." << std::endl;
    } else {
        std::cout << BLACK << MSG_SEP << RESET << std::endl;
        std::cout << std::right << std::setw(10) << "Index" << " | " << std::setw(10) \
        << "First Name" << " | " << std::setw(10) << "Last Name" << " | " \
        << std::setw(10) << "Nickname" << std::endl;
        for (int i = 0; i < this->_numContacts; i++) {
            std::cout << std::right << std::setw(10) << i + 1 << " | ";
            this->_contacts[i].display();
        }
    }
}

void PhoneBook::searchContact(void) {
    std::cout << BLACK << MSG_SEP << RESET << std::endl;
    std::cout << "All Contacts:" << std::endl;
    displayContacts();
    std::cout << BLACK << MSG_SEP << RESET << std::endl;

    int indexToDisplay;
    std::cout << "Enter the index of the contact you want to display (0 to cancel): ";
    std::cin >> indexToDisplay;

    handleCtrlD();
    std::cout << BLACK << MSG_SEP << RESET << std::endl;
    if (indexToDisplay > 0 && indexToDisplay <= this->_numContacts) {
        int contactIndex = indexToDisplay - 1;
        std::cout << "Contact details:" << std::endl;
        std::cout << BLACK << MSG_SEP << RESET << std::endl;
        Contact contact = this->_contacts[contactIndex];
        std::cout << "First name: " << contact.getFirstName() << std::endl;
        std::cout << "Last name: " << contact.getLastName() << std::endl;
        std::cout << "Nickname: " << contact.getNickname() << std::endl;
        std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
        std::cout << BLACK << MSG_SEP << RESET << std::endl;
    } else if (indexToDisplay == 0) {
        std::cout << "Canceled searching." << std::endl;
    } else {
        std::cout << "Invalid index." << std::endl;
    }
}

int    PhoneBook::isNotValidNumber(std::string phoneNumber) {
    if (phoneNumber[0] && phoneNumber[0] == '+') {
        if (phoneNumber.length() < 12) {
            return (1);
        }
    } else if (phoneNumber.length() != 10) {
        return (1);
    }
    for (int i = 0; phoneNumber[i]; i++) {
        if (i == 0 && phoneNumber[i] == '+')
            i++;
        if (phoneNumber[i] && !isdigit(phoneNumber[i])) {
            return (1);
        }
    }
    return (0);
}

PhoneBook::~PhoneBook(void) {

    std::cout << BOLDRED << "Destructor called " << RESET << __func__ << std::endl;
}
