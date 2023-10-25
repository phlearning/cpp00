/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:27:17 by pvong             #+#    #+#             */
/*   Updated: 2023/10/25 13:57:13 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>

#ifndef COLOR_HPP
    #define COLOR_HPP

    #define RESET "\033[0m"
    #define BLACK "\033[30m"              /* Black */
    #define RED "\033[31m"                /* Red */
    #define GREEN "\033[32m"              /* Green */
    #define YELLOW "\033[33m"             /* Yellow */
    #define BLUE "\033[34m"               /* Blue */
    #define MAGENTA "\033[35m"            /* Magenta */
    #define CYAN "\033[36m"               /* Cyan */
    #define WHITE "\033[37m"              /* White */
    #define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
    #define BOLDRED "\033[1m\033[31m"     /* Bold Red */
    #define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
    #define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
    #define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
    #define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
    #define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
    #define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

#endif

PhoneBook::PhoneBook(void) : _numContacts(0), _oldestIndex(0) {

    std::cout << BOLDGREEN << "Constructor called " << RESET << __func__ << std::endl;
    std::cout << "this->_numContacts: " << this->_numContacts << std::endl;
    std::cout << "this->_oldestIndex: " << this->_oldestIndex << std::endl;
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
        return;
    }
    
    if (this->_numContacts < PhoneBook::_maxContacts) {
        this->_contacts[this->_numContacts] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
        this->_numContacts++;
        std::cout << "Contact added successfully!" << std::endl;
    } else {
        this->_contacts[this->_oldestIndex] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
        this->_oldestIndex = (this->_oldestIndex + 1) % PhoneBook::_maxContacts;
        std::cout << "PhoneBook is full. Replaced the oldest contact." << std::endl;
    }
}

void    PhoneBook::displayContacts(void) {
    
    if (this->_numContacts == 0) {
        std::cout << "Phonebook is empty." << std::endl;
    } else {
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
    std::cout << "All Contacts:" << std::endl;
    displayContacts();

    int indexToDisplay;
    std::cout << "Enter the index of the contact you want to display (0 to cancel): ";
    std::cin >> indexToDisplay;

    handleCtrlD();

    if (indexToDisplay > 0 && indexToDisplay <= this->_numContacts) {
        int contactIndex = indexToDisplay - 1;
        std::cout << "Contact details:" << std::endl;
        Contact contact = this->_contacts[contactIndex];
        std::cout << "First name: " << contact.getFirstName() << std::endl;
        std::cout << "Last name: " << contact.getLastName() << std::endl;
        std::cout << "Nickname: " << contact.getNickname() << std::endl;
        std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
    } else if (indexToDisplay == 0) {
        std::cout << "Canceled searching." << std::endl;
    } else {
        std::cout << "Invalid index." << std::endl;
    }
}

PhoneBook::~PhoneBook(void) {

    std::cout << BOLDRED << "Destructor called " << RESET << __func__ << std::endl;
}

int main(void) {
    PhoneBook myPhoneBook;

    while (true) {

        std::cout << "Phonebook Menu:" << std::endl;
        std::cout << "ADD. Add Contact" << std::endl;
        std::cout << "DISPLAY. Display Contacts" << std::endl;
        std::cout << "SEARCH. Search Contact" << std::endl;
        std::cout << "QUIT. Quit" << std::endl;

        std::string choice;
        std::cin >> choice;
        myPhoneBook.handleCtrlD(); // Check for Ctrl+D while reading input

        if (choice == "ADD") {
            std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
            std::cout << "Enter first name: ";
            std::cin.ignore();
            std::getline(std::cin, firstName);
            myPhoneBook.handleCtrlD(); // Check for Ctrl+D during contact addition
            std::cout << "Enter last name: ";
            std::getline(std::cin, lastName);
            myPhoneBook.handleCtrlD(); // Check for Ctrl+D during contact addition
            std::cout << "Enter nickname: ";
            std::getline(std::cin, nickname);
            myPhoneBook.handleCtrlD(); // Check for Ctrl+D during contact addition
            std::cout << "Enter phone number: ";
            std::getline(std::cin, phoneNumber);
            myPhoneBook.handleCtrlD(); // Check for Ctrl+D during contact addition
            std::cout << "Enter darkest secret: ";
            std::getline(std::cin, darkestSecret);
            myPhoneBook.addContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
        } else if (choice == "DISPLAY") {
            myPhoneBook.displayContacts();
        } else if (choice == "SEARCH") {
            myPhoneBook.searchContact();
        } else if (choice == "QUIT") {
            std::cout << "Goodbye!" << std::endl;
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }

        myPhoneBook.handleCtrlD();
    }

    return 0;
}
