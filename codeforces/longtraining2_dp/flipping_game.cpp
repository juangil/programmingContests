# include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	while(cin >> n){
		vector<int> mio(n);
		vector<int> mmio(n);
		for(int i = 0; i < n; ++i){
			int tmp;
			cin >>tmp;
			mmio[i] = tmp;
			mio[i] = (tmp == 0)? 1:-1;
		}
		int max_here = 0;
		int max_total = 0;
		int j = -1, k = 0, jj = -1;
		for(int i = 0; i < n; ++i){
			max_here += mio[i];
			if(max_here < 0){
				max_here = 0;				
				j = i;
			}
			if(max_here >= max_total){
				max_total = max_here;
				jj = j;
				k = i;
			}			
		}
		//cout<<endl;
		int total_sum = 0;
		for(int i =  0; i < n; ++i)
			total_sum += (i <= k && i > jj)? (1 - mmio[i]):mmio[i];
		if(jj == k) total_sum -= 1;
		cout<<total_sum<<endl;
		//cout<<jj<<" "<<k<<endl;
		
	}
	return 0;
}