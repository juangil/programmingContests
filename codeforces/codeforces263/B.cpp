# include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	char mio[n];
	scanf("%s", &mio);
	vector<long long int> supermio(26,0);
	for(int i = 0; i < n; ++i)
		supermio[mio[i] - 'A'] += 1;
	
	long long int superk = k;
	long long int total = 0;
	sort(supermio.begin(), supermio.end());
	for(int i = 25; i >= 0; i--){		
		if(supermio[i] > 0){
			long long int tmp = min(supermio[i], superk);
			superk -= tmp;
			total += tmp*tmp;
			if(superk == 0) break;
		}
	}
	cout<<total<<endl;
	
	return 0;
}