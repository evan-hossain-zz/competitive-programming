#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, d, r, i, j, mor[105], eve[105], taka;
    while(cin >> n >> d >> r)
    {
        taka = 0;
        if(r == 0 && n == 0 && d == 0)
            break;
        i = 0;
        while(i < n)
            cin >> mor[i++];
        i = 0;
        while(i < n)
            cin >> eve[i++];
        sort(mor, mor + n);
        sort(eve, eve + n);
        for(i = 0, j = n - 1; i < n; i++, j--)
        {
            if(mor[i]+eve[j] > d)
                taka += ((mor[i] + eve[j] - d) * r);
        }
        cout << taka << endl;
    }
    return 0;
}
