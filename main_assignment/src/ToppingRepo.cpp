#include "ToppingRepo.h"

ToppingRepo::ToppingRepo()
{
    //ctor
}

ToppingRepo::~ToppingRepo()
{
    //dtor
}

void ToppingRepo::store_toppings(Topping& newTop)
{
    fstream file;
    file.open("Topping.txt", ios::app|ios::in);
    if(file.is_open()) {
        newTop.write(file);
    } else {
        cout << "File did not open" << endl;
    }

    file.close();
}

vector<Topping> ToppingRepo::get_toppings()
{
    fstream file;
    file.open("Topping.txt", ios::out|ios::in);
    vector<Topping>newTop;
    Topping temp;

    if(file.is_open()) {
        while(!(file.eof())) {
            temp.read(file);
            newTop.push_back(temp);
        }

        file.close();
    } else {
        cout << "File did not open" << endl;
    }
    return newTop;
}
