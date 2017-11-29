#include <iostream>
#include <fstream>


using namespace std;

int main()
{
    ifstream myfile ("file1.txt");
    string line;
    char cont = 'y';
    if(myfile.is_open()){
        while(cont == 'y'){
            int i = 0;
            while(getline(myfile,line) && i < 10){
                cout << line << endl;
                i++;
            }
            cout << "Want to continue (y,n)? ";
            do{
            cin >> cont;
            if(cont == 'y' || cont == 'n'){
                break;
            }
            cout << "Wrong input try again! ";
            }while(true);
        }

    }else{
        cout << "File did not open" << endl;
    }
    return 0;
}


