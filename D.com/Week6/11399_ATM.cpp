#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int cmp(int a, int b)
{
    return a > b;
}

int main(void)
{
    int n, res = 0;
    
    cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end(), cmp);

    for(int i = n; i >= 1; i--)
    {
        res += i * v[i - 1];
    }

    cout << res << '\n';

    return 0;
}