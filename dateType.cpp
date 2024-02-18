#include "dateType.h"
#include <iostream>

dateType::dateType(int month, int day, int year) {
    setDate(month, day, year);
}

void dateType::setDate(int month, int day, int year) {
    if (year >= 1900 && month >= 1 && month <= 12 && day >= 1 && day <= getDaysInMonth(month, year)) {
        this->month = month;
        this->day = day;
        this->year = year;
    } else {
        this->month = 1;
        this->day = 1;
        this->year = 1900;
        std::cout << "Date invalid, setting to 1/1/1900" << std::endl;
    }
}

int dateType::getDay() const { return day; }
int dateType::getMonth() const { return month; }
int dateType::getYear() const { return year; }

void dateType::printDate() const {
    std::cout << month << "-" << day << "-" << year << std::endl;
}

bool dateType::isLeapYear(int year) const {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int dateType::getDaysInMonth(int month, int year) const {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}
