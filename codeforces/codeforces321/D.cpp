# include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
const lli MAXNUMS = 20;
int M = 0, N = 0;
lli mcost[MAXNUMS];
lli mnext[MAXNUMS][MAXNUMS];
lli dp[1 << MAXNUMS][MAXNUMS];

lli solve(int mask, int last){
    if(__builtin_popcount(mask) == M) return 0LL;
    if(dp[mask][last] != -1 && last != -1) return dp[mask][last];
    lli ans = 0LL;
    for(int i = 0; i < N; ++i){
        if(((1 << i) & mask) == 0){
            int new_mask = (mask | (1 << i));
            lli new_gain = mcost[i] + ((last != -1)? mnext[last][i]:0LL);
            ans = max(ans, new_gain + solve(new_mask, i));
        }
    }
    dp[mask][last] = ans;
    return dp[mask][last];
}


int main(){
    int n,m,k;
    cin >> n >> m >> k;
    M = m; N = n;
    for(int i = 0; i < (1 << MAXNUMS); ++i)
        for(int j = 0; j < MAXNUMS; ++j)
            dp[i][j] = -1;

    for(int i = 0; i < MAXNUMS; i++)
        for(int j = 0; j < MAXNUMS; ++j)
            mnext[i][j] = 0;

    for(int i = 0; i < n; ++i)
        cin >> mcost[i];

    for(int i = 0; i < k; ++i){
        int x,y;
        lli z;
        cin >> x >> y >> z;
        mnext[x -  1][y  - 1] = z;
    }
    cout << solve(0,-1) << endl;
    return 0;
}
