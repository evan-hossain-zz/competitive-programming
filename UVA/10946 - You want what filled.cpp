#include<cstdio>
#include<cstdlib>

typedef struct
{
    char ch;
    int n;
} strct;

int comp(const void *a, const void *b)
{
    int p = ((strct *) a)->n;
    int q = ((strct *) b)->n;
    if(p != q)
        return p - q;
    else
    p = ((strct *) a)->ch;
    q = ((strct *) b)->ch;
        return p - q;
}
void dfs(int r, int c, char x);

int cnt, x, y, max;
char grid[500][500], ltr;

int main()
{
    int i, j, k, l, h, kase = 0, limit;
    while(scanf("%d %d", &x, &y) == 2)
    {
        strct holes[2500] = {0};
        max = h = 0;
        if(x == 0 && y == 0) break;
        for(i = 0; i < x; i++)
        {
            for(j = 0; j < y; j++)
                scanf(" %c", &grid[i][j]);
        }
        for(i = 0; i < x; i++)
        {
            for(j = 0; j < y; j++)
            {
                if(grid[i][j] >= 'A' && grid[i][j] <= 'Z')
                {
                    cnt = 0;
                    holes[h].ch = ltr = grid[i][j];
                    grid[i][j] = 0;
                    dfs(i, j, ltr);
                    holes[h].n = cnt;
                    if(cnt > max) max = cnt;
                    h++;
                }
            }
        }
        limit = x * y;
        qsort(holes, limit, sizeof(strct), comp);
        printf("Problem %d:\n", ++kase);
        for(i = max; i > 0; i--)
        {
            for(j = 0; j < limit; j++)
            {
                if(holes[j].n == i)
                    printf("%c %d\n", holes[j].ch, holes[j].n);
            }
        }
    }
    return 0;
}

void dfs(int r, int c, char ltr)
{
    cnt++;
    if(r - 1 >= 0)
    {
        if(grid[r - 1][c] == ltr)
        {
            grid[r - 1][c] = 0;
            dfs(r - 1, c, ltr);
        }
    }
    if(c - 1 >= 0)
    {
        if(grid[r][c - 1] == ltr)
        {
            grid[r][c - 1] = 0;
            dfs(r, c - 1, ltr);
        }
    }
    if(c + 1 < y)
    {
        if(grid[r][c + 1] == ltr)
        {
            grid[r][c + 1] = 0;
            dfs(r, c + 1, ltr);
        }
    }
    if(r + 1 < x)
    {
        if(grid[r + 1][c] == ltr)
        {
            grid[r + 1][c] = 0;
            dfs(r + 1, c, ltr);
        }
    }
}
