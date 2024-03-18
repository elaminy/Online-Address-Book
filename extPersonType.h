#ifndef EXTPERSONTYPE_H
#define EXTPERSONTYPE_H

#include "personType.h"
#include "dateType.h"
#include "addressType.h"
#include <string>

class extPersonType : public personType {
public:
    extPersonType(std::string first = "", std::string last = "", std::string street = "", std::string city = "", std::string state = "", std::string zip = "", int month = 1, int day = 1, int year = 1900, std::string phone = "", std::string relation = "Friend");

    void setInfo(std::string first, std::string last, std::string street, std::string city, std::string state, std::string zip, int month, int day, int year, std::string phone, std::string relation);

    void printInfo() const;

    bool isBirthday(int month) const;

    void setRelationship(std::string relation);
    std::string getRelationship() const;

    void setPhoneNumber(std::string phone);
    std::string getPhoneNumber() const;

    // Overloaded relational operators
    bool operator==(const extPersonType& other) const;
    bool operator!=(const extPersonType& other) const;
    bool operator>=(const extPersonType& other) const;

    // Additional getter functions
    std::string getAddress() const;
    std::string getCity() const;
    std::string getState() const;
    int getZipcode() const;
    int getMonth() const;
    int getDay() const;
    int getYear() const;

private:
    addressType address;
    dateType birthDate;
    std::string phoneNumber;
    std::string relationship;
};

#endif // EXTPERSONTYPE_H