#include "PizzaRepository.h"

PizzaRepository::PizzaRepository()
{
    //ctor
}

void PizzaRepository::write(const Pizza& pizza)
{
    ofstream file;
    file.open("Pizza.dat", ios::binary|ios::app);

    if(file.is_open()){
        cout << sizeof(Pizza) << endl;
        file.write((char*)(&pizza), sizeof(Pizza));
    } else {
        cout << "File could not open! " << endl;
    }
}

void PizzaRepository::read(vector<Pizza>&pizzas)
{
    ifstream file;
    file.open("Pizza.dat", ios::binary);

    if(file.is_open()){
        Pizza temp_pizza;
        while(!(file.eof())){
            cout << sizeof(Pizza) << endl;
            file.read((char*)(&temp_pizza), sizeof(Pizza));
            pizzas.push_back(temp_pizza);
            //cout << "readnig pizza" << endl;
        }
        //pizzas.pop_back();
    } else {
        cout << "File could not open! " << endl;
    }
}
