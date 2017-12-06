#include "PizzaRepository.h"

PizzaRepository::PizzaRepository()
{
    //ctor
}

void PizzaRepository::write(const Pizza& pizza)
{
    cout << "Writing to file" << endl;
    ofstream file;
    file.open("Pizza.dat", ios::binary|ios::app);

    if(file.is_open()){
        //cout << sizeof(Pizza) << endl;
        //file.write((char*)(&pizza), sizeof(Pizza));
        pizza.write(file);
        file.close();
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
        pizzas.clear();
        while(!file.eof()){
//cout << "readnig pizza" << endl;
            temp_pizza.read(file);
            pizzas.push_back(temp_pizza);

        }
        //cout << "while end" << endl;
        file.close();
        pizzas.pop_back();
    } else {
        cout << "File could not open! " << endl;
    }
}
