#include<iostream>
#include<math.h>
using namespace std;

int main(void)
{
    int t, x1, y1, r1, x2, y2, r2, d, cond1, cond2;

    cin >> t;

    while(t--)
    {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        d = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
        cond1 = (r2 - r1) * (r2 - r1);
        cond2 = (r2 + r1) * (r2 + r1);

        if(d == 0)
        {
            if(cond1 == 0)
                cout << -1 << endl;
            else
                cout << 0 << endl;
        }
        else
        {
            if(d == cond1 || d == cond2)
                cout << 1 << endl;
            else if(cond1 < d && d < cond2)
                cout << 2 << endl;
            else
                cout << 0 << endl;
        }
    }

    return 0;
}