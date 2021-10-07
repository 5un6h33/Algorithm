#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(void)
{
    int len;

    ifstream fin;
    fin.open("input.txt");
    ofstream fout;
    fout.open("output.txt");

    string str, text;

    while(getline(fin, str))
        text += str + " ";

    cout << "length = ";
    cin >> len;

    for(int i = 0; i <= text.length(); i++)
    {
        if(i % len == 0 && i != 0)
            fout << '\n';
        fout << text[i];
    }

    fin.close();
    fout.close();

    return 0;
}