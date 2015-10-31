# include <bits/stdc++.h>

using namespace std;
typedef unsigned long long int lli;

int main(){
    lli t,w,b;
    cin >> t >> w >> b;
    lli fav_cas = 0;
    lli mmin = min(w,b);
    lli mmax = max(w,b);
    pair<int,int> ret;
    if(t < mmin){
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
        comp_ans(fav_cas, t);
        return 0;
    }
    else{
        
    }

}
