#include <iostream>

using namespace std;

int divisor(int a);

int main()
{
    int i, n, t = 0;
    while(cin >> n && n)
    {
        cout << "Case "<< ++t << ": ";
        for(i = n; i >= 1; i--)
        {
            if(divisor(i) == n)
            {
                cout << i << endl;
                break;
            }
        }
        if(i == 0)
            cout << "-1\n";
    }
    return 0;
}

int divisor(int a)
{
    int cnt = 1, p;
    for(p = 2; p <= a; p++)
    {
        if(a % p == 0)
            cnt += p;
    }
    return cnt;
}
