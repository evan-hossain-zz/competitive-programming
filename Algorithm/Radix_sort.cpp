#include <bits/stdc++.h>

using namespace std;

#define MAX 10000
#define LL long long

void radix_sort(LL arr[], int n)
{
    int C[260], i;
    LL sorted_array[n + 1], mask = (1LL << 8) - 1, pos = 0;
    while(mask < (1LL << 32))
    {
        memset(C, 0, sizeof C);
        for(i = 1; i <= n; i++)
            C[(mask & arr[i]) >> pos]++;
        for(i = 1; i <= 258; i++)
            C[i] += C[i - 1];
        for(i = n; i > 0; i--)
        {
            sorted_array[C[(mask & arr[i]) >> pos]] = arr[i];
            C[(mask & arr[i]) >> pos]--;
        }
        for(i = 1; i <= n; i++)
            arr[i] = sorted_array[i];
        mask = mask << 8;
        pos += 8;
    }
}

int main()
{
    int n, i;
    LL arr[MAX];
    while(cin >> n && n)
    {
        for(i = 1; i <= n; i++)
            cin >> arr[i];
        radix_sort(arr, n);
        cout << endl << "sorted :";
        for(i = 1; i <= n; i++)
            cout << ' ' << arr[i];
        cout << endl;
    }
    return 0;
}
