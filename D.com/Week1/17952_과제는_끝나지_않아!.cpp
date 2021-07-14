#include<iostream>
#include<stack>

using namespace std;

int main(void)
{
    stack<int> s, m;
    int n, task, a, t, res = 0;

    cin >> n;

    while(n-- != 0)
    {
        cin >> task;
        if(task == 1)
        {   
            cin >> a >> t;
            s.push(a);
            m.push(t-1);
            if(m.top() == 0)
            {
                res += s.top();
                s.pop();
                m.pop();
            }
        }
        else
        {
            if(m.top() - 1 == 0)
            {
                res += s.top();
                s.pop();
                m.pop();
            }
            else
                m.top() -= 1;
        }
    }

    cout << res;

    return 0;
    
}