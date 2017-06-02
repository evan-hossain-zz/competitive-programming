#include <bits/stdc++.h>

using namespace std;

int arr[1000];
void qsort(int beg, int en)
{
    int loc = beg, right = en, left = beg;
    while(true)
        {
            while(arr[loc] <= arr[right] && loc != right)
                right--;
            if(loc == right)
                break;
            swap(arr[loc], arr[right]);
            loc = right;
            while(arr[left] <= arr[loc] && loc != left)
                left++;
            if(loc == left)
                break;
            swap(arr[left], arr[loc]);
            loc = left;
        }
    if(loc > beg)
        qsort(beg, loc - 1);
    if(loc < en)
        qsort(loc + 1, en);
    return;
}

int main()
{
    int n, i;
    while(cin >> n && n)
        {
            for(i = 0; i < n; i++)
                cin >> arr[i];
            qsort(0, n - 1);
            cout << "Sorted List :";
            for(i = 0; i < n; i++)
                cout << arr[i] << ' ';
            cout << endl;
        }
    return 0;
}
