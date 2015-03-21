# include <bits/stdc++.h>

using namespace std;

int main(){
	int m,n;
	while(cin >> m >> n){
		int may_mat [m][n];
		int row_and[m];
		int col_and[n];
		vector< pair<int,int> > zeroes;
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < n; ++j){
				cin >> may_mat[i][j];
				if(may_mat[i][j] == 0){
					pair<int,int> tmp = make_pair(i,j);
					zeroes.push_back(tmp);
				}
			}
		}
		int refinal [m][n];
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; ++j)
				refinal[i][j] = 1;

		for(int i = 0; i < zeroes.size(); ++i){
			int a = zeroes[i].first;
			int b = zeroes[i].second;
			for(int j = 0; j < n; ++j)
				refinal[a][j] = 0;
			for(int j = 0; j < m; ++j)
				refinal[j][b] = 0;			
		}
		int row_or[m];
		int col_or[n];
		for(int i = 0; i < m; ++i){
			int tmp = 0;
			for(int j = 0; j < n; ++j)
				tmp |= refinal[i][j];
			row_or[i] = tmp;
		}
		for(int i = 0; i < n; ++i){
			int tmp = 0;
			for(int j = 0; j < m; ++j)
				tmp |= refinal[j][i];
			col_or[i] = tmp;
		}

		int validate [m][n];
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; ++j)
				validate[i][j] = col_or[j] | row_or[i];	

		bool flag = true;
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; ++j)
				if(validate[i][j] != may_mat[i][j]) flag = false;
		
		if(flag){
			cout<<"YES"<<endl;
			for(int i = 0; i < m; i++){
				for(int j = 0; j < n; ++j)
					cout<<refinal[i][j]<<" ";
				cout<<endl;
			}
		}
		else
			cout<<"NO"<<endl;
		
	}
	return 0;
}