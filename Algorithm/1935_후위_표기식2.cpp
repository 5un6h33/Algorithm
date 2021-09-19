#include<iostream>
#include<stack>
#include<string>

#define MAX 26

using namespace std;

int alphabet[MAX];

int main(void)
{
    int n, len;
    cin >> n;

    string str;
    cin >> str;

    for(int i = 0; i < n; i++)
        cin >> alphabet[i];

    stack<double> s;

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            double oper2 = s.top();
            s.pop();
            double oper1 = s.top();
            s.pop();

            switch (str[i])
            {
            case '+':
                s.push(oper1 + oper2);
                break;
            case '-':
                s.push(oper1 - oper2);
                break;
            case '*':
                s.push(oper1 * oper2);
                break;
            case '/':
                s.push(oper1 / oper2);
                break;
            }
        }
        else 
            s.push(alphabet[str[i] - 'A']);
    }

    cout << fixed;
    cout.precision(2);
    cout << s.top();

    return 0;
}