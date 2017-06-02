LL tree[MAX], A[MAX], B[MAX], n;

LL read(int idx)
{
    LL sum = 0;
    while(idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, LL val)
{
    while(idx <= n)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    CF
    int test, i;
    LL res;
    cin >> test;
    while(test--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> A[i], B[i] = A[i];
        clr(tree, 0);
        sort(B, B + n);
        for(i = 0; i < n; i++)
            A[i] = (lower_bound(B, B + n, A[i]) - B) + 1;
        res = 0;
        for(i = n - 1; i >= 0; i--)
        {
            res += read(A[i] - 1);
            update(A[i], 1);
        }
        cout << res << "\n";
    }
    return 0;
}

