#include "MainUI.h"

MainUI::MainUI()
{
    welcom_screen();
    startUI();
}

MainUI::~MainUI()
{
    //dtor
}


void MainUI::welcom_screen()
{
    system("CLS");
    string flush;
    cout << " _____    _   ______   ______        ____                  .       " << endl;
    cout << "|  __ \\  | | |____  / |____  /      / _  |               , /      " << endl;
    cout << "| |__) | | |     / /      / /      / / | |              , /___     " << endl;
    cout << "|  __ /  | |    / /      / /      / /__| |             .___  .     " << endl;
    cout << "| |      | |   / /      / /      /  ___  |                / ,      " << endl;
    cout << "| |      | |  / /___   / /___   / /    | |               /,        " << endl;
    cout << "|_|      |_| /______| /______| /_/     |_|              /.         " << endl;
    cout << "                                                                   " << endl;
    cout << " _____    _             ____    __    _    ______   _________      " << endl;
    cout << "|  __ \\  | |           / _  |  |  \\  | |  |  ____| |___   ___|   " << endl;
    cout << "| |__) | | |          / / | |  |   \\ | |  | |___       | |        " << endl;
    cout << "|  __ /  | |         / /__| |  |    \\| |  |  ___|      | |        " << endl;
    cout << "| |      | |        /  ___  |  | |\\    |  | |          | |        " << endl;
    cout << "| |      | |___    / /    | |  | | \\   |  | |____      | |        " << endl;
    cout << "|_|      |______| /_/     |_|  |_|  \\__|  |______|     |_|        " << endl;
    cout << "                                                                   " << endl;
    cout << "Welcome to the Pizza program" << endl;
    cout << "Made by." << endl;
    cout << "\tKristinn Bjorgvinsson" << endl;
    cout << "\tOskar Jorgen Sandholt" << endl;
    cout << "\tSilja Dogg Birgisdottir" << endl;
    cout << endl << endl;
    cout << "\t\t Press return to continue" << endl;
    getline(cin,flush);
}

void MainUI::startUI()
{

    char user = '\0';

    while(user != 'q') {
        system("CLS");
        cout << "Please login" << endl;
        cout << " +------------------+" << endl;
        cout << " |m. Manager        |" << endl;
        cout << " |s. Salesman       |" << endl;
        cout << " |b. Baker          |" << endl;
        cout << " |c. Cashier        |" << endl;
        cout << " |q. Quit           |" << endl;
        cout << " +------------------+" << endl;
        cout << " (m, s, b, c, q):";
        cin >> user;

        if(user == 'm'){
            ManagerUI managerui;
        } else if (user == 's') {
            SalesmanUI salesmanui;
        } else if (user == 'b') {
            BakerUI bakerui;
        } else if (user == 'c') {
            CashierUI cashierui;
        }

    }
}
