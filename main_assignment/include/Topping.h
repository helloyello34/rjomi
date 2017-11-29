#ifndef TOPPING_H
#define TOPPING_H


class Topping
{
    public:
        Topping();
        virtual ~Topping();
    private:
        char name[32];
        double price;
};

#endif // TOPPING_H
