# include <cstdio>
# include <iostream>
# include <cstdlib>
# include <cmath>
# include <set>

using namespace std;

int main(){
	int n,k; cin >> n >> k;
	if(k <= n){
		int mdiv = n / k;
		cout << (mdiv+1) * k << endl;
	}
	else{
		cout << k << endl;
	}
	return 0;
}