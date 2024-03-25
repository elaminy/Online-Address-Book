#include <iostream>
#include "addressType.h"
#include "dateType.h"
#include "extPersonType.h"
#include "addressBookType.h"

int main() {
    // Create and test addressType
    addressType address("123 South Street", "Newport News", "VA", 23664);
    std::cout << "Testing addressType:" << std::endl;
    address.print();
    std::cout << std::endl;

    // Create and test dateType
    dateType date(12, 25, 2020);
    std::cout << "Testing dateType:" << std::endl;
    date.printDate();
    std::cout << std::endl;

    // Create and test extPersonType
    extPersonType person("John", "Doe", "456 West Road", "Richmond", "VA", "23220", 4, 15, 1990, "555-6789", "Friend");
    std::cout << "Testing extPersonType:" << std::endl;
    person.printInfo();
    std::cout << std::endl;

    // Create and test addressBookType
    addressBookType addressBook;
    addressBook.loadAddressBook();

    int choice;
    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add Entry" << std::endl;
        std::cout << "2. Remove Entry" << std::endl;
        std::cout << "3. Search Entry" << std::endl;
        std::cout << "4. Update Entry" << std::endl;
        std::cout << "5. Print Names in a Month" << std::endl;
        std::cout << "6. Print Info in a Month" << std::endl;
        std::cout << "7. Print Names with Status" << std::endl;
        std::cout << "8. Print Info with Status" << std::endl;
        std::cout << "9. Print Address Book" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string firstName, lastName, street, city, state, zip, phoneNumber, relationship;
            int month, day, year;

            std::cout << "Enter first name: ";
            std::cin >> firstName;
            std::cout << "Enter last name: ";
            std::cin >> lastName;
            std::cout << "Enter street: ";
            std::cin >> street;
            std::cout << "Enter city: ";
            std::cin >> city;
            std::cout << "Enter state: ";
            std::cin >> state;
            std::cout << "Enter ZIP: ";
            std::cin >> zip;
            std::cout << "Enter birth month: ";
            std::cin >> month;
            std::cout << "Enter birth day: ";
            std::cin >> day;
            std::cout << "Enter birth year: ";
            std::cin >> year;
            std::cout << "Enter phone number: ";
            std::cin >> phoneNumber;
            std::cout << "Enter relationship: ";
            std::cin >> relationship;

            extPersonType newPerson(firstName, lastName, street, city, state, zip, month, day, year, phoneNumber, relationship);
            addressBook.addEntry(newPerson);
            break;
        }
        case 2: {
            std::string firstName, lastName;

            std::cout << "Enter first name: ";
            std::cin >> firstName;
            std::cout << "Enter last name: ";
            std::cin >> lastName;

            addressBook.removeEntry(lastName, firstName);
            break;
        }
        case 3: {
            std::string firstName, lastName;

            std::cout << "Enter first name: ";
            std::cin >> firstName;
            std::cout << "Enter last name: ";
            std::cin >> lastName;

            addressBook.searchEntry(lastName, firstName);
            break;
        }
        case 4: {
            std::string firstName, lastName;

            std::cout << "Enter first name: ";
            std::cin >> firstName;
            std::cout << "Enter last name: ";
            std::cin >> lastName;

            addressBook.updateEntry(lastName, firstName);
            break;
        }
        case 5: {
            int month;

            std::cout << "Enter month: ";
            std::cin >> month;

            addressBook.printNameInTheMonth(month);
            break;
        }
        case 6: {
            int month;

            std::cout << "Enter month: ";
            std::cin >> month;

            addressBook.printInfoInTheMonth(month);
            break;
        }
        case 7: {
            std::string status;

            std::cout << "Enter status: ";
            std::cin >> status;

            addressBook.printNameWithStatus(status);
            break;
        }
        case 8: {
            std::string status;

            std::cout << "Enter status: ";
            std::cin >> status;

            addressBook.printInfoWithStatus(status);
            break;
        }
        case 9: {
            addressBook.printAddressBook();
            break;
        }
        case 0: {
            addressBook.saveAddressBook();
            std::cout << "Exiting..." << std::endl;
            break;
        }
        default: {
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
        }

        std::cout << std::endl;
    } while (choice != 0);

    return 0;
}
