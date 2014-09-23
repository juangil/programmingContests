# include <bits/stdc++.h>

using namespace std;

int bit_equal(int a, int b, int k){
	int cont = 0;
	for(int i = 0; i < 32; ++i){
		int mio = 1 << i;
		if(mio & a){
			if(!(mio & b))
				cont ++;
		}
		else if(mio & b){
				cont ++;
		}
				
	}
	if (cont <= k) return 1;
	else return 0;
}

int main(){
	int n,m,k;
	cin >> n >> m >> k;
	vector<int> mio(m);
	int remio;
	for(int i = 0; i < m; ++i)
		cin >> mio[i];
	cin >> remio;
	int cont = 0;
	for(int i = 0; i < m; ++i)
		cont += bit_equal(mio[i], remio, k);
	cout<<cont<<endl;
	return 0;
}