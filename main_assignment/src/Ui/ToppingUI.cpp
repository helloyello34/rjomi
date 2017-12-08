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
    char input;

    while(input != '5')
    {
        system("CLS");
        cout << "   Toppings " << endl;
        cout << " ====================" << endl;
        cout << "  1. Add Toppings      " << endl;
        cout << "  2. Edit Toppings     " << endl;
        cout << "  3. Delete Toppings   " << endl;
        cout << "  4. View Toppings     " << endl;
        cout << "  5. Back           " << endl;
        cout << " ====================" << endl;
        cout << " (1-5): ";
        cin >> input;

        if(input == '1'){
            add_new_topping();
        } else if(input == '2') {
            ///Edit Toppings
        } else if(input == '3') {
            delete_topping();
        } else if(input == '4'){
//            list_toppings();
            system("pause");
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

//void ToppingUI::retrive_topping()
//{
//    ToppingRepo newVector;
//    this->toppings = newVector.get_toppings();
//}

Topping ToppingUI::getTopping(int id)
{
    if((unsigned)id <= this->toppings.size()) {
        return this->toppings[id-1];
    } else {
        cout << "Invalid choice" << endl;
        Topping temp;
        return temp;
    }
}

//void ToppingUI::list_toppings()
//{
//        system("CLS");
//        retrive_topping();
//        cout << "   Avalable toppings " << endl;
//        cout << " =========================" << endl;
//        for(unsigned int i = 0; i < this->toppings.size(); i++) {
//            cout << "  " << i+1 << ". "<< this->toppings[i] << endl;
//        }
//        cout << " ==========================" << endl << endl;
//}
