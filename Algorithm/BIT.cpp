LL tree[MAX];

LL read(int idx)
{
    LL sum = 0;
    while(idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int readSingle(int idx)
{
    int sum = tree[idx]; // sum will be decreased
    if (idx > 0)  // special case
    {
        int z = idx - (idx & -idx); // make z first
        idx--; // idx is no important any more, so instead y, you can use idx
        while (idx != z)  // at some iteration idx (y) will become z
        {
            sum -= tree[idx]; // substruct tree frequency which is between y and "the same path"
            idx -= (idx & -idx);
        }
    }
    return sum;
}

void update(int idx, LL val, int n)
{
    while(idx <= n)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
/*
2D BIT
void update(int x, int y, int val)
{
    int y1;
    while (x <= max_x)
    {
        y1 = y;
        while (y1 <= max_y)
        {
            tree[x][y1] += val;
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
}

read(r1,c1,r2,c2) = read(r2,c2) - read(r2,c1-1) - read(r1-1,c2) + read(r1-1,c1-1);
int read(int x,int y)  // return sum from 1,1 to x,y.
{
    int sum= 0;
    while( x)
    {
        int y1 = y;
        while(y1)
        {
            sum += tree[x][y1];
            y1 -= y1 & -y1;
        }
        x -= x & -x;
    }
    return sum;
}*/
