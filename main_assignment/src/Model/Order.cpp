#include "Order.h"

using namespace std;

Order::Order()
{
<<<<<<< HEAD
    // Initializes default order
    this->orderStatus = RECEVED;
=======
    this->orderStatus = RECEIVED;
>>>>>>> 73d17f20318fa0e5bb0169c84fc2b9dc302a6699
    this->phone[0] = '\0';
    this->paid = false;
    this->price = 0;
    this->comment[0] = '\0';
}

void Order::add_phone_number(char* number)
{
    // Adds phone number
    strcpy(this->phone, number);
}

void Order::add_pizza(Pizza& pizza)
{
    // Adds pizza to order
    this->pizzas.push_back(pizza);
    this->price += pizza.get_price();
}

void Order::add_drink(Drink& drink)
{
    // Adds drink to order
    this->drinks.push_back(drink);
    this->price += drink.get_price();
}

void Order::add_sides(Sides& side)
{
    // Adds side to order
    this->sides.push_back(side);
    this->price += side.get_price();
}

void Order::set_location(Location& location)
{
    // Sets current location
    this->location = location;
}

void Order::set_comment(char* comment)
{
    // Sets comment
    strcpy(this->comment, comment);
}

void Order::set_status(status orderstatus)
{
    // Sets status of order
    this->orderStatus = orderstatus;
}

void Order::read(ifstream& file)
{
    // reads order from file
    this->location.read(file);

    file.read(this->phone, sizeof(this->phone));
    file.read(this->comment, sizeof(this->comment));
    file.read((char*)(&this->orderStatus), sizeof(this->orderStatus));
    file.read((char*)(&this->paid), sizeof(this->paid));
    file.read((char*)(&this->price), sizeof(this->price));

    size_t pizza_num;
    size_t drinks_num;
    size_t sides_num;

    file.read((char*)(&pizza_num), sizeof(pizza_num));
    // Cap for amount of pizzas in order
    if (pizza_num > 100)
    {
        return;
    }

    file.read((char*)(&drinks_num), sizeof(drinks_num));
    // Cap for amount of drinks in order
    if (drinks_num > 100)
    {
        return;
    }

    file.read((char*)(&sides_num), sizeof(sides_num));
    // Cap for amount of sides in order
    if (sides_num > 100)
    {
        return;
    }

    // clears and fills vector with order
    this->pizzas.clear();
    Pizza tempPizza;
    for(size_t i = 0; i < pizza_num; i++)
    {
        tempPizza.read(file);
        this->pizzas.push_back(tempPizza);
    }

    this->drinks.clear();
    Drink tempDrink;
    for(size_t i = 0; i < drinks_num; i++)
    {
        tempDrink.read(file);
        this->drinks.push_back(tempDrink);
    }

    this->sides.clear();
    Sides tempSide;
    for(size_t i = 0; i < sides_num; i++)
    {
        tempSide.read(file);
        this->sides.push_back(tempSide);
    }
}

void Order::write(ofstream& file)
{
    // Write to file
    this->location.write(file);

    file.write(this->phone, sizeof(this->phone));
    file.write(this->comment, sizeof(this->comment));
    file.write((char*)(&this->orderStatus), sizeof(this->orderStatus));
    file.write((char*)(&this->paid), sizeof(this->paid));
    file.write((char*)(&this->price), sizeof(this->price));

    // sets counter size
    size_t pizza_num = this->pizzas.size();
    size_t drinks_num = this->drinks.size();
    size_t sides_num = this->sides.size();

    file.write((char*)(&pizza_num), sizeof(pizza_num));
    file.write((char*)(&drinks_num), sizeof(drinks_num));
    file.write((char*)(&sides_num), sizeof(sides_num));
    // Writes Pizzas into file
    for(size_t i = 0; i < pizza_num; i++)
    {
        this->pizzas[i].write(file);
    }
    // Writes drinks into file
    for(size_t i = 0; i < drinks_num; i++)
    {
        this->drinks[i].write(file);
    }
    // Writes sides into file
    for(size_t i = 0; i < sides_num; i++)
    {
        this->sides[i].write(file);
    }
}

void Order::set_paid(bool paid)
{
    // Sets if pizza has been paid
    this->paid = paid;
}

string Order::get_location()
{
    // Returns location
    return this->location.get_name();
}

string Order::get_phone()
{
    // Returns phone number
    return (string)this->phone;
}

string Order::get_comment()
{
    // Returns comment
    return (string)this->comment;
}

status Order::get_status()
{
    // Returns status of order
    return this->orderStatus;
}

bool Order::get_paid()
{
    // Returns status of whether order is paid or not
    return this->paid;
}

ostream& operator << (ostream& out, const Order& order)
{
    // Prints location and phone number
    out << "   Location: " << order.location;
    out << "   Phone number: " << order.phone << endl << endl;

    // If there is a pizza in the vector
    if(order.pizzas.size() > 0)
    {
        // Print pizzas
        out << "  ===== Pizzas =====" << endl;
        for(size_t i = 0; i < order.pizzas.size(); i++)
        {
           out << order.pizzas[i] << endl;
        }
    }

    // If there is a drink in the vector
    if(order.drinks.size() > 0)
    {
        //Prints drinks
        cout << "  ===== Drinks =====" << endl;
        for(size_t i = 0; i < order.drinks.size(); i++)
        {
            out << order.drinks[i] << endl;
        }
    }

    // If there are sides in the vector
    if(order.sides.size() > 0)
    {
        // Print sides
        out << "  ===== Side dish =====" << endl;
        for(size_t i = 0; i < order.sides.size(); i++)
        {
//        out << "  Name: " << order.sides[i].get_name() << endl;
//        out << "  Price: " << order.sides[i].get_price() << endl;
            out << order.sides[i] << endl;
        }
    }
    // Print total
    cout << "   =======================" << endl;
    cout << "    Total price: ";
    out << order.price << endl << endl;

    cout << "  ==========================" << endl;

    // Prints status
    out << "   Status: ";
    switch(order.orderStatus)
    {
    case RECEIVED:
        cout << "Order recieved" << endl;
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
    // Prints whether order is paid
    out << "   Paid: ";
    if(order.paid)
    {
        out << "Yes" << endl;
    }
    else
    {
        out << "No" << endl;
    }
    // If there is a comment print it
    if(strlen(order.comment) > 0)
    {
        out << "   Comment: ";
        out << order.comment << endl;
    }


    cout << " =============================" << endl;

    return out;
}

<<<<<<< HEAD
bool Order::is_order_receved()
=======




istream& operator >> (istream& in, Order& order)
{

    cout << "Would you like to add comment or change status? " << endl;
    cout << "2. change status" << endl;
    cout << "0. abort " << endl;
    char choice;

    try
    {
        in >> choice;
        if(choice == '2')
        {
            cout << "Status is: ";
            switch(order.orderStatus)
            {
            case RECEIVED:
                cout << "Order received" << endl;
                break;
            case PREP:
                cout << "In preparation" << endl;
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
            switch(order.orderStatus)
            {
            case RECEIVED:
                cout << "1. In preperation" << endl;
                cout << "2. In the oven" << endl;
                cout << "3. Ready" << endl;
                cout << "0. abort" << endl;
                cout << "id: ";
                try
                {
                    in >> status;
                    if(in.fail())
                    {
                        in.clear();
                        throw InvalidIdException();
                    }
                    if(status == 0)
                    {
                        return in;
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
                        order.orderStatus = PREP;
                        break;
                    case 2:
                        order.orderStatus = OVEN;
                        break;
                    case 3:
                        order.orderStatus = READY;
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
                    in >> status;
                    if(in.fail())
                    {
                        in.clear();
                        throw InvalidIdException();
                    }
                    if(status == 0)
                    {
                        return in;
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
                        order.orderStatus = OVEN;
                        break;
                    case 2:
                        order.orderStatus = READY;
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
                    in >> status;
                    if(in.fail())
                    {
                        in.clear();
                        throw InvalidIdException();
                    }
                    if(status == 0)
                    {
                        return in;
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
                        order.orderStatus = READY;
                        break;
                    }
                }
                catch (InvalidIdException)
                {
                    cout << "Invalid id" << endl;
                }
                break;
            case READY:
                if(order.paid)
                {
                    cout << "Should not be here" << endl;
                }
                else
                {
                    cout << "Just needs to be charged" << endl;
                }
            }
        }
        else
        {
            throw InvalidIdException();
        }
    }
    catch (InvalidIdException)
    {
        cout << "Error: Invalid id" << endl;
    }

    return in;
    /*

    cout << "===== Writing new order =====" << endl;
    for(unsigned int i = 0; i < order.pizzas.size(); i++){
        in >> order.pizzas[i];
    }
    for(unsigned int i = 0; i < order.drinks.size(); i++){
        in >> order.drinks[i];
    }
    for(unsigned int i = 0; i < order.sides.size(); i++){
        in >> order.sides[i];
    }

    */



}
bool Order::is_order_received()
>>>>>>> 73d17f20318fa0e5bb0169c84fc2b9dc302a6699
{
    // Checks if order is paid or not
    if(this->paid)
    {
        if(this->orderStatus == READY)
        {
            return true;
        }
    }
    return false;
}

bool operator == (Order& order1, Order& order2)
{
    // Checks if two orders are by the same number in the same location
    if(order1.get_location() == order2.get_location())
    {
        if(order1.get_phone() == order2.get_phone())
        {
            return true;
        }
    }
    return false;
}
