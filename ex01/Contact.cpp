/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:31:49 by pvong             #+#    #+#             */
/*   Updated: 2023/10/24 18:27:37 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret) {
    std::cout << "Constructor called " << __func__ << std::endl; 
    this->firstName = firstName;
    std::cout << "this->firstName: " << this->firstName << std::endl;
    this->lastName = lastName;
    std::cout << "this->lastName: " << this->lastName << std::endl;
    this->nickname = nickname;
    std::cout << "this->nickname: " << this->nickname << std::endl;
    this->phoneNumber = phoneNumber;
    std::cout << "this->phoneNumber: " << this->phoneNumber << std::endl;
    this->darkestSecret = darkestSecret;
    std::cout << "this->darkestSecret: " << this->darkestSecret << std::endl;
}

std::string Contact::getFirstName() const {
    return firstName;
}

std::string Contact::getLastName() const {
    return lastName;
}

std::string Contact::getNickname() const {
    return nickname;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return darkestSecret;
}

Contact::~Contact() {
    std::cout << "Destructor called " << __func__ << std::endl; 
}

int main() {
    Contact Sample("hello", "hello", "hello", "hello", "hello");

    return 0;
}