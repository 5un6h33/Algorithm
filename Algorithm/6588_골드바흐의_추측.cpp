#include<iostream>

using namespace std;

int is_prime(int num)
{
    if(num == 1)
    {
        return 0;
    }
    for(int i = 2; i*i <= num; i++)
    {
        if(num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int goldbach(int num)
{
    for(int i = num; i > 0; i--)
    {
        if(is_prime(i) && is_prime(num - i))
        {
            return num - i;
        }
    }

    return 0;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, a, b;

    while(1)
    {
        cin >> n;

        if(n == 0)
        {
            break;
        }

        a = goldbach(n);
        b = n - a;
        if(a != 0)
        {
            cout << n << " = " << a << " + " << b << '\n';
        }
        else
        {
            cout << "Goldbach's conjecture is wrong." << '\n';
        }
    }


    return 0;
}