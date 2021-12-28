#include<iostream>
#include<math.h>
using namespace std;

int is_prime(int n)
{
    for(int i = 2; i <= sqrt(n); i++)
        if(n % i == 0)
            return 0;
    return 1;
}

int main(void)
{
    int n, count = 0;

    while(1)
    {
        cin >> n;
        count = 0;

        if(n == 0)
            break;

        for(int i = n + 1; i <= n * 2; i++)
        {
            if(is_prime(i))
                count++;
        }

        cout << count << endl;
    }

    return 0;
}