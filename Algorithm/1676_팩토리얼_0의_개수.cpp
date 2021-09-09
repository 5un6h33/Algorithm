#include<iostream>
#include<string>

using namespace std;

int main(void)
{
    int n, ans = 0;
    cin >> n;
    
    for(int i = 5; i <= n; i*=5)
        ans += n/i;

    cout << ans;

    return 0;
}

// 5 10 15 20    30 35 40 45    55 60 65 70    80 85 90 95
//            25             50             75             100