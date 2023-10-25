/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:25:30 by pvong             #+#    #+#             */
/*   Updated: 2023/10/25 13:43:26 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook {

public:
    PhoneBook(void);
    void addContact(std::string firstName, std::string lastName, std::string nickname,
                    std::string phoneNumber, std::string darkestSecret);
    void displayContacts(void);
    void searchContact(void);
    void handleCtrlD(void);
    ~PhoneBook(void);

private:
    static const int _maxContacts = 8;
    Contact _contacts[_maxContacts];
    int _numContacts;
    int _oldestIndex;
};

#endif