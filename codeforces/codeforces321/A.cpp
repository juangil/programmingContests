//# include <iostream>
//# include <cstdlib>
//# include <math.h>
//# include <vector>
# include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> mnums(n);
	for(int i = 0; i < n; ++i)
		cin >> mnums[i];
	int j = 0, k = 1;
	int ans = 1;
	int tmp = 1;
	while(k < n){
		if(mnums[k] >= mnums[k - 1]){
			tmp = k - j + 1;
			k++;
		}
		else{
			j = k;
			k++;
			ans = max(ans,tmp);
		}
	}
	cout << max(ans,tmp) << endl;
	return 0;
}