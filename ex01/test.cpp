#include <iostream>
#include <iomanip>
#include <string>

class Contact {
public:
    Contact() {
        firstName = "";
        phoneNumber = "";
    }

    Contact(std::string firstName, std::string phoneNumber) {
        this->firstName = firstName;
        this->phoneNumber = phoneNumber;
    }

    void display() {
        std::string truncatedName = firstName.substr(0, 10);
        if (truncatedName.length() == 10) {
            truncatedName[9] = '.';
        }
        std::string truncatedPhoneNumber = phoneNumber.substr(0, 10);
        if (truncatedPhoneNumber.length() == 10) {
            truncatedPhoneNumber[9] = '.';
        }
        std::cout << std::right << std::setw(10) << truncatedName << " | " << std::setw(10) << truncatedPhoneNumber << std::endl;
    }

    std::string getName() {
        return firstName;
    }

    std::string getPhoneNumber() {
        return phoneNumber;
    }

private:
    std::string firstName;
    std::string phoneNumber;
};

class Phonebook {
public:
    Phonebook() {
        numContacts = 0;
        oldestContactIndex = 0;
    }

    void addContact(std::string firstName, std::string phoneNumber) {
        if (numContacts < maxContacts) {
            contacts[numContacts] = Contact(firstName, phoneNumber);
            numContacts++;
            std::cout << "Contact added successfully!" << std::endl;
        } else {
            // Replace the oldest contact with the new one
            contacts[oldestContactIndex] = Contact(firstName, phoneNumber);
            oldestContactIndex = (oldestContactIndex + 1) % maxContacts; // Circular buffer
            std::cout << "Phonebook is full. Replaced the oldest contact." << std::endl;
        }
    }

    void displayContacts() {
        if (numContacts == 0) {
            std::cout << "Phonebook is empty." << std::endl;
        } else {
            std::cout << std::right << std::setw(10) << "Index" << " | " << std::setw(10) << "Name" << " | " << std::setw(10) << "Phone Number" << std::endl;
            for (int i = 0; i < numContacts; i++) {
                std::cout << std::right << std::setw(10) << i + 1 << " | ";
                contacts[i].display();
            }
        }
    }

    void searchContact(std::string query) {
        bool found = false;
        std::cout << "Search Results:" << std::endl;

        for (int i = 0; i < numContacts; i++) {
            if (contacts[i].getName() == query || contacts[i].getPhoneNumber() == query) {
                contacts[i].display();
                found = true;
            }
        }

        if (!found) {
            std::cout << "Contact not found." << std::endl;
        }
    }

private:
    static const int maxContacts = 8;
    Contact contacts[maxContacts];
    int numContacts;
    int oldestContactIndex;
};

int main() {
    Phonebook myPhonebook;

    while (true) {
        std::cout << " ===============" << std::endl;
        std::cout << " Phonebook Menu:" << std::endl;
        std::cout << " ADD: Add Contact" << std::endl;
        std::cout << " DISPLAY: Display Contacts" << std::endl;
        std::cout << " SEARCH: Search Contact" << std::endl;
        std::cout << " QUIT: Quit" << std::endl;
        std::cout << " ===============" << std::endl;

        std::string choice;
        std::cin >> choice;

        if (choice == "ADD") {
            std::string firstName, lastName, nickname, phoneNumber;
            std::cout << " Enter contact first name: ";
            std::cin >> firstName;
            std::cout << " Enter contact last name: ";
            std::cin >> lastName;
            std::cout << " Enter contact nickname: ";
            std::cin >> nickname;
            std::cout << " Enter phone number: ";
            std::cin >> phoneNumber;
            myPhonebook.addContact(firstName, phoneNumber);
        } else if (choice == "DISPLAY") {
            myPhonebook.displayContacts();
        } else if (choice == "SEARCH") {
            std::string query;
            std::cout << " Enter a name or phone number to search: ";
            std::cin >> query;
            myPhonebook.searchContact(query);
        } else if (choice == "QUIT") {
            std::cout << " ===============" << std::endl;
            std::cout << " Goodbye!" << std::endl;
            std::cout << " ===============" << std::endl;
            break;
        } else {
            std::cout << " ===============" << std::endl;
            std::cout << " Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
