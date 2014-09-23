# include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef unsigned long long int ulli;
const int MAXN = 5002;
const int MAXK = 5002;
int K;
int N;
int M;

vector<lli> ii;
ulli dp[MAXN][MAXK];

lli solve(int i, int j){
	int ni = i + M - 1;
	if(j == K || ni > N) return 0;
	if(dp[i][j] != -1) return dp[i][j];	
	lli ans = max(ii[ni] - ii[i - 1] + solve(ni + 1, j + 1), solve(i + 1, j));
	return dp[i][j] = ans;
}

int main(){
	int n,m,k;
	while(cin >> n >> m >> k){
		N = n; K = k; M = m;
		vector<lli> mio(n);
		ii.resize(n + 1);
		ii.clear();

		for(int i = 0; i < n; ++i)
			cin >> mio[i];
		
		//cout<<"pass"<<endl;
		ii[0] = 0;
		for(int i = 1; i < n+1; ++i)
			ii[i] = mio[i - 1] + ii[i-1];

		
		for(int i = 0; i <= n; ++i)
			for(int j = 0; j <= k; ++j)
				dp[i][j] = -1;

		lli mayor = solve(1,0);
		cout<<mayor<<endl;
	}
	return 0;
}