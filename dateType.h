#pragma once
#ifndef DATETYPE_H
#define DATETYPE_H

// Class definition for dateType
class dateType {
public:
    dateType(int month = 1, int day = 1, int year = 1900); // Postconditions: Sets the date, defaulting to 1/1/1900 if invalid.

    void setDate(int month, int day, int year); // Preconditions: month, day, year must be valid. Postconditions: Date is set if valid, otherwise set to 1/1/1900.

    int getDay() const; // Postconditions: Returns the day.
    int getMonth() const; // Postconditions: Returns the month.
    int getYear() const; // Postconditions: Returns the year.

    void printDate() const; // Postconditions: Prints the date in MM-DD-YYYY format.

private:
    int month;
    int day;
    int year;

    bool isLeapYear(int year) const; // Postconditions: Returns true if year is a leap year, false otherwise.
    int getDaysInMonth(int month, int year) const; // Postconditions: Returns the number of days in the given month and year.
};

#endif
