#include<iostream>
#include<stack>
#include<string>

using namespace std;


int main(void)
{
    int n;
    string str;
    stack <char> s;

    cin >> n;
    cin.ignore();
    while(n--)
    {
        getline(cin, str);
        str += ' ';
        
        for(string::iterator iter = str.begin(); iter != str.end(); ++iter)
        {
            if(*iter == ' ')
            {
                while(!s.empty())
                {
                    cout << s.top();
                    s.pop();
                }
                cout << ' ';
            }
            else
            {
                s.push(*iter);
            }
        }

        cout << '\n';
    }

    return 0;
}