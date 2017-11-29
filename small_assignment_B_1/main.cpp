#include <iostream>
#include "SuperHero.h"

using namespace std;

void get_input(char& input);

int main()
{
    char input = ' ';
    string line;

    while(input != 'q'){
        get_input(input);

        if(input == 'w'){
            ofstream fout ("textfile.txt", ios::app);
            SuperHero temp;
            cin >> temp;
            fout << temp;
            fout.close();
        }
        if(input == 'r'){
            ifstream fin ("textfile.txt");
            if(fin.is_open()){
                cout << endl;
                while(!fin.eof()){
                    getline(fin,line);
                    cout << line << endl;
                }
                cout << endl;
            }else{
                cout << "File is not open" << endl;
            }

            fin.close();
        }
        if(input == 'c'){
            ofstream f ("textfile.txt");
            f.close();
        }

    }

    return 0;
}

void get_input(char& input){
    cout << "w: Write" << endl;
    cout << "r: Read" << endl;
    cout << "q: Quit" << endl;
    cout << "c: Clear" << endl << endl;
    cout << "Please input :";
    cin >> input;
}
