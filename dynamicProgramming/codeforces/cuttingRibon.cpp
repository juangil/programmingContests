# include <bits/stdc++.h>

using namespace std;

int n,a,b,c;
const int maxn = 4002;
const int INF = (1<<30);

int dp[maxn];


int main(){
     while (cin >> n >> a >> b >> c){
	dp[0] = 0;
	for (int i = 1; i <= n; ++i){
		dp[i] = -INF;
		if (i >= a) dp[i] = max(dp[i], 1 + dp[i-a]);
		if (i >= b) dp[i] = max(dp[i], 1 + dp[i-b]);
		if (i >= c) dp[i] = max(dp[i], 1 + dp[i-c]);
	}
	cout << dp[n] << endl;
     }
     return 0;
}
