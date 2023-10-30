/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:25:30 by pvong             #+#    #+#             */
/*   Updated: 2023/10/30 11:28:28 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Color.hpp"
#include "Contact.hpp"
#include <string>

#define MAX_CONTACT 8

class PhoneBook {

public:
    PhoneBook(void);

    void addContact(std::string firstName, std::string lastName, std::string nickname,
                    std::string phoneNumber, std::string darkestSecret);
    void displayContacts(void);
    void searchContact(void);
    void handleCtrlD(void);
    int isNotValidNumber(std::string phoneNumber);

    ~PhoneBook(void);

private:
    Contact _contacts[MAX_CONTACT];
    int _numContacts;
    int _oldestIndex;
};

#endif