#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

int C[MAX], sorted_array[MAX], arr[MAX];

int counting_sort(int *arr, int n)
{
    int i, mx = *max_element(arr, arr + n + 1);
    memset(C, 0, sizeof C);
    for(i = 1; i <= n; i++)
        C[arr[i]]++;
    for(i = 1; i <= mx; i++)
        C[i] += C[i - 1];
    for(i = n; i > 0; i--)
    {
        sorted_array[C[arr[i]]] = arr[i];
        C[arr[i]]--;
    }
    for(i = 1; i <= n; i++)
        arr[i] = sorted_array[i];
}

int main()
{
    int n, i;
    while(cin >> n && n)
    {
        for(i = 1; i <= n; i++)
            cin >> arr[i];
        counting_sort(arr, n);
        cout << endl << "sorted :";
        for(i = 1; i <= n; i++)
            cout << ' ' << arr[i];
        cout << endl;
    }
}
