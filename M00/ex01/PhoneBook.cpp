# include "PhoneBook.hpp"

/**
 * no argument constructor
*/
PhoneBook::PhoneBook () {
    rw_head = 0;
}

void PhoneBook::addRecord(const Contact contact) {
    int index = this->rw_head % size;
    this->records[index] = contact;
    std::cout << "index : " << std::to_string(index) << std::endl;
    std::cout << "rw_head : " << std::to_string(this->rw_head) << std::endl;
    this->rw_head++;
    std::cout << "rw_head after : " << std::to_string(this->rw_head) << std::endl;
}

// void PhoneBook::searchRecord(int index) {

// }

// void PhoneBook::viewSingleContact(Contact contact) {

// }

void PhoneBook::veiwAllContacts(void) {

    if (this->rw_head == 0) {
        std::cout << "there are no record availabe !\n";
    }

    printColumn("index");
    printColumn("first name");
    printColumn("last name");
    printColumn("nick name");
    std::cout << "\n";

    for(int i = 0; i < std::min(this->rw_head, size); i++) {
        printColumn(std::to_string(i));
        this->records[i].print();
        std::cout << "\n";
    }
}
