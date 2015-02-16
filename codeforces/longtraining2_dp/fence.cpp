# include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k;
	while(cin >> n >> k){
		vector<int> ii(n + 1, 0);
		ii[0] = 0;
		vector<int> my_nums(n);
		for(int i = 0; i < n; ++i)
			cin >> my_nums[i];
		for(int i = 1; i < n + 1; ++i)
			ii[i] = my_nums[i - 1] + ii[i - 1];
		vector<int> dp(n + 1);
		dp[0] = 1 << 30;
		int mmin = 1 << 30;		
		for(int i = 1; i < n + 1; ++i){
			if(i + k - 1 >= n + 1){
				dp[i] = dp[i - 1];
				continue;
			}
			int tmp = ii[i + k - 1] - ii[i - 1];
			if(tmp < mmin){
				mmin = tmp;
				dp[i] = i;
			}
			else
				dp[i] = dp[i - 1];			
		}
		/*for(int i = 0; i < n + 1; ++i)
			cout<<ii[i]<<" ";
		cout<<endl;*/
		cout<<dp[n]<<endl;
	}
}