#include<iostream>

using namespace std;

int gcd(int a, int b)
{
    int tmp, n;

    if(a < b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }

    while(b != 0)
    {
        n = a % b;
        a = b;
        b = n;
    }

    return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        cout << lcm(a, b) << '\n';
    }

    return 0;
}