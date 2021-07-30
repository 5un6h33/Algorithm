#include<iostream>

using namespace std;

void HanoiTower(int n, int from, int via, int to)
{
    if(n == 1)
    {
        printf("%d %d\n", from, to);
    }
    else {
        HanoiTower(n - 1, from, to, via);
        printf("%d %d\n", from, to);
        HanoiTower(n - 1, via, from, to);
    }
}

int main(void)
{
    int n;
    cin >> n;

    cout << (1 << n) - 1 << "\n";
    HanoiTower(n, 1, 2, 3);

    return 0;
}