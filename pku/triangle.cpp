# include <iostream>
# include <cstdlib>
# include <cstdio>

# define ___ ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;


const int MAXROW = 102;
const int MAXCOL = 102;

int dp[MAXROW][MAXCOL];
int my_mat[MAXROW][MAXROW];
int N;

int solve(int i, int j){
	if(i == N - 1) return my_mat[i][j];
	if(dp[i][j] != -1) return dp[i][j];
	int ans = max(my_mat[i][j] + solve(i+1, j), my_mat[i][j] + solve(i+1, j+1));
	dp[i][j] = ans;
	return ans;
}

int main(){
	int n;
	___
	while(cin >> n){
		N = n;
		for(int i = 0; i < MAXROW; ++i){
			for(int j = 0; j < MAXCOL; ++j){
				dp[i][j] = -1;
				my_mat[i][j] = 0;
			}
		}

		for(int i = 0; i < n; ++i)
			for(int j = 0; j < i + 1; ++j)
					cin >> my_mat[i][j];
		
		cout<<solve(0,0)<<endl;
	}
	
}