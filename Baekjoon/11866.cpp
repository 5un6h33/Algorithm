#include <iostream>
#include <queue>

using namespace std;

int N, K, idx;
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
        if (idx % K == 0)
        {
            if (q.empty())
                cout << q.front() << ">";
            else
                cout << q.front() << ", ";
            q.pop();
        }
        else
        {
            q.push(q.front());
            q.pop();
        }
        idx++;
    }

    cout << ">";

    return 0;
}