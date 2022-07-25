#include <iostream>
#include <queue>

using namespace std;

int N, K, cnt;
queue<int> q;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        q.push(i);

    cout << "<";

    while (!q.empty())
    {
        cnt++;
        if (cnt % K == 0)
        {
            int ans = q.front();
            q.pop();
            if (q.empty())
                cout << ans << ">";
            else
                cout << ans << ", ";
        }
        else
        {
            int ans = q.front();
            q.pop();
            q.push(ans);
        }
    }

    return 0;
}