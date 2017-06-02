#include <iostream>
#include <algorithm>

using namespace std;
int com(const int &a, const int &b)
{
    return b < a;
}
int main()
{
    int items[20010], i, ans, n, test;
    cin >> test;
    while(test--)
    {
        cin >> n;
        i = ans = 0;
        while(i < n)
            cin >> items[i++];
        sort(items, items + n, com);
        for(i = 2; i < n; i += 3)
            ans += items[i];
        cout << ans << endl;
    }
    return 0;
}
