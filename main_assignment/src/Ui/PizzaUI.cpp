#include "PizzaUI.h"

PizzaUI::PizzaUI()
{
    //ctor
}

void PizzaUI::add_pizza()
{
    Pizza newPizza;

    try {
        input_pizza(newPizza);
        pizza_service.add_pizza(newPizza);

    } catch (InvalidNameException) {
        cout << "Error: Invalid name" << endl;
    } catch (InvalidIdException) {
        cout << "Error: Input shoudl only hold integers! " << endl;
    } catch (UnableToOpenFileException) {
        cout << "Error: Could not write to file" << endl;
    }
}

void PizzaUI::view_pizza()
{
    try {
        this->pizzas.clear();
        pizza_service.retreve_pizza(this->pizzas);
        cout << "   Pizza " << endl;
        cout << "==================" << endl;
        for(size_t i = 0; i < this->pizzas.size(); i++) {
            cout << i+1 << ". " <<  this->pizzas[i] << endl;
            cout << "====================" << endl;
        }
    } catch (UnableToOpenFileException) {
        cout << "Error: Could not read from file" << endl;
    }
}

void PizzaUI::edit_pizza()
{
    view_pizza();

    cout << "Edit pizza" << endl;
    cout <<"===========================================" << endl;
    cout << "Which pizza would you like to edit" << endl;
    cout << "Insert '0' To exit" << endl;
    cout << "Id: ";
    size_t id;
    try {
        cin >> id;
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
        input_pizza(this->pizzas[id-1]);
        pizza_service.overwrite_pizza(this->pizzas);

    } catch (InvalidNameException) {
        cout << "Error: Invalid name" << endl;
    } catch (InvalidIdException) {
        cout << "Error: Input shoudl only hold integers! " << endl;
    } catch (UnableToOpenFileException) {
        cout << "Error: Could not write to file" << endl;
    }
}

void PizzaUI::delete_pizza()
{
    view_pizza();

    cout << "Delete pizza" << endl;
    cout <<"===========================================" << endl;
    cout << "Which pizza would you like to Pizza" << endl;
    cout << "Insert '0' To exit" << endl;
    cout << "Id: ";
    size_t id;
    try {
        cin >> id;
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
        this->pizzas.erase(this->pizzas.begin() + id-1);
        pizza_service.overwrite_pizza(this->pizzas);

    } catch (InvalidNameException) {
        cout << "Error: Invalid name" << endl;
    } catch (InvalidIdException) {
        cout << "Error: Input shoudl only hold integers! " << endl;
    } catch (UnableToOpenFileException) {
        cout << "Error: Could not write to file" << endl;
    }
}

void PizzaUI::input_pizza(Pizza& pizza)
{
    cin.ignore();
    cin >> pizza;
    pizza.clear_toppings();
    cout << "Topping"<< endl;
    cout << "=================" << endl;
    cout << "Press '0' to exit toppings selection" << endl;
    size_t id = 1;
    while(id != 0) {
        topping_ui.view_topping();
        cout << "Id: ";
        cin >> id;
        if(cin.fail()) {
            cin.clear();
            throw InvalidIdException();
        } else if (id == 0) {
            break;
        } else if(id < 1 || id > topping_ui.get_topping_size()) {
            cout << "Error: id is out of bound " << endl;
        } else {
            Topping temp = topping_ui.getTopping(id);
            pizza.add_topping(temp);
        }
    }
}

Pizza PizzaUI::get_pizza(size_t id)
{
    this->pizzas.clear();
    pizza_service.retreve_pizza(this->pizzas);
    return this->pizzas[id-1];
}

size_t PizzaUI::get_vector_size()
{
    this->pizzas.clear();
    pizza_service.retreve_pizza(this->pizzas);
    return this->pizzas.size();
}
