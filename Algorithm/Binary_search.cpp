#include <bits/stdc++.h>

using namespace std;

#define MAX 100000

int my_binary_search(int arr[], int low, int high, int key)
{
    int mid, pos = -1;
    while(low <= high)
    {
        mid = (low + high) >> 1;
        if(arr[mid] > key)
            high = mid - 1;
        else if(arr[mid] < key)
            low = mid + 1;
        else
        {
            pos = mid;
            high = mid - 1; // for lower bound
            // low = mid + 1 // for upper bound
        }
    }
    return pos;
}

int main()
{
    int n, key, i, arr[MAX], res;
    while(cin >> n && n)
    {
        for(i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr, arr + n);
        cout << "input list in sorted order : " ;
        for(i = 0; i < n; i++)
            cout << arr[i] << ' ';
        cout << endl;
        while(true)
        {
            cout << "search in the list for :";
            cin >> key;
            if(!key)
            {
                cout << "Enter new input Data :\n";
                break;
            }
            res = my_binary_search(arr, 0, n - 1, key);
            if(res == -1)
                cout << key << " not found in the list\n";
            else
                cout << key << " found at position : " << res + 1 << endl;
        }
    }
    return 0;
}
