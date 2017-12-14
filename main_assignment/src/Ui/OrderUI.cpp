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


        cout << "   Salesman " << endl;
        cout << " ====================" << endl;
        cout << "  1. Show orders     " << endl;
        cout << "  2. Make order      " << endl;
        cout << "  3. look for order  " << endl;
        cout << "  4. Change comment  " << endl;
        cout << "  5. Back            " << endl;
        cout << " ====================" << endl;
        cout << " (1-5): ";
        cin >> choice;

        if(choice == '1')
        {
            ///Show orders
            system("CLS");
            show_order(staff_location);
            cout << endl << "  ";
            system("pause");
            system("CLS");
        }
        else if(choice == '2')
        {
            ///Make order
            system("CLS");
            make_order(staff_location);
            cout << endl << "  ";
            system("pause");
            system("CLS");
        }
        else if (choice == '3')
        {
            ///Look for order
            system("CLS");
            look_for_order();
            cout << endl << "  ";
            system("pause");
            system("CLS");
        }
        else if (choice == '4')
        {
            ///Change comment
            system("CLS");
            find_order_comment(staff_location);
            cout << endl << "  ";
            system("pause");
            system("CLS");
        }
        else if (choice == '5')
        {
            system ("CLS");
            return;
        }
        else
        {
            system("CLS");
            cout << "Invalid Input" << endl;
            system("pause");
            system("CLS");
        }
    }
    system("CLS");
}


void OrderUI::managerUI()
{
    char choice = '\0';
    while(choice != '5')
    {

        system("CLS");
        cout << "   Orders " << endl;
        cout << " =========================" << endl;
        cout << "  1. Show orders          " << endl;
        cout << "  2. Show old orders      " << endl;
        cout << "  3. Look for order       " << endl;
        cout << "  4. Back                 " << endl;
        cout << " =========================" << endl;
        cout << " (1-5): ";
        cin >> choice;

        if(choice == '1')
        {
            ///Show current orders
            system("CLS");
            show_order();
            cout << endl << "  ";
            system("pause");
            system("CLS");
        }
        else if(choice == '2')
        {
            ///Show old orders
            system("CLS");
            show_old_orders();
            cout << endl << "  ";
            system("pause");
            system("CLS");
        }
        else if (choice == '3')
        {
            ///Look for order
            system("CLS");
            look_for_order();
            cout << endl << "  ";
            system("pause");
            system("CLS");

        }
        else if( choice == '4')
        {
            ///Return
            return ;
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
    char choice;
    Order order;
    order.set_location(staff_location);
    cout << "  Please enter a phone number for this order" << endl;
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
        cout << "  Phone added" << endl;
        while(choice != '5')
        {

            cout << order << endl;
            cout << "  What would you like to add to the Order?" << endl;
            cout << "  1. Pizza " << endl;
            cout << "  2. Sides " << endl;
            cout << "  3. Drinks " << endl;
            cout << "  4. Add comment" << endl;
            cout << "  5. Finish order" << endl;

            try
            {
                cin >> choice;

                if(cin.fail())
                {
                    cin.clear();
                    throw InvalidIdException();
                }
                switch (choice)
                {
                case '1':
                    try
                    {
                        add_pizza(order);
                        break;
                    }
                    catch(UnableToOpenFileException)
                    {
                        cout << "  Error: could not open file! " << endl;
                    }
                case '2':
                    try
                    {
                        add_sides(order);
                        break;
                    }
                    catch(UnableToOpenFileException)
                    {
                        cout << "  Error: could not open file! " << endl;
                    }
                case '3':
                    try
                    {
                        add_drink(order);
                        break;
                    }
                    catch(UnableToOpenFileException)
                    {
                        cout << "  Error: could not open file! " << endl;
                    }
                case '4':
                    try
                    {
                        comment_order(order);
                        break;
                    }
                    catch(UnableToOpenFileException)
                    {
                        cout << "  Error: could not open file! " << endl;
                    }
                case '5':
                    try
                    {
                        store_order(order);
                        break;
                    }
                    catch(UnableToOpenFileException)
                    {
                        cout << "  Error: could not open file! " << endl;
                    }
                default:
                    break;

                }



            }
            catch (InvalidIdException)
            {
                cout << "  Error: Invalid id" << endl;
            }
        }
    }
    catch (InvalidPhoneNumberException)
    {
        cout <<"  Error: Invalid phone number!" << endl;
    }
}

void OrderUI::add_pizza(Order& order)
{
    ///Create a pizza and prints out available types
    Pizza pizza;
    pizza_ui.view_pizza();
    size_t id;
    cout << "  Which pizza would you like to add? " << endl;
    cout << "  Id: ";
    try
    {
        ///Read which pizza you want
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
        ///Throws an error if the ID is not valid
        if(id < 0|| id > pizza_ui.get_vector_size())
        {
            throw InvalidIdException();
        }
        pizza = pizza_ui.get_pizza(id);
        order.add_pizza(pizza);
    }
    catch (InvalidIdException)
    {
        cout << "  Error: Invalid Id" << endl;
    }
}

void OrderUI::add_sides(Order& order)
{
    ///Create a side and print out available sides
    Sides side;
    sides_ui.view_sides();
    size_t id;
    cout << "  Which side would you like to add? " << endl;
    cout << "  Id: ";
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
        ///Checks if the ID is valid
        if(id < 0|| id > sides_ui.get_vector_size())
        {
            throw InvalidIdException();
        }
        side = sides_ui.get_side(id);
        order.add_sides(side);
    }
    catch (InvalidIdException)
    {
        cout << "  Error: Invalid Id" << endl;
    }
}

void OrderUI::add_drink(Order& order)
{
    ///Create a drink and print out available drinks
    Drink drink;
    drink_ui.view_drinks();
    size_t id;
    cout << "  Which drink would you like to add? " << endl;
    cout << "  Id: ";
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
        ///Checks if the ID is valid
        if(id < 0|| id > drink_ui.get_vector_size())
        {
            throw InvalidIdException();
        }
        drink = drink_ui.get_drink(id);
        order.add_drink(drink);
    }
    catch (InvalidIdException)
    {
        cout << "  Error: Invalid Id" << endl;
    }
}

///Gets the orders that are on this location
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
    /// Show orders that have yet to be carried out on this location
    if(orders.size() == 0)
    {
        cout << "  No active orders" << endl;
        return;
    }
    try
    {
        this->orders.clear();
        order_service.fill_vector(this->orders);
        //cout << "Order fill vector done!" << endl;
        erase_other_locations(location);

        for(size_t i = 0; i < this->orders.size(); i++)
        {

            cout << "   Order: " << i+1 << endl;
            cout << " =====================" << endl;
            cout << this->orders[i] << endl;

        }
    }
    catch (UnableToOpenFileException)
    {
        cout << "  Error: could not open file! " << endl;
    }
}

void OrderUI::show_order()
{
    ///Show orders on all locations
    try
    {

        this->orders.clear();
        order_service.fill_vector(this->orders);
        if(orders.size() == 0)
        {
            cout << "  No active orders" << endl;
            return;
        }
        //cout << "Order fill vector done!" << endl;
        cout << "   Show Order" << endl;
        cout << " ====================" << endl;

        for(size_t i = 0; i < this->orders.size(); i++)
        {

            cout << "    Order id. " << i+1 << endl;
            cout << "  =====================" << endl;
            cout << this->orders[i] << endl;

        }
        this->orders.clear();
    }
    catch (UnableToOpenFileException)
    {
        cout << "  Error: could not open file! " << endl;
    }
}

void OrderUI::show_old_orders()
{
    /// Show old orders
    try
    {
        this->orders.clear();
        order_service.fill_old_vector(this->orders);
        //cout << "Order fill vector done!" << endl;

        for(size_t i = 0; i < this->orders.size(); i++)
        {

            cout << "   Order " << i+1 << endl;
            cout << " =====================" << endl;
            cout  << this->orders[i] << endl;

        }
        this->orders.clear();
    }
    catch (UnableToOpenFileException)
    {
        cout << "  Error: could not open file! " << endl;
    }
}

void OrderUI::look_for_order()
{
    ///Look for orders by phone number
    try
    {
        this->orders.clear();
        order_service.fill_vector(this->orders);

        //    erase_other_locations(location);

        if(orders.size() == 0)
        {
            cout << " No active orders" << endl;
            return;
        }

        char search_phone[8];

        cout << "   Search for order" << endl;
        cout << " ===========================" << endl;
        cout << "  Enter corresponding phone number" << endl;
        cout << "  (Number): ";

        ///Check if phone number is legit

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
            ///Print out order
            system("CLS");
            cout << "   Search for order" << endl;
            cout << " ===========================" << endl;

            for(size_t i = 0; i < this->orders.size(); i++)
            {
                if(search_phone == this->orders[i].get_phone())
                {
                    cout << "  Order Id. " << i+1 << endl;
                    cout << "  =====================" << endl;
                    cout  << this->orders[i] << endl;
                }
            }
        }
        catch (InvalidPhoneNumberException)
        {
            cout << "  Invalid Phone nubmer" << endl;
        }
    }
    catch (UnableToOpenFileException)
    {
        cout << "  Error: could not open file! " << endl;
    }
}

void OrderUI::store_order(Order& order)
{
    ///Store order in file
    try
    {
        order_service.store_order(order);
    }
    catch (UnableToOpenFileException)
    {
        cout << "  Error: unable to open file" << endl;
    }
}

void OrderUI::change_status(Order& order)
{
    ///Set the order status
    try
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
            ///Get the current order status
            cout << "  Status: ";
            switch(orders[i].get_status())
            {
            case RECEIVED:
                cout << "  Order received" << endl;
                break;
            case PREP:
                cout << "  In preparation" << endl;
                break;
            case OVEN:
                cout << "  In the oven" << endl;
                break;
            case READY:
                cout <<   "Ready" << endl;
                break;

            }
            cout << "  What would you like to set the status as?" << endl;
            int status;
            switch(orders[i].get_status())
            {
            case RECEIVED:
                cout << "  1. In preparation" << endl;
                cout << "  2. In the oven" << endl;
                cout << "  3. Ready" << endl;
                cout << "  0. abort" << endl;
                cout << "  id: ";
                try
                {
                    ///Error catching
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
                    cout << "  Invalid id" << endl;
                }
                break;
            case PREP:
                cout << "  1. In the oven" << endl;
                cout << "  2. Ready" << endl;
                cout << "  0. abort" << endl;
                cout << "  id: ";
                ///Error Catching
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
                    cout << "  Invalid id" << endl;
                }
                break;
            case OVEN:
                cout << "  1. Ready" << endl;
                cout << "  0. abort" << endl;
                cout << "  id: ";
                ///Error catching
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
                    cout << "  Invalid id" << endl;
                }
                break;
            case READY:
                if(orders[i].get_paid())
                {
                    cout << "  Should not be here" << endl;
                }
                else
                {
                    cout << "  Just needs to be charged" << endl;
                }
            }

            try
            {
                ///move this order to old orders
                if(this->orders[i].is_order_received())
                {
                    order_service.store_old_order(this->orders[i]);
                    this->orders.erase(this->orders.begin() + (i));
                }
                order_service.overwrite_orders(this->orders);
            }
            catch (UnableToOpenFileException)
            {
                cout << "  Unable to overwrite file" << endl;
            }
        }
        catch (InvalidIdException)
        {
            cout << "  Error: Invalid id" << endl;
        }
    }
    catch (UnableToOpenFileException)
    {
        cout << "  Error: could not open file! " << endl;
    }

}

void OrderUI::comment_order(Order& order)
{
    ///add a comment to an order
    char comment[255];
    try
    {
        cin.ignore();
        cout << "  Comment: ";
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
        cout << "  Invalid Comment!" << endl;
    }
}

///Set order as paid
void OrderUI::set_order_paid(Order& order)
{
    order.set_paid(true);
}

void OrderUI::find_order_status(Location& location)
{
    ///Get the order on this location to change their status
    try
    {
        orders.clear();
        order_service.fill_vector(orders);
        erase_other_locations(location);
        if(orders.size() == 0)
        {
            cout << "  No active orders" << endl;
            return;
        }


        cout << "   Change status" << endl;
        cout << " =================================================" << endl;
        show_order(location);
        cout << "  What order would you like to change status? " << endl;
        cout << "  Id: ";
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
            system("CLS");
            cout << "   Change status" << endl;
            cout << " =================================================" << endl;
            cout << this->orders[id-1];
            change_status(this->orders[id-1]);
        }
        catch (InvalidIdException)
        {
            cout << "  Invalid id!" << endl;
        }
    }

    catch (UnableToOpenFileException)
    {
        cout << "  Could not open file" << endl;
    }
}

void OrderUI::find_order_comment(Location& location)
{
    ///change comments on orders on the specified location
    try
    {
        order_service.fill_vector(orders);
        erase_other_locations(location);
        if(orders.size() == 0)
        {
            cout << "  No active orders" << endl;
            return;
        }
        show_order(location);
        cout << "  For what order would you like to change the comment? " << endl;
        cout << "  Id: ";
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
            system("CLS");
            cout << this->orders[id-1];
            comment_order(this->orders[id-1]);
            order_service.overwrite_orders(this->orders);
        }
        catch (InvalidIdException)
        {
            cout << "  Invalid id!" << endl;
        }
    }
    catch(UnableToOpenFileException)
    {
        cout << "  Could not open file" << endl;
    }
}


void OrderUI::find_order_paid(Location& location)
{
    ///set order as paid
    try
    {
        order_service.fill_vector(orders);
        erase_other_locations(location);
        if(orders.size() == 0)
        {
            cout << "  No orders in progress" << endl;
            return;
        }
        show_order(location);
        cout << "  What order would you like to charge for? " << endl;
        cout << "  Id: ";
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
            if(this->orders[id-1].is_order_received())
            {
                order_service.store_old_order(this->orders[id-1]);
                this->orders.erase(this->orders.begin() + (id-1));
            }
            order_service.overwrite_orders(this->orders);
        }
        catch (InvalidIdException)
        {
            cout << "  Invalid id!" << endl;
        }
    }
    catch (UnableToOpenFileException)
    {
        cout << "  Could not open file" << endl;
    }
}
