# include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	char mio[n][n];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j)
			cin >> mio[i][j];
	}
	int supercont = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			int cont = ((i + 1 < n)?(mio[i + 1][j] == 'o'):0) + 
			           ((j + 1 < n)?(mio[i][j + 1] == 'o'):0) + 
			           ((i - 1 >= 0)?(mio[i - 1][j] == 'o'):0) +
			           ((j - 1 >= 0)?(mio[i][j - 1] == 'o'):0);
			supercont += (cont%2 == 0);		
		}
	}
	if(supercont == n*n)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}