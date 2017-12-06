#ifndef INVALIDYEAREXCEPTIONS_H
#define INVALIDYEAREXCEPTIONS_H

#include <iostream>
#include <string>

using namespace std;

class InvalidYearExceptions
{
    public:
        InvalidYearExceptions();
        InvalidYearExceptions(string message);
        void print_message();
    private:
        string message;
};

#endif // INVALIDYEAREXCEPTIONS_H
