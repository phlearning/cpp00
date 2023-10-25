#include <iostream>
#include <iomanip>
#include <string>

const int MAX_CONTACTS = 100;

class Contact {
public:
    Contact() {
        firstName = "";
        lastName = "";
        nickname = "";
        phoneNumber = "";
        darkestSecret = "";
    }

    Contact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->nickname = nickname;
        this->phoneNumber = phoneNumber;
        this->darkestSecret = darkestSecret;
    }

    void display() {
        std::string truncatedFirstName = firstName.substr(0, 10);
        if (truncatedFirstName.length() == 10) {
            truncatedFirstName[9] = '.';
        }

        std::string truncatedLastName = lastName.substr(0, 10);
        if (truncatedLastName.length() == 10) {
            truncatedLastName[9] = '.';
        }

        std::string truncatedNickname = nickname.substr(0, 10);
        if (truncatedNickname.length() == 10) {
            truncatedNickname[9] = '.';
        }

        std::string truncatedPhoneNumber = phoneNumber.substr(0, 10);
        if (truncatedPhoneNumber.length() == 10) {
            truncatedPhoneNumber[9] = '.';
        }

        std::string truncatedDarkestSecret = darkestSecret.substr(0, 10);
        if (truncatedDarkestSecret.length() == 10) {
            truncatedDarkestSecret[9] = '.';
        }

        std::cout << std::left << std::setw(12) << truncatedFirstName << " | " << std::setw(12) << truncatedLastName << " | " << std::setw(12) << truncatedNickname << " | " << std::setw(12) << truncatedPhoneNumber << " | " << std::setw(12) << truncatedDarkestSecret << std::endl;
    }

    std::string getFirstName() {
        return firstName;
    }

    std::string getLastName() {
        return lastName;
    }

    std::string getNickname() {
        return nickname;
    }

    std::string getPhoneNumber() {
        return phoneNumber;
    }

    std::string getDarkestSecret() {
        return darkestSecret;
    }

private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
};

class Phonebook {
public:
    Phonebook() {
        numContacts = 0;
        oldestContactIndex = 0;
    }

    void addContact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret) {
        if (firstName.empty() || lastName.empty() || phoneNumber.empty()) {
            std::cout << "Contact details cannot be empty. Please provide valid information." << std::endl;
            return;
        }

        if (numContacts < MAX_CONTACTS) {
            contacts[numContacts] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
            numContacts++;
            std::cout << "Contact added successfully!" << std::endl;
        } else {
            contacts[oldestContactIndex] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
            oldestContactIndex = (oldestContactIndex + 1) % MAX_CONTACTS;
            std::cout << "Phonebook is full. Replaced the oldest contact." << std::endl;
        }
    }

    void displayContacts() {
        if (numContacts == 0) {
            std::cout << "Phonebook is empty." << std::endl;
        } else {
            std::cout << std::left << std::setw(5) << "Index" << " | " << std::setw(12) << "First Name" << " | " << std::setw(12) << "Last Name" << " | " << std::setw(12) << "Nickname" << " | " << std::setw(12) << "Phone Number" << " | " << std::setw(12) << "Darkest Secret" << std::endl;
            for (int i = 0; i < numContacts; i++) {
                std::cout << std::left << std::setw(5) << i + 1 << " | ";
                contacts[i].display();
            }
        }
    }

void handleCtrlD() {
    if (std::cin.eof()) {
        std::cout << "End of input. Exiting program." << std::endl;
        exit(0); // Exit the program
    }
}

    void searchContact() {
        std::cout << "All Contacts:" << std::endl;
        displayContacts();

        int indexToDisplay;
        std::cout << "Enter the index of the contact you want to display (0 to cancel): ";
        std::cin >> indexToDisplay;

        handleCtrlD();

        if (indexToDisplay > 0 && indexToDisplay <= numContacts) {
            int contactIndex = indexToDisplay - 1;
            std::cout << "Contact Details:" << std::endl;
            Contact contact = contacts[contactIndex];
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

private:
    Contact contacts[MAX_CONTACTS];
    int numContacts;
    int oldestContactIndex;
};

int main() {
    Phonebook myPhonebook;

    while (true) {
        std::cout << "Phonebook Menu:" << std::endl;
        std::cout << "ADD. Add Contact" << std::endl;
        std::cout << "DISPLAY. Display Contacts" << std::endl;
        std::cout << "SEARCH. Search Contact" << std::endl;
        std::cout << "QUIT. Quit" << std::endl;

        std::string choice;
        std::cin >> choice;
        myPhonebook.handleCtrlD(); // Check for Ctrl+D while reading input

        if (choice == "ADD") {
            std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
            std::cout << "Enter first name: ";
            std::cin.ignore();
            std::getline(std::cin, firstName);
            myPhonebook.handleCtrlD(); // Check for Ctrl+D during contact addition
            std::cout << "Enter last name: ";
            std::getline(std::cin, lastName);
            myPhonebook.handleCtrlD(); // Check for Ctrl+D during contact addition
            std::cout << "Enter nickname: ";
            std::getline(std::cin, nickname);
            myPhonebook.handleCtrlD(); // Check for Ctrl+D during contact addition
            std::cout << "Enter phone number: ";
            std::getline(std::cin, phoneNumber);
            myPhonebook.handleCtrlD(); // Check for Ctrl+D during contact addition
            std::cout << "Enter darkest secret: ";
            std::getline(std::cin, darkestSecret);
            myPhonebook.addContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
        } else if (choice == "DISPLAY") {
            myPhonebook.displayContacts();
        } else if (choice == "SEARCH") {
            myPhonebook.searchContact();
        } else if (choice == "QUIT") {
            std::cout << "Goodbye!" << std::endl;
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }

        myPhonebook.handleCtrlD();
    }

    return 0;
}