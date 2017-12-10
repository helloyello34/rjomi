#include "Order.h"

using namespace std;

Order::Order()
{

}

void Order::add_phone_number(char* number)
{
    strcpy(this->phone, number);
}

void Order::add_pizza(Pizza& pizza)
{
    this->pizzas.push_back(pizza);
    //this->price += pizza.get_price();
}

void Order::add_drink(Drink& drink)
{
    this->drinks.push_back(drink);
}

void Order::add_sides(Sides& side)
{
    this->sides.push_back(side);
}

void Order::set_location(Location& location)
{
    this->location = location;
}

void Order::read(ifstream& file)
{
    this->location.read(file);

    file.read(this->phone, sizeof(this->phone));

    size_t pizza_num;

    size_t drinks_num;

    size_t sides_num;

    file.read((char*)(&pizza_num), sizeof(pizza_num));
    //cout << pizza_num << endl;
    if (pizza_num > 100) {
        return;
    }

    file.read((char*)(&drinks_num), sizeof(drinks_num));
    //cout << drinks_num << endl;
    if (drinks_num > 100) {
        return;
    }

    file.read((char*)(&sides_num), sizeof(sides_num));
    //cout << sides_num << endl;
    if (sides_num > 100) {
        return;
    }


    this->pizzas.clear();
    Pizza tempPizza;
    for(size_t i = 0; i < pizza_num; i++) {
        tempPizza.read(file);
        this->pizzas.push_back(tempPizza);
    }

    this->drinks.clear();
    Drink tempDrink;
    for(size_t i = 0; i < drinks_num; i++) {
        tempDrink.read(file);
        this->drinks.push_back(tempDrink);
    }


    this->sides.clear();
    Sides tempSide;
    for(size_t i = 0; i < sides_num; i++) {
        tempSide.read(file);
        this->sides.push_back(tempSide);
    }
}

void Order::write(ofstream& file)
{
    this->location.write(file);

    file.write(this->phone, sizeof(this->phone));

    size_t pizza_num = this->pizzas.size();

    size_t drinks_num = this->drinks.size();

    size_t sides_num = this->sides.size();

    file.write((char*)(&pizza_num), sizeof(pizza_num));
    file.write((char*)(&drinks_num), sizeof(drinks_num));
    file.write((char*)(&sides_num), sizeof(sides_num));
    for(size_t i = 0; i < pizza_num; i++) {
        this->pizzas[i].write(file);
    }
    for(size_t i = 0; i < drinks_num; i++) {
        this->drinks[i].write(file);
    }
    for(size_t i = 0; i < sides_num; i++) {
        this->sides[i].write(file);
    }
}

string Order::get_location()
{
    return this->location.get_name();
}

string Order::get_phone()
{
    return (string)this->phone;
}

ostream& operator << (ostream& out, const Order& order)
{
    cout << "Location: " << order.location;
    cout << "Phone number: " << order.phone << endl << endl;

    if(order.pizzas.size() > 0) {
    cout << "===== Pizzas =====" << endl;
    for(size_t i = 0; i < order.pizzas.size(); i++){
//        out << "  Name: " << order.pizzas[i].get_name() << endl;
//        out << "  Price: " << order.pizzas[i].get_price() << endl;
        out << order.pizzas[i] << endl;
    }
    }

    if(order.drinks.size() > 0) {
    cout << "===== Drinks =====" << endl;
    for(size_t i = 0; i < order.drinks.size(); i++){
//        out << "  Name: " << order.drinks[i].get_name() << endl;
//        out << "  Price: " << order.drinks[i].get_price() << endl;
        out << order.drinks[i] << endl;
    }
    }

    if(order.sides.size() > 0) {
    cout << "===== Side dish =====" << endl;
    for(size_t i = 0; i < order.sides.size(); i++){
//        out << "  Name: " << order.sides[i].get_name() << endl;
//        out << "  Price: " << order.sides[i].get_price() << endl;
        out << order.sides[i] << endl;
    }
    }
    return out;
}

istream& operator >> (istream& in, Order& order)
{
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

    return in;
}
