#include <iostream>
#include <cstdio>
#include <vector>

#define pub push_back
#define pob pop_back

using namespace std;

void call(void);

int taken[6], s[15], k, start;
vector <int> res;

int main()
{
    int cnt = 0;
    while(scanf("%d", &k) == 1 && k)
    {
        if(cnt)
            printf("\n");
        cnt++;
        for(int i = 0; i < k; i++)
            scanf("%d", &s[i]);
        call();
    }
    return 0;
}

void call(void)
{
    for(int i = 0; i < k - 5; i++)
    {
        for(int j = i + 1; j < k - 4; j++)
        {
            for(int l = j + 1; l < k - 3; l++)
            {
                for(int m = l + 1; m < k - 2; m++)
                {
                    for(int n = m + 1; n < k - 1; n++)
                    {
                        for(int o = n + 1; o  < k; o++)
                            printf("%d %d %d %d %d %d\n",\
                        s[i], s[j], s[l], s[m], s[n], s[o]);
                    }
                }
            }
        }
    }
}
