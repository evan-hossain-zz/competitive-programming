LL segtree[SZ * 4], beg, en, sum;
LL lazy[SZ * 4];
int main()
{
    int n, q, t, i, c, val;
    scanf("%d", &t);
    for(int kase = 1; kase <= t; kase++)
    {
        scanf("%d %d", &n, &q);
        printf("Case %d:\n", kase);
        clr(segtree, 0);
        clr(lazy, 0);
        for(i = 0; i < q; i++)
        {
            scanf(" %d", &c);
            if(!c)
            {
                scanf("%d %d %d", &beg, &en, &val);
                beg++, en++;
                lazy_update(1, n, 1, val);
            }
            else
            {
                scanf("%d %d", &beg, &en);
                beg++, en++;
                printf("%lld\n", query(1, n, 1));
            }
        }
    }
    return 0;
}

void lazy_update(int lef, int rig, int cur, int val)
{
    if(lazy[cur])
    {
        segtree[cur] += (rig - lef + 1) * lazy[cur];
        if(lef != rig)
        {
            lazy[cur << 1] += lazy[cur];
            lazy[(cur << 1) + 1] += lazy[cur];
        }
        lazy[cur] = 0;
    }
    if(lef > en || rig < beg)
        return;
    if(lef >= beg && rig <= en)
    {
        segtree[cur] += (rig - lef + 1) * val;
        if(rig != lef)
        {
            lazy[cur << 1] += val;
            lazy[(cur << 1) + 1] += val;
        }
        return;
    }
    lazy_update(lef, (lef + rig) >> 1, cur << 1, val);
    lazy_update(((lef + rig) >> 1) + 1, rig, (cur << 1) + 1, val);
    segtree[cur] = segtree[cur << 1] + segtree[(cur << 1) + 1];
}

LL query(int lef, int rig, int cur)
{
    if(lazy[cur])
    {
        segtree[cur] += (rig - lef + 1) * lazy[cur];
        if(lef != rig)
        {
            lazy[cur << 1] += lazy[cur];
            lazy[(cur << 1) + 1] += lazy[cur];
        }
        lazy[cur] = 0;
    }
    if(lef > en || rig < beg)
        return 0;
    if(lef >= beg && rig <= en)
        return segtree[cur];
    return query(lef, (lef + rig) >> 1, cur << 1) + query(((lef + rig) >> 1) + 1, rig, (cur << 1) + 1);
}

