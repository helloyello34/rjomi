#ifndef SUPERHERO_H
#define SUPERHERO_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class SuperHero
{
    public:
        SuperHero();
        SuperHero(string name, int age, char power);
        friend ostream& operator << (ostream& outs, const SuperHero& hero);
        friend istream& operator >> (istream& ins, SuperHero& hero);
    private:
        string name;
        int age;
        char power;
};

#endif // SUPERHERO_H
