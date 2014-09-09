# include <bits/stdc++.h>

using namespace std;


int main(){
	int n; cin >> n;
	vector<int> lleve(n);
	int mayor = 0;
	for(int i = 0; i < n; ++i){
		cin >> lleve[i];
		if(lleve[i] > mayor)
			mayor = lleve[i];
	}	
	cout<<mayor<<endl;
}	