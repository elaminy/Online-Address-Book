#ifndef ADDRESSTYPE_H
#define ADDRESSTYPE_H

#include <string>

class addressType {
public:
    addressType();
    addressType(std::string st, std::string ci, std::string sta, int z);

    void setState(std::string sta);
    void setZipcode(int z);
    void setAddress(std::string st, std::string ci, std::string sta, int z);
    void setCity(std::string ci);

    std::string getState() const;
    int getZipcode() const;
    std::string getAddress() const;
    std::string getCity() const;

    void print() const;

private:
    std::string street, city, state;
    int zip;
};

#endif // ADDRESSTYPE_H
