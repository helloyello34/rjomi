#include "PizzaUI.h"

PizzaUI::PizzaUI()
{
    //ctor
}

void PizzaUI::add_pizza()
{
    // Construct a new pizza
    Pizza newPizza;

    try {
        cout << "   Add Pizza" << endl;
        // Call to a function that writes to the pizza
        input_pizza(newPizza);
        // Sends the pizza to the Service class
        pizza_service.add_pizza(newPizza);

    } catch (InvalidNameException) {
        cout << "  Error: Invalid name" << endl;
    } catch (InvalidIdException) {
        cout << "  Error: Input shoudl only hold integers! " << endl;
    } catch (UnableToOpenFileException) {
        cout << "  Error: Could not write to file" << endl;
    }
}

void PizzaUI::view_pizza()
{
    try {
        // Clear the vector of pizzas
        this->pizzas.clear();
        // Reads data from the file to the vector
        pizza_service.retreve_pizza(this->pizzas);
        cout << " ==================" << endl;
        for(size_t i = 0; i < this->pizzas.size(); i++) {
            // Print out the pizza at the index i
            cout << "  " << i+1 << ". " <<  this->pizzas[i] << endl;
            cout << " ====================" << endl;
        }
    } catch (UnableToOpenFileException) {
        cout << "  Error: Could not read from file" << endl;
    }
}

void PizzaUI::edit_pizza()
{
    cout << "   Edit Pizza" << endl;
    // Print out the avaliable pizzas
    view_pizza();
    cout << "  Which pizza would you like to edit?" << endl;
    cout << "  Insert '0' To exit" << endl;
    cout << "  Id: ";
    size_t id;
    try {
        // Input the index of the pizza you would like to change
        cin >> id;
        // Error check
        if(cin.fail()) {
            cin.clear();
            throw InvalidIdException();
        }
        if(id == 0) {
            return ;
        }
        if(id < 1 || id > this->pizzas.size())  {
            throw InvalidIdException();
        }
        system("CLS");
        cout << "   Edit Pizza" << endl;
        // Write into the pizza at that index
        input_pizza(this->pizzas[id-1]);
        // Send the vector to the Service class to overwrite the data
        pizza_service.overwrite_pizza(this->pizzas);

    } catch (InvalidNameException) {
        // If there was thrown an invalid name exception
        cout << "  Error: Invalid name" << endl;
    } catch (InvalidIdException) {
        // If there was thrown an invalid id exception
        cout << "  Error: Input shoudl only hold integers! " << endl;
    } catch (UnableToOpenFileException) {
        // If repository class could not open file
        cout << "  Error: Could not write to file" << endl;
    }
}

void PizzaUI::delete_pizza()
{
    cout << "   Delete pizza" << endl;
    // View avaliable pizzas
    view_pizza();

    cout << "  Which pizza would you like to delete" << endl;
    cout << "  Insert '0' To exit" << endl;
    cout << "  Id: ";
    size_t id;
    try {
        // Input of the index of the pizza to be deleted
        cin >> id;
        cout << endl << "  ";
        // Error check
        if(cin.fail()) {
            cin.clear();
            throw InvalidIdException();
        }
        if(id == 0) {
            return ;
        }
        if(id < 1 || id > this->pizzas.size())  {
            throw InvalidIdException();
        }
        // Erase the pizza at the given index
        this->pizzas.erase(this->pizzas.begin() + id-1);
        // Overwrite the data in the file with pizzas
        pizza_service.overwrite_pizza(this->pizzas);

    } catch (InvalidNameException) {
        cout << "  Error: Invalid name" << endl;
    } catch (InvalidIdException) {
        cout << "  Error: Input shoudl only hold integers! " << endl;
    } catch (UnableToOpenFileException) {
        cout << "  Error: Could not write to file" << endl;
    }
}

void PizzaUI::input_pizza(Pizza& pizza)
{
    string name;
    cin.ignore();
    cout << " =======================" << endl;
    // Input name for pizza
    cin >> pizza;
    cout << " -------------------------" << endl;
    // Clear the toppings if there were any on the pizza
    pizza.clear_toppings();
    // give the variable name the name of the pizza
    name = pizza.get_name();
    size_t id = 1;
    while(id != 0) {
        system("CLS");
        cout << "  Name: " << name << endl;
        cout << "  =================" << endl;
        // List up avaliable toppings
        topping_ui.view_topping();
        cout << "   Press '0' to exit" << endl;
        cout << "   Id: ";
        // Input the index of topping you would like to add
        cin >> id;
        // Error check on the index
        if(cin.fail()) {
            cin.clear();
            throw InvalidIdException();
        } else if (id == 0) {
            cout << endl << "  ";
            break;
        } else if(id < 1 || id > topping_ui.get_topping_size()) {
            cout << "   Error: id is out of bound " << endl;
        } else {
            // create a temp topping to add to the pizza
            Topping temp = topping_ui.getTopping(id);
            // Add the topping to the pizza
            pizza.add_topping(temp);
        }
    }
}

Pizza PizzaUI::get_pizza(size_t id)
{
    // Returns the pizza at the index id
    this->pizzas.clear();
    pizza_service.retreve_pizza(this->pizzas);
    return this->pizzas[id-1];
}

size_t PizzaUI::get_vector_size()
{
    // Returns the number of pizzas on the menu
    this->pizzas.clear();
    pizza_service.retreve_pizza(this->pizzas);
    return this->pizzas.size();
}
