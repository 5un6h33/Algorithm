#include<iostream>
#include<string.h>
using namespace std;

int main(void)
{
    int T, L, R;
    string str;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        L = 0, R = 0;
        cin >> str;
        for(int j = 0; j < str.length(); j++)
        {
            if(str[j] == '(')
                L += 1;
            else    
                R += 1;
            if(L - R < 0)
                break;
        } 
        if(L == R)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}