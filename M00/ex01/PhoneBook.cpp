# include "PhoneBook.hpp"

/**
 * @brief constructor will intialized the read/write head to zero
 */
PhoneBook::PhoneBook () {
    rw_head = 0;
}

/**
 * @brief adding record to the phonebook
 * @param contact new record need to added
*/
void PhoneBook::addRecord(const Contact contact) {
    int index = this->rw_head % size;
    this->records[index] = contact;
    this->rw_head++;
    std::cout << "contact added successfully !" << std::endl;
}

/**
 * @brief displaying the content of a record after search by the index
 * @param index index of the contact record in the array
*/
void PhoneBook::viewSingleContact(int index) {

    // index should be with in the range of records saved
    if (index < 0 || index >= std::min(this->rw_head, size)) {
        // user trying to access out of range record
        std::cerr << "there is no such record !\n";
    } else {
        // accessing a record with correct index
        this->records[index].view();
    }
}

/**
 * @brief displaying the full list of contacts stored in the array
*/
bool PhoneBook::viewAllContacts(void) {

    if (this->rw_head == 0) {
        // user trying to view and search empty phonebook
        std::cerr << "phone book is empty !\n";
        return (false);

    } else {
        // header colunmn
        printColumn("index");
        printColumn("first name");
        printColumn("last name");
        printColumn("nick name");

        std::cout << "\n";
        // print all the records one by one
        for(int i = 0; i < std::min(this->rw_head, size); i++) {
            printColumn(std::to_string(i));
            this->records[i].print();
            std::cout << "\n";
        }
        return (true);
    }
}

/**
 * @brief add test data, exatly 06 data records to make iot easy to test the circular
 * index correctly working
*/
void PhoneBook::addSomeTestDate(void) {

    this->addRecord(Contact (
        "Thiwanka",
        "Somachandra",
        "tsomacha",
        "045 555 3838",
        "I am the superman"
    ));

    this->addRecord(Contact (
        "Linus",
        "Trovalds",
        "mr.linux",
        "(045)-123-4567",
        "Farther of linux and git"
    ));

    this->addRecord(Contact (
        "Ada",
        "Lovelace",
        "goat",
        "+358 11 111 1111",
        "world first programmer"
    ));

    this->addRecord(Contact (
        "Allan",
        "Turin",
        "complex",
        "045 123 4567",
        "he invented the turing machine"
    ));

    this->addRecord(Contact (
        "Dennis",
        "Ritchie",
        "mr.c",
        "(045) 123 4567",
        "Farther of C and Unix"
    ));

    this->addRecord(Contact (
        "Bjarne",
        "Stroustrup",
        "mr.cpp",
        "0451234567",
        "Farther of C++"
    ));
}
