/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:32:28 by pvong             #+#    #+#             */
/*   Updated: 2023/10/25 16:19:20 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

int main(void) {
    PhoneBook myPhoneBook;

    while (true) {
        std::cout << BLACK << MSG_SEP << RESET << std::endl;
        std::cout << "Phonebook Menu:" << std::endl;
        std::cout << "ADD: Add Contact" << std::endl;
        std::cout << "SEARCH: Search Contact" << std::endl;
        std::cout << "EXIT: Quit the program" << std::endl;
        std::cout << BLACK << MSG_SEP << RESET << std::endl;

        std::string choice;
        std::cin >> choice;
        myPhoneBook.handleCtrlD();

        if (choice == "ADD") {
            std::cout << BLACK << MSG_SEP << RESET << std::endl;
            std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
            std::cout << "Enter first name: ";
            std::cin.ignore();
            std::getline(std::cin, firstName);
            myPhoneBook.handleCtrlD();
            std::cout << "Enter last name: ";
            std::getline(std::cin, lastName);
            myPhoneBook.handleCtrlD();
            std::cout << "Enter nickname: ";
            std::getline(std::cin, nickname);
            myPhoneBook.handleCtrlD();
            std::cout << "Enter phone number: ";
            std::getline(std::cin, phoneNumber);
            while (myPhoneBook.isNotValidNumber(phoneNumber)) {
                myPhoneBook.handleCtrlD();
                std::cout << "Enter a valid phone number: ";
                std::getline(std::cin, phoneNumber);
            }
            myPhoneBook.handleCtrlD();
            std::cout << "Enter darkest secret: ";
            std::getline(std::cin, darkestSecret);
            std::cout << BLACK << MSG_SEP << RESET << std::endl;
            myPhoneBook.addContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
        } else if (choice == "SEARCH") {
            myPhoneBook.searchContact();
        } else if (choice == "EXIT") {
            std::cout << "Goodbye!" << std::endl;
            break;
        } else {
            std::cout << BLACK << MSG_SEP << RESET << std::endl;
            std::cout << "Invalid choice. Please try again." << std::endl;
        }

        myPhoneBook.handleCtrlD();
    }

    return 0;
}