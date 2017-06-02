#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

void insertion_sort(int arr[], int n)
{
    int cur, i, j;
    for(i = 1; i < n; i++)
    {
        cur = arr[i];
        j = i - 1;
        while(j >= 0 && cur < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = cur;
    }
}


int main()
{
    int arr[MAX], i, n;
    while(cin >> n && n)
    {
        for(i = 0; i < n; i++)
            cin >> arr[i];
        insertion_sort(arr, n);
        cout << endl << "sorted list :";
        for(i = 0; i < n; i++)
            cout << ' ' << arr[i];
        cout << endl;
    }
}
