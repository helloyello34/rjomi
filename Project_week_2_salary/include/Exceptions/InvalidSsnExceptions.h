#ifndef INVALIDSSNEXCEPTIONS_H
#define INVALIDSSNEXCEPTIONS_H

#include <iostream>
#include <string>

using namespace std;

class InvalidSsnExceptions
{
    public:
        InvalidSsnExceptions();
        InvalidSsnExceptions(string message);
        void print_message();
    private:
        string message;
};

#endif // INVALIDSSNEXCEPTIONS_H
