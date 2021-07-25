#include<iostream>
#include<cmath>

using namespace std;

void d_to_b(int num)
{
    if(num == 0 || num == 1)
    {
        cout << num;
        return;
    }
    d_to_b(num / 2);
    cout << num % 2;
}

int main(void)
{
    int n;

    cin >> n;
    d_to_b(n);

    return 0;
}