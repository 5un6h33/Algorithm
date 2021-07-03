#include <iostream>

using namespace std;

int main(void)
{
    int t, a, b;
    cin >> t;
    
    for(int i; i < t; i++)
    {
        cin >> a >> b;
        cout << a + b << endl;
    }

    return 0;
}