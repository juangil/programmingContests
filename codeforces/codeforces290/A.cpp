# include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	while(cin >> n >> m){
		char mio[n][m];
		int rows = 0;
		for(int i = 0; i < n; ++i){
			bool flag = false;						
			for(int j = 0; j < m; ++j){				
				if(i%2 == 0){
					mio[i][j] = '#';
					if(flag == false){
						rows++;
						flag = true;
					}
				}
				else{
					if(rows%2 != 0 && j == m - 1)
						mio[i][j] = '#';
					else if(rows%2 == 0 && j == 0)
						mio[i][j] = '#';
					else
						mio[i][j] = '.';
				}
				cout<<mio[i][j];
			}
			cout<<endl;
		}

	}
	return 0;
}