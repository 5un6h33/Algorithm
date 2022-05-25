#include<iostream>
#include<algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, ans;
int arr[1001];
int dp[1001];

int main() {
    fastio;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
            if(arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
    }

    for(int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    cout << ans + 1;

    return 0;
}
