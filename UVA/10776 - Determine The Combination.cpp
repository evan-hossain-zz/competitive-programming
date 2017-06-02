#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

#define pub push_back
#define pob pop_back

using namespace std;

void call(void);
int arr[35];

int size;
vector <char> res;
string s;
char track[35];

int main()
{
    while(cin >> s >> size)
    {
        sort(s.begin(), s.end());
        for(int j = 0; j < s.size(); j++)
            arr[s[j] - 97]++;
        call();
        res.clear();
    }
    return 0;
}

void call(void)
{
    if(res.size() == size)
    {
        for(int i = 0; i < size; i++)
            printf("%c", res[i]);
        printf("\n");
        return;
    }
    for(int j = 0; j < s.size(); j++)
    {
        if(track[j] == 0)
        {
            track[j] = 1, res.pub(s[j]);
            call();
            res.pob(), track[j] = 0;
        }
    }
}
