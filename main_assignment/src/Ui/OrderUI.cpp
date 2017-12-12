#include "OrderUI.h"

OrderUI::OrderUI()
{
    /// blyat
}

void OrderUI::salesmanUI(Location& staff_location)
{
    char choice = '\0';
    while(choice != '5')
    {


        cout << "Salesman: " << endl;
        cout << " +------------------+" << endl;
        cout << " |1. Show orders    |" << endl;
        cout << " |2. Make orders    |" << endl;
        cout << " |3. look for order |" << endl;
        cout << " |4. Change orders  |" << endl;
        cout << " |5. Back           |" << endl;
        cout << " +------------------+" << endl;
        cout << " (1-5): ";
        cin >> choice;

        if(choice == '1')
        {
            system("CLS");
            show_order(staff_location);
            system("pause");
            system("CLS");
        }
        else if(choice == '2')
        {
            system("CLS");
            make_order(staff_location);
            system("pause");
            system("CLS");
        }
        else if (choice == '3')
        {
            system("CLS");
            look_for_order(staff_location);
            system("pause");
            system("CLS");
        }
        else if (choice == '4')
        {
            system("CLS");
            find_order_comment(staff_location);
//            change_status(staff_location);
            system("pause");
            system("CLS");
        }
        else
        {
            system("CLS");
            bakerUI(staff_location);
//            cout << "Invalid Input" << endl;
            system("pause");
            system("CLS");
        }
    }
    system("CLS");
}

void OrderUI::bakerUI(Location& staff_location)
{
    char choice = '\0';
    while(choice != '5')
    {


        cout << "baker: " << endl;
        cout << " +------------------+" << endl;
        cout << " |1. Show orders    |" << endl;
        cout << " |2. Make orders    |" << endl;
        cout << " |3. look for order |" << endl;
        cout << " |4. Change orders  |" << endl;
        cout << " |5. Back           |" << endl;
        cout << " +------------------+" << endl;
        cout << " (1-5): ";
        cin >> choice;

        if(choice == '1')
        {
            system("CLS");
            show_order(staff_location);
            system("pause");
            system("CLS");
        }
        else if(choice == '2')
        {
            system("CLS");
            make_order(staff_location);
            system("pause");
            system("CLS");
        }
        else if (choice == '3')
        {
            system("CLS");
            look_for_order(staff_location);
            system("pause");
            system("CLS");

        }
        else if (choice == '4')
        {
            system("CLS");
            find_order_status(staff_location);
            system("pause");
            system("CLS");
        }
        else
        {
            system("CLS");
            cashierUI(staff_location);
//            cout << "Invalid Input" << endl;
            system("pause");
            system("CLS");
        }
    }
}

void OrderUI::cashierUI(Location& staff_location)
{
    char choice = '\0';
    while(choice != '5')
    {


        cout << "cashier: " << endl;
        cout << " +------------------+" << endl;
        cout << " |1. Show orders    |" << endl;
        cout << " |2. Make orders    |" << endl;
        cout << " |3. look for order |" << endl;
        cout << " |4. Change orders  |" << endl;
        cout << " |5. Back           |" << endl;
        cout << " +------------------+" << endl;
        cout << " (1-5): ";
        cin >> choice;

        if(choice == '1')
        {
            system("CLS");
            show_order(staff_location);
            system("pause");
            system("CLS");
        }
        else if(choice == '2')
        {
            system("CLS");
            make_order(staff_location);
            system("pause");
            system("CLS");
        }
        else if (choice == '3')
        {
            system("CLS");
            look_for_order(staff_location);
            system("pause");
            system("CLS");

        }
        else if (choice == '4')
        {
            system("CLS");
            find_order_paid(staff_location);
            system("pause");
            system("CLS");
        }
        else
        {
            system("CLS");
            cout << "Invalid Input" << endl;
            system("pause");
            system("CLS");
        }
    }
}

void OrderUI::make_order(Location& staff_location)
{
    this->orders.clear();
    char choise;
    Order order;
    order.set_location(staff_location);
    cout << "Please enter a phone number for this order" << endl;
    cout <<" Phone (7 digits): ";
    char phone[8];
    try
    {
        cin.ignore();
        cin.getline(phone, 8);
        if(cin.fail())
        {
            cin.clear();
            throw InvalidPhoneNumberException();
        }
        if(strlen(phone) != 7)
        {
            throw InvalidPhoneNumberException();
        }
        for(size_t i = 0; i < 7; i++)
        {
            if(!isdigit(phone[i]))
            {
                throw InvalidPhoneNumberException();
            }
        }
        order.add_phone_number(phone);

        while(choise != '5')
        {

            cout << order << endl;
            cout << "What would you like to add to the Order?" << endl;
            cout << "1. Pizza " << endl;
            cout << "2. Sides " << endl;
            cout << "3. Drinks " << endl;
            cout << "4. Add comment" << endl;
            cout << "5. Finish order" << endl;


            try
            {
                cin >> choise;

                if(cin.fail())
                {
                    cin.clear();
                    throw InvalidIdException();
                }
                switch (choise)
                {
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
                    comment_order(order);
                    break;
                case '5':
                    store_order(order);
                    return;
                default:
                    break;

                }



            }
            catch (InvalidIdException)
            {
                cout << "Error: Invalid id" << endl;
            }
        }
    }
    catch (InvalidPhoneNumberException)
    {
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
    try
    {
        cin >> id;
        if(cin.fail())
        {
            cin.clear();
            throw InvalidIdException();
        }
        if (id == 0)
        {
            return ;
        }
        if(id < 0|| id > pizza_ui.get_vector_size())
        {
            throw InvalidIdException();
        }
        pizza = pizza_ui.get_pizza(id);
        order.add_pizza(pizza);
    }
    catch (InvalidIdException)
    {
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
    try
    {
        cin >> id;
        if(cin.fail())
        {
            cin.clear();
            throw InvalidIdException();
        }
        if (id == 0)
        {
            return ;
        }
        if(id < 0|| id > sides_ui.get_vector_size())
        {
            throw InvalidIdException();
        }
        side = sides_ui.get_side(id);
        order.add_sides(side);
    }
    catch (InvalidIdException)
    {
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
    try
    {
        cin >> id;
        if(cin.fail())
        {
            cin.clear();
            throw InvalidIdException();
        }
        if (id == 0)
        {
            return ;
        }
        if(id < 0|| id > drink_ui.get_vector_size())
        {
            throw InvalidIdException();
        }
        drink = drink_ui.get_drink(id);
        order.add_drink(drink);
    }
    catch (InvalidIdException)
    {
        cout << "Error: Invalid Id" << endl;
    }
}

void OrderUI::erase_other_locations(Location& location)
{
    vector<Order>newOrder;
    for(size_t i = 0; i < this->orders.size(); i++)
    {
        if(location.get_name() == this->orders[i].get_location() )
        {
            newOrder.push_back(this->orders[i]);
        }
        else
        {
            continue;
        }
    }
    this->orders = newOrder;
}

void OrderUI::show_order(Location& location)
{
    /// Show orders that have yet been carried out
    try
    {
        this->orders.clear();
        order_service.fill_vector(this->orders);
        //cout << "Order fill vector done!" << endl;
        erase_other_locations(location);

        for(size_t i = 0; i < this->orders.size(); i++)
        {

            cout << "Order id. " << i+1 << endl;
            cout << "=====================" << endl;
            cout  << this->orders[i] << endl;

        }
    }
    catch (UnableToOpenFileException)
    {
        cout << "Error: could not open file! " << endl;
    }
}

void OrderUI::look_for_order(Location& location)
{
    this->orders.clear();
    order_service.fill_vector(this->orders);

    erase_other_locations(location);

    char search_phone[8];

    try
    {
        cin.ignore();
        cin.getline(search_phone, 8);
        if(cin.fail())
        {
            cin.clear();
            throw InvalidPhoneNumberException();
        }
        if(strlen(search_phone) != 7)
        {
            throw InvalidPhoneNumberException();
        }
        for(size_t i = 0; i < 7; i++)
        {
            if(!isdigit(search_phone[i]))
            {
                throw InvalidPhoneNumberException();
            }
        }

        vector<Order>phoneNumberOrder;

        for(size_t i = 0; i < this->orders.size(); i++)
        {
            if(search_phone == this->orders[i].get_phone())
            {
                cout << "Order Id. " << i+1 << endl;
                cout << "=====================" << endl;
                cout  << this->orders[i] << endl;
            }
        }
    }
    catch (InvalidPhoneNumberException)
    {
        cout << "Invalid Phone nubmer" << endl;
    }
}

void OrderUI::look_for_order(Location& location, size_t &id)
{
    this->orders.clear();
    order_service.fill_vector(this->orders);

    erase_other_locations(location);

    char search_phone[8];

    try
    {
        cout << "Phone number: ";
        cin.ignore();
        cin.getline(search_phone, 8);
        if(cin.fail())
        {
            cin.clear();
            throw InvalidPhoneNumberException();
        }
        if(strlen(search_phone) != 7)
        {
            throw InvalidPhoneNumberException();
        }
        for(size_t i = 0; i < 7; i++)
        {
            if(!isdigit(search_phone[i]))
            {
                throw InvalidPhoneNumberException();
            }
        }

        for(size_t i = 0; i < this->orders.size(); i++)
        {
            if(search_phone == this->orders[i].get_phone())
            {
                cout << "Order." << endl;
                cout << "=====================" << endl;
                cout  << this->orders[i] << endl;
                id = i;
                break;
            }
            else
            {
                id = -1;
            }
        }
    }
    catch (InvalidPhoneNumberException)
    {
        cout << "Invalid Phone nubmer" << endl;
    }
}

void OrderUI::store_order(Order& order)
{
    try
    {
        order_service.store_order(order);
    }
    catch (UnableToOpenFileException)
    {
        cout << "Error: unable to open file" << endl;
    }
}

void OrderUI::change_status(Order& order)
{

    this->orders.clear();
    order_service.fill_vector(this->orders);
    size_t i = 0;
    for(; i < this->orders.size(); i++)
    {
        if(order == this->orders[i])
        {
            break;
        }
    }
    try
    {
        cout << "Status: ";
        switch(orders[i].get_status())
        {
        case RECEVED:
            cout << "Order receved" << endl;
            break;
        case PREP:
            cout << "In preperation" << endl;
            break;
        case OVEN:
            cout << "In the oven" << endl;
            break;
        case READY:
            cout << "Ready" << endl;
            break;

        }
        cout << "What would you like to status it as?" << endl;
        int status;
        switch(orders[i].get_status())
        {
        case RECEVED:
            cout << "1. In preperation" << endl;
            cout << "2. In the oven" << endl;
            cout << "3. Ready" << endl;
            cout << "0. abort" << endl;
            cout << "id: ";
            try
            {
                cin >> status;
                if(cin.fail())
                {
                    cin.clear();
                    throw InvalidIdException();
                }
                if(status == 0)
                {
                    return;
                }
                if (status < 0)
                {
                    throw InvalidIdException();
                }
                if(status > 3)
                {
                    throw InvalidIdException();
                }
                switch(status)
                {
                case 1:
                    orders[i].set_status(PREP);
                    break;
                case 2:
                    orders[i].set_status(OVEN);
                    break;
                case 3:
                    orders[i].set_status(READY);
                    break;
                }
            }
            catch (InvalidIdException)
            {
                cout << "Invalid id" << endl;
            }
            break;
        case PREP:
            cout << "1. In the oven" << endl;
            cout << "2. Ready" << endl;
            cout << "0. abort" << endl;
            cout << "id: ";
            try
            {
                cin >> status;
                if(cin.fail())
                {
                    cin.clear();
                    throw InvalidIdException();
                }
                if(status == 0)
                {
                    return;
                }
                if (status < 0)
                {
                    throw InvalidIdException();
                }
                if(status > 2)
                {
                    throw InvalidIdException();
                }
                switch(status)
                {
                case 1:
                    orders[i].set_status(OVEN);
                    break;
                case 2:
                    orders[i].set_status(READY);
                    break;
                }
            }
            catch (InvalidIdException)
            {
                cout << "Invalid id" << endl;
            }
            break;
        case OVEN:
            cout << "1. Ready" << endl;
            cout << "0. abort" << endl;
            cout << "id: ";
            try
            {
                cin >> status;
                if(cin.fail())
                {
                    cin.clear();
                    throw InvalidIdException();
                }
                if(status == 0)
                {
                    return;
                }
                if (status < 0)
                {
                    throw InvalidIdException();
                }
                if(status > 1)
                {
                    throw InvalidIdException();
                }
                switch(status)
                {
                case 1:
                    orders[i].set_status(READY);
                    break;
                }
            }
            catch (InvalidIdException)
            {
                cout << "Invalid id" << endl;
            }
            break;
        case READY:
            if(orders[i].get_paid())
            {
                cout << "Should not be here" << endl;
            }
            else
            {
                cout << "Just needs to be charged" << endl;
            }
        }

        try
        {
            if(this->orders[i].is_order_receved())
        {
            order_service.store_old_order(this->orders[i]);
            this->orders.erase(this->orders.begin() + (i));
        }
            order_service.overwrite_orders(this->orders);
        }
        catch (UnableToOpenFileException)
        {
            cout << "Unable to overwrite file" << endl;
        }
    }
    catch (InvalidIdException)
    {
        cout << "Error: Invalid id" << endl;
    }





    /*
    look_for_order(location);
    cout << this->orders.size() << endl;
    Order temp;
    if(this->orders.size() > 0)
    {
        cin >> this->orders[0];
    //        cout << "done cin" << endl;
        temp = this->orders[0];
        this->orders.clear();
        order_service.fill_vector(this->orders);
        for(size_t i = 0; i < this->orders.size(); i++)
        {
            if(temp == this->orders[i])
            {
                this->orders[i] = temp;
                break;
            }
        }
        try
        {
            order_service.overwrite_orders(this->orders);
        }
        catch (UnableToOpenFileException)
        {
            cout << "Unable to open file!" << endl;
        }


    }
    else
    {
        cout << "There is no order by this phone number!" << endl;
    }


    */


}

void OrderUI::comment_order(Order& order)
{

    char comment[255];
    try
    {
        cin.ignore();
        cin.getline(comment, 256);
        if(cin.fail())
        {
            cin.clear();
            throw InvalidCommentException();
        }
        order.set_comment(comment);
    }
    catch (InvalidCommentException)
    {
        cout << "Invalid Comment!" << endl;
    }
}

void OrderUI::set_order_paid(Order& order)
{
    order.set_paid(true);
}

void OrderUI::find_order_status(Location& location)
{
    show_order(location);
    cout << "What order would you like to change status? " << endl;
    cout << "Id: ";
    size_t id;
    try
    {
        cin >> id;
        if(cin.fail())
        {
            cin.clear();
            throw InvalidIdException();
        }
        if(id == 0)
        {
            return ;
        }
        if (id < 0 || id > this->orders.size())
        {
            throw InvalidIdException();
        }
        change_status(this->orders[id-1]);
    }
    catch (InvalidIdException)
    {
        cout << "Invalid id!" << endl;
    }
}

void OrderUI::find_order_comment(Location& location)
{
    show_order(location);
    cout << "What order would you like to change comment? " << endl;
    cout << "Id: ";
    size_t id;
    try
    {
        cin >> id;
        if(cin.fail())
        {
            cin.clear();
            throw InvalidIdException();
        }
        if(id == 0)
        {
            return ;
        }
        if (id < 0 || id > this->orders.size())
        {
            throw InvalidIdException();
        }
        comment_order(this->orders[id-1]);
        order_service.overwrite_orders(this->orders);
    }
    catch (InvalidIdException)
    {
        cout << "Invalid id!" << endl;
    }
}

void OrderUI::find_order_paid(Location& location)
{
    show_order(location);
    cout << "What order would you like to change comment? " << endl;
    cout << "Id: ";
    size_t id;
    try
    {
        cin >> id;
        if(cin.fail())
        {
            cin.clear();
            throw InvalidIdException();
        }
        if(id == 0)
        {
            return ;
        }
        if (id < 0 || id > this->orders.size())
        {
            throw InvalidIdException();
        }
        set_order_paid(this->orders[id-1]);
        if(this->orders[id-1].is_order_receved())
        {
            order_service.store_old_order(this->orders[id-1]);
            this->orders.erase(this->orders.begin() + (id-1));
        }
        order_service.overwrite_orders(this->orders);
    }
    catch (InvalidIdException)
    {
        cout << "Invalid id!" << endl;
    }
}
