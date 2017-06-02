#include <iostream>
#include <stack>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

int main()
{
    stack <char> stk;
    char ch, temp, s[5];
    map <char, int> m;
    m['+'] = m['-'] = 1;
    m['*'] = m['/'] = 2;
    string input;
    int test, i, j;
    cin >> test;
    getchar();
    while(test--)
    {
        gets(s);
        if(strlen(s) != 0)
        {
            sscanf(s, "%c", &ch);
            input += ch;
        }
        while(gets(s))
        {
            if(strlen(s) == 0)
                break;
            sscanf(s, "%c", &ch);
            input += ch;
        }
        input += ')';
        stk.push('(');
        for(i = 0; i < input.size(); i++)
        {
            if(input[i] >= '0' && input[i] <= '9')
                cout << input[i];
            else if(input[i] == ')')
            {
                temp = stk.top();
                while(temp != '(')
                {
                    cout << temp;
                    stk.pop();
                    temp = stk.top();
                }
                stk.pop();
            }
            else if(m[input[i]] == 1 || m[input[i]] == 2)
            {
                temp = stk.top();
                while(m[temp] >= m[input[i]] && temp != '(')
                {
                    cout << temp;
                    stk.pop();
                    temp = stk.top();
                }
                stk.push(input[i]);
            }
            else
                stk.push(input[i]);
        }
        cout << endl;
        if(test)
            cout << endl;
        while(!stk.empty())
            stk.pop();
        input.clear();
    }
    return 0;
}
