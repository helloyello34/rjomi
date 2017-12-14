#ifndef ORDERUI_H
#define ORDERUI_H

#include <stdlib.h>
#include <iostream>

#include "Order.h"
#include "OrderService.h"

#include "PizzaUI.h"
#include "DrinkUI.h"
#include "SidesUI.h"

using namespace std;

class OrderUI
{
public:
    OrderUI();

    /////////////////////////////////////////////////////
    /// Salesman UI
    void salesmanUI(Location& staff_location);

    /// Baker UI
    void bakerUI(Location& staff_location);

    /// Cashier UI
    void cashierUI(Location& staff_location);

    /// Manager UI
    void managerUI();
    /////////////////////////////////////////////////////

    /////////////////////////////////////////////////////
    /// Create a new order
    void make_order(Location& staff_location);

    /// Add pizza to the order
    void add_pizza(Order& order);

    /// Add side dish to the order
    void add_sides(Order& order);

    /// Add drink to the order
    void add_drink(Order& order);
    /////////////////////////////////////////////////////

    /////////////////////////////////////////////////////
    /// Show all orders on the set location
    void show_order(Location& location);

    /// Show all avaliable orders
    void show_order();

    /// Show all old orders
    void show_old_orders();

    /// Look for orders via phone number
    void look_for_order();
    /////////////////////////////////////////////////////

    /////////////////////////////////////////////////////
    /// filters out other locations from the vector
    void erase_other_locations(Location& location);

    /// Stores order on file
    void store_order(Order& order);
    /////////////////////////////////////////////////////

    /////////////////////////////////////////////////////
    /// Finds order for baker to change the status
    void find_order_status(Location& location);

    /// Find order for salesman to change comment
    void find_order_comment(Location& location);

    /// Find order for cashier to change order to paid
    void find_order_paid(Location& location);
    /////////////////////////////////////////////////////

    /////////////////////////////////////////////////////
    /// Change status on the order
    void change_status(Order& order);

    /// Change the comment on the order
    void comment_order(Order& order);

    /// Change the bool paid to true on order
    void set_order_paid(Order& order);
    /////////////////////////////////////////////////////

    /////////////////////////////////////////////////////
    /// if the order is both ready and paid it goes to old ordersw
    void order_receved(Order& order);
    /////////////////////////////////////////////////////
private:
    PizzaUI pizza_ui;
    DrinkUI drink_ui;
    SidesUI sides_ui;

    vector<Order>orders;

    OrderService order_service;
};

#endif // ORDERUI_H
