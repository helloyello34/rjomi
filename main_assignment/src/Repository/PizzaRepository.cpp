#include "PizzaRepository.h"

PizzaRepository::PizzaRepository()
{
    //ctor
}

void PizzaRepository::add_pizza(Pizza& newPizza)
{
    // Makes ofstream to write data to the pizza data file
    ofstream file;
    file.open("binaries\\Menu\\pizza.dat", ios::binary|ios::app);

    // Checks if the file opened
    if(file.is_open())
    {
        // Writes the new pizza to the file
        newPizza.write(file);

        // Close the file
        file.close();
    }
    else
    {
        throw UnableToOpenFileException();
    }

}

void PizzaRepository::retreve_pizza(vector<Pizza>&pizzas)
{
    // Makes ifstream to read data from the pizza data file
    ifstream file;
    file.open("binaries\\Menu\\pizza.dat", ios::binary);

    // Checks if the file is open
    if(file.is_open())
    {
        // Makes a temp pizza
        Pizza temp;

        while(!(file.eof()))
        {
            // Reads data to the temp pizza
            temp.read(file);

            // Sets the pizza to the vector
            pizzas.push_back(temp);
        }
        // Deletes the last instance of pizza
        pizzas.pop_back();

        // Close file
        file.close();
    }
    else
    {
        throw UnableToOpenFileException();
    }

}

void PizzaRepository::overwrite_pizza(vector<Pizza>&pizzas)
{
    // Makes ofstream to write data to the pizza data file
    ofstream file;
    file.open("binaries\\Menu\\pizza.dat", ios::binary);

    // Checks if the file is open
    if(file.is_open())
    {
        for(size_t i = 0; i < pizzas.size(); i++)
        {
            // Writes pizza to the file
            pizzas[i].write(file);
        }

        // Close the file
        file.close();
    }
    else
    {
        throw UnableToOpenFileException();
    }

}
