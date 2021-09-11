#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(void)
{
    int n;
    char cmd;
    stack <char> left, right;
    string str;

    cin >> str;

    for(string::iterator iter = str.begin(); iter != str.end(); ++iter)
    {
        left.push(*iter);
    }

    cin >> n;

    while(n--)
    {
        cin >> cmd;

        if(cmd == 'L')
        {
            if(!left.empty())
            {
                right.push(left.top());
                left.pop();
            }
        }
        else if(cmd == 'D')
        {
            if(!right.empty())
            {
                left.push(right.top());
                right.pop();
            }
        }
        else if(cmd == 'B')
        {
            if(!left.empty())
            {
                left.pop();
            }
        }
        else if(cmd == 'P')
        {
            char c;
            cin >> c;
            left.push(c);
        }
    }

    while(!left.empty())
    {
        right.push(left.top());
        left.pop();
    }

    while(!right.empty())
    {
        cout << right.top();
        right.pop();
    }

    return 0;
}