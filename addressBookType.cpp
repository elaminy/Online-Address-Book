#include "addressBookType.h"
#include <iostream>
#include <fstream>

void addressBookType::loadAddressBook() {
    std::ifstream inFile("AddressBookData.txt");
    if (!inFile) {
        std::cout << "Unable to open file." << std::endl;
        return;
    }

    extPersonType person;
    std::string firstName, lastName, street, city, state, zip, phoneNumber, relationship;
    int month, day, year;

    while (inFile >> firstName >> lastName >> street >> city >> state >> zip >> month >> day >> year >> phoneNumber >> relationship) {
        person.setInfo(firstName, lastName, street, city, state, zip, month, day, year, phoneNumber, relationship);
        insert(person);
    }

    inFile.close();
}

void addressBookType::addEntry(extPersonType& newEntry) {
    insert(newEntry);
}

void addressBookType::removeEntry(const std::string& lastName, const std::string& firstName) {
    extPersonType searchPerson(firstName, lastName);
    deleteNode(searchPerson);
}

void addressBookType::searchEntry(const std::string& lastName, const std::string& firstName) const {
    extPersonType searchPerson(firstName, lastName);
    nodeType<extPersonType>* current = first;
    bool found = false;

    while (current != nullptr) {
        if (current->info == searchPerson) {
            current->info.printInfo();
            found = true;
            break;
        }
        current = current->link;
    }

    if (!found) {
        std::cout << "Person not found." << std::endl;
    }
}

void addressBookType::updateEntry(const std::string& lastName, const std::string& firstName) {
    extPersonType searchPerson(firstName, lastName);
    nodeType<extPersonType>* current = first;
    bool found = false;

    while (current != nullptr) {
        if (current->info == searchPerson) {
            std::string street, city, state, zip, phoneNumber, relationship;
            int month, day, year;

            std::cout << "Enter updated information:" << std::endl;
            std::cout << "Street: ";
            std::cin >> street;
            std::cout << "City: ";
            std::cin >> city;
            std::cout << "State: ";
            std::cin >> state;
            std::cout << "ZIP: ";
            std::cin >> zip;
            std::cout << "Birth Month: ";
            std::cin >> month;
            std::cout << "Birth Day: ";
            std::cin >> day;
            std::cout << "Birth Year: ";
            std::cin >> year;
            std::cout << "Phone Number: ";
            std::cin >> phoneNumber;
            std::cout << "Relationship: ";
            std::cin >> relationship;

            current->info.setInfo(firstName, lastName, street, city, state, zip, month, day, year, phoneNumber, relationship);
            found = true;
            break;
        }
        current = current->link;
    }

    if (!found) {
        std::cout << "Person not found." << std::endl;
    }
}

void addressBookType::printNameInTheMonth(int month) const {
    nodeType<extPersonType>* current = first;
    while (current != nullptr) {
        if (current->info.isBirthday(month)) {
            current->info.print();
            std::cout << std::endl;
        }
        current = current->link;
    }
}

void addressBookType::printInfoInTheMonth(int month) const {
    nodeType<extPersonType>* current = first;
    while (current != nullptr) {
        if (current->info.isBirthday(month)) {
            current->info.printInfo();
            std::cout << std::endl;
        }
        current = current->link;
    }
}

void addressBookType::printNameWithStatus(const std::string& status) const {
    nodeType<extPersonType>* current = first;
    while (current != nullptr) {
        if (current->info.getRelationship() == status) {
            current->info.print();
            std::cout << std::endl;
        }
        current = current->link;
    }
}

void addressBookType::printInfoWithStatus(const std::string& status) const {
    nodeType<extPersonType>* current = first;
    while (current != nullptr) {
        if (current->info.getRelationship() == status) {
            current->info.printInfo();
            std::cout << std::endl;
        }
        current = current->link;
    }
}

void addressBookType::printAddressBook() const {
    nodeType<extPersonType>* current = first;
    while (current != nullptr) {
        current->info.printInfo();
        std::cout << std::endl;
        current = current->link;
    }
}

void addressBookType::saveAddressBook() const {
    std::ofstream outFile("AddressBookData.txt");
    if (!outFile) {
        std::cout << "Unable to open file." << std::endl;
        return;
    }

    nodeType<extPersonType>* current = first;
    while (current != nullptr) {
        outFile << current->info.getFirstName() << " " << current->info.getLastName() << " "
            << current->info.getAddress() << " " << current->info.getCity() << " "
            << current->info.getState() << " " << current->info.getZipcode() << " "
            << current->info.getMonth() << " " << current->info.getDay() << " "
            << current->info.getYear() << " " << current->info.getPhoneNumber() << " "
            << current->info.getRelationship() << std::endl;
        current = current->link;
    }

    outFile.close();
}