#include <stdio.h>
#include <cstring>
#include <vector>
#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 510

int arr[3];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int _set, _pair, _nopair;
    while(cin >> arr[0] >> arr[1] >> arr[2])
    {
        if(arr[0] + arr[1] + arr[2] == 0)
            break;
        _pair = _nopair = _set = 0;
        sort(arr, arr + 3);
        if(arr[0] == arr[2])
            _set = 1;
        else if(arr[0] == arr[1] || arr[1] == arr[2])
            _pair = 1;
        else _nopair = 1;
        bool flag = false;
        if(_set)
        {
            if(arr[0] != 13)
                arr[0]++, arr[1]++, arr[2]++;
            else
                flag = true;
        }
        else if(_pair)
        {
            if(arr[1] == arr[2])
            {
                if(arr[0] != 12)
                {
                    arr[0]++;
                    if(arr[0] == arr[1])
                        if(arr[0] != 13)
                            arr[0]++;
                }
                else
                    arr[0] = arr[1] = arr[2] = 1;
            }
            else
                if(arr[2] != 13)
                {
                    arr[2]++;
                    if(arr[2] == arr[1])
                        if(arr[2] != 13)
                            arr[2]++;
                }
                else
                    arr[1] = arr[2] = arr[0] + 1, arr[0] = 1;
        }
        else
        {
            arr[0] = arr[1] = 1;
            arr[2] = 2;
        }
        sort(arr, arr + 3);
        if(!flag)
        cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;
        else
            cout << "*" << endl;

    }
    return 0;
}

