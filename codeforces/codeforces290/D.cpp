# include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

vector<lli> my_nums;
vector<lli> my_cost;
map< pair<int,lli>, lli> memo;
//map<lli, lli> memo;
const lli INF = 1152921504606846975;


lli solve(int i, lli my_gcd){
	pair<int, lli> tmp_diff = make_pair(i, my_gcd);	
	if(memo[tmp_diff]) return memo[tmp_diff];
	if(abs(my_gcd) == 1) return 0;	
	if(i >= my_nums.size() && abs(my_gcd) != 1) return INF;	
	lli ret = min(my_cost[i] + solve(i + 1, __gcd(my_gcd, my_nums[i])), my_cost[i] + solve(i + 1, __gcd(my_gcd, -my_nums[i])));
	ret = min(ret, solve(i + 1, my_gcd));
	memo[tmp_diff] = ret;
	return ret;
} 

int main(){
	int n;
	while(cin >> n){
		my_nums.clear();
		my_cost.clear();
		my_nums.resize(n);
		my_cost.resize(n);
		memo.clear();
		for(int i = 0; i < n; ++i)
			cin >> my_nums[i];
		for(int i = 0; i < n; ++i)
			cin >> my_cost[i];
		lli ret = solve(0,0);
		ret = (ret == INF)? -1:ret;
		cout<<ret<<endl;
	}
	return 0;
}