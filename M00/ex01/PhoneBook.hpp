# ifndef PHONEBOOK_HPP
#  define PHONEBOOK_HP

/**
 * standard headers
*/
# include <iostream>
/**
 * custome headers
*/
# include "Contact.hpp"

/**
 * size will detemine the number of records program will allocate memory
*/
constexpr int size  = 8;

class PhoneBook {

    private :
        int rw_head;
        Contact records[size];

    public  :
        /**
         * constructors
        */
        PhoneBook();
        /**
         * default destructor
        */
        ~PhoneBook() = default;
        /**
         * other class methods declaration
        */
        void addRecord(const Contact contact);
        //void searchRecord(int index);
        void viewSingleContact(int index);
        void veiwAllContacts(void);
};

# endif
