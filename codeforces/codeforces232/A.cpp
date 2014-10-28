# include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	int a,b; cin >> a >> b;
	int mypos[102];
	for(int i = 0; i < 102; ++i)
		mypos[i] = 0;
	for(int i = a ; i < b; ++i )
		mypos[i] = 1;
	
	
	for(int i = 0; i < n - 1; ++i){
		int x,y; cin >> x >> y;
		for(int j = x  ; j < y; ++j)
			mypos[j] = 0;
	}
	int cont  = 0;
	//for(int i = 0; i < 102; ++i)
		//cout<<mypos[i]<<endl;
	for(int i = a ; i < b; ++i )
		if(mypos[i]) cont++;
	cout<<cont<<endl;

	return 0;
}
