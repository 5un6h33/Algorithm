#include<iostream>
#include<queue>
using namespace std;

priority_queue<int> pq;
int N;

int main()
{
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int a = 0;
        cin >> a;
        if(!a && pq.empty())
            cout << 0 << '\n';
        else if(!a)
        {
            cout << pq.top() << '\n';
            pq.pop();
        }
        else
            pq.push(a);
    }

    return 0;
}