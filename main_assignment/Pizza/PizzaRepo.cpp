#include "PizzaRepo.h"


PizzaRepo::PizzaRepo()
{
    //ctor
}

PizzaRepo::~PizzaRepo()
{
    //dtor
}



void PizzaRepo::write_pizza(const Pizza& pizza)
{
    fstream file;
    file.open("Pizza_Menu.txt", ios::binary|ios::out|ios::app);

    if(file.is_open()) {
        pizza.write(file);
        cout << pizza << endl;
        //cout << "PizzaSize: " << sizeof(Pizza) << endl;
        ///file.write((char*)(&pizza), sizeof(Pizza));
        file.close();
    } else {
        cout << "File did not open" << endl;
    }
    //pizza.write(file);

    //file.write((char*)(&pizza), sizeof(Pizza));


}


void PizzaRepo::read_pizza(vector<Pizza>&vector_of_pizzas)
{
    fstream file;
    file.open("Pizza_Menu.txt", ios::binary|ios::in);
    //vector<Pizza>vector_of_pizzas;
    Pizza temp_pizza;

    //int Pizza_count;

    //file.read((char*)(&Pizza_count), sizeof(Pizza_count));

    if(file.is_open()) {


            while(!(file.eof())) {
                temp_pizza.read(file);
                //cout << temp_pizza << endl;
                ///cout << "PizzaSize: " << sizeof(Pizza) << endl;
                ///file.read((char*)(&temp_pizza), sizeof(Pizza));
                ///cout << "Reading from file. " << endl;
                vector_of_pizzas.push_back(temp_pizza);
                //cout << "Reading to vector" << endl;
            }
            vector_of_pizzas.pop_back();

            file.close();



////        file.read((char*)(&temp_pizza), sizeof(Pizza));
////        cout << "binary read pizza" << endl;
////        cout << temp_pizza << endl;
////        vector_of_pizzas.push_back(temp_pizza);

        /*
        while(file.tellg() != file.seekg(0,file.end)){

        temp_pizza.read(file);
        vector_of_pizzas.push_back(temp_pizza);

        }
        file.close();


        */
        /*


        while(!file.eof()){
            file.read((char*)(&temp_pizza), sizeof(Pizza));
            vector_of_pizzas.push_back(temp_pizza);
        }

        file.close();

        */


    } else {
        cout << "File could not open!" << endl;
    }


    //return vector_of_pizzas;
}
