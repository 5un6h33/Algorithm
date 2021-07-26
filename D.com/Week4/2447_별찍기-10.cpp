#include<iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int count = n / 3;
            while(count != 0)
            {
                if((i / count) % 3 == 1 && (j / count) % 3 == 1)
                {
                    cout << " ";
                    break;
                }
                count /= 3;
            }
            if(count == 0)
            {
                cout << "*";
            }
        }
        cout << endl;
    }

    return 0;
}