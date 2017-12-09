#include "MainUI.h"



MainUI::MainUI()
{
    //ctor
}


void MainUI::Main_Menu()
{
    char input = '\0';
    while(input != '4'){
    cout << "   Main Menu"                                << endl;
    cout << " ==========================================" << endl;
    cout << "  1. Add salary record"                      << endl;
    cout << "  2. Get salary for given SSN"               << endl;
    cout << "  3. Get highest salary for a given year"    << endl;
    cout << "  4. Quit"                                   << endl;
    cout << " =========================================="      << endl;
    cout << " (1-4): ";
    cin >> input;
    validate(input);
    }
}

void MainUI::validate(char input)
{
    switch(input){
    case '1': system("CLS"); add_salary(); system("pause"); system("CLS"); break;
    case '2': system("CLS"); get_salary_ssn(); system("pause"); system("CLS"); break;
    case '3': system("CLS"); get_salary_year(); system("pause"); system("CLS"); break;
    case '4': cout << "  Good Bye" << endl; break;
    default:  system("CLS"); cout << " Invalid input" << endl; break;

    }
}

void MainUI::add_salary()
{
    Salary salary;
    try{
    cin >> salary;
    salary_service.add_salary(salary);
    }
    catch(InvalidSsnExceptions e){
        e.print_message();
    }

    catch(InvalidMonthExceptions e){
        e.print_message();
    }
    catch(InvalidYearExceptions e){
        e.print_message();
    }


}

void MainUI::get_salary_ssn()
{
    char this_ssn[20];
    cout << "   Get salary for given SSN" << endl;
    cout << " ==========================================" << endl;
    cout << "  Enter an SSN (10): ";
    try{
    cin >> this_ssn;
    if(strlen(this_ssn) != 10){
        throw InvalidSsnExceptions("  Error: You have to input 10 integers");
    }
    for(int i = 0; i < 10; i++) {
        if(!(isdigit(this_ssn[i]))){
            throw InvalidSsnExceptions("  Error: SSN should only hold integers");
        }
    }
    salary_service.print_salary(this_ssn);
    }
    catch(InvalidSsnExceptions e){
        cout << " ==========================================" << endl;
        e.print_message();
        cout << endl << "  ";
    }
    catch(FirstTimeWritingException e){
        cout << "  There is nothing stored! " << endl;
    }
}

void MainUI::get_salary_year()
{
    int this_year;
    char this_ssn[20];
    try{
        cout << "   Get highest salary for a given year" << endl;
        cout << " ==========================================" << endl;
        cout << "  Enter SSN: ";
        cin >> this_ssn;
        if(strlen(this_ssn) != 10){
        throw InvalidSsnExceptions("  Error: You have to input 10 integers");
        }
        for(int i = 0; i < 10; i++) {
        if(!(isdigit(this_ssn[i]))){
            throw InvalidSsnExceptions("  Error: SSN should only hold integers");
        }
        }
        cout << "  Enter the year: ";
        cin >> this_year;
        if(cin.fail())
        {
            cin.clear();
            throw InvalidYearExceptions("  Error: Year should only consist of integers");
        }
        if(this_year > 2017 || this_year < 1900){
            throw InvalidYearExceptions("  Error: Input Should be between 1900 - 2017");
        }
        salary_service.print_year(this_ssn, this_year);
    }

    catch(InvalidYearExceptions e){
        cout << " ==========================================" << endl;
        e.print_message();
        cout << endl << "  ";
    }
    catch(InvalidSsnExceptions e){
        cout << " ==========================================" << endl;
        e.print_message();
        cout << endl << "  ";
    }
}
