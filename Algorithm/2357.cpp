#include<iostream>
#include<algorithm>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

using namespace std;
using ll = long long;

ll arr[101010];
ll min_tree[404040];
ll max_tree[404040];
int N, M, a, b;

void build(int start = 1, int end = N, int node = 1)
{
    if(start == end)
    {
        min_tree[node] = max_tree[node] = arr[start - 1];
        return;
    }
    int mid = (start + end) >> 1;
    build(start, mid, node << 1);
    build(mid + 1, end, node << 1 | 1);
    min_tree[node] = min(min_tree[node << 1], min_tree[node << 1 | 1]);
    max_tree[node] = max(max_tree[node << 1], max_tree[node << 1 | 1]);
}

ll find_min(int left, int right, int start = 1, int end = N, int node = 1)
{
    if(end < left || right < start)
        return 1000000001;
    if(left <= start && end <= right)
        return min_tree[node];
    int mid = (start + end) >> 1;
    return min(find_min(left, right, start, mid, node << 1), find_min(left, right, mid + 1, end, node << 1 | 1));
}

ll find_max(int left, int right, int start = 1, int end = N, int node = 1)
{
    if(end < left || right < start)
        return -1000000001;
    if(left <= start && end <= right)
        return max_tree[node];
    int mid = (start + end) >> 1;
    return max(find_max(left, right, start, mid, node << 1), find_max(left, right, mid + 1, end, node << 1 | 1));
}

int main(void)
{
//    freopen("input.txt", "r", stdin);
    fastio
    cin >> N >> M;
    
    for(int i = 0; i < N; ++i)
        cin >> arr[i];
    
    build();

    for(int i = 0; i < M; ++i)
    {
        cin >> a >> b;
        cout << find_min(a, b) << " " << find_max(a, b) << '\n';
    }
    
    return 0;
}
