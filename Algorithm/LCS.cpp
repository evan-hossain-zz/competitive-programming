#include <bits/stdc++.h>

using namespace std;

int arr[1010][1010];

int main()
{
    string a, b;
    int i, j;
    while(cin >> a && a != "#")
    {
        cin >> b;
        for(i = 1; i <= a.size(); i++)
        {
            for(j = 1; j <= b.size(); j++)
            {
                if(a[i-1] == b[j-1])
                    arr[i][j] = arr[i-1][j - 1] + 1;
                else
                    arr[i][j] = max(arr[i-1][j], arr[i][j - 1]);
            }
        }
        cout << "Length of Longest common subsequence is ";
        printf("%d\n", arr[i - 1][j - 1]);
        for(i = 0; i <= max(a.size(), b.size()); i++)
            arr[i][0] = arr[0][i] = 0;
    }
    return 0;
}

