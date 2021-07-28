#include<iostream>

using namespace std;

void binary(unsigned long long n)
{
    if(n != 1) binary(n / 2);
    cout << (n % 2);
}

int main(void)
{
    long long n;
    cin >> n;
    binary(n);
    cout << endl;

    return 0;
}