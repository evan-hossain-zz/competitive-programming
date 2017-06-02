#include <stdio.h>

void  dfs(int row, int col);
int findT(int row, int col);

int checkx[4] = {1, 0, -1, 0},\
checky[4] = {0, -1, 0, 1};

char grid[55][55];

int r, c, cnt, w, h;

int main()
{
    int i, j;
    while(scanf("%d %d", &w, &h) == 2)
    {
        for(i = 0; i < h; i++)
        {
            for(j = 0; j < w; j++)
            {
                scanf(" %c", &grid[i][j]);
                if(grid[i][j] == 'P')
                {
                    r = i;
                    c = j;
                }
            }
        }
        cnt = 0;
        if(findT(r, c))
            dfs(r, c);
        printf("%d\n", cnt);
    }
    return 0;
}

void dfs(int row, int col)
{
    int p, val, x, y;
    for(p = 0; p < 4; p++)
    {
        x = col + checkx[p];
        y = row + checky[p];
        if((y >= 0 && y < h)
        && (x >= 0 && x < w))
        {
            if(grid[y][x] != 0 &&
            grid[y][x] != '#')
            {
                if(grid[y][x] == 'G')
                    cnt++;
                val = findT(y, x);
                if(val)
                {
                    grid[y][x] = 0;
                    dfs(y, x);
                }
                else
                    grid[y][x] = 0;
            }
        }
    }
    return;
}

int findT(int row, int col)
{
    int q, x2, y2;
    for(q = 0; q < 4; q++)
    {
        x2 = col + checkx[q];
        y2 = row + checky[q];
        if((y2 >= 0 && y2 < h)
                && (x2 >= 0 && x2 < w))
        {
            if(grid[y2][x2] == 'T')
                return 0;
        }
    }
    return 1;
}
