#include<iostream>
#include<vector>

using namespace std;

int max_num = 0, temp = 0;
vector<int> v;

void e_max()
{
    if(v.size() == 2)
    {
        if(max_num < temp)
            max_num = temp;
        return;
    }

    for(int i = 1; i < v.size() - 1; i++)
    {
        int select = v[i];
        temp = temp + v[i - 1] * v[i + 1];
        v.erase(v.begin() + i);
        e_max();
        v.insert(v.begin() + i, select);
        temp = temp - v[i - 1] * v[i + 1];
    }
}

int main(void)
{
    int n, num;
    cin >> n;
    
    while(n--)
    {
        cin >> num;
        v.push_back(num);
    }
    e_max();
    cout << max_num;

    return 0;
}