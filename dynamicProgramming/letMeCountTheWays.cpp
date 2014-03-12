# include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ulli;
typedef long long lli;

const int N = 5;
const int MAXN = 30003;
const int INF = 1<<30;
int my_coins[] = {1, 5, 10, 25, 50};
ulli dp[MAXN][N];



ulli solve(int amount, int coin){
	if(amount == 0) return 1;
	if(dp[amount][coin] != -1) return dp[amount][coin];
	ulli ans = 0;
	for(int i = 0; i < N; ++i){
		if(amount >= my_coins[i]){
			if(my_coins[i] >= my_coins[coin]) 
				ans += solve(amount - my_coins[i], i);
		}
	}
	return dp[amount][coin] = ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int v; 
	for(int i = 0; i <= MAXN; ++i)
			for(int j = 0; j < N; ++j)
				dp[i][j] = -1;

	while(cin >> v){
		if(v == 0){
			cout<<"There is only 1 way to produce "<<v<<" cents change."<<endl;
			continue;
		}
		ulli ans = solve(v,0);
		if(ans == 1)cout<<"There is only 1 way to produce "<<v<<" cents change."<<endl;
		else cout<<"There are "<<ans<<" ways to produce "<<v<<" cents change."<<endl;
	}
	return 0;
}