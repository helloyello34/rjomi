#include "ToppingUI.h"

ToppingUI::ToppingUI()
{

}

/// Add new topping to menu
void ToppingUI::add_topping()
{
    // Create a new instance of topping
    Topping newTop;
    try
    {
        cin.ignore();
        cout << "   Add Topping" << endl;
        // Write into the new topping
        cin >> newTop;
        cout << endl << "  ";
        // Send the new topping to the service which sends it to the repository
        topping_service.add_topping(newTop);
    }
    catch (InvalidNameException)
    {
        cout << "Error: Invalid name" << endl;
    }
    catch (InvalidPriceException)
    {
        cout << "Error: Invalid price" << endl;
    }
    catch (UnableToOpenFileException)
    {
        cout << "Error: Unable to store the new topping! " << endl;
    }
}

/// Delete toppings from menu
void ToppingUI::delete_topping()
{
    cout << "  Delete toppings" << endl;
    cout << " =========================" << endl;
    // View all avaliable toppings
    view_topping();
    unsigned int id;
    cout << "  Which topping would you like to delete? " << endl;
    cout << "  Press '0' To exit" << endl;
    cout << "  Id: ";
    try
    {
        // Input the index which will be deleted
        cin >> id;
        system("CLS");
        // Error check
        if(cin.fail())
        {
            throw InvalidIdException();
        }
        if(id == 0)
        {
            return;
        }
        if(id > this->toppings.size())
        {
            throw InvalidIdException();
        }
        // if the index is valid you erase the topping in that index
        this->toppings.erase(this->toppings.begin()+(id-1));
        // and ovewrite the data on the file
        topping_service.overwrite_topping(this->toppings);
        cout << "  Topping Deleted" << endl;



    }
    catch (InvalidIdException)
    {
        cout << "  Error: Invalid id!" << endl;
    }
}

/// View all avaliable toppings
void ToppingUI::view_topping()
{
    // Reads the data from the file to the vector
    fill_topping_vector();
    // Checks if the vector has read anything from the file
    if(this->toppings.size() > 0)
    {
        // if there was some data in the file then the list will be printed to the screen
        cout << "   Toppings" << endl;
        cout << "  ---------------------------" << endl;
        for(size_t i = 0; i < this->toppings.size(); i++)
        {
            cout << "   " << i+1 << ". " << this->toppings[i] << endl;
            cout << "  ---------------------------" << endl;
        }
    }
}

/// Edit/change abaliable toppings
void ToppingUI::edit_topping()
{
    cout << "  Edit toppings" << endl;
    cout << " ========================" << endl;
    // view avaliable toppings
    view_topping();
    cout << " ========================" << endl;
    unsigned int id;
    cout << "  Which topping would you like to edit? " << endl;
    cout << "  '0' To exit" << endl;
    cout << "  Id: ";
    try
    {
        // Input index to be changed
        cin >> id;
        system("CLS");
        // Error check
        if(cin.fail())
        {
            throw InvalidIdException();
        }
        if(id == 0)
        {
            return;
        }
        if(id > this->toppings.size())
        {
            throw InvalidIdException();
        }
        cin.ignore();
        cout << "   Edit Topping" << endl;
        // Write into the topping at the right index
        cin >> this->toppings[id-1];
        // ovewrite the toppings data
        topping_service.overwrite_topping(this->toppings);


    }
    catch (InvalidIdException)
    {
        cout << "  Error: Invalid id!" << endl;
    }
    catch (InvalidNameException)
    {
        cout << "  Error: Invalid name" << endl;
    }
    catch (InvalidPriceException)
    {
        cout << "  Error: Invalid price" << endl;
    }
}

void ToppingUI::fill_topping_vector()
{
    // Clear the vector
    this->toppings.clear();
    try
    {
        // Read into the toppings vector from the file
        this->toppings = topping_service.get_topping_vector();
    }
    catch (UnableToOpenFileException)
    {
        cout << "Error: Unable to open file!" << endl;
    }
}

Topping ToppingUI::getTopping(size_t id)
{
    // call to fill the vector
    fill_topping_vector();
    // returns the topping at the index id
    return this->toppings[id-1];
}

size_t ToppingUI::get_topping_size()
{
    // call to flil the vector
    fill_topping_vector();
    // Return the size of the vector (Number of toppings)
    return this->toppings.size();
}
