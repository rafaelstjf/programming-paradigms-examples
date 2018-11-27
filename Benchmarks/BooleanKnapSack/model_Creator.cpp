#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    while (true)
    {
        string filename;
        string line1, line2;
        int numItems = 0;
        cout << "Enter the name of the file: " << endl;
        cin >> filename;
        fstream capacity;
        capacity.open(filename + "_c.txt", fstream::in);
        fstream weight;
        weight.open(filename + "_w.txt", fstream::in);
        fstream value;
        value.open(filename + "_p.txt", fstream::in);
        fstream output;
        cout << "Enter the number of items: " << endl;
        cin >> numItems;
        output.open(to_string(numItems) + ".txt", fstream::out);
        output << numItems << endl;
        getline(capacity, line1);
        output << line1.c_str() << endl;
        for (int i = 0; i < numItems; i++)
        {
            getline(weight, line1);
            getline(value, line2);
            output << atoi(line1.c_str()) << ';' << atoi(line2.c_str()) << endl;
        }
        capacity.close();
        weight.close();
        value.close();
        output.close();
    }
    return 0;
}