# include <bits/stdc++.h>
# define MAXSIZE 6000

using namespace std;


int dp [MAXSIZE];
int mynums [MAXSIZE];
int N;

int lnds(int i){
    if(dp[i] != -1) return dp[i];
    if(i == 0) return 1;
    int ans = 1;
    for(int j = 0; j < i; ++j){
        if(mynums[i] >= mynums[j])
            ans = max(ans, 1 + lnds(j));
    }
    //dp[i] = ans;
    return ans;
}

int main(){
    int n,m;
    while(cin >> n >> m){
        N = n;
        for(int i = 0; i < n; ++i){
            double dummy;
            cin >> mynums[i] >> dummy;
            dp[i] = -1;
        }
        int ans = -1;
        for(int i = 0; i < n; ++i){
            dp[i] = lnds(i);
            ans = max(dp[i], ans);
        }
        cout << n - ans <<endl;
    }
    return 0;
}
