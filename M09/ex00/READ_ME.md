## Class Architecture in the program

### Class : FileHandler
    - a base class
    - exceptions will handle using std::exception
    - should not be able to create instances with copy constructor or assignment operator
#### Data :
    | name              | type              |
    |-------------------|-------------------|
    | file_name         | string            |
    | file descriptor   | input stream      |
    | data container    | run time          |

#### Methods :
    - readData()        : read all the file line by line
        input       : file descriptor and data container
        output      : data container filled with data
        excpetions  :
                * no file existing with the given file name
                * file can be empty
                * access restrictions
    - readFile()        : public API / enable user to read data from a file
        input       : file name and data container
        output      : data container filled with data
        exceptions  :
                * file handling will manage using readData() method

### Class : Validate
    - a base class
    - all exceptions will handle using CustomeExecption
    - should not be able to create instances with copy constructor or assignment operator
#### Data :
    | name              | type              |
    |-------------------|-------------------|
    | header format     | string /regex     |
    | record format     | string /regex     |
    | release date      | year_month_day    |
    | amount limit      | double            |
    | excptions         | custome exception |

#### Methods :
    - setHeaderFormat()     : public API enabling user to set the Header
        input       : string which is the exact header
        output      : void / update the class data
        exception   :
            * header can not be null

    - isValidDate()         : public API enabling user to varify a date with in the context
        input       : std::chrono::year_month_day
        output      : boolean state true/false
        expection   :
            * not a valid calander date
            * older date than the released date

    - isValidRecord()       : public API to check the record format
        input       : string
        output      : boolen state true/false
        execption   :
            * can not be null
            * incorrect format

    - isValidAmount         : public API to validate the value provided
        input       : value to be check type long double
        output      : boolen state true/false
        exception   :
            * can not be a negative value
            * can not exceed the amount limit

### Class : CustomeExecption
    - a base class extended from std::exception
    - all the methods will be noexecpt
    - should not be able to create instances with copy constructor or assignment operator
#### Data :
    | name              | type              |
    |-------------------|-------------------|
    | message           | string            |
#### Methods :
    - const char* what()    : over-ride to meet the standards
        input       : handle using constructors
        output      : a c-string
        exception   :
            * no execption hence this the ultimate bottom of an exception

### Class : BitcoinExchange
    - child class inherit from FileHandler and Validate
    - all exceptions will handle using CustomeExecption
    - should not be able to create instances with copy constructor or assignment operator
#### Data :
    | name              | type              |
    |-------------------|-------------------|
    | data storage      | std map           |
#### Methods :
    - getPrice()        : public API to inquire a price on a certain day
        input       : data value in string
        output      : price on the date or most recent historic date
        exceptions  :
            * incorrect format
            * incorrect date

    - getPriceAll()     : public API to inqure price with a file
        input       : file name need to read
        output      : display all the records on std output
        exceptions  :
            * file refereed by the name is not existing
            * access restrictions
            * file can be corrupted
            * incorrect data
            * incorrect header

    - displayRecord()   : will diplay a record or an Error message
        input       : string need to display
        output      : formatted string on the std output
        exceptions  :
            * unxecpeted error occuring

