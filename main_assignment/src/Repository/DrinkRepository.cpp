#include "DrinkRepository.h"

DrinkRepository::DrinkRepository()
{
    /// Default constructor for DrinkRepository
}

void DrinkRepository::store_drink(Drink& drink)
{
    // Open file to write to
    ofstream file;
    file.open("binaries\\Menu\\drink.dat", ios::binary|ios::app);

    // Check if the file is open
    if(file.is_open())
    {

        drink.write(file);

        // Close file
        file.close();
    }
    else
    {
        throw UnableToOpenFileException();
    }
}

void DrinkRepository::retreive_drink(vector<Drink>&drinks)
{
    // Open file to read from
    ifstream file;
    file.open("binaries\\Menu\\drink.dat", ios::binary);

    if(file.is_open())
    {

        // Clear the vector
        drinks.clear();

        // Create a temporary drink to read to
        Drink drink;

        // While it is not end of file run
        while(!(file.eof()))
        {

            //Read to the temporary drink from file and store it in a vector
            drink.read(file);
            drinks.push_back(drink);
        }
        drinks.pop_back();

        // close the file
        file.close();
    }
    else
    {
        throw UnableToOpenFileException();
    }
}

void DrinkRepository::overwrite_drink(vector<Drink>&drinks)
{
    // Overwrites drink file
    ofstream file;
    file.open("binaries\\Menu\\drink.dat", ios::binary);

    if(file.is_open())
    {

        for(unsigned int i = 0; i < drinks.size(); i++)
        {
            drinks[i].write(file);
        }

        file.close();
    }
    else
    {
        cout << "'Drink.dat' file could not open! " << endl;
    }
}
