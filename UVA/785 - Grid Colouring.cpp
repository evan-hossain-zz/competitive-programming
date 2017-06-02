#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char grid[32][82], ch, col[32][82];
void dfs(int r, int c, char ch);
int row, climit[82], len;
int main()
{
    char contour = 0;
    int colum = 0, l = 0, i, j;
    while(gets(grid[row]))
    {
        if(contour == 0)
        {
            for(i = 0; i < strlen(grid[row]); i++)
            {
                if(grid[row][i] == ' ' || grid[row][i] == '_')
                    continue;
                else
                {
                    contour = grid[row][i];
                    break;
                }
            }
        }
        if(grid[row][0] == '_')
        {
            for(i = 0; i < row; i++)
            {
                for(j = 0; j < climit[i]; j++)
                {
                    if(grid[i][j] == contour || grid[i][j] == ' ')
                        continue;
                    else
                    {
                        ch = grid[i][j];
                        col[i][j] = 1;
                        dfs(i, j, ch);
                    }
                }
            }
            for(i = 0; i < row; i++)
            {
                for(j = 0; j < climit[i]; j++)
                    printf("%c", grid[i][j]);
                printf("\n");
            }
            printf("%s\n", grid[row]);
            row = 0;
            len = 0;
            memset(climit, 0, sizeof(climit));
            memset(grid, 0, sizeof(grid));
            memset(col, 0, sizeof(col));
            ch = getchar();
            if(ch == '\n')
                printf("\n");
            contour = 0;
        }
        else
        {
            climit[row] = strlen(grid[row]);
            len = max(climit[row], len);
            row++;
        }

    }
    return 0;
}

void dfs(int r, int c, char ch)
{
    if(r - 1 >= 0)
    {
        if(grid[r - 1][c] == ' ' && col[r - 1][c] != 1)
        {
            grid[r - 1][c] = ch;
            col[r - 1][c] = 1;
            dfs(r - 1, c, ch);
        }
    }
    if(c - 1 >= 0)
    {
        if(grid[r][c - 1] == ' ' && col[r][c - 1] != 1)
        {
            grid[r][c - 1] = ch;
            col[r][c - 1] = 1;
            dfs(r, c - 1, ch);
        }
    }
    if(c + 1 < len)
    {
        if(grid[r][c + 1] == ' ' && col[r][c + 1] != 1)
        {
            grid[r][c + 1] = ch;
            col[r][c + 1] = 1;
            dfs(r, c + 1, ch);
        }
    }
    if(r + 1 < row)
    {
        if(grid[r + 1][c] == ' ' && col[r + 1][c] != 1)
        {
            grid[r + 1][c] = ch;
            col[r + 1][c] = 1;
            dfs(r + 1, c, ch);
        }
    }
}

