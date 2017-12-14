#include "ToppingRepo.h"

ToppingRepo::ToppingRepo()
{
    //ctor
}


void ToppingRepo::store_toppings(Topping& newTop)
{
    // Make ofstream to write of file for topping data
    ofstream file;
    file.open("binaries\\Menu\\toppings\\topping.dat", ios::app|ios::binary);

    // Cecks if file is open
    if(file.is_open())
    {
        // Call write in topping class to write the topping to file
        newTop.write(file);

        // Close the file
        file.close();
    }
    else
    {
        throw UnableToOpenFileException();

    }
}

void ToppingRepo::retreve_toppings(vector<Topping>&toppings)
{
    // Make ifstream to read data file for topping data
    ifstream file;
    file.open("binaries\\Menu\\toppings\\topping.dat", ios::binary);
    Topping temp;

    if(file.is_open())
    {
        //temp.read(file);
        Topping temp;

        // Clear the vector
        toppings.clear();

        while(!(file.eof()))
        {
            // Read to the temp topping
            temp.read(file);
            // Pushes it to the vector
            toppings.push_back(temp);
        }
        // Deletes the last topping in the vector
        toppings.pop_back();
        file.close();
    }
    else
    {
        throw UnableToOpenFileException();
    }
}

void ToppingRepo::overwrite_toppings(vector<Topping>&toppings)
{
    // Makes ofstream to write data to the topping data file
    ofstream file;
    file.open("binaries\\Menu\\toppings\\topping.dat", ios::binary);

    // Checks if the file opened
    if(file.is_open())
    {
        for(size_t i = 0; i < toppings.size(); i++)
        {
            // Writes the topping to the file
            toppings[i].write(file);
        }
    }
    else
    {
        throw UnableToOpenFileException();
    }
}
