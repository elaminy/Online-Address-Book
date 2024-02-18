#pragma once
#ifndef PERSONTYPE_H
#define PERSONTYPE_H

#include <string>

class personType {
public:
    personType(std::string first = "", std::string last = "");

    void setName(std::string first, std::string last);
    std::string getFirstName() const;
    std::string getLastName() const;
    void print() const;

private:
    std::string firstName;
    std::string lastName;
};

#endif //PERSONTYPE_H
