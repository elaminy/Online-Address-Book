#include <iostream>
#include "addressType.h"
#include "dateType.h"
#include "extPersonType.h"

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

    return 0;
}
