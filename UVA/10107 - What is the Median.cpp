#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

#define pub push_back

using namespace std;

int main()
{
    vector <int> v;
    int n;
    while(scanf("%d", &n) == 1)
    {
        v.pub(n);
        sort(v.begin(), v.end());
        int l = v.size(), i;
        if(!(l & 1))
            printf("%d\n", (v[l >> 1] + v[(l >> 1) - 1]) >> 1);
        else
            printf("%d\n", v[l >> 1]);
    }
    return 0;
}
