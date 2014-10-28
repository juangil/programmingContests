# include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli mod = 1000000007;
const int MAXN = 100002;

lli dp [MAXN];
lli dp_acum [MAXN];

int main(){
	int t,k;
	dp[0] = 1;
	cin >> t >> k;
	for(int i = 1; i < MAXN - 1; ++i){
		if(k > i)
			dp[i] = 1;
		else{
			dp[i] = (dp[i - 1]%mod + dp[i - k]%mod)%mod;
			//cout<<(dp[i]<=mod)<<endl;
		}
	}
	dp_acum[0] = 0;
	for(int i = 1; i < MAXN; ++i)
		dp_acum[i] = (dp[i] + dp_acum[i - 1]);

	for(int i = 0; i < t; ++i){
		int a,b;
		cin >> a >> b;
		cout<<(dp_acum[b] - dp_acum[a - 1])%mod<<endl;
	}
	return 0;
}