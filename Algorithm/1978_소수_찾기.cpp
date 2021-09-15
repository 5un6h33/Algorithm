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
    int n, num, count = 0;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> num;
        if(is_prime(num) == 1)
            count++;
    }

    cout << count;

    return 0;
}