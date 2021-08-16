#include<iostream>
using namespace std;

int main(void)
{
    int n, res = 0;
    cin >> n;
    n = 1000 - n;
    int arr[7] = {500, 100, 50, 10, 5, 1};

    for(int i = 0; i < 6; i++)
    {
        while(n - arr[i] >= 0)
        {
            res++;
            n -= arr[i];
        }
    }

    cout << res << '\n';

    return 0;
}