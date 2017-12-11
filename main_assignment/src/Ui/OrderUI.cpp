#include "OrderUI.h"

OrderUI::OrderUI()
{
    /// blyat
}

void OrderUI::salesmanUI(Location& staff_location)
{
    char choice = '\0';
    while(choice != '5') {


        cout << "Order: " << endl;
        cout << " +------------------+" << endl;
        cout << " |1. Show orders    |" << endl;
        cout << " |2. Make orders    |" << endl;
        cout << " |3. look for order |" << endl;
        cout << " |4. Change orders  |" << endl;
        cout << " |5. Back           |" << endl;
        cout << " +------------------+" << endl;
        cout << " (1-4): ";
        cin >> choice;

        if(choice == '1') {
            system("CLS");
            show_order(staff_location);
            system("pause");
            system("CLS");
        } else if(choice == '2') {
            system("CLS");
            make_order(staff_location);
            system("pause");
            system("CLS");
        } else if (choice == '3') {
            system("CLS");
            look_for_order(staff_location);
            system("pause");
            system("CLS");
        }
    }
}

void OrderUI::make_order(Location& staff_location)
{
    char choice;
    Order order;
    order.set_location(staff_location);
    cout << "Please enter a phone number for this order" << endl;
    cout <<" Phone (7 digits): ";
    char phone[8];
    try {
        cin.ignore();
        cin.getline(phone, 8);
        if(cin.fail()) {
            cin.clear();
            throw InvalidPhoneNumberException();
        }
        if(strlen(phone) != 7) {
            throw InvalidPhoneNumberException();
        }
        for(size_t i = 0; i < 7; i++) {
            if(!isdigit(phone[i])){
                throw InvalidPhoneNumberException();
            }
        }
        order.add_phone_number(phone);

    while(choice != '5') {

        cout << order << endl;
        cout << "What would you like to add to the Order?" << endl;
        cout << "1. Pizza " << endl;
        cout << "2. Sides " << endl;
        cout << "3. Drinks " << endl;
        cout << "4. Finish order" << endl;


        try {
            cin >> choice;

            if(cin.fail()) {
                cin.clear();
                throw InvalidIdException();
            }
            switch (choice) {
            case '1':
                add_pizza(order);
                break;
            case '2':
                add_sides(order);
                break;
            case '3':
                add_drink(order);
                break;
            case '4':
                store_order(order);
                return;
            default:
                break;

            }



        } catch (InvalidIdException) {
            cout << "Error: Invalid id" << endl;
        }
    }
    } catch (InvalidPhoneNumberException) {
        cout << "Error: Invalid Phone number" << endl;
    }
}

void OrderUI::add_pizza(Order& order)
{
    Pizza pizza;
    pizza_ui.view_pizza();
    size_t id;
    cout << "Which side would you like to add? " << endl;
    cout << "Id: ";
    try {
        cin >> id;
        if(cin.fail()) {
            cin.clear();
            throw InvalidIdException();
        }
        if (id == 0) {
            return ;
        }
        if(id < 0|| id > pizza_ui.get_vector_size()) {
            throw InvalidIdException();
        }
        pizza = pizza_ui.get_pizza(id);
        order.add_pizza(pizza);
    } catch (InvalidIdException) {
        cout << "Error: Invalid Id" << endl;
    }
}

void OrderUI::add_sides(Order& order)
{
    Sides side;
    sides_ui.view_sides();
    size_t id;
    cout << "Which side would you like to add? " << endl;
    cout << "Id: ";
    try {
        cin >> id;
        if(cin.fail()) {
            cin.clear();
            throw InvalidIdException();
        }
        if (id == 0) {
            return ;
        }
        if(id < 0|| id > sides_ui.get_vector_size()) {
            throw InvalidIdException();
        }
        side = sides_ui.get_side(id);
        order.add_sides(side);
    } catch (InvalidIdException) {
        cout << "Error: Invalid Id" << endl;
    }
}

void OrderUI::add_drink(Order& order)
{
    Drink drink;
    drink_ui.view_drinks();
    size_t id;
    cout << "Which side would you like to add? " << endl;
    cout << "Id: ";
    try {
        cin >> id;
        if(cin.fail()) {
            cin.clear();
            throw InvalidIdException();
        }
        if (id == 0) {
            return ;
        }
        if(id < 0|| id > drink_ui.get_vector_size()) {
            throw InvalidIdException();
        }
        drink = drink_ui.get_drink(id);
        order.add_drink(drink);
    } catch (InvalidIdException) {
        cout << "Error: Invalid Id" << endl;
    }
}

void OrderUI::erase_other_locations(Location& location)
{
    vector<Order>newOrder;
    for(size_t i = 0; i < this->orders.size(); i++) {
        if(location.get_name() == this->orders[i].get_location() ) {
            newOrder.push_back(this->orders[i]);
        } else {
            continue;
        }
    }
    this->orders = newOrder;
}

void OrderUI::show_order(Location& location)
{
    /// Show orders that have yet been carried out
    try {
        this->orders.clear();
        order_service.fill_vector(this->orders);
        //cout << "Order fill vector done!" << endl;
        erase_other_locations(location);

        for(size_t i = 0; i < this->orders.size(); i++) {

                cout << "Order" << endl;
                cout << "=====================" << endl;
                cout  << this->orders[i] << endl;

        }
        system("pause");
    } catch (UnableToOpenFileException) {
        cout << "Error: could not open file! " << endl;
    }
}

void OrderUI::look_for_order(Location& location)
{
    this->orders.clear();
    order_service.fill_vector(this->orders);

    erase_other_locations(location);

    char search_phone[8];

    try {
        cin.ignore();
        cin.getline(search_phone, 8);
        if(cin.fail()) {
            cin.clear();
            throw InvalidPhoneNumberException();
        }
        if(strlen(search_phone) != 7) {
            throw InvalidPhoneNumberException();
        }
        for(size_t i = 0; i < 7; i++) {
            if(!isdigit(search_phone[i])){
                throw InvalidPhoneNumberException();
            }
        }

        for(size_t i = 0; i < this->orders.size(); i++) {
            if(search_phone == this->orders[i].get_phone()) {
                    cout << "Order Id. " << i+1 << endl;
                    cout << "=====================" << endl;
                    cout  << this->orders[i] << endl;

            }
        }
    } catch (InvalidPhoneNumberException) {
        cout << "Invalid Phone nubmer" << endl;
    }
}

void OrderUI::store_order(Order& order)
{
    try {
        order_service.store_order(order);
    } catch (UnableToOpenFileException) {
        cout << "Error: unable to open file" << endl;
    }
}
