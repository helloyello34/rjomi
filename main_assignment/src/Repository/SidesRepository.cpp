#include "SidesRepository.h"

SidesRepository::SidesRepository()
{
    //ctor
}

void SidesRepository::store_side(Sides& side)
{

    ofstream file;
    file.open("binaries\\Menu\\sides.dat", ios::binary|ios::app);

    if(file.is_open()) {

        side.write(file);

        file.close();

    } else {
        cout << "File could not open !" << endl;
    }
}

void SidesRepository::read_side(vector<Sides>&sides)
{
    ifstream file;
    file.open("binaries\\Menu\\sides.dat", ios::binary);

    if(file.is_open()) {

        Sides temp;

        sides.clear();

        while(!(file.eof())){
            temp.read(file);
            sides.push_back(temp);
        }
        sides.pop_back();

        file.close();

    } else {
        cout << "File could not open !" << endl;
    }

}

void SidesRepository::overwrite_sides(vector<Sides>&sides)
{
    ofstream file;
    file.open("binaries\\Menu\\sides.dat", ios::binary);

    if(file.is_open()) {

        for(unsigned int i = 0; i < sides.size(); i++) {
            sides[i].write(file);
        }

        file.close();

    } else {
        cout << "File could not open !" << endl;
    }
}
