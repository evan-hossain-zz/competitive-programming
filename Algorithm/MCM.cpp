#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

int cost[MAX][MAX], partition_at[MAX][MAX];

void matrix_chain_order(vector <int> p)
//p = row dimensions of every matrix
{
    int i, j, l, k, q, n = p.size() - 1;
    for(i = 1; i <= n; i++)
        cost[i][i] = 0;
    for(l = 2; l <= n; l++) // chain length
    {
        for(i = 1; i <= n - l + 1; i++)
        {
            j = i + l - 1;
            cost[i][j] = 1 << 30;
            for(k = i; k <= j - 1; k++) // partition:(i - k)(k + 1 - j)
            {
                q = cost[i][k] + cost[k + 1][j] + (p[i - 1] * p[k] * p[j]);
                if(q < cost[i][j])
                {
                    cost[i][j] = q;
                    partition_at[i][j] = k; // save optimal partitioning
                }
            }
        }
    }
}

void print_parens(int i, int j)
{
    if(i == j)
        cout << "A" << i;
    else
    {
        cout << "(";
        print_parens(i, partition_at[i][j]);
        print_parens(partition_at[i][j] + 1, j);
        cout << ")";
    }
}

int main()
{
    int N, i, n, m, j;
    vector <int> p;
    while(cin >> N && N)
    {
        p.clear();
        for(i = 1; i <= N; i++)
        {
            cin >> n >> m;
            p.push_back(n);
        }
        p.push_back(m);
        matrix_chain_order(p);
        print_parens(1, N);
        cout << endl;
    }
    return 0;
}
