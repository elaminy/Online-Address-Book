#include "addressType.h"
#include <iostream>

addressType::addressType() : street(""), city(""), state("XX"), zip(10000) {}

addressType::addressType(std::string st, std::string ci, std::string sta, int z)
    : street(st), city(ci), state(sta), zip(z) {
    setState(sta);
    setZipcode(z);
}

void addressType::setState(std::string sta) {
    if (sta.length() == 2) state = sta;
    else std::cout << "Invalid state. Must be 2 characters. State unchanged.\n";
}

void addressType::setZipcode(int z) {
    if (z >= 11111 && z <= 99999) zip = z;
    else std::cout << "Invalid ZIP code. Must be between 11111 and 99999. ZIP code unchanged.\n";
}

void addressType::setAddress(std::string st, std::string ci, std::string sta, int z) {
    street = st;
    city = ci;
    setState(sta);
    setZipcode(z);
}

void addressType::setCity(std::string ci) {
    city = ci;
}

std::string addressType::getState() const {
    return state;
}

int addressType::getZipcode() const {
    return zip;
}

std::string addressType::getAddress() const {
    return street;
}

std::string addressType::getCity() const {
    return city;
}

void addressType::print() const {
    std::cout << street << ", " << city << ", " << state << " " << zip << std::endl;
}
