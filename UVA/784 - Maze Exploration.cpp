#include<cstdio>
#include<cstring>

char maze[32][82];
void dfs(int r, int c);
int max, i;
int main()
{
    int tst, j, k, x, y, l;
    scanf("%d", &tst);
    while(tst--)
    {
        i = 0;
        max = 0;
        while(scanf(" %[^\n]", maze[i]) == 1)
        {
            if(maze[i][0] == '_')
                break;
            l = strlen(maze[i]);
            if(l > max) max = l;
            while(l--)
            {
                if(maze[i][l] == '*')
                {
                    x = i;
                    y = l;
                }
            }
                i++;
        }
        maze[x][y] = '#';
        dfs(x, y);
        for(j = 0; j <= i; j++)
            printf("%s\n", maze[j]);
    }
    return 0;
}

void dfs(int r, int c)
{
    if(r - 1 >= 0)
    {
        if(maze[r - 1][c] == ' ')
        {
            maze[r - 1][c] = '#';
            dfs(r - 1, c);
        }
    }
    if(c - 1 >= 0)
    {
        if(maze[r][c - 1] == ' ')
        {
            maze[r][c - 1] = '#';
            dfs(r, c - 1);
        }
    }
    if(c + 1 < max)
    {
        if(maze[r][c + 1] == ' ')
        {
            maze[r][c + 1] = '#';
            dfs(r, c + 1);
        }
    }
    if(r + 1 < i)
    {
        if(maze[r + 1][c] == ' ')
        {
            maze[r + 1][c] = '#';
            dfs(r + 1, c);
        }
    }
}
