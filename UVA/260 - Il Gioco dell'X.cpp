#include<cstdio>
#include<cctype>

void bdfs(int r, int c);
void wdfs(int r, int c);
int m, paisi, cnt;
char board[205][205];
int main()
{
    int i, j, k = 0;
    while(scanf("%d", &m) == 1 && m)
    {
        cnt = 0;
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < m; j++)
                scanf(" %c", &board[i][j]);
        }
        printf("%d ", ++k);
        for(j = 0; j < m; j++)
        {
            if(board[0][j] == 'b')
            {
                board[0][j] = 0;
                bdfs(0, j);
                if(cnt == 1)
                {
                    printf("B\n");
                    break;
                }
            }
        }
        if(cnt == 0)
        {
            for(i = 0; i < m; i++)
            {
                if(board[i][0] == 'w')
                {
                    board[i][0] = 0;
                    wdfs(i, 0);
                    if(cnt == 1)
                {
                    printf("W\n");
                    break;
                }
                }
            }
        }

    }
    return 0;
}
void bdfs(int r, int c)
{

    int p, q;
    for(p = r - 1; p <= r + 1; p++)
    {
        if(p >= 0 && p < m)
        {
            for(q = c - 1; q <= c + 1; q++)
            {
                if(q >= 0 && q < m)
                {
                    if((p == r + 1 && q == c - 1) ||
                            (p == r - 1 && q == c + 1))
                        continue;
                    else
                    {
                        if(board[p][q] == 'b')
                        {
                            if(p == m - 1)
                            {
                                cnt = 1;
                                return ;
                            }
                            board[p][q] = 0;
                            bdfs(p, q);
                        }
                    }
                }
            }
        }
    }
}

void wdfs(int r, int c)
{
    int p, q;
    for(p = r - 1; p <= r + 1; p++)
    {
        if(p >= 0 && p < m)
        {
            for(q = c - 1; q <= c + 1; q++)
            {
                if(q >= 0 && q < m)
                {
                    if((p == r + 1 && q == c - 1) ||
                            (p == r - 1 && q == c + 1))
                        continue;
                    else
                    {
                        if(board[p][q] == 'w')
                        {
                            if(q == m - 1)
                            {
                                cnt = 1;
                                return ;
                            }
                            board[p][q] = 0;
                            wdfs(p, q);
                        }
                    }
                }
            }
        }
    }
}
