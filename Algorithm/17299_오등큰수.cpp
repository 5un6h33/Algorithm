#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, num;
    vector<int> v;
    stack<int> s;

    cin >> n;

    vector<int> ans(n, -1);
    vector<int> nv(n + 1, 0);

    for(int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
        nv[num] += 1;
    }

    for(int i = 0; i < n; i++)
    {
        while(!s.empty() && nv[v[s.top()]] < nv[v[i]])
        {
            ans[s.top()] = v[i];
            s.pop();
        }
        s.push(i);
    }

    for(int x: ans)
    {
        cout << x << " ";
    }

    return 0;
}