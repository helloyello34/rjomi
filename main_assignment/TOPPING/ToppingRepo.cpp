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
    file.open("Topping.txt", ios::app|ios::in|ios::out|ios::binary);
    if(file.is_open()) {
    newTop.write(file);
    //file.write((char*)(&newTop), sizeof(Topping));
    } else {
        cout << "File did not open" << endl;
    }

    file.close();
}

vector<Topping> ToppingRepo::get_toppings()
{
    fstream file;
    file.open("Topping.txt", ios::out|ios::in|ios::binary);
    vector<Topping>newTop;
    Topping temp;

    if(file.is_open()) {
        //temp.read(file);
        while(true) {
            if(file.eof()) {
                break;
            }
            //file.read((char*)(&temp), sizeof(Topping));
            temp.read(file);
            newTop.push_back(temp);
        }
        newTop.pop_back();

        file.close();
    } else {
        cout << "File did not open" << endl;
    }
    return newTop;
}
