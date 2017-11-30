#ifndef TOPPING_H
<<<<<<< HEAD
#define TOPPING_H

#include <iostream>

=======
#define TOPPING_H

#include <iostream>

>>>>>>> bd4fe9044ed99aab036e96921a5fa56b5df0651d
using namespace std;

class Topping
{
    public:
        Topping();
        virtual ~Topping();
        friend ostream& operator << (ostream& out, const Topping& topping);
        friend istream& operator >> (istream& in, Topping& topping);

    private:
        char name[32];
        double price;
};

#endif // TOPPING_H
