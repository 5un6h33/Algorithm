#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(void)
{
    string line1, line2, filename1, filename2;
    int count = 1, flag = 0;

    while(1)
    {
        cout << "File1 : ";
        cin >> filename1;

        ifstream ifs1(filename1);

        if(!ifs1)
        {
            cout << "[-] \"" << filename1 << "\" is not exist" << endl;
            continue;
        }

        cout << "File2 : ";
        cin >> filename2;

        ifstream ifs2(filename2);

        if(!ifs2)
        {
            cout << "[-] \"" << filename2 << "\" is not exist" << endl;
            continue;
        }

        while(1)
        {
            getline(ifs1, line1);
            getline(ifs2, line2);
            // cout << line1 << endl;
            // cout << line2 << endl;

            if(ifs1.eof() || ifs2.eof())
            {
                flag = 2;
                break;
            }

            if(line1 != line2)
            {
                flag = 1;
                break;
            }
            count++;
        }

        if(flag == 1)
        {
            cout << endl << "[-] File1 : " << line1 << endl;
            cout << "[-] File1 : " << line2 << endl;
            cout  << "[-] Line " << count << " is differnet" << endl << endl;
        }
        else if(flag == 2)
        {
            cout  << "[-] File line num is different Line " << endl << endl;  
        }
        else
        {
            cout << "[+] " << "Same file!" << endl << endl;
        }

        count = 1, flag = 0;

        ifs1.close();
        ifs2.close();
    }

    return 0;
}