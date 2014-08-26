# include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
const int N = 100010;


int main(){
	int n; cin >> n;
	vector<long long int> mio(n);
	vector<long long int> ii(n+1,0);
	for(int i = 0; i < n; ++i)
		cin >> mio[i];
	if(n == 1){
		cout<<mio[0]<<endl;
		return 0;
	}
	sort(mio.begin(), mio.end());
	ii[1] = mio[0];
	for(int i = 2; i < n + 1; ++i)
		ii[i] = mio[i - 1] + ii[i - 1];

	int last = n;
	long long int total = 0;
	for(int i = 0; i < n + 1; ++i)
		total += (ii[last] - ii[i]);		
	for(int i = 0; i < n - 1; ++i)
		total += mio[i];
	
	cout<<total<<endl;
	return 0;
}