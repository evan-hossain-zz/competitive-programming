///calculates nCr for biiiiiiiig N with modulus

LL mod = 1000003, F[MAX]; /// F[MAX] is factorial, it needs to be pre-calculated here MAX = mod value

LL small(LL n, LL r)
{
    LL ret = bigmod(F[r], mod-2, mod) * bigmod(F[n-r], mod-2, mod);
    ret %= mod;
    ret = (F[n] * ret) % mod;
    return ret;
}

LL Lucas(LL n, LL m)
{
    if (n==0 && m==0) return 1;
    LL ni = n % mod;
    LL mi = m % mod;
    if (mi>ni) return 0;
    return (Lucas(n/mod, m/mod) * small(ni, mi)) % mod;
}

void pre()
{
    LL i;
    F[0]=F[1]=1;
    for(i=2;i<MAX;i++)
        F[i]=(i * F[i-1])%mod;
}
