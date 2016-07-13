//# include <bits/stdc++.h>
# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <math.h>
# include <map>
# include <vector>
# include <set>

using namespace std;

typedef long long int lli;

int main(){
	vector<lli> mnums;
	for(int i = 1; i < 62; ++i){
		lli mmask = 0;
		lli aux = 0;
		for(int j = 0; j <= i; ++j){
			aux = 1LL << j;
			mmask = mmask | aux;
		}

		for(int j = i - 1; j >= 0; j--){
			aux = 1LL << j;
			lli tmp = mmask ^ aux;
			mnums.push_back(tmp);
		}
	}
	sort(mnums.begin(), mnums.end());
	//cout << mnums[mnums.size() - 1] << endl;
	//cout << mnums[0] << endl;
	lli a,b;
	while(cin >> a >> b){
		int ans = 0;
		for(int i = 0; i < mnums.size(); ++i){
			if(mnums[i] >= a && mnums[i] <= b)
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}