#ifndef INVALIDMONTHEXCEPTIONS_H
#define INVALIDMONTHEXCEPTIONS_H

#include <iostream>
#include <string>

using namespace std;

class InvalidMonthExceptions
{
    public:
        InvalidMonthExceptions();
        InvalidMonthExceptions(string message);
        void print_message();
    private:
        string message;
};

#endif // INVALIDMONTHEXCEPTIONS_H
