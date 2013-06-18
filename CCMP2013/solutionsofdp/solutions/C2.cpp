#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<math.h>
#include<time.h>
#include<assert.h>

#define SZ 17
#define MOD 1000000007

using namespace std;

typedef pair<long long, long long> PII;

int p2toi[1 << SZ];

long long prime[SZ];
int cnt[SZ];
long long mpval[SZ];
long long lpsum[SZ];
long long modinv[SZ];

long long msod[1 << SZ];
long long mnod[1 << SZ];
long long lsod[1 << SZ];
long long lnod[1 << SZ];
long long mp[1 << SZ];



int p2[SZ];
int n;

bool flag[1005];
bool isprime(int n)
{
    int i;
    int sq = sqrt((double)n) + 2;
    if(n == 2)
        return true;
    for(i = 3; i < sq; i += 2)
    {
        if((n % i) == 0)
        {
            return false;
        }
    }
    return true;
}

int flipb(int bits)
{
    bits = ~bits;
    bits = (bits & (p2[n] - 1));
    return bits;
}


void process(int ind)
{
    int i;
    //long long sum = 0;
    mpval[ind] = 1;
    lpsum[ind] = 0;
    for(i = 0; i < cnt[ind]; i++)
    {
        lpsum[ind] = (lpsum[ind] + mpval[ind]) % MOD;
        mpval[ind] = (mpval[ind] * prime[ind]) % MOD;
    }
    //mpval[ind] = (mpval[ind] * prime[ind]) % MOD;
}

long long sod(int bitmsk, bool ismax)
{
    if(bitmsk == 0)
        return 1;

    int lstbit = (bitmsk & ~(bitmsk - 1));
    long long ret;

    if(ismax == true)
        ret = msod[bitmsk];
    else
        ret = lsod[bitmsk];

    if(ret != -1)
        return ret;

    int ind = p2toi[lstbit];
    int nbitmsk = (bitmsk ^ lstbit);
    long long tmp;
    if(ismax == true)
    {
        tmp = (lpsum[ind] + mpval[ind]) % MOD;
        ret = (tmp * sod(nbitmsk, ismax)) % MOD;
        msod[bitmsk] = ret;
    }
    else
    {
        tmp = lpsum[ind];
        ret = (tmp * sod(nbitmsk, ismax)) % MOD;
        lsod[bitmsk] = ret;
    }

    return ret;
}

long long nod(int bitmsk, bool ismax)
{
    if(bitmsk == 0)
        return 1;

    int lstbit = (bitmsk & ~(bitmsk - 1));
    long long ret;

    if(ismax == true)
        ret = mnod[bitmsk];
    else
        ret = lnod[bitmsk];

    if(ret != -1)
        return ret;

    int ind = p2toi[lstbit];
    int nbitmsk = (bitmsk ^ lstbit);
    if(ismax == true)
    {
        ret = ((cnt[ind] + 1) * nod(nbitmsk, ismax)) % MOD;
        mnod[bitmsk] = ret;
    }
    else
    {
        ret = (cnt[ind] * nod(nbitmsk, ismax)) % MOD;
        lnod[bitmsk] = ret;
    }

    return ret;
}

long long getmp(int bitmsk, bool isone)
{
    if(bitmsk == 0)
        return 1;
    int lstbit = (bitmsk & ~(bitmsk - 1));
    long long ret = mp[bitmsk];
    if(ret != -1)
    {
        return ret;
    }
    int ind = p2toi[lstbit];
    int nbitmsk = (bitmsk ^ lstbit);
    ret = (mpval[ind] * getmp(nbitmsk, isone)) % MOD;
    mp[bitmsk] = ret;
    return ret;
}

long long getval(int bitmsk)
{
    long long ret = 0;
    long long tmp1 = 1;
    long long tmp2 = 1;

    int nbitmsk = flipb(bitmsk);

    tmp1 = (tmp1 * getmp(bitmsk, true)) % MOD;

    tmp1 = (tmp1 * sod(nbitmsk, false)) % MOD;
    tmp1 = (tmp1 * nod(bitmsk, true)) % MOD;

    tmp2 = (tmp2 * getmp(nbitmsk, false)) % MOD;

    tmp2 = (tmp2 * nod(nbitmsk, false)) % MOD;
    tmp2 = (tmp2 * sod(bitmsk, true)) % MOD;

    ret = (tmp1 + tmp2) % MOD;

    return ret;
}

int main()
{
    //freopen("LCMPSum.in", "rt", stdin);
    //freopen("LCMPSum.ans", "wt", stdout);
    double cl = clock();
    int inp, i, kase;

    p2[0] = 1;
    p2toi[1] = 0;
    long long num;
    long long md2 = (MOD + 1) / 2;
    for(i = 1; i < SZ; i++)
    {
        p2[i] = p2[i - 1] * 2;
        p2toi[p2[i]] = i;
    }
    scanf("%d", &inp);
    assert(inp > 0 && inp <= 500);

    for(kase = 1; kase <= inp; kase++)
    {
        memset(msod, -1, sizeof(msod));
        memset(mnod, -1, sizeof(mnod));
        memset(lsod, -1, sizeof(lsod));
        memset(lnod, -1, sizeof(lnod));
        memset(mp, -1, sizeof(mp));
        scanf("%d", &n);

        assert(n >= 1 && n <= 15);
        memset(flag, false, sizeof(flag));


        num = 1;
        for(i = 0; i < n; i++)
        {
            scanf("%lld %d", &prime[i], &cnt[i]);

            assert(prime[i] >= 2 && prime[i] <= 1000);
            assert(isprime(prime[i]));
            assert(flag[prime[i]] == false);
            flag[prime[i]] = true;
            assert(cnt[i] >=1 && cnt[i] <= 50);


            process(i);
            num = (num * mpval[i]) % MOD;
        }
        long long res = 0;
        for(i = 0; i < p2[n]; i++)
        {
            res = (res + getval(i)) % MOD;
        }
        num = (num * 2) % MOD;
        res = (res + MOD - num) % MOD;
        res = (res * md2) % MOD;
        res = (res + num) % MOD;
        printf("Case %d: %lld\n", kase, res);
        //fprintf(stderr, "Case %d Completed!\n", kase);
    }
    assert(scanf("%d", &n) == EOF);
    cl = clock() - cl;
    fprintf(stderr, "Total Time: %lf\n", cl / CLOCKS_PER_SEC);
    return 0;
}
