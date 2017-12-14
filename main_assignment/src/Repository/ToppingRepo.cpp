#include "ToppingRepo.h"

ToppingRepo::ToppingRepo()
{
    //ctor
}


void ToppingRepo::store_toppings(Topping& newTop)
{
    // Make ofstream of file for topping data
    ofstream file;
    file.open("binaries\\Menu\\toppings\\topping.dat", ios::app|ios::binary);

    // Cecks if file is open
    if(file.is_open())
    {
        newTop.write(file);
        file.close();
        //file.write((char*)(&newTop), sizeof(Topping));
    }
    else
    {
        throw UnableToOpenFileException();

    }

    file.close();
}

void ToppingRepo::retreve_toppings(vector<Topping>&toppings)
{
    ifstream file;
    file.open("binaries\\Menu\\toppings\\topping.dat", ios::binary);
    Topping temp;

    if(file.is_open())
    {
        //temp.read(file);
        Topping temp;
        toppings.clear();
        while(!(file.eof()))
        {
            temp.read(file);
            toppings.push_back(temp);
        }
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
    ofstream file;
    file.open("binaries\\Menu\\toppings\\topping.dat", ios::binary);

    if(file.is_open())
    {
        for(size_t i = 0; i < toppings.size(); i++)
        {
            toppings[i].write(file);
        }
    }
    else
    {
        throw UnableToOpenFileException();
    }
}
