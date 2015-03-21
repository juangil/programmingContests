# include <bits/stdc++.h>

using namespace std;

int msum(vector<int> &my_nums){
	int total_sum = 0;
	int n = my_nums.size();
	for(int i = 0; i < n; ++i){
		int sub_sum = 0;
		for(int j = i; j < n; ++j){
			int mmin = 1 << 30;
			for(int k = i; k <= j; ++k)
				mmin = min(mmin, my_nums[k]);
			sub_sum += mmin;
		}
		total_sum += sub_sum;
	}
	return total_sum;
}

int main(){
	int n, m;
	while(cin >> n >> m){
		vector<int> my_nums(n);
		for(int i = 0; i < n; ++i)
			my_nums[i] = i+1;
		//sort(my_nums.begin(), my_nums.end());
		int mayor = -1;		
		do{
			int total_sum = msum(my_nums);
			mayor = max(mayor,total_sum);				
		}while(next_permutation(my_nums.begin(), my_nums.end()));
		sort(my_nums.begin(), my_nums.end());
		int cont = 0;
		do{
			int total_sum = msum(my_nums);
			if(total_sum == mayor)
				cont++;
			if(cont == m){
				for(int i = 0; i < n; ++i)
					cout<<my_nums[i]<<" ";
				cout<<endl;
				break;
			}
		}while(next_permutation(my_nums.begin(), my_nums.end()));		
	}

	return 0;
}