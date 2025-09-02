#include <iostream>

#include "utilities.hpp"
#include "PhoneBook.hpp"

// helper functions declaration
void process_choice(std::string choice, PhoneBook& my_phone_book);
void contact_add(PhoneBook& my_phone_book);
void contact_search(PhoneBook& my_phone_book);

int main(void) {

    /**
     * varibale to handle the user command possible valid values can be ADD, SEARCH
     * and EXIT
    */
    std::string choice;

    PhoneBook my_phone_book = PhoneBook();

    /**
     * un-comment below function to add some test data
    */
    //my_phone_book.addSomeTestDate();

    /**
     * phonebook program will display a prompt and wait for a user input, the loop
     * will continiously prompt unstill user enter EXIT. The process_choice() will
     * process the user expectation otherwise
    */
    while(true)
    {
        std::cout << " --- Welcome to phonebook app ---      " << std::endl;
        std::cout << " Enter your prefferred command :       " << std::endl;
        std::cout << "  ADD     -> to add new contact.       " << std::endl;
        std::cout << "  SEARCH  -> to search for a contact.  " << std::endl;
        std::cout << "  EXIT    -> to exit the program.      " << std::endl;
        std::cout << " --------------------------------------" << std::endl;
        std::cout << "  your choice : ";

        if(!std::getline(std::cin, choice)) {
            std::cout << "EOF detected, leaving the program !\n";
            break;
        }

        if (choice == "EXIT")
        {
            std::cout << "leaving the program." << std::endl;
            break;
        }
        process_choice(choice, my_phone_book);
    }
    return (0);
}

/**
 * @brief invoking funtionalities based on the user's choice
 * @param choice a string
 * @param my_phone_book refernce to the Phonebook instance
 */
void process_choice(std::string choice, PhoneBook& my_phone_book) {

    if(choice == "ADD")
        contact_add(my_phone_book);
    else if(choice == "SEARCH")
        contact_search(my_phone_book);
    else if(!choice.empty())
        std::cerr << "Incorrect choice, try agin !" << std::endl;
    choice.clear();
}

/**
 * @brief adding a new contact to the phonbook
 * @param my_phone_book refernce to the Phonebook instance
 */
void contact_add(PhoneBook& my_phone_book) {

    std::string f_name, l_name, n_name, p_number, secret;

    /**
     * will propmt and wait for user input, for any invalid input an error message
     * will display followed by the previous propmt.
     * process will continue untill user enter a valid input for first name.
     * only alphabetical characters will accept
    */
    do {
            std::cout << " Enter first name     : ";
            std::getline(std::cin, f_name);
            if (!isValidName(f_name))
            {
                std::cerr << "Invalid first  name, try again!\n";
                f_name.clear();
            }
    } while (f_name.empty());

    /**
     * will propmt and wait for user input, for any invalid input an error message
     * will display followed by the previous propmt.
     * process will follow continue user enter a valid input for last name.
     * only alphabetical characters will accept
    */
    do {
            std::cout << " Enter last name      : ";
            std::getline(std::cin, l_name);
            if (!isValidName(l_name))
            {
                std::cerr << "Invalid last name, try again!\n";
                l_name.clear();
            }
    } while (l_name.empty());

    /**
    * will prompt and wait for a user input, no validating.
    * user can not leave this balnk but can enter any character as prefer
    */
    do {
            std::cout << " Enter nick name      : ";
            std::getline(std::cin, n_name);
            if (!isNotBlank(n_name)) {
                std::cerr << "nick name can not be blank, try again!\n";
                n_name.clear();
            }
    } while (n_name.empty());

    /**
     * will propmt and wait for a user input, strict validation will follow for both
     * content and format.
     * process will continue untill user enter a valid input for phone number.
    */
    do {
            std::cout << " Enter phone number   : ";
            std::getline(std::cin, p_number);
            if (!isValidNumber(p_number))
            {
                std::cerr << "Invalid phone number, try again!\n";
                p_number.clear();
            }
    } while (p_number.empty());

    /**
    * will prompt and wait for a user input, no validating. user can not leave this
    * balnk but can enter any character as prefer
    */
    do {
            std::cout << " Enter darkest secret : ";
            std::getline(std::cin, secret);
            if (!isNotBlank(secret)) {
                std::cerr << "secret can not be blank, try again!\n";
                secret.clear();
            }
    } while (secret.empty());

    /**
     * creating new contact instance and add to my_phonebook
    */
    my_phone_book.addRecord(Contact(f_name, l_name, n_name, p_number, secret));
}

/**
 * @brief travese through my_phonebook and display records
 * @param my_phone_book refernce to the Phonebook instance
 */
void contact_search(PhoneBook& my_phone_book) {

    std::string input;

    /**
     * view all the contacts saved in the phonebook
    */
    if (my_phone_book.viewAllContacts()) {
        /**
        * prompt and wait for user input for index to to view single contact
        */
        do {
                std::cout << "\n" << " Enter index   : ";
                std::getline(std::cin, input);
                if (!isValidIndex(input)) {
                    std::cerr << "Invalid index !\n";
                    input.clear();
                }
        } while (input.empty());
        /**
         * convert user input to int and invoke the view function
        */
        my_phone_book.viewSingleContact(std::stoi(input));
    }
}
