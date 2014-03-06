# include <bits/stdc++.h>

using namespace std;

const int MAXN = 10000;
int dp[MAXN];
vector<int> myNums;

int lds(int i){
	if(dp[i] != -1) return dp[i];
	if(i == 0) return 1;

	int ans = 1;
	for(int j = 0; j < i; ++j){
		if(myNums[i] < myNums[j])
			ans = max(ans,1 + lds(j));
	}
	return ans;
}

int main(){
	int a;
	int t = 0;
	bool primero = true;;
	while(cin >> a && a != -1){
		if(!primero) cout<<endl;
		myNums.clear();
		myNums.push_back(a);
		while(cin >> a){
			if(a == -1){
				t++;
				break;
			}
			myNums.push_back(a);
		}
		for(int i = 0; i < myNums.size(); ++i) 
			dp[i] = -1;

		int ans = 1;
		for(int i = 0; i < myNums.size(); ++i){
			dp[i] = lds(i);
			ans = max(ans,dp[i]);
		}
		cout<<"Test #"<<t<<":"<<endl;
		cout<<"  maximum possible interceptions: "<<ans<<endl;
		if(primero)primero = false;

	}

	return 0;
}