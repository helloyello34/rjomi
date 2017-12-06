#include "InvalidYearExceptions.h"

InvalidYearExceptions::InvalidYearExceptions()
{
    //ctor
}

InvalidYearExceptions::InvalidYearExceptions(string message)
{
    this->message = message;
}

void InvalidYearExceptions::print_message()
{
    cout << this->message << endl;
}
