# include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	int cont = 0;
	for(int i = 0; i < n; ++i){
		int a, b;
		cin >> a >> b;
		int diff = b - a;
		if(diff >= 2)cont += 1;		
	}
	cout<<cont<<endl;

	return 0;
}