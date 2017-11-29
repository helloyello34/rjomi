#include <iostream>
#include <fstream>


using namespace std;

class Superhero
{

public:
    Superhero()
    {
        this->name[0] = '\0';
        this->age = 0;
        this->power = 'n';
    }

    friend ostream& operator << (ostream& out, const Superhero& hero)
    {
        out << hero.name << " (" << hero.age << ") ";
        switch(hero.power) {
        case 'f':
            out << "Flying" << endl;
            break;
        case 'g':
            out << "Giant" << endl;
            break;
        case 'h':
            out << "Hacker" << endl;
            break;
        case 'n':
            out << "None" << endl;
            break;
        default :
            out << "Weakling" << endl;
            break;
        }

        return out;
    }

    friend istream& operator >> (istream& in, Superhero& hero)
    {
        cout << "Name: ";
        in >> hero.name;
        //in.getline(hero.name,32);
        cout << "Age: ";
        in >> hero.age;
        cout << "Power (f,g,h,n)";
        in >> hero.power;

        return in;
    }


private:
    char name[32];
    int age;
    char power;
};



int main()
{
    Superhero hero;
    char choice = '\0';

    while(choice != 'q') {
        cout << "w: write" << endl;
        cout << "r: read" << endl;
        cout << "q: quit" << endl;
        cout << ":";
        cin >> choice;

        if(choice == 'w') {
            ofstream fout ("superh.dat", ios::app|ios::binary);
            Superhero hero;
            cin >> hero;
            fout.write((char*)(&hero), sizeof(Superhero));
            fout.close();
        } else if (choice == 'r') {
            ifstream fin ("Superh.dat", ios::binary);

            if(fin.is_open()) {
                fin.seekg(0,fin.end);
                int records = fin.tellg() / sizeof(Superhero);
                fin.seekg(0,fin.beg);

                Superhero *hero = new Superhero[records];
                fin.read((char*)hero, sizeof(Superhero)*records);

                for(int i = 0; i < records; i++) {
                    cout << hero[i];
                }

                delete[] hero;

            } else {
                cout << "File did not open " << endl;
            }
        }

    }

    return 0;
}
