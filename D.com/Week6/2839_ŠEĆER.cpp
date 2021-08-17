#include<iostream>

using namespace std;

int main(void)
{
    int n, m, k, temp, res = 0;
    cin >> n;
    m = n / 5;
    temp = n;

    for(int i = m; i >= 0; i--)
    {
        n -= 5 * i;
        res += i;

        k = n / 3;
        n -= 3 * k;
        res += k;

        if(n == 0)  break;
        
        n = temp;
        res = 0;
    }

    if(res == 0) res = -1;

    cout << res << '\n';

    return 0;
}