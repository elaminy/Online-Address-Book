#include "extPersonType.h"
#include <iostream>

extPersonType::extPersonType(std::string first, std::string last, std::string street, std::string city, std::string state, std::string zip, int month, int day, int year, std::string phone, std::string relation)
    : personType(first, last), address(street, city, state, std::stoi(zip)), birthDate(month, day, year), phoneNumber(phone), relationship(relation) {}

void extPersonType::setInfo(std::string first, std::string last, std::string street, std::string city, std::string state, std::string zip, int month, int day, int year, std::string phone, std::string relation) {
    personType::setName(first, last);
    address.setAddress(street, city, state, std::stoi(zip));
    birthDate.setDate(month, day, year);
    this->phoneNumber = phone;
    this->relationship = relation;
}

void extPersonType::printInfo() const {
    personType::print();
    std::cout << std::endl;
    birthDate.printDate();
    std::cout << std::endl;
    address.print();
    std::cout << std::endl;
    std::cout << "Phone: " << phoneNumber << std::endl;
    std::cout << "Relationship: " << relationship << std::endl;
}

bool extPersonType::isBirthday(int month) const {
    return birthDate.getMonth() == month;
}

void extPersonType::setRelationship(std::string relation) {
    if (relation == "Family" || relation == "Friend" || relation == "Business") {
        this->relationship = relation;
    }
    else {
        this->relationship = "Friend";
    }
}

std::string extPersonType::getRelationship() const {
    return relationship;
}

void extPersonType::setPhoneNumber(std::string phone) {
    phoneNumber = phone;
}

std::string extPersonType::getPhoneNumber() const {
    return phoneNumber;
}
