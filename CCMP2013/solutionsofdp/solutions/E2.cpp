#include<stdio.h>
#include<vector>
#include<time.h>
#include<utility>
#include<algorithm>
using namespace std;

#define maxN 700
#define MOD 1000003

//typedef __int64 LL;
typedef long long LL;

int quad[maxN];
LL tx[maxN], ty[maxN];
LL nmx[maxN], nmy[maxN];

int id[3*maxN];
int n, x[maxN], y[maxN], nn;

bool cmp_ang(int a, int b)
{
    if(quad[a]!=quad[b]) return quad[a]<quad[b];

    return nmx[a]*nmy[b] - nmy[a]*nmx[b]>0;
}

void arrange_around(int a)
{
    int cx, cy, i;

    cx = x[a];
    cy = y[a];

    for(i=0;i<n;i++)
    {
        id[i] = i;
        nmx[i] = x[i] - cx;
        nmy[i] = y[i] - cy;

        if(nmx[i]>=0 && nmy[i]>=0) quad[i]=1;
        else if(nmx[i]<=0 && nmy[i]>=0) quad[i]=2;
        else if(nmx[i]<=0 && nmy[i]<=0) quad[i]=3;
        else quad[i]=4;
    }

    nn=n-1;

    //	swap(id[nn], id[a]);
    swap(nmx[nn], nmx[a]); 
    swap(nmy[nn], nmy[a]);
    swap(quad[nn], quad[a]);

    sort(id+0, id+nn, cmp_ang);

    for(i=0;i<nn;i++) 
    {
        id[i+nn] = id[i+2*nn] = id[i];
        tx[i] = (nmx[i]+MOD+MOD)%MOD;
        ty[i] = (nmy[i]+MOD+MOD)%MOD;
    }
}

LL BigMod(LL a, LL b)
{
    if(b==0) return 1;
    LL x = BigMod(a,b/2);
    x = (x*x)%MOD;
    if(b&1) x = (x*a)%MOD;
    return x;
}

int ccw(int id1, int id2)
{
    id1 = id[id1];
    id2 = id[id2];

    return nmx[id1]*nmy[id2] - nmy[id1]*nmx[id2] > 0;
}


LL f1() //2*concave + 4*convex
{
    LL ret, leftx, lefty, rightx, righty, to_add;
    int at, left, right, cnt_left, cnt_right;

    ret = 0;

    at = nn;

    left=nn;
    leftx = lefty = 0;
    while( left+1<at+nn && ccw(at, left+1) ) 
    {
        left++;

        leftx = (leftx + tx[ id[left] ])%MOD;
        lefty = (lefty + ty[ id[left] ])%MOD;
    }

    right=nn;
    rightx = righty = 0;
    while( right-1>at-nn && ccw(right-1, at) ) 
    {
        right--;

        rightx = (rightx + tx[ id[right] ])%MOD;
        righty = (righty + ty[ id[right] ])%MOD;
    }


    for(at=nn;at<nn+nn;at++)
    {
        if(at!=nn)
        {
            if(left>=at)
            {
                leftx = (leftx + MOD - tx[ id[at] ])%MOD;
                lefty = (lefty + MOD - ty[ id[at] ])%MOD;
            }

            rightx = (rightx + tx[ id[at-1] ])%MOD;
            righty = (righty + ty[ id[at-1] ])%MOD;

            if(left<at) left=at, leftx=lefty=0;
            //			if(right<=at-nn) right=at-nn, rightx=righty=0;

            while( left+1<at+nn && (left<at || ccw(at, left+1)) ) 
            {
                left++;

                leftx = (leftx + tx[ id[left] ])%MOD;
                lefty = (lefty + ty[ id[left] ])%MOD;
            }

            while( right<at && (right<=at-nn || ccw(at, right)) ) 
            {
                rightx = (rightx + MOD - tx[ id[right] ])%MOD;
                righty = (righty + MOD - ty[ id[right] ])%MOD;

                right++;
            }
        }


        cnt_left = left - at;
        cnt_right = at - right;

        //left
        to_add = (tx[ id[at] ]*lefty - (ty[ id[at] ]*leftx)%MOD + MOD)%MOD;
        ret =  (ret + cnt_right*to_add)%MOD;

        //right
        to_add = (ty[ id[at] ]*rightx - (tx[ id[at] ]*righty)%MOD + MOD)%MOD;
        ret =  (ret + cnt_left*to_add)%MOD;
    }

    return ret;
}

LL f2() //1*concave + 4*convex
{
    LL ret, sumx, sumy, cumx, cumy, cum_sxty, cum_sytx;
    LL to_add;

    int at, left;

    ret = 0;

    at = 0;

    left=0;
    sumx = sumy = 0;
    cumx = cumy = 0;
    cum_sxty = cum_sytx = 0;

    while( left+1<at+nn && ccw(at, left+1) ) 
    {
        left++;

        cumx = (cumx + sumx)%MOD;
        cumy = (cumy + sumy)%MOD;

        cum_sxty = (cum_sxty + tx[ id[left] ]*sumy)%MOD;
        cum_sytx = (cum_sytx + ty[ id[left] ]*sumx)%MOD;

        sumx = (sumx + tx[ id[left] ])%MOD;
        sumy = (sumy + ty[ id[left] ])%MOD;
    }

    for(at=0;at<nn;at++)
    {
        if(at!=0)
        {
            while( left+1<at+nn && (left<at || ccw(at, left+1)) ) 
            {
                left++;

                if(left<=at) continue;

                cumx = (cumx + sumx)%MOD;
                cumy = (cumy + sumy)%MOD;

                cum_sxty = (cum_sxty + tx[ id[left] ]*sumy)%MOD;
                cum_sytx = (cum_sytx + ty[ id[left] ]*sumx)%MOD;

                sumx = (sumx + tx[ id[left] ])%MOD;
                sumy = (sumy + ty[ id[left] ])%MOD;
            }
        }

        to_add = (tx[ id[at] ]*cumy - (ty[ id[at] ]*cumx)%MOD + MOD)%MOD;
        ret = (ret + to_add)%MOD;

        ret = (ret + cum_sytx - cum_sxty + MOD)%MOD;


        if(left>=at+1)
        {
            sumx = (sumx - tx[ id[at+1] ] + MOD)%MOD;
            sumy = (sumy - ty[ id[at+1] ] + MOD)%MOD;

            cum_sxty = (cum_sxty - (sumx*ty[ id[at+1] ])%MOD + MOD)%MOD;
            cum_sytx = (cum_sytx - (sumy*tx[ id[at+1] ])%MOD + MOD)%MOD;

            cumx = (cumx - ((left-at-1)*tx[ id[at+1] ])%MOD + MOD)%MOD;
            cumy = (cumy - ((left-at-1)*ty[ id[at+1] ])%MOD + MOD)%MOD;
        }
    }

    return ret;
}

int main()
{
    //	freopen("sample.in","r",stdin);
    //	freopen("sample.out","w",stdout);
    //	freopen("olddays.in","r",stdin);
    //	freopen("olddays.out","w",stdout);

    double start = clock();

    int T, ks, i;
    LL ans1, ans2, convex, concave;
    int ans;

    scanf("%d",&T);
    for(ks=1;ks<=T;ks++)
    {
        //		fprintf(stderr,"%d\n",ks);

        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d%d",&x[i],&y[i]);

        if(n<4)
        {
            printf("Case %d: %d\n", ks, 0);
            continue;
        }

        ans1 = 0;
        ans2 = 0;
        for(i=0;i<n;i++)
        {
            arrange_around(i);

            ans1 += f1();
            ans2 += f2();

            ans1 %= MOD;
            ans2 %= MOD;
            //		fprintf(stderr,"Ans1 = %d\n",ans1);
            //		fprintf(stderr,"Ans2 = %d\n",ans2);
        }

        //		fprintf(stderr,"Ans1 = %d\n",ans1);
        //		fprintf(stderr,"Ans2 = %d\n",ans2);

        concave = (ans1 - ans2 + MOD)%MOD;
        convex = ((ans2 - concave+MOD)*BigMod(4,MOD-2))%MOD;

        //		printf("Convex = %d\n",convex);
        //		printf("Concave = %d\n",concave);

        ans = (convex + concave)%MOD;

        printf("Case %d: %d\n", ks, ans);
    }

    double end = clock();

    fprintf(stderr,"%lf\n",(end-start)/ CLOCKS_PER_SEC);
    return 0;
}
