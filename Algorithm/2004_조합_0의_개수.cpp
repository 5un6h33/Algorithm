#include<iostream>

using namespace std;

int main(void)
{
    int n, m, ans_n = 0, ans_m = 0;
    cin >> n >> m;

    for(int i = 5; i <= n; i*=5)
        ans_n += n/i;
    for(int j = 5; j <= m; j*=5)
        ans_m += m/j;

    cout << ans_n - ans_m;

    return 0;
}