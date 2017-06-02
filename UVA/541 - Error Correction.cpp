#include <iostream>

using namespace std;

int main()
{
    char arr[105][105];
    int n, i, j, corrupt_col, corrupt_row, corrupt, error, cnt;
    while(cin >> n && n)
    {
        corrupt_col = corrupt_row = 200;
        corrupt = error = 0;
        for(i = 0; i < n; i++)
        {
            cnt = 0;
            for(j = 0; j < n; j++)
            {
                cin >> arr[i][j];
                if(arr[i][j] == '1')
                    cnt++;
            }
            if(cnt & 1)
            {
                if(!corrupt)
                {
                    if(!error)
                    {
                        if(corrupt_row == 200)
                        {
                            corrupt_row = i;
                            error = 1;
                        }
                    }
                    else
                        corrupt = 1;

                }
            }
        }
        error = 0;
        if(!corrupt)
        {
            for(i = 0; i < n; i++)
            {
                cnt = 0;
                for(j = 0; j < n; j++)
                {
                    if(arr[j][i] == '1')
                        cnt++;
                }
                if(cnt & 1)
                {
                    if(!corrupt)
                    {
                        if(!error)
                        {
                            if(corrupt_col == 200)
                            {
                                corrupt_col = i;
                                error = 1;
                            }
                        }
                        else
                            corrupt = 1;

                    }
                }
            }
        }
        if(corrupt)
            cout << "Corrupt\n";
        else if(error)
            cout << "Change bit (" << corrupt_row + 1 <<\
             "," << corrupt_col + 1 << ")\n";
        else
            cout << "OK\n";
    }
    return 0;
}
