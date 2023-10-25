/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:09:42 by pvong             #+#    #+#             */
/*   Updated: 2023/10/25 13:33:00 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {

public:
    // Constructor
    Contact(void);
    Contact(std::string firstName, std::string lastName, std::string nickname,
            std::string phoneNumber, std::string darkestSecret);

    void display(void);

    // Accessor methods (getters)
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;

    // Destructor
    ~Contact(void);

private:
    static int _nbInst;
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;
};

#endif