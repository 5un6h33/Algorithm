#include<iostream>

using namespace std;

int is_prime(int num)
{
    if(num == 1)
        return 0;
    for(int i = 2; i*i <= num; i++)
    {
        if(num % i == 0)
            return 0;
    }
    return 1;
}

int main(void)
{
    int m, n;

    cin >> m >> n;

    for(; m <= n; m++)
    {
        if(is_prime(m))
        {
            cout << m << '\n';
        }
    }

    return 0;
}