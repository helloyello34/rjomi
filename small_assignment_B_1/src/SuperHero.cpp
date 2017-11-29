#include "SuperHero.h"

SuperHero::SuperHero()
{
    this->name = "";
    this->age = 0;
    this->power = 'n';
}

SuperHero::SuperHero(string name, int age, char power)
{
    this->name = name;
    this->age = age;
    this->power = power;
}

ostream& operator << (ostream& outs, const SuperHero& hero)
{
    outs << hero.name;
    outs << " (" << hero.age << "): ";
    switch(hero.power){
        case 'f': outs << "Flying" << endl; break;
        case 'g': outs << "Giant" << endl; break;
        case 'h': outs << "Hacker" << endl; break;
        case 'n': outs << "None" << endl; break;
        default : outs << "Weakling" << endl; break;
    }

    return outs;
}

istream& operator >> (istream& ins, SuperHero& hero)
{
    cout << "Name: ";
    ins >> hero.name;
    cout << "Age: ";
    ins >> hero.age;
    cout << "Power (f, g, h, n): ";
    ins >> hero.power;
    cout << endl;
    return ins;
}
