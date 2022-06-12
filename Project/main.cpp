#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Cube.hpp"
using namespace std;

vector<string> split(string str, char Delimiter)
{
    istringstream iss(str);
    string buffer;

    vector<string> result;

    while (getline(iss, buffer, Delimiter))
    {
        result.push_back(buffer);
    }

    return result;
}

int main()
{
    Cube c;
    string item;
    int input, z, y, x;
    ifstream readFile;
    readFile.open("WordBook.txt");

    if (readFile.is_open())
    {
        while (!readFile.eof())
        {
            string str;
            getline(readFile, str);
            vector<string> result = split(str, ' ');
            if (result.size() <= 2)
                continue;
            z = stoi(result[0]);
            y = stoi(result[1]);
            x = stoi(result[2]);
            str = result[3].substr(0, result[3].length() - 1);
            c.Insert(z, y, x, str);
        }
    }

    while (1)
    {
        cout << "Enter Any Command(1 : Insert, 2 : Delete, 3 : Find, 4 : Print, 5 : Print_All, 6 : Turn, 7 : Exchange, 8 : Exit) : ";
        cin >> input;
        if (input == 1)
        {
            cin >> z >> y >> x >> item;
            c.Insert(z, y, x, item);
        }
        else if (input == 2)
        {
            cin >> z >> y >> x >> item;
            c.Delete(z, y, x, item);
        }
        else if (input == 3)
        {
            cin >> item;
            c.Find(item);
        }
        else if (input == 4)
        {
            cin >> z >> y >> x;
            c.Print(z, y, x);
        }
        else if (input == 5)
        {
            c.Print_All();
        }
        else if (input == 6)
        {
        }
        else if (input == 7)
        {
        }
        else if (input == 8)
        {
            cout << "Program Exit" << endl;
            break;
        }
    }

    readFile.close();
    return 0;
}