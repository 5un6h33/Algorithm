#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, num;
    cin >> n;

    vector<int> v;
    stack<int> s;

    for(int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    vector<int> ans(n, -1);
    
    for(int i = 0; i < v.size(); i++)
    {
        while(!s.empty() && v[s.top()] < v[i])
        {
            ans[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }

    for(int x: ans)
    {
        cout << x << ' ';
    }

    return 0;
}