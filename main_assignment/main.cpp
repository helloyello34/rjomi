#include <iostream>
#include <fstream>
#include <stdlib.h>


using namespace std;

void welcom_screen();
int login_screen();
void menu(int user);
void manager_menu();
void salesman_menu();
void baker_menu();
void cashier_menu();

int main()
{
    int user;
    welcom_screen();
    user = login_screen();
    menu(user);

    return 0;
}

void welcom_screen()
{
    system("CLS");
    string flush;
     cout << " _____    _   ______   ______        ____" << endl;
    cout << "|  __ \\  | | |____  / |____  /      / _  |" << endl;
    cout << "| |__) | | |     / /      / /      / / | |" << endl;
    cout << "|  __ /  | |    / /      / /      / /__| |" << endl;
    cout << "| |      | |   / /      / /      /  ___  |" << endl;
    cout << "| |      | |  / /___   / /___   / /    | |" << endl;
    cout << "|_|      |_| /______| /______| /_/     |_|" << endl;
    cout << "                                       " << endl;
    cout << " _____    _             ____    __    _    ______   _________     " << endl;
    cout << "|  __ \\  | |           / _  |  |  \\  | |  |  ____| |___   ___|              " << endl;
    cout << "| |__) | | |          / / | |  |   \\ | |  | |___       | |         " << endl;
    cout << "|  __ /  | |         / /__| |  |    \\| |  |  ___|      | |           " << endl;
    cout << "| |      | |        /  ___  |  | |\\    |  | |          | |          " << endl;
    cout << "| |      | |___    / /    | |  | | \\   |  | |____      | |         " << endl;
    cout << "|_|      |______| /_/     |_|  |_|  \\__|  |______|     |_|         " << endl;
    cout << "                                                                  " << endl;
    cout << "Welcome to the Pizza program" << endl;
    cout << "Made by." << endl;
    cout << "\tKristinn Bjorgvinsson" << endl;
    cout << "\tOskar Jorgen Sandholt" << endl;
    cout << "\tSilja Dogg Birgisdottir" << endl;
    cout << endl << endl;
    cout << "\t\t Press return to continue" << endl;
    getline(cin,flush);
}


int login_screen()
{
    system("CLS");
    int user;
    cout << "Please login" << endl;
    cout << " +------------------+" << endl;
    cout << " |1. Manager        |" << endl;
    cout << " |2. Salesman       |" << endl;
    cout << " |3. Baker          |" << endl;
    cout << " |4. Cashier        |" << endl;
    cout << " +------------------+" << endl;
    cout << " (1-4):";
    cin >> user;
    while(user < 1 || user > 4){
        cout << " Wrong input (1-4): ";
        cin >> user;
    }
    return user;
}

void menu(int user)
{
    switch(user){
        case 1: manager_menu(); break;
        case 2: salesman_menu(); break;
        case 3: baker_menu(); break;
        case 4: cashier_menu(); break;
    }
}

void manager_menu()
{
    system("CLS");
    int choice;
    cout << "Salesman: " << endl;
    cout << " +------------------+" << endl;
    cout << " |1. Current orders |" << endl;
    cout << " |2. Old orders     |" << endl;
    cout << " |3. Edit menu      |" << endl;
    cout << " |4. Location       |" << endl;
    cout << " |5. Back           |" << endl;
    cout << " |6. Quit           |" << endl;
    cout << " +------------------+" << endl;
    cout << " (1-6): ";
    cin >> choice;
    while((choice < 1 | choice > 6)){
        if(!isdigit(choice)){
            choice = 0;
        }
        cout << " Wrong input (1-6): ";
        cin >> choice;
    }

}

void salesman_menu()
{
    system("CLS");
    int choice;
    cout << "Salesman: " << endl;
    cout << " +------------------+" << endl;
    cout << " |1. Make order     |" << endl;
    cout << " |2. Charge order   |" << endl;
    cout << " |3. Comments       |" << endl;
    cout << " |4. Back           |" << endl;
    cout << " |5. Quit           |" << endl;
    cout << " +------------------+" << endl;
    cout << " (1-5): ";
    cin >> choice;
    while(choice < 1 | choice > 5){
        cout << " Wrong input (1-5): ";
        cin >> choice;
    }
}

void baker_menu()
{
    system("CLS");
    int choice;
    cout << "Baker: " << endl;
    cout << " +------------------+" << endl;
    cout << " |1. Your location  |" << endl;
    cout << " |2. Back           |" << endl;
    cout << " |3. Quit           |" << endl;
    cout << " +------------------+" << endl;
    cout << " (1-3): ";
    cin >> choice;
    while(choice < 1 | choice > 3){
        cout << " Wrong input (1-3): ";
        cin >> choice;
    }
}

void cashier_menu()
{
    system("CLS");
    int choice;
    cout << "Cashier: " << endl;
    cout << " +------------------+" << endl;
    cout << " |1. Your location  |" << endl;
    cout << " |2. Back           |" << endl;
    cout << " |3. Quit           |" << endl;
    cout << " +------------------+" << endl;
    cout << " (1-3): ";
    cin >> choice;
    while(choice < 1 | choice > 3){
        cout << " Wrong input (1-3): ";
        cin >> choice;
    }
}

