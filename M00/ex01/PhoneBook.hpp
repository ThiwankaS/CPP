# ifndef PHONEBOOK_HPP
#  define PHONEBOOK_HP

# include <string>
# include <iostream>

# include "Contact.hpp"


//size will detemine the number of records program will allocate memory
constexpr int size  = 8;

class PhoneBook {

    private :
        // read/write head to point the index in te array
        int rw_head;
        // an array of contacts
        Contact records[size];

    public  :
        // constructors
        PhoneBook();

        // default destructor
        ~PhoneBook() = default;

        // other class methods declaration
        void addRecord(const Contact contact);
        void viewSingleContact(int index);
        bool viewAllContacts(void);

        // adding some data for testing purposes - 06 rows of data will added
        void addSomeTestDate(void);
};

# endif
