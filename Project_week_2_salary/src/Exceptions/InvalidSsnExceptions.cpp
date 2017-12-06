#include "InvalidSsnExceptions.h"

InvalidSsnExceptions::InvalidSsnExceptions()
{
    //ctor
}

InvalidSsnExceptions::InvalidSsnExceptions(string message)
{
    this->message = message;
}

void InvalidSsnExceptions::print_message()
{
    cout << this->message << endl;
}

