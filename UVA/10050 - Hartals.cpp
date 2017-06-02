#include <iostream>

using namespace std;

int main()
{
    char  days[3655];
    int t, n, p, i, j, k, l, cnt;
    cin >> t;
    while(t--)
    {
        cnt = 0;
        cin >> n;
        for(j = 1; j <= n; j++)
            days[j] = 0;
        cin >> p;
        while(p--)
        {
            cin >> i;
            for(j = i; j <= n; j += i)
            {
                if(j % 7 == 0 || (j + 1) % 7 == 0)
                    continue;
                else if(days[j] == 0)
                {
                    days[j] = 1;
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
