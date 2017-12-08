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
    ofstream file;
    file.open("binaries\\Menu\\toppings\\topping.dat", ios::app|ios::binary);
    if(file.is_open()) {
    newTop.write(file);
    file.close();
    //file.write((char*)(&newTop), sizeof(Topping));
    } else {
        cout << "File did not open" << endl;

    }

    file.close();
}

void ToppingRepo::retreve_toppings(vector<Topping>&toppings)
{
    ifstream file;
    file.open("binaries\\Menu\\toppings\\topping.dat", ios::binary);
    Topping temp;

    if(file.is_open()) {
        //temp.read(file);
        Topping temp;
        toppings.clear();
        while(!(file.eof())) {
            temp.read(file);
            toppings.push_back(temp);
        }
        toppings.pop_back();
        file.close();
    } else {
        cout << "File did not open" << endl;
    }
}

void ToppingRepo::overwrite_toppings(vector<Topping>&toppings)
{
    ofstream file;
    file.open("binaries\\Menu\\toppings\\topping.dat", ios::binary);

    if(file.is_open()){
        for(size_t i = 0; i < toppings.size(); i++) {
            toppings[i].write(file);
        }
    } else {
        cout << "File could not open!" << endl;
    }
}
