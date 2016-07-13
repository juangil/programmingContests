# include <bits/stdc++.h>
# include <iostream>
# include <cstdlib>
# include <cstdio>
# include <math.h>

using namespace std;
typedef unsigned long long int lli;

void comp_ans(lli a, lli b){
    lli mgcd = __gcd(a,b);
    //cout << a << "/" << b  << ": ";
    while(mgcd != 1){
        a /= mgcd;
        b /= mgcd;
        mgcd = __gcd(a,b);
    }
    cout << a << "/" << b << endl;
    return;
}

int main(){
    lli t,w,b;
    cin >> t >> w >> b;
    lli fav_cas = 0;
    lli mmin = min(w,b);
    lli mmax = max(w,b);
    pair<int,int> ret;
    if(mmin == 1 || mmax == 1){
        cout << t/mmax << "/" << t << endl;
        return 0;
    }
    if(t < mmin || mmin == mmax){
        cout << "1/1" << endl;
        return 0;
    }
    else if(t == mmin){
        cout << t - 1 << "/" << t << endl;
        return 0;
    }
    else
        fav_cas += mmin - 1;
    if(t <= mmax){
        fav_cas += (mmax == t && mmax%mmin == 0)? 1:0;
        comp_ans(fav_cas, t);
        return 0;
    }
    lli res = t - mmax;    
    if(res < mmax){
        fav_cas += (mmax%mmin == 0)? 1:0;
        fav_cas += min(res, mmin - 1);
        comp_ans(fav_cas, t);
    }
    else if(res == mmax){
        fav_cas += (mmax%mmin == 0)? 2:0;
        fav_cas += (mmax%mmin == 0)? mmin - 1:0;
        //cout << fav_cas << endl;
        comp_ans(fav_cas,t);
    }
    else{
        lli spaces = t / mmax;
        //cout << spaces << endl;
        if(spaces >= mmin){
            lli lcm = mmin*mmax/__gcd(mmin,mmax);
            lli caben = t / lcm;
            fav_cas += (caben + ((caben-1)*(mmin - 1)));
            //cout << caben << " " << fav_cas << endl;
            fav_cas += min(mmin - 1, t - (lcm * caben));
            //cout << fav_cas << endl;
            comp_ans(fav_cas, t);
        }
        else{
            if(mmax % mmin == 0){
                lli caben = t / mmax;
                fav_cas += (caben + ((caben-1)*(mmin - 1)));
                fav_cas += min(mmin - 1, t - (mmax * caben));
            }
            comp_ans(fav_cas,t);
        }
    }

    return 0;
}
