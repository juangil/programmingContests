# include <bits/stdc++.h>

using namespace std;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

set<int> ret;
int N;

void solve(int a, vector<int> mio){
    if( a > N || mio.size() == 1)
        return;
    vector<int> divi;
    vector<int> ndivi;
    for(int i = 0; i < mio.size(); ++i){
        if(mio[i]%a == 0)
            divi.push_back(mio[i]);
        else
            ndivi.push_back(mio[i]);
    }
    if(ndivi.size() == mio.size() || divi.size() == mio.size())
        solve(a + 1, mio);
    else{
        ret.insert(a);
        solve(a + 1, divi);
        solve(a + 1, ndivi);
    }
    return;
}

int main(){
    int n; cin >> n;
    N = n;
    vector<int> mio(n);
    for(int i = 0; i < n; ++i)
        mio[i] = i + 1;
    solve(2, mio);
    cout << ret.size() << endl;
    if(ret.size() > 0){
        string ans = "";
        for (set<int>::iterator it=ret.begin(); it!=ret.end(); ++it)
            //cout <<  *it << " ";
            ans += toStr(*it) + " ";

        ans.erase(ans.size() - 1, 1);
        cout << ans << endl;
    }
    return 0;
}
