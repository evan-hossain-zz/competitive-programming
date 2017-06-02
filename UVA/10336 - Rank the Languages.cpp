#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char grid[1000][1000], ch;
int h, w, languages[27];

void dfs(int r, int c, char ch);
int main()
{
    int i, j, test, kase = 0, max;
    scanf("%d", &test);
    while(kase < test)
    {
        memset(languages, 0, sizeof(int) * 27);
        max = 0;
        scanf("%d %d", &h, &w);
        for(i = 0; i < h; i++)
        {
            for(j = 0; j < w; j++)
                scanf(" %c", &grid[i][j]);
        }
        printf("World #%d\n", ++kase);
        for(i = 0; i < h; i++)
        {
            for(j = 0; j < w; j++)
            {
                if(grid[i][j] != 0)
                {
                    ch = grid[i][j];
                    languages[ch - 97]++;
                    if(languages[ch - 97] > max)
                        max = languages[ch - 97];
                    grid[i][j] = 0;
                    dfs(i, j, ch);
                }
            }
        }
        for(i = max; i > 0; i--)
        {
            for(j = 0; j < 26; j++)
            {
                if(i == languages[j])
                {
                    printf("%c: %d\n", j + 97, i);
                }
            }
        }
    }
    return 0;
}

void dfs(int r, int c, char ch)
{
    if(r - 1 >= 0 && grid[r - 1][c] == ch)
    {
        grid[r - 1][c] = 0;
        dfs(r - 1, c, ch);
    }
    if(c - 1 >= 0 && grid[r][c - 1] == ch)
    {
        grid[r][c - 1] = 0;
        dfs(r, c - 1, ch);
    }
    if(c + 1 < w && grid[r][c + 1] == ch)
    {
        grid[r][c + 1] = 0;
        dfs(r, c + 1, ch);
    }
    if(r + 1 < h && grid[r + 1][c] == ch)
    {
        grid[r + 1][c] = 0;
        dfs(r + 1, c, ch);
    }
}
