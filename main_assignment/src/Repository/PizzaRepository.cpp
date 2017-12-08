#include "PizzaRepository.h"

PizzaRepository::PizzaRepository()
{
    //ctor
}

void PizzaRepository::add_pizza(Pizza& newPizza)
{

    ofstream file;
    file.open("binaries\\Menu\\pizza.dat", ios::binary|ios::app);

    if(file.is_open()) {
        newPizza.write(file);
//        file.write((char*)(&newPizza), sizeof(Pizza));
        file.close();
    } else {
        throw UnableToOpenFileException();
    }

}

void PizzaRepository::retreve_pizza(vector<Pizza>&pizzas)
{

    ifstream file;
    file.open("binaries\\Menu\\pizza.dat", ios::binary);

    if(file.is_open()) {
        Pizza temp;
        while(!(file.eof())) {
            temp.read(file);
//            file.read((char*)(&temp), sizeof(Pizza));
            pizzas.push_back(temp);
        }
        pizzas.pop_back();
        file.close();
    } else {
        throw UnableToOpenFileException();
    }

}

void PizzaRepository::overwrite_pizza(vector<Pizza>&pizzas)
{

    ofstream file;
    file.open("binaries\\Menu\\pizza.dat", ios::binary);

    if(file.is_open()) {
        for(size_t i = 0; i < pizzas.size(); i++) {
            pizzas[i].write(file);
        }
        file.close();
    } else {
        throw UnableToOpenFileException();
    }

}
