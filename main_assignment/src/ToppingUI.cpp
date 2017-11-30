#include "ToppingUI.h"

ToppingUI::ToppingUI()
{
    this->numberOfToppings = 0;
}

ToppingUI::~ToppingUI()
{
    //dtor
}

void ToppingUI::startUI()
{
    char choice = '\0';

    while(choice != '4'){
        cout << "1: add new topping" << endl;
        cout << "2: delete topping" << endl;
        cout << "3: view topping" << endl;
        cout << "4: Back " << endl;

        cin >> choice;

        if(choice == '1'){
            add_new_topping();
        }else if(choice == '2'){
            delete_topping();
        }else if(choice == '3'){
            list_toppings();
        }
    }
}

void ToppingUI::add_new_topping()
{
    Topping newTop;
    cin >> newTop;
    store_topping(newTop);
}

void ToppingUI::delete_topping()
{

}

void ToppingUI::store_topping(Topping& newTop)
{
    ToppingRepo newTopping;
    newTopping.store_toppings(newTop);
}

void ToppingUI::retrive_topping()
{
    ToppingRepo newVector;
    this->toppings = newVector.get_toppings();
}

Topping ToppingUI::getTopping(int id)
{
    if((unsigned)id <= this->toppings.size()){
        return this->toppings[id-1];
    }else{
        cout << "Invalid choice" << endl;
        Topping temp;
        return temp;
    }
}

void ToppingUI::list_toppings()
{
    retrive_topping();
    cout << "Avalable toppings " << endl;
    for(unsigned int i = 0; i < this->toppings.size(); i++){
        cout << i+1 << ". "<< this->toppings[i] << endl;
    }
}


