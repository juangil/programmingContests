# include <bits/stdc++.h>

using namespace std;

int main(){
	int a,b,c,d;
	while(cin >> a >> b >> c >> d){
		int cal [4];
		cal[0] = a;
		cal[1] = b;
		cal[2] = c;
		cal[3] = d;
		string mio; cin >> mio;
		long long int calories = 0;
		for(int i = 0;i < mio.size(); ++i){
			calories += cal[(mio[i] - '0') - 1];
		}
		cout<<calories<<endl;
	}
	return 0;
}
