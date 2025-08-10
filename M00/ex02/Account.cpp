# include <iostream>
# include <ctime>

# define HIGLIGHT_START	"\x1b[1m\x1b[38;2;0;0;0m\x1b[48;2;255;255;170m"
# define HIGLIGHT_END	"\x1b[0m"

# include "Account.hpp"

/**
* initializing static varibales
*/
int Account::_nbAccounts         = 0;
int Account::_totalAmount        = 0;
int Account::_totalNbDeposits    = 0;
int Account::_totalNbWithdrawals = 0;

/**
* no argument constructor, will only initialize the varibales
*/
Account::Account (void) {

	this->_accountIndex          = 0;
	this->_amount                = 0;
	this->_nbDeposits            = 0;
	this->_nbWithdrawals         = 0;
}

/**
* this constructor will accept a value as the initial_deposit and update records
* as necessary.
*/
Account::Account( int initial_deposit ) {

    // update records related to individual account
    this->_accountIndex          = Account::_nbAccounts;
	this->_amount                = initial_deposit;
	this->_nbDeposits            = 0;
	this->_nbWithdrawals         = 0;

    // update records to entire bank, globle state
    Account::_totalAmount += initial_deposit;
    Account::_nbAccounts++;

    // displaying updated record with time stamp
    Account::_displayTimestamp();
    std::cout   << " index:" << this->_accountIndex << ";"
                << "amount:" << this->_amount << ";"
                << "created\n";
}

/**
 * default destructor
*/
Account::~Account (void) {

    // update records to entire bank for account closure, globle state
    Account::_totalAmount -= this->_amount;
    Account::_nbAccounts--;
    Account::_totalNbWithdrawals++;

    // displaying time stamp and record details before destroying the indiviual object
    Account::_displayTimestamp();
    std::cout   << " index:" << this->_accountIndex << ";"
                << "amount:" << this->_amount << ";"
                << "closed\n";
}

/**
 * this function is used to print the time stame
*/
void	Account::_displayTimestamp( void ) {

    // declare and initialized time_t varibale
    std::time_t time = std::time(NULL);
    // decalring a char array to hols the values with the size of desired format string
    char time_string[sizeof("[yyyymmdd_hhmmss]")];

    // standard formatted string function from <ctime>
    std::strftime(
        time_string,            // char array to holds the data
        sizeof(time_string),    // size of the char array
        "[%Y%m%d_%H%M%S]",      // expected format
        std::localtime(&time)   // set local time value
    );
    // printing time string, this will be a null terminated string
    std::cout << time_string;
}

/**
 * helper function to access _nbAccounts value
*/
int	Account:: getNbAccounts( void ) {
    return (Account::_nbAccounts);
};

/**
 * helper function to access _totalAmount value
*/
int	Account:: getTotalAmount( void ) {
    return (Account::_totalAmount);
};

/**
 * helper function to access _totalNbDeposits value
*/
int	Account:: getNbDeposits( void ) {
    return (Account::_totalNbDeposits);
};

/**
 * helper function to access _totalNbWithdrawals value
*/
int	Account:: getNbWithdrawals( void ) {
    return (Account::_totalNbWithdrawals);
};

/**
 * displaying all the account infomation
*/
void Account:: 	displayAccountsInfos( void ) {

    Account::_displayTimestamp();
    std::cout	<< HIGLIGHT_START
				<< " accounts:" << Account::getNbAccounts() << ";"
                << "total:" << Account::getTotalAmount() << ";"
                << "deposits:" << Account::getNbDeposits() << ";"
                << "withdrawals:" << Account::getNbWithdrawals()
				<< HIGLIGHT_END
				<< "\n";
};

/**
 * funtion to deposit cash to the account
*/
void Account::makeDeposit( int deposit ) {

    // dispalying the first part
    Account::_displayTimestamp();
    std::cout   << " index:" << this->_accountIndex << ";"
                << "p_amount:" << this->_amount << ";";

    // update individual account data
    this->_amount            += deposit;
    this->_nbDeposits++;

    // update records for bank
    Account::_totalAmount   += deposit;
    Account::_totalNbDeposits++;

    // print the rest of the record
    std::cout   << "depost:" << deposit << ";"
                << "amount:" << this->_amount << ";"
                << "nb_deposits:" << this->_nbDeposits << "\n";
};

// withdrawing cash from an account
bool Account::makeWithdrawal( int withdrawal ) {

    // displaying the first part
    Account::_displayTimestamp();
    std::cout   << " index:" << this->_accountIndex << ";"
                << "p_amount:" << this->_amount << ";";
    // check wether the respective account has enough funds
    if (withdrawal > this->checkAmount()) {
        // account dose not have enough funds
        std::cout   << "withdrawal:" << "refused\n";
        return (false);
    } else {
        // update individual account records
        this->_amount -= withdrawal;
        this->_nbWithdrawals++;

        // update banks records
        Account::_totalAmount   -= withdrawal;
        Account::_totalNbWithdrawals++;

        // priting the rest of the record
        std::cout   << "depost:" << withdrawal << ";"
                << "withdrawal:" << this->_amount << ";"
                << "_nbWithdrawals:" << this->_nbWithdrawals << "\n";
        return (true);
    }
};

/**
 * helper function to access the _amount value
*/
int Account::checkAmount( void ) const {
    return (this->_amount);
};

/**
 * function to display individual account status
*/
void Account::displayStatus( void ) const {

    Account::_displayTimestamp();
    std::cout   << " index:" << this->_accountIndex << ";"
                << "amount:" << this->_amount << ";"
                << "deposits:" << this->_nbDeposits << ";"
                << "withdrawals:" << this->_nbWithdrawals << "\n";
};
