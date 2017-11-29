#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream input_file ("input.txt", ios::app);
    string line;

    if(input_file.is_open()){
        cout << "Writing to file!! " << endl;
        while(true){
            getline(cin, line);
            if(line[0] == '\\'){
                break;
            }
            input_file << line << "\n";
        }
        input_file.close();
    }else{
        cout << "could not open" << endl;
    }

    return 0;
}
