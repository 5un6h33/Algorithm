#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(void)
{
    stack<int> s;

    int n, num;
    string str;
    cin >> n;

    while(n-- != 0)
    {
        cin >> str;
        if(str == "push")
        {
            cin >> num;
            s.push(num);
        }
        else if(str == "top")
        {
            if(!s.empty())
            {
                cout << s.top() << endl;
            }
            else
            {
                cout << "-1" << endl;
            }
        }
        else if(str == "size")
        {
            cout << s.size() << endl;
        }
        else if(str == "empty")
        {
            if(s.empty())
            {
                cout << "1" << endl;
            }
            else{
                cout << "0" << endl;
            }
        }
        else if(str == "pop")
        {
            if(s.empty())
            {
                cout << "-1" << endl;
            }
            else
            {
                cout << s.top() << endl;
                s.pop();
            }
        }
    }

    return 0;
}