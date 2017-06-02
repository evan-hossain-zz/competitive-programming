#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int arr[10010], m;

bool comp(const int &p, const int &q)
{
    int a = p % m, b = q % m;
    if(a == b)
    {
        if((p & 1) == 0 && (q & 1) == 0)
            return p < q;
        else if((p & 1) != 0 && (q & 1) != 0)
            return p > q;
        else
            return ((p & 1) != 0);
    }
    return a < b;
}

int main()
{
    int n, i;
    while(scanf("%d %d", &n, &m) && n)
    {
        printf("%d %d\n", n, m);
        i = 0;
        while(i < n)
            scanf("%d", &arr[i++]);
        sort(arr, arr + n, comp);
        for(i = 0; i < n; i++)
            printf("%d\n", arr[i]);
    }
    printf("0 0\n");
    return 0;
}
