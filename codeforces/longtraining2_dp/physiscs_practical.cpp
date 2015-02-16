# include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while(cin >> n){
		vector<int> my_nums(n);
		for(int i = 0; i < n; ++i)
			cin >> my_nums[i];
		sort(my_nums.begin(), my_nums.end());
		int mayor = 0;
		for(int i = 0; i < n; ++i){
			int tmp = my_nums[i]*2;
			int idx = lower_bound(my_nums.begin(), my_nums.end(), tmp) - my_nums.begin();
			int idx2 = idx;
			if(idx < n){
				int mio = my_nums[idx];
				if(my_nums[idx] == tmp)
					idx2 = upper_bound(my_nums.begin(), my_nums.end(), tmp) - my_nums.begin();
				idx2--;
			}
			else
				idx2--;
			int diff = idx2 - i + 1;
			if(diff > mayor)
				mayor = diff;
		}
		cout<<n - mayor<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}