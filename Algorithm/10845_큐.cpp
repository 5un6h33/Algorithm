#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main(void)
{
    int n, c;
    string cmd;
    queue<int> q;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> cmd;

        if(cmd == "push")
        {
            cin >> c;
            q.push(c);
        }
        else if(cmd == "pop")
        {
            if(q.empty()) cout << -1 << endl;
            else 
            {
                cout << q.front() << endl;
                q.pop();
            }
        }
        else if(cmd == "size")
        {
            cout << q.size() << endl;
        }
        else if(cmd == "empty")
        {
            cout << q.empty() << endl;
        }
        else if(cmd == "front")
        {
            if(q.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << q.front() << endl;
            }
        }
        else if(cmd == "back")
        {
            if(q.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << q.back() << endl;
            }
        }
    }

    return 0;
}