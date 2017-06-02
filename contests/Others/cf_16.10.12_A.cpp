#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

struct info{
        int roll;
        char hand;
    };

bool comp(const info &a, const info &b)
{
    return a.hand < b.hand;
}
int main()
{
    info arr[110];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf(" %c", &arr[i].hand);
        arr[i].roll = i + 1;
    }
    sort(arr, arr + n, comp);
    for(int i = 0; i < n; i++)
    {
        int diff = abs(arr[i].roll - arr[i + 1].roll);
        if(diff == 1)
            swap(arr[i].roll, arr[i + 1].roll);
    }
    for(int i = 0; i < n; i += 2)
        cout << arr[i].roll << " " << arr[i + 1].roll << endl;
}
