#include "PizzaService.h"

PizzaService::PizzaService()
{
    //ctor
}

void PizzaService::new_pizza()
{
    Pizza pizza;
    cin >> pizza;
    store_pizza(pizza);
}

void PizzaService::store_pizza(const Pizza& pizza)
{
    this->pizza_repo.write(pizza);
}

void PizzaService::retrive_pizza()
{
    this->pizza_repo.read(this->pizzas);
}

void PizzaService::list_pizza()
{
    retrive_pizza();
    cout << "before loop" << endl;
    for(unsigned int i = 0; i < this->pizzas.size(); i++){
        cout << "Loop" << endl;
        cout << this->pizzas[i] << endl;
    }
}
