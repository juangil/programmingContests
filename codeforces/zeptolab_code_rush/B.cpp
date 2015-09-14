# include <bits/stdc++.h>

using namespace std;
const int MAXN = 2100;

int lights_on [MAXN];
int N;
int supermax;
int ans = 0;

int dfs_max(int i){
    //cout << (int)floor(log2(i)) << endl;
    if((int)floor(log2(i)) == N) return 0;
    int m1 = lights_on[2*i] + dfs_max(2*i);
    int m2 = lights_on[(2*i) + 1] + dfs_max((2*i) + 1);
    int mmax = max(m1, m2);
    ans += (mmax - m1) + (mmax - m2);
    return mmax;
}

int main(){
    int n;
    while(cin >> n){
        N = n;
        for(int i = 2; i <= ((1 << (n + 1)) - 1); ++i){
            int a; cin >> a;
            lights_on[i] = a;
        }
        ans = 0;
        dfs_max(1);
        cout << ans << endl;
    }
    return 0;
}
