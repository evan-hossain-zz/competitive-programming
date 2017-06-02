#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int x, y, max = -1, min = 1000000005, cnt = 1, n, paisi;
    scanf("%d", &n);
    vector <int> v;
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        if(x <= min && y >= max)
        {
            min = x, max = y;
            paisi = i;
        }
        v.push_back(x), v.push_back(y);
    }
    sort(v.begin(), v.end());
    if(min <= v[0] && max >= v[v.size() - 1])
        printf("%d", paisi + 1);
    else
        printf("-1");
    return 0;
}
