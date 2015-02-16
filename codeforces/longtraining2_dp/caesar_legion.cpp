# include <bits/stdc++.h> 

using namespace std;

typedef long long int lli;
const lli mod = 100000000;
const int MAXN = 102;
const int MAXK = 12;
int kk1 = 0;
int kk2 = 0;

lli memo[MAXN][MAXN][MAXK][MAXK];

lli solve(int n1, int n2, int k1, int k2){
	if(memo[n1][n2][k1][k2] != -1) return memo[n1][n2][k1][k2];
	if(n1 == 0 && n2 > kk2)return 0;
	if(n1 == 0 && n2 <= kk2)return 1;	
	if(n2 == 0 && n1 > kk1) return 0;
	if(n2 == 0 && n1 <= kk1)return 1;
	if(n1 == 0 && n2 == 0) return 1;
	lli ret = 0;
	if(k1 > 0 && k2 > 0)
		ret += solve(n1 - 1, n2, k1 - 1, kk2)%mod + solve(n1, n2 - 1, kk1, k2 - 1);
	else if(k1 > 0)
		ret += solve(n1 - 1, n2, k1 - 1, kk2)%mod;
	else if (k2 > 0)
		ret += solve(n1, n2 - 1, kk1, k2 - 1)%mod;
	memo[n1][n2][k1][k2] = ret;
	return ret;
}

int main(){
	int n1,n2,k1,k2;
	while(cin >> n1 >> n2 >> k1 >> k2){		
		for(int i = 0; i <= n1; i++)
			for(int j = 0; j <= n2; j++)
				for(int k = 0; k <= k1; ++k)
					for(int l = 0; l <= k2; ++l)
						memo[i][j][k][l] = -1;
		kk1 = k1;
	 	kk2 = k2;
	 	lli ret = solve(n1, n2, k1, k2)%mod;
		cout<<ret<<endl;
	}
}