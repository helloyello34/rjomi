#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    vector<int>*bin;

    char choice = '\0';

    while(choice != 'q'){
        cout << "w, r, q" << endl;
        cin >> choice;

        if(choice == 'w'){
            ofstream fout ("vector.dat", ios::binary|ios::app);
            int a;
            cin >> a;
            fout.write((char*)(&a), sizeof(int));


            fout.close();
        } else if(choice == 'r'){
            ifstream fin ("vector.dat", ios::binary);

            fin.seekg(0,fin.end);
            int records = fin.tellg() / sizeof(int);
            fin.seekg(0,fin.beg);


            fin.read((char*)(bin), sizeof(int) * records);

            for(unsigned int i = 0; i < bin.size(); i++){
                cout << bin[i] << endl;
            }

            fin.close();
        }

    }

    return 0;
}
