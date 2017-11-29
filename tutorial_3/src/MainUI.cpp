#include "MainUI.h"

MainUI::MainUI()
{
    //ctor
}

void MainUI::startUI()
{
    char selection = '\0';

    while(selection != 'q'){
        cout << "p: make pizza" << endl;
        cout << "w: wrtie" << endl;
        cout << "r: read" << endl;
        cout << "q: quit" << endl;
        cin >> selection;

        if(selection == 'w'){

        }
        else if (selection == 'r'){

        }
        else if(selection == 'p'){
            PizzaUI pizza;
            pizza.startUI();
        }
    }
}
