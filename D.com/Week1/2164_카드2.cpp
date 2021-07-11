#include<iostream>
#include<queue>

using namespace std;

int main(void)
{
    queue<int> q;
    int n, last;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    while(!q.empty())
    {
        last = q.front();
        q.pop();
        if(q.empty())
            break;
        q.push(q.front());
        q.pop();
    }

    cout << last;


    return 0;
}