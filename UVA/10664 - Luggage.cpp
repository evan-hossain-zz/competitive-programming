#include <iostream>
#include <algorithm>

using namespace std;

int cap, n, weight[200];
int calc(int i, int w);
int main()
{
    int tst, k, res;
    cin >> tst;
    while(tst--)
    {
        cin >> n;
        k = 1;
        while(k <= n)
            cin >> weight[k++];
        if(n % 2 != 0)
            cout << "no\n";
        else
        {
            cap = n / 2;
            res = calc(1, 0);
            if(res == cap)
                cout << "yes\n";
            else
                cout << "no\n";
        }
    }
}

int calc(int i, int w)
{
    int way1, way2;
    if(i > n) return 0;
    if(dp[i] != -1)
        return dp[i];
    if(w + weight[i] <= cap)
        way1 = weight[i] + calc(i + 1, weight[i]);
    else
        way1 = 0;
    way2 = calc(i + 1, w);
    ans = max(way1, way2);
    return ans;
}
