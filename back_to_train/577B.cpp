# include <bits/stdc++.h>

using namespace std;

int M;
int N;
vector<int> mnums;
int dp[1002][1002];
int dp2[1002][1002][2];

void solve(int i, int sum){
    if(dp[i][sum] == 1 || i == N) return;
    int nsum = ((sum == -1)? mnums[i]%M:(sum + mnums[i])%M);
    dp[i][nsum] = 1;
    if(sum != -1) dp[i][sum] = 1;
    solve(i + 1, nsum);
    solve(i + 1, sum);
    return;
}

bool solve2(int i, int msum, bool taken){
    if(dp2[i][msum][taken] != -1) return dp2[i][msum][taken];
    if(i == N) return (msum == 0 && taken == 1);
    bool ans = solve2(i + 1, (msum + mnums[i])%M, 1) || solve2(i + 1, msum, taken);
    dp2[i][msum][taken] = ans;
    return dp2[i][msum][taken];
}

int main(){
    int n,m;
    cin >> n >> m;
    if(n >= m){
        cout << "YES" << endl;
        return 0;
    }
    M = m;
    N = n;
    mnums.resize(n);
    for(int i = 0; i < n; ++i)
        cin >> mnums[i];

    /*for(int i = 0; i < 1002; ++i)
        for(int j = 0; j < 1002; ++j)
            dp[i][j] = -1;
    solve(0,-1);
    for(int i = 0; i < n; ++i){
        if(dp[i][0] == 1){
            //cout << i << " " << dp[i][0] << endl;
            cout << "YES" << endl;
            return 0;
        }
    }*/
    for(int i = 0; i < 1002; ++i){
        for(int j = 0; j < 1002; ++j){
            dp2[i][j][0] = -1;
            dp2[i][j][1] = -1;
        }
    }

    if(solve2(0,0,0)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
