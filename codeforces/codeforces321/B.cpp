#include <bits/stdc++.h>
#define __ ios_base::sync_with_stdio(0); cin.tie(0);


using namespace std;

typedef long long int lli;

bool mycmp(pair<lli,lli> a, pair<lli,lli> b){
    return a.first < b.first;
}

int main(){
    int n,d;
    cin >> n >> d;
    vector< pair<lli, lli> > mnums(n);
    vector<lli> msum(n + 1, 0);
    for(int i = 0; i < n; ++i){
        int a,b; cin >> a >> b;
        mnums[i] = make_pair(a,b);
    }
    if(n == 1){
        cout << mnums[0].second << endl;
        return 0;
    }
    sort(mnums.begin(), mnums.end(), mycmp);
    //cout << "paso2"<<endl;
    vector<lli> tmp(n);
    for(int i = 0; i < n; ++i){
        tmp[i] = mnums[i].first;
        //cout << tmp[i] << endl;
    }
    //cout << "paso3" << endl;
    for(int i = 1; i < n + 1; ++i){
        //cout << mnums[i - 1].second << " " <<  msum[i - 1] << endl;
        msum[i] = mnums[i - 1].second + msum[i - 1];
    }
    /*for(int i = 0; i < n + 1; ++i)
        cout << msum[i] << endl;*/
    //cout << "paso"<<endl;
    lli mmax = 0;
    for(int i = 0; i < n; ++i){
        int high = tmp[i] + d;
        vector<lli>::iterator b = lower_bound(tmp.begin(), tmp.end(), high) ;
        int r =  b - tmp.begin();
        if(r != 0) r--;
        //cout << i << " " << r << endl;
        //cout << msum[r] << " " << msum[i] << endl;
        mmax = max(mmax, msum[r + 1] - msum[i]);
    }
    cout << mmax << endl;
    return 0;
}
