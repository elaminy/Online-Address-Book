#ifndef ADDRESSBOOKTYPE_H
#define ADDRESSBOOKTYPE_H

#include "orderedLinkedList.h"
#include "extPersonType.h"

class addressBookType : public orderedLinkedList<extPersonType> {
public:
    void loadAddressBook();
    void addEntry(extPersonType& newEntry);
    void removeEntry(const std::string& lastName, const std::string& firstName);
    void searchEntry(const std::string& lastName, const std::string& firstName) const;
    void updateEntry(const std::string& lastName, const std::string& firstName);
    void printNameInTheMonth(int month) const;
    void printInfoInTheMonth(int month) const;
    void printNameWithStatus(const std::string& status) const;
    void printInfoWithStatus(const std::string& status) const;
    void printAddressBook() const;
    void saveAddressBook() const;
};

#endif // ADDRESSBOOKTYPE_H