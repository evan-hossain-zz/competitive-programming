#include <iostream>

using namespace std;

int arr[100];

int main()
{
    int i, j, r, c, kase, m, n, t = 0, max, cnt;
    char ch;
    cin >> kase;
    while(t < kase)
    {
        max = cnt = 0;
        cin >> r >> c >> m >> n;
        for(i = 0; i < r; i++)
        {
            for(j = 0; j < c; j++)
            {
                cin >> ch;
                arr[ch]++;
                if(max < arr[ch])
                    max = arr[ch];
            }
        }
        for(i = 'A'; i <= 'Z'; i++)
        {
            if(arr[i] == max)
            {
                cnt += (m * max);
                arr[i] = 0;
            }
            else if(arr[i])
            {
                cnt += (n * arr[i]);
                arr[i] = 0;
            }
        }
        cout << "Case " << ++t << ": " << cnt << endl;
    }
    return 0;
}
